#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 500000
#define K 19
struct edge{int nx,t;}e[MN+5];
int fa[K][MN+5],d[MN+5],h[MN+5],en,f[MN+5],z[MN+5],zn;
ll ans[MN+5],s;
vector<int> v[MN+5],vv[MN+5];
inline void ins(int x,int y){e[++en]=(edge){h[x],y};h[x]=en;}
void dfs(int x)
{
	v[d[x]].push_back(x);
	for(int i=h[x];i;i=e[i].nx)
		d[e[i].t]=d[x]+1,dfs(e[i].t);
}
int lca(int x,int y)
{
	if(d[x]<d[y])swap(x,y);
	int i,j=d[x]-d[y];
	for(i=0;j;++i,j>>=1)if(j&1)x=fa[i][x];
	if(x==y)return x;
	for(i=K;i--;)if(fa[i][x]!=fa[i][y])x=fa[i][x],y=fa[i][y];
	return fa[0][x];
}
void dpl(int x)
{
	if(f[x]=vv[x].empty())ans[x]+=s,s+=d[x];
	for(int i=0;i<vv[x].size();++i)
		dpl(vv[x][i]),s-=(d[vv[x][i]]-d[x])*f[vv[x][i]],f[x]+=f[vv[x][i]];
}
void dpr(int x)
{
	if(vv[x].empty())ans[x]+=s,s+=d[x];
	for(int i=vv[x].size();i--;)
		dpr(vv[x][i]),s-=(d[vv[x][i]]-d[x])*f[vv[x][i]];
	vv[x].clear();
}
int main()
{
	int n=read(),i,j,k,l;
	for(i=1;i<=n;++i)ins(fa[0][i]=read(),i);
	for(i=1;i<K;++i)for(j=1;j<=n;++j)fa[i][j]=fa[i-1][fa[i-1][j]];
	for(i=1;i<=n;++i)if(!fa[0][i])d[i]=1,dfs(i);
	for(i=1;v[i].size();++i)
	{
		z[zn=1]=v[i][0];
		for(j=1;j<v[i].size();++j)
		{
			l=lca(v[i][j],z[zn]);
			while(zn>1&&d[z[zn-1]]>=d[l])vv[z[zn-1]].push_back(z[zn]),--zn;
			if(z[zn]!=l)vv[l].push_back(z[zn]);z[zn]=l;z[++zn]=v[i][j];
		}
		while(zn>1)vv[z[zn-1]].push_back(z[zn]),--zn;
		s=0;dpl(z[1]);s=0;dpr(z[1]);
		for(j=0;j<v[i].size();++j)ans[v[i][j]]+=ans[fa[0][v[i][j]]]+d[v[i][j]]-1;
	}
	for(i=1;i<=n;++i)printf("%I64d ",ans[i]);
}