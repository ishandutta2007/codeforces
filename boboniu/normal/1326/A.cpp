#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int t, n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		if (n == 1)
		{
			cout << -1 << "\n";
		}
		else
		{
			for (int j = 0; j < n - 1; j++)
				cout << 9;
			cout << 8 << "\n";
		}
	}
}