#include <cstdio>
#include <bitset>
#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>
#define pb push_back
using std::vector;
using std::bitset;
using std::queue;
const int N=105;
int T, n, fa[N], vis[N][N];
inline int findfa(int x) { return x==fa[x]?x:fa[x]=findfa(fa[x]); }
char s[N];
bitset<N> ok[N][N], res[N];
vector<int> e[N];
int x[N], y[N], tp;
void dfs(int a, int b)
{
	if(vis[a][b]) return;
	vis[b][a]=vis[a][b]=1;
	if(tp<n) x[++tp]=a, y[tp]=b;
	res[a].reset(b), res[b].reset(a);
	for(int t:{0, 1})
	{
		while(1)
		{
			int t=(res[b]&ok[a][b])._Find_first();
			// fprintf(stderr, "%d %d %d\n", a, b, t);
			if(t>n) break;
			if(vis[b][t]) exit(514);
			dfs(b, t);
		}
		std::swap(a, b);
	}
}
bool bfs(int s)
{
	queue<int> q, q1;
	static int dis[N];
	static bitset<N> rs[N];
	for(int i=1; i<=n; ++i) rs[i].reset();
	std::fill(dis+1, dis+n+1, 0);
	dis[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int v:e[u]) if(!dis[v])
		{
			dis[v]=dis[u]+1;
			q.push(v);
		}
	}
	for(int i=1; i<=n; ++i) if(!dis[i]) return 0;
	for(int i=1; i<=n; ++i) rs[dis[i]].set(i);
	for(int i=1; i<=n; ++i) if(rs[dis[i]]!=ok[i][s]) return 0;
	return 1;
}
bool chk(void)
{
	for(int i=1; i<=n; ++i) if(!bfs(i)) return 0;
	return 1;
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) ok[i][j].reset(), ok[i][j].set(i), vis[i][j]=0;
		for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j)
		{
			scanf("%s", s+1);
			for(int k=1; k<=n; ++k) if(s[k]=='1') ok[i][k].set(j), ok[j][k].set(i);
		}
		for(int i=1; i<=n; ++i) res[i].set(), res[i].reset(i);
		for(int a=1; a<=n; ++a) for(int b=a+1; b<=n; ++b) if(!vis[a][b])
		{
			// fprintf(stderr, "%d %d\n", a, b);
			tp=0;
			dfs(a, b);
			if(tp!=n-1) continue;
			for(int i=1; i<=n; ++i) e[i].clear();
			for(int i=1; i<n; ++i) e[x[i]].pb(y[i]), e[y[i]].pb(x[i]);
			if(chk())
			{
				puts("Yes");
				for(int i=1; i<n; ++i) printf("%d %d\n", x[i], y[i]);
				goto out;
			}
		}
		puts("No");
		out:;
	}
	return 0;
}