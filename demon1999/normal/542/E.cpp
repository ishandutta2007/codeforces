/*













 
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
const int MAXN = 1007;
int color[MAXN];
int compId[MAXN];
vector<int> g[MAXN];
int res[MAXN];
bool BAD = false;
void dfs(int v, int c, int cc)
{
	color[v] = c;
	compId[v] = cc;
	for (int i = 0; i < (int)g[v].size(); i++)
	{
		int to = g[v][i];
		int goc = 3 - c;
		if (color[to] == c)
		{
			BAD = true;
		}
		else if (color[to] == 0)
		{
			dfs(to, goc, cc);
		}
	}
}
int was[MAXN];
int zhfs()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int nxtId = 0;
	for (int i = 1; i <= n; i++)
	{
		if (color[i] == 0)
		{
			nxtId++;
			dfs(i, 1, nxtId);
		}
	}
	if (BAD)
	{
		printf("-1\n");
		re 0;
	}
	for (int i = 1; i <= n; i++)
	{
		memset(was, 0, sizeof(was));
		int cur = 0;
		was[i] = 1;
		queue<int> q;
		q.push(i);
		while (!q.empty())
		{
			int v = q.front();
			q.pop();
			if (was[v] == -1) continue;
			cur = max(cur, was[v]);
			int curw = was[v];
			was[v] = -1;
			for (int i = 0; i < (int)g[v].size(); i++)
			{
				int to = g[v][i];
				if (was[to] == 0 || was[to] == curw + 1)
				{
					was[to] = curw + 1;
					q.push(to);
				}
			}
		}
		cur--;
		res[compId[i]] = max(res[compId[i]], cur);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += res[i];
	}
	printf("%d\n", ans);
}