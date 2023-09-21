// array - это массив, в котором мы проводим поиски.
// target - это искомое значение.
// min - это индекс минимальной границы массива, в котором мы осуществляем поиск.
// max - это индекс максимальной границы массива, в котором мы осуществляем поиск.
// Функция binarySearch() должна возвращать индекс искомого значения, если он обнаружен. В противном случае, возвращаем -1
#include<iostream>
int binarySearch(int* array, int target, int min, int max)
{
	while (min <= max)
	{
		int sr = min + ((max - min) / 2);
		if (array[sr] == target)
			return sr;
		if (array[sr] > target)
			max = sr -1;
		if (array[sr] < target)
			min = 1 + sr;
		
	}
	return -1;
}
int binarySearchRecurs(int* array, int target, int min, int max)
{
	if (min <= max)
	{
		int sr = min + ((max - min) / 2);
		if (array[sr] == target)
			return sr;
		if (array[sr] > target)
			return binarySearchRecurs(array, target, min, sr - 1);
		if (array[sr] < target)
			return binarySearchRecurs(array, target, sr + 1, max);
	}
}

int main()
{
	int array[] = { 4, 7, 9, 13, 15, 19, 22, 24, 28, 33, 37, 41, 43, 47, 50 };

	std::cout << "Enter a number: ";
	int x;
	std::cin >> x;

	int index = binarySearchRecurs(array, x, 0, 14);

	if (array[index] == x)
		std::cout << "Good! Your value " << x << " is on position " << index << " in array!\n";
	else
		std::cout << "Fail! Your value " << x << " isn't in array!\n";

	return 0;
}