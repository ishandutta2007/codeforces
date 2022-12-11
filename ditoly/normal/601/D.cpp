#include<cstdio>
#include<set>
using namespace std;
#define ll unsigned long long
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 300000
#define MOD 998244353666233
struct edge{int nx,t;}e[MN*2+5];
char s[MN+5];
int c[MN+5],h[MN+5],en,mx,ms,z[MN+5];
ll hs[MN+5];
set<ll> st[MN+5];
inline void ins(int x,int y)
{
	e[++en]=(edge){h[x],y};h[x]=en;
	e[++en]=(edge){h[y],x};h[y]=en;
}
int merge(int x,int y)
{
	if(st[z[x]].size()>st[z[y]].size())swap(x,y);
	for(set<ll>::iterator i=st[z[x]].begin();i!=st[z[x]].end();++i)st[z[y]].insert(*i);
	return z[y];
}
void dfs(int x,int fa)
{
	st[z[x]=x].insert(hs[x]=(hs[fa]*233+s[x])%MOD);
	for(int i=h[x];i;i=e[i].nx)if(e[i].t!=fa)
		dfs(e[i].t,x),z[x]=merge(x,e[i].t);
	c[x]+=st[z[x]].size();
	if(c[x]>mx)mx=c[x],ms=0;if(c[x]==mx)++ms;
}
int main()
{
	int n=read(),i;
	for(i=1;i<=n;++i)c[i]=read();
	scanf("%s",s+1);
	for(i=1;i<n;++i)ins(read(),read());
	dfs(1,0);
	printf("%d\n%d",mx,ms);
}