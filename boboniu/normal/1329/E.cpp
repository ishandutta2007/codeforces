#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxN = 456789;
int tc;
i64 n, k, p[maxN], len[maxN];
int m;
void solve()
{
	cin >> n >> m >> k;
	p[0] = 0;
	for (int i = 1; i <= m; i++)
	{
		cin >> p[i];
	}
	p[m + 1] = n;
	m++;
	for (int i = 1; i <= m; i++)
		len[i] = p[i] - p[i - 1];
	i64 seg = m + k;
	i64 l = 0, r = n + 1;
	while (l + 1 < r)
	{
		i64 mid = (l + r) / 2;
		i64 s = 0;
		for (int i = 1; i <= m; i++)
		{
			s += len[i] / mid;
		}
		if (s >= seg)
			l = mid;
		else
			r = mid;
	}
	i64 fL = l;
	l = 0, r = n + 1;
	while (l + 1 < r)
	{
		i64 mid = (l + r) / 2;
		i64 s = 0;
		for (int i = 1; i <= m; i++)
		{
			s += (len[i] + mid - 1) / mid;
		}
		if (s <= seg)
			r = mid;
		else
			l = mid;
	}
	i64 fR = r;
	vector<pair<i64, i64>> extra;
	for (int i = 1; i <= m; i++)
	{
		if (len[i] / fL >= (len[i] + fR - 1) / fR)
			continue;
		i64 x = len[i] / fL, pL = 1ll << 60;
		if (x != 0)
			pL = (len[i] + x - 1) / x;
		i64 y = (len[i] + fR - 1) / fR, pR = len[i] / y;
		extra.push_back({pR, pL});
	}
	sort(extra.begin(), extra.end());
	i64 maxR = fR;
	i64 ans = n + 1;
	for (auto p : extra)
	{
		ans = min(ans, maxR - p.first);
		maxR = max(maxR, p.second);
	}
	ans = min(ans, maxR - fL);
	cout << ans << "\n";
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