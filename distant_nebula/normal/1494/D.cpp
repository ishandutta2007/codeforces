#include <cstdio>
#include <vector>
#include <algorithm>
#define x first
#define y second
#define mp std::make_pair
#define N 2005
using std::pair;
int n, a[N][N], val[N], fa[N], pa[N], top, tp;
pair<int, pair<int, int> > pr[N*N];
int findfa(int x) { return fa[x]==x?x:fa[x]=findfa(fa[x]); }
int main()
{
	scanf("%d", &n);
	top=n;
	for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j)
	{
		scanf("%d", a[i]+j);
		if(i!=j) pr[++tp]=mp(a[i][j], mp(i, j));
		else val[i]=a[i][j];
	}
	for(int i=1; i<=n; ++i) fa[i]=i;
	std::sort(pr+1, pr+tp+1);
	for(int i=1; i<=tp; ++i)
	{
		int v=pr[i].x, x=pr[i].y.x, y=pr[i].y.y;
		x=findfa(x), y=findfa(y);
		if(x==y) continue;
		if(val[x]==v) { pa[y]=x, fa[y]=x; continue; }
		if(val[y]==v) { pa[x]=y, fa[x]=y; continue; }
		pa[x]=pa[y]=++top;
		fa[x]=fa[y]=fa[top]=top;
		val[top]=v;
	}
	printf("%d\n", top);
	for(int i=1; i<=top; ++i) printf("%d ", val[i]);
	puts("");
	int id=0;
	for(int i=1; i<=top; ++i) if(!pa[i]) id=i;
	printf("%d\n", id);
	for(int i=1; i<=top; ++i) if(pa[i]) printf("%d %d\n", i, pa[i]);
	return 0;
}