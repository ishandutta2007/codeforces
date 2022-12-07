#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxN = 123456;
int a[maxN];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t, n;
	cin >> t;
	for (int tc = 0; tc < t; tc++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int pmax = a[0], d = 0;
		for (int i = 1; i < n; i++)
		{
			d = max(d, pmax - a[i]);
			pmax = max(pmax, a[i]);
		}
		int ans = 0;
		while ((1ll << ans) - 1 < d)
			ans++;
		cout << ans << "\n";
	}
	return 0;
}