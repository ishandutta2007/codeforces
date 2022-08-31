/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, M = 2e5 + 50;

int ans[N];
pii f[N];
vector <pii> x[M], y[M];

int main()
{
	int n, w, h;
	cin >> n >> w >> h;
	for (int i = 1; i <= n; ++i)
	{
		int g, p, t;
		cin >> g >> p >> t;
		if (g == 1)
		{
			x[p - t + N].pb({p, i});
			f[i] = {p, h};
		}
		else
		{
			y[p - t + N].pb({p, i});
			f[i] = {w, p};
		}

		ans[i] = i;
	}

	for (int t = 0; t < M; ++t)
	{
		// cout << t << '\n';
		sort(x[t].begin(), x[t].end());
		sort(y[t].begin(), y[t].end());
		int k = x[t].size(), m = y[t].size();
		if (!k or !m)
			continue;

		// if (k > m)
		// {
		// 	swap(x[t], y[t]);
		// 	swap(k, m);
		// }

		if (k <= m)
		{
			for (int c = m; c >= m - k + 1; --c)
				ans[y[t][c - 1].second] = x[t][m - c].second;

			for (int c = 1; c <= k; ++c)
				ans[x[t][c - 1].second] = y[t][k - c].second;

			for (int c = 1; c <= m - k; ++c)
				ans[y[t][c - 1].second] = y[t][c + k - 1].second;
		}

		else
		{
			for (int c = k; c >= k - m + 1; --c)
				ans[x[t][c - 1].second] = y[t][k - c].second;

			for (int c = 1; c <= m; ++c)
				ans[y[t][c - 1].second] = x[t][m - c].second;

			for (int c = 1; c <= k - m; ++c)
				ans[x[t][c - 1].second] = x[t][c + m - 1].second;
		}

		// if (t == 1 - 10 + N)
		// {
		// 	cout << y[t][0].first << ' ' << y[t][0].second << 'a' << endl;
		// }
	}

	for (int i = 1; i <= n; ++i)
		cout << f[ans[i]].first << ' ' << f[ans[i]].second << endl;
}