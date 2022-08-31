#include <iostream>
#include <algorithm>

using namespace std;

long long nc2[(int)1e5];

void pre()
{
	for (long long i = 1; i < 1e5; ++i)
	{
		nc2[i] = i*(i-1)/2;
	}
}

int binSearch(int l, int r, int val)
{
	while (l <= r)
	{
		int mid = (l+r)/2;

		if (nc2[mid] == val)
			return mid;

		else if (nc2[mid] < val)
			l = mid+1;

		else
			r = mid-1;
	}

	return -1;
}

bool isPossible(int a00, int a01, int a10, int a11, int n, int m)
{
	if (a10 + a01 != n*m or abs(a10-a01) % 2 != n*m % 2)
	{
		return false;
	}

	if (!n)
	{
		for (int i = 0; i < m; ++i)
			cout << 0;

		return true;
	}

	if (!m)
	{
		for (int i = 0; i < n; ++i)
			cout << 1;

		return true;
	}

	for (int i = 0; i < a01/n; ++i)
		cout << 0;

	for (int i = 0; i < n-(a01%n); ++i)
		cout << 1;

	if (a01/n < m)
		cout << 0;

	for (int i = 0; i < a01%n; ++i)
		cout << 1;

	for (int i = 0; i < (m - a01/n - 1); ++i)
		cout << 0;

	return true;
}

int main()
{
	pre();

	int a00, a01, a10, a11;
	cin >> a00 >> a01 >> a10 >> a11;

	int n = binSearch(1, 1e5-1, a11), m = binSearch(1, 1e5-1, a00);

	if (n == -1 or m == -1 or (n == 0 and m == 0))
	{
		cout << "Impossible";
		return 0;
	}

	if (!n)
	{
		for (int i = 0; i < m; ++i)
			cout << 0;

		return 0;
	}

	if (!m)
	{
		for (int i = 0; i < n; ++i)
			cout << 1;

		return 0;
	}

	bool ans = false;

	if (n == 1 and m == 1)
	{
		ans = ans or isPossible( a00,  a01,  a10,  a11,  n,  m) or isPossible( a00,  a01,  a10,  a11,  n, 0) or isPossible( a00,  a01,  a10,  a11, 0,  m);
		if (!ans)
			cout << "Impossible";
	}

	else if (n == 1)
	{
		ans = ans or isPossible( a00,  a01,  a10,  a11, 0,  m) or isPossible( a00,  a01,  a10,  a11,  n,  m);
		if (!ans)
			cout << "Impossible";
	}

	else if (m == 1)
	{
		ans = ans or isPossible( a00,  a01,  a10,  a11,  n, 0) or isPossible( a00,  a01,  a10,  a11,  n,  m);
		if (!ans)
			cout << "Impossible";
	}

	else
	{
		ans = isPossible( a00,  a01,  a10,  a11,  n,  m);
		if (!ans)
			cout << "Impossible";
	}
}