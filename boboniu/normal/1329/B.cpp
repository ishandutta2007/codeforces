#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxN = 123456;
int tc, num[maxN];
void solve()
{
	int d, m;
	cin >> d >> m;
	i64 ans = 1;
	for (int i = 1; i <= 30; i++)
	{
		int l = 1 << (i - 1), r = (1 << i) - 1;
		r = min(r, d);
		if (l <= r)
			num[i] = r - l + 1;
		else
			num[i] = 0;
		ans = ans * (num[i] + 1) % m;
	}
	ans = (ans + m - 1) % m;
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		solve();
	}
}