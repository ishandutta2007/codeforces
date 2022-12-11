#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 200000
#define N 262144
#define mp(x,y) make_pair(x,y)
struct edge{int nx,t;}e[MN+5];
int h[MN+5],en,s[MN+5],mx[MN+5],d[MN+5],fa[MN+5],f[MN+5],l[MN+5],p[MN+5],cnt,t[N*2+5],F[MN+5];
vector<pair<pair<int,int>,int> > v[MN+5];
inline void ins(int x,int y){e[++en]=(edge){h[x],y};h[x]=en;}
void add(int k,int x){for(k+=N;k;k>>=1)t[k]+=x;}
int query(int l,int r)
{
	int res=0;
	if(l<=r)for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1)res+=t[l+1];
		if( r&1)res+=t[r-1];
	}
	return res;
}
void dfs(int x)
{
	s[x]=1;
	for(int i=h[x];i;i=e[i].nx)
	{
		fa[e[i].t]=x;d[e[i].t]=d[x]+1;
		dfs(e[i].t);
		s[x]+=s[e[i].t];
		if(s[e[i].t]>s[mx[x]])mx[x]=e[i].t;
	}
}
void build(int x)
{
	p[l[x]=++cnt]=x;
	if(mx[x])f[mx[x]]=f[x],build(mx[x]);
	for(int i=h[x];i;i=e[i].nx)if(e[i].t!=mx[x])build(f[e[i].t]=e[i].t);
}
int lca(int x,int y)
{
	while(f[x]!=f[y])if(d[f[x]]>d[f[y]])x=fa[f[x]];else y=fa[f[y]];
	return d[x]<d[y]?x:y;
}
int up(int x,int y)
{
	for(;f[x]!=f[y];x=fa[f[x]])
		if(fa[f[x]]==y)return f[x];
	return p[l[y]+1]; 
}
int Q(int x,int y)
{
	int res=0;
	for(;f[x]!=f[y];x=fa[f[x]])
		res+=query(l[f[x]],l[x])+F[mx[x]]-F[f[x]];
	return res+query(l[y],l[x])+F[mx[x]];
}
void dp(int x)
{
	for(int i=h[x];i;i=e[i].nx)dp(e[i].t),F[x]+=F[e[i].t];
	add(l[x],F[x]-F[mx[x]]);
	for(int i=0;i<v[x].size();++i)
	{
		int y=up(v[x][i].first.first,x);
		F[x]=max(F[x],Q(v[x][i].first.first,y)+Q(v[x][i].first.second,x)-F[y]+v[x][i].second);
	}
}
int main()
{
	int n,m,i,x,y;
	n=read();m=read();
	for(i=2;i<=n;++i)ins(read(),i);
	dfs(1);build(f[1]=1);
	while(m--)
	{
		i=lca(x=read(),y=read());
		if(x==i)swap(x,y);
		v[i].push_back(mp(mp(x,y),read()));
	}
	dp(1);
	printf("%d",F[1]);
}