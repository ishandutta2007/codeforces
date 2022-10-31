#include <cstdio>
#include <numeric>
#include <vector>
#include <algorithm>
#define INF 0x3f3f3f3f
#define pb push_back
using std::vector;
const int N=400005;
int T, n, m;
int x[N], y[N], dep[N], rp[N], col[N];
vector<int> e[N], rs;
void dfs(int u, int fa, int rfa)
{
	dep[u]=dep[rfa]+1;
	// printf("in %d %d\n", u, dep[u]);
	for(int i:e[u]) if(i!=fa)
	{
		int v=u^x[i]^y[i];
		if(dep[v])
		{
			if(dep[v]<dep[u])
			{
				rp[i]=fa;
				// printf("now %d\n", i);
				rs.pb(i);
			}
		}
		else dfs(v, i, u);
	}
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; ++i) e[i].clear(), dep[i]=0;
		for(int i=1; i<=m; ++i)
		{
			scanf("%d%d", x+i, y+i), col[i]=0;
			e[x[i]].pb(i), e[y[i]].pb(i);
		}
		rs.clear();
		dfs(1, 0, 0);
		if(rs.size()==3)
		{
			for(int a:rs)
			{
				int ok0=0, ok1=0;
				for(int b:rs) if(a!=b)
				{
					if(x[a]==x[b]||x[a]==y[b]) ok0=1;
					if(y[a]==x[b]||y[a]==y[b]) ok1=1;
				}
				if(!ok0||!ok1) goto out;
			}
			rs[2]=rp[rs[2]];
			out:;
		}
		for(int x:rs) col[x]=1;
		for(int i=1; i<=m; ++i) putchar('0'+col[i]);
		puts("");
	}
	return 0;
}