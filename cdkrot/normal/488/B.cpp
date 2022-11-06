#include <iostream>
#include <algorithm>
#include <assert.h>

using std::max;
using std::cin;
using std::cout;
using std::endl;

bool check(int* data)
{
	return (data[3] == 3 * data[0]) and (data[2] + data[1] == 4 * data[0]) and \
		(data[0] <= data[1]) and (data[1] <= data[2]) and (data[2] <= data[3]);
}

void do_3(int* data) // 0, 1, 2, [3]
{
	if (4 * data[0] == data[1] + data[2] and data[2] <= 3 * data[0])
	{
		cout << "YES" << endl;
		cout << 3 * data[0] << endl;
		return;
	}
	if (data[2] == 3 * data[0] and (4 * data[0] - data[1]) <= data[2] and (4 * data[0] - data[1]) >= data[0])
	{
		cout << "YES" << endl;
		cout << (4 * data[0] - data[1]) << endl;
		return;
	}
	if (4 * data[2] == 3 * (data[0] + data[1]) and data[2] / 3 <= data[0])
	{
		cout << "YES" << endl;
		cout << data[2] / 3 << endl;
		return;
	}
	cout << "NO" << endl;
}

void do_2(int* data) // 0, 1, [2], [3].
{
	int a = data[0];
	int b = data[1];
	
	if (b == 3 * a)
	{
		cout << "YES" << endl;
		cout << 2 * a << "\n" << 2 * a << "\n";
		return;
	}
	if (4 * a - b >= a and max(4 * a - b, b) <= 3 * a)
	{
		cout << "YES" << endl;
		cout << 4 * a - b << "\n" << 3 * a << "\n";
		return;
	}
	if ((a + b) % 4 == 0 and (a + b) / 4 <= a and 3 * (a + b) / 4 >= b)
	{
		cout << "YES" << endl;
		cout << (a + b) / 4 << "\n" << 3 * (a + b) /4 << endl;
		return;
	}
	if (b % 3 == 0 and (b / 3) <= a and 4 * (b / 3) - a <= b and 4 * (b / 3) - a >= b / 3)
	{
		cout << "YES" << endl;
		cout << b / 3 << "\n" << 4 * (b / 3) - a << "\n";
		return;
	}
	cout << "NO\n";
}

int main()
{
	int data[4];
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> data[i];
	
	if (n == 0)
		cout << "YES" << endl << "1\n1\n3\n3\n";
	else if (n == 1)
		cout << "YES" << endl << data[0] * 2 << "\n" << data[0] * 2 << "\n" << data[0] * 3 << endl;
	else if (n == 4)
	{
		std::sort(data, data + 4);
		if (check(data))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	else
	{
		std::sort(data, data + n);
		
		if (n == 3)
			do_3(data);
		else if (n == 2)
			do_2(data);
		else
			assert(false);
	}
	
	return 0;
}