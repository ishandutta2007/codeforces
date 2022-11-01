#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define zhfs main
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 1; i <= n; i++)
int maxCost(int solved, int total)
{
	if (2LL * solved > total) return 500;
	if (4LL * solved > total) return 1000;
	if (8LL * solved > total) return 1500;
	if (16LL * solved > total) return 2000;
	if (32LL * solved > total) return 2500;
	return 3000;
}
int cost(int solved, int total, int time)
{
	if (time == -1) return 0;
	return maxCost(solved, total) / 250 * (250 - time);
}
int getSolved(int n, int x, int solved, int want)
{
	int l = 0, r = x + 1;
	while (r - l > 1)
	{
		int m = (l + r) / 2;
		if (maxCost(solved + m, n + x) >= want)
		{
			l = m;
		}
		else
		{
			r = m;
		}
	}
	return l;
}
int a[125][7];
int solved[7];
ll calcDelta(int n, int x)
{
	int res = 0;
	for (int i = 1; i <= 5; i++)
	{
		int cur = -1000000;
		if (a[1][i] == -1)
		{
			cur = cost(solved[i], n + x, a[1][i]) - cost(solved[i], n + x, a[2][i]);
		}
		else
		{
			for (int j = 500; j <= 3000; j += 500)
			{
				int vv = getSolved(n, x, solved[i], j);
				cur = max(cur, cost(solved[i] + vv, n + x, a[1][i]) - cost(solved[i] + vv, n + x, a[2][i]));
			}
		}
		res += cur;
	}
	return res;
}
int zhfs()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			scanf("%d", &a[i][j]);
			if (a[i][j] != -1)
			{
				solved[j]++;
			}
		}
	}
	int l = -1, r = (int)1e9 + 8;
	for (int i = 0; i <= 10000; i++)
	{
		if (calcDelta(n, i) > 0)
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
	calcDelta(n, 0);
	while (r - l > 1)
	{
		int m = (l + r) / 2;
		if (calcDelta(n, m) > 0)
		{
			r = m;
		}
		else
		{
			l = m;
		}
	}
	if (r == (int)1e9 + 8) r = -1;
	printf("%d\n", r);
}