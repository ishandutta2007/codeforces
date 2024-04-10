#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int t, n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	i64 x = 0;
	for (int i = 0; i < n; i++)
	{
		int y;
		cin >> y;
		if (y >= 0)
		{
			x += y;
			cout << x << " ";
		}
		else
		{
			cout << x + y << " ";
		}
	}
}