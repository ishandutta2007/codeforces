#include<bits/stdc++.h>
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
#define MX 10000000
#define MOD 1000000007
struct edge{int nx,t;}e[MN*2+5];
int h[MN+5],en,a[MN+5],u[MX+5],p[MX+5],pn,fa[K][MN+5],d[MN+5],ans[MN+5],s[MX+5],xx[MN+5];
vector< pair<int,int> > v[MN+5];
inline void ins(int x,int y)
{
	e[++en]=(edge){h[x],y};h[x]=en;
	e[++en]=(edge){h[y],x};h[y]=en;
}
inline int inv(int x)
{
	int r=1,y=MOD-2;
	for(;y;y>>=1,x=1LL*x*x%MOD)if(y&1)r=1LL*r*x%MOD;
	return r;
}
void pre(int x)
{
	for(int i=h[x];i;i=e[i].nx)if(e[i].t!=fa[0][x])
		d[e[i].t]=d[x]+1,fa[0][e[i].t]=x,pre(e[i].t);
}
int lca(int x,int y)
{
	if(d[x]<d[y])swap(x,y);
	int i,k=d[x]-d[y];
	for(i=0;k;++i,k>>=1)if(k&1)x=fa[i][x];
	if(x==y)return x;
	for(i=K;i--;)if(fa[i][x]!=fa[i][y])x=fa[i][x],y=fa[i][y];
	return fa[0][x];
}
void dfs(int x)
{
	int i,j,k,t;
	for(i=a[x];i>1;)for(j=t=u[i];i%t==0;i/=t,j*=t)s[j]=1LL*s[j]*t%MOD;
	for(k=0;k<v[x].size();++k)
		for(i=xx[v[x][k].first];i>1;)for(j=t=u[i];i%t==0;i/=t,j*=t)
			ans[v[x][k].first]=1LL*ans[v[x][k].first]*(v[x][k].second?inv(s[j]):s[j])%MOD;
	for(i=h[x];i;i=e[i].nx)if(e[i].t!=fa[0][x])dfs(e[i].t);
	for(i=a[x];i>1;)for(j=t=u[i];i%t==0;i/=t,j*=t)s[j]=1LL*s[j]*inv(t)%MOD;
}
int main()
{
	int n=read(),q,i,j,x,y;
	for(i=1;i<n;++i)ins(read(),read());
	for(i=1;i<=n;++i)a[i]=read();
	for(i=2;i<=MX;++i)
	{
		if(!u[i])u[i]=p[++pn]=i;
		for(j=1;i*p[j]<=MX;++j)if(u[i*p[j]]=p[j],i%p[j]==0)break;
	}
	pre(1);
	for(i=1;i<K;++i)for(j=1;j<=n;++j)fa[i][j]=fa[i-1][fa[i-1][j]];
	for(q=read(),i=1;i<=q;++i)
	{
		ans[i]=1;
		j=lca(x=read(),y=read());xx[i]=read();
		v[x].push_back(make_pair(i,0));
		v[y].push_back(make_pair(i,0));
		v[j].push_back(make_pair(i,1));
		v[fa[0][j]].push_back(make_pair(i,1));
	}
	for(i=1;i<=MX;++i)s[i]=1;
	dfs(1);
	for(i=1;i<=q;++i)printf("%d\n",ans[i]);
}