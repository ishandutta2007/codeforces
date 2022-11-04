#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n = 1;
	long long cur = 2;
	long long x;
	cin >> x;
	while (n <= x)
	{
//		cerr << n << endl;
		if (x == n || x == n + 1)
		{
			cout << 1 << endl;
			return 0;
		}
		n = 2 * n + cur;
		cur = 3 - cur;
	}
	cout << 0 << endl;
	return 0;
}