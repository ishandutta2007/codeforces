#include<cstdio>
#include<vector>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
#define K 17
#define ND 2000000
struct edge{int nx,t;}e[MN*2+5];
struct node{int l,r,s;}t[ND+5];
int m,h[MN+5],en,rt[MN+5],tn,fa[K][MN+5],d[MN+5],a;
vector<int> v[MN+5],ans;
inline void ins(int x,int y)
{
	e[++en]=(edge){h[x],y};h[x]=en;
	e[++en]=(edge){h[y],x};h[y]=en;
}
int add(int k,int l,int r,int x)
{
	int p=++tn,mid=l+r>>1;
	t[p]=t[k];++t[p].s;
	if(l<r)if(x<=mid)t[p].l=add(t[p].l,l,mid,x);
				else t[p].r=add(t[p].r,mid+1,r,x);
	return p;
}
void dfs(int x)
{
	for(int i=0;i<v[x].size();++i)rt[x]=add(rt[x],1,m,v[x][i]);
	for(int i=h[x];i;i=e[i].nx)if(e[i].t!=fa[0][x])
		d[e[i].t]=d[x]+1,rt[e[i].t]=rt[fa[0][e[i].t]=x],dfs(e[i].t);
}
int lca(int x,int y)
{
	int i,p=d[x]-d[y];
	if(p<0)p=-p,x^=y^=x^=y;
	for(i=0;p;p>>=1,++i)if(p&1)x=fa[i][x];
	if(x==y)return x;
	for(i=K;i--;)if(fa[i][x]!=fa[i][y])x=fa[i][x],y=fa[i][y];
	return fa[0][x];
}
void solve(int l,int r,int k1,int k2,int k3,int k4)
{
	if(!(t[k1].s+t[k2].s-t[k3].s-t[k4].s)||!a)return;
	if(l==r){ans.push_back(l);--a;return;}
	int mid=l+r>>1;
	solve(l,mid,t[k1].l,t[k2].l,t[k3].l,t[k4].l);
	solve(mid+1,r,t[k1].r,t[k2].r,t[k3].r,t[k4].r);
}
int main()
{
	int n,q,i,j,l;
	n=read();m=read();q=read();
	for(i=1;i<n;++i)ins(read(),read());
	for(i=1;i<=m;++i)v[read()].push_back(i);
	dfs(1);
	for(i=1;i<K;++i)for(j=1;j<=n;++j)fa[i][j]=fa[i-1][fa[i-1][j]];
	while(q--)
	{
		i=read();j=read();a=read();l=lca(i,j);ans.clear();
		solve(1,m,rt[i],rt[j],rt[l],rt[fa[0][l]]);
		printf("%d ",ans.size());
		for(i=0;i<ans.size();++i)printf("%d ",ans[i]);puts("");
	}
}