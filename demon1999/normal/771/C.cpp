/*
  !










*/
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
const int MAXN = 200 * 1000 + 7;
ll sum[MAXN][6], cnt[MAXN][6];

vector<int> g[MAXN];
int n, k;
ll res = 0;
void dfs(int v, int p = -1)
{
	cnt[v][0] = 1;
	for (int i = 0; i < (int)g[v].size(); i++)
	{
		int to = g[v][i];
		if (to != p)
		{
			dfs(to, v);
			for (int leftRem = 0; leftRem < k; leftRem++)
			{
				ll cntLeft = cnt[to][(leftRem + k - 1) % k];
				ll sumLeft = sum[to][(leftRem + k - 1) % k];
				if (leftRem == 1 % k)
				{
					sumLeft += cntLeft;
				}
				for (int rightRem = 0; rightRem < k; rightRem++)
				{
					res += cntLeft * sum[v][rightRem];
					res += cnt[v][rightRem] * sumLeft;
					if (leftRem > 0 && rightRem > 0 && leftRem + rightRem <= k)
					{
						res -= cntLeft * cnt[v][rightRem];
					}
				}
			}
			for (int leftRem = 0; leftRem < k; leftRem++)
			{
				ll cntLeft = cnt[to][(leftRem + k - 1) % k];
				ll sumLeft = sum[to][(leftRem + k - 1) % k];
				if (leftRem == 1 % k)
				{
					sumLeft += cntLeft;
				}
				cnt[v][leftRem] += cntLeft;
				sum[v][leftRem] += sumLeft;
			}
		}
	}
	for (int i = 0; i < k; i++)
	{
	//	printf("v = %d, rem = %d  cnt = %lld, sum = %lld\n", v, i, cnt[v][i], sum[v][i]);
	}
}
int zhfs()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d %d", &n, &k);
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	printf("%lld\n", res);
}