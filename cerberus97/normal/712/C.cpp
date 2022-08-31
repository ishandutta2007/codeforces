#include <iostream>

using namespace std;

int getAns(int x, int y)
{
	if (x == y)
		return 0;

	int steps = 0, prev = x, next = x;

	while (next < y)
	{
		++steps;

		int temp = next;
		next += prev - 1;
		prev = temp;
	}

	return steps + 2;
}

int main()
{
	int x, y;
	cin >> x >> y;

	if (y < x)
		swap(x, y);

	cout << getAns(x, y);
}