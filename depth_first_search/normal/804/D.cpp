#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 100000
#define LL long long
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
int n,m,ee,lnk[N+5];struct edge {int to,nxt;}e[N<<1];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
int pos[N+5],sz[N+5];vector<int> v[N+5];vector<LL> s[N+5];
int f[N+5],g[N+5],p[N+5];I void dfs1(CI x,CI lst=0)
{
	for(RI i=lnk[x];i;i=e[i].nxt) e[i].to^lst&&(pos[e[i].to]=pos[x],
		dfs1(e[i].to,x),f[e[i].to]+1>f[x]?(g[x]=f[x],f[x]=f[p[x]=e[i].to]+1):g[x]=max(g[x],f[e[i].to]+1));
}
I void dfs2(CI x,CI lst=0,CI l=-1e9)
{
	l+1>f[x]?(g[x]=f[x],f[x]=l+1,p[x]=0):g[x]=max(g[x],l+1),v[pos[x]].push_back(f[x]);
	for(RI i=lnk[x];i;i=e[i].nxt) e[i].to^lst&&(dfs2(e[i].to,x,e[i].to^p[x]?f[x]:g[x]),0);
}
map<pair<int,int>,double> S;I double Q(RI x,RI y)
{
	if((sz[x]^sz[y]?sz[x]>sz[y]:x>y)&&(swap(x,y),0),S.count(make_pair(x,y))) return S[make_pair(x,y)];
	RI D=max(v[x].back(),v[y].back());LL t=0;for(RI i=0,o;i^sz[x];++i)
		o=lower_bound(v[y].begin(),v[y].end(),D-v[x][i]-1)-v[y].begin(),
		t+=1LL*o*D+1LL*(sz[y]-o)*(v[x][i]+1)+s[y].back()-(o?s[y][o-1]:0);
	return S[make_pair(x,y)]=1.0*t/sz[x]/sz[y];
}
int main()
{
	RI Qt,i,j,x,y;for(read(n,m,Qt),i=1;i<=m;++i) read(x,y),add(x,y),add(y,x);
	for(i=1;i<=n;++i) if(!pos[i]) for(pos[i]=i,dfs1(i),dfs2(i),
		sort(v[i].begin(),v[i].end()),sz[i]=v[i].size(),j=0;j^sz[i];++j) s[i].push_back((j?s[i].back():0)+v[i][j]);
	W(Qt--) read(x,y),pos[x]^pos[y]?printf("%.8lf\n",Q(pos[x],pos[y])):puts("-1");return 0;
}