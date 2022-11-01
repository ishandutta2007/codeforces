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
const int MAXN = 150 * 1000 + 7;
vector<int> g[MAXN];
int zhfs()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	set<pair<int, int> > have;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(g[i].begin(), g[i].end());
	}
	for (int i =1 ;i <= n; i++)
	{
		for (int j = 0; j < (int)g[i].size(); j++)
		{
			int u = g[i][j];
			int ptr = 0;
			for (int k = j + 1; k < (int)g[i].size(); k++)
			{
				int v = g[i][k];
				while (ptr < (int)g[u].size() && g[u][ptr] < v) ptr++;
				if (ptr == (int)g[u].size() || g[u][ptr] != v)
				{
					printf("NO\n");
					re 0;
				}
			}
		}
	}
	printf("YES\n");
	re 0;
}