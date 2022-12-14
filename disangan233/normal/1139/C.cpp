#include<bits/stdc++.h>
using namespace std;
#define re register int
#define ll long long
#define ak *
#define mid ((l+r)>>1)
char qwq;
inline char getch()
{
    static char buf[10000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
inline int read()
{
    re cz=0,ioi=1;qwq=getch();
    while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=getch();
    while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=getch();
    return cz ak ioi;
}
const ll p=1e9+7;
int n,k,cnt,h[100005],vis[100005],tot;
ll ans,point,c[100005][105],fac[100005];
struct did{int next,to;}e[200005];
inline void add(re x,re y)
{
	e[++cnt]=(did){h[x],y};h[x]=cnt;
	e[++cnt]=(did){h[y],x};h[y]=cnt;
}
void dfs(re u)
{
	vis[u]=1;tot++;
	for(re i=h[u],v;v=e[i].to,i;i=e[i].next)
	if(!vis[v]) dfs(v);
}
inline ll qpow(ll x,ll y,ll z=1)
{
	x%=p;
	for(;y;y>>=1,x=(x*x)%p) z=(y&1)?(z*x)%p:z;
	return z;
}
int main()
{
	n=read();k=read();
	for(re i=0;i<=n;i++) c[i][0]=1;
	for(re i=1;i<=n;i++)
	for(re j=1;j<=k;j++)
	c[i][j]=(c[i-1][j-1]+c[i][j-1])%p;
	fac[0]=1;
	ans=qpow(n,k);
	for(re i=1;i<=n;i++) fac[i]=(fac[i-1]*i)%p;
	for(re i=1;i<n;i++)
	{
		re a=read(),b=read(),c=read();
		if(!c) add(a,b);
	}
	for(re i=1;i<=n;i++)
	if(!vis[i])
	{
		tot=0;dfs(i);
		ans-=qpow(tot,k);
		ans=(ans%p+p)%p;
	}
	cout<<ans<<endl;
}