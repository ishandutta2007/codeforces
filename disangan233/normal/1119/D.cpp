#include<bits/stdc++.h>
using namespace std;
#define re register int
#define un unsigned
#define ll un long long
#define int ll
#define ak *
char qwq;
inline ll read()
{
	ll cz=0,ioi=1;qwq=getchar();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=getchar();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=getchar();
	return cz ak ioi;
}
inline ll qpow(ll x,ll y,ll p,ll z=1)
{
 	for(;y;y>>=1,x=(x*x)%p) z=(y&1)?(x*z)%p:z;
	return z;
}
ll n,m,s[100005],ans[100005],mn[100005],mx[100005],fa[100005];
struct did{
	ll x,y;
	bool operator <(did a) const {return x<a.x;}
}p[100005],q[100005];
ll getfa(re x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
signed main()
{
	n=read();
	for(re i=1;i<=n;i++) s[i]=read();
	sort(s+1,s+n+1);
	for(re i=1;i<n;i++) p[i]=(did){s[i+1]-s[i],(ll)i};
	sort(p+1,p+n);m=read();
	for(re i=1;i<=m;i++)
	{
		ll a=read(),b=read();
		q[i]=(did){b-a,(ll)i};
	}
	sort(q+1,q+m+1);re sum=n,cur=1,cnt=n;
	for(re i=1;i<=n;i++) mn[i]=mx[i]=fa[i]=i;
	for(re i=1;i<=m;i++)
	{
		while(cur<n&&p[cur].x<=q[i].x)
		{
			re l=p[cur].y,u=getfa(l),v=getfa(l+1);
			sum+=s[mn[v]];sum-=s[mx[u]];sum--;
			fa[u]=v,mn[v]=mn[u];
			cnt--;cur++;
		}
		ans[q[i].y]=sum+cnt*q[i].x;
	}
	for(re i=1;i<=m;i++) printf("%llu ",ans[i]);
	return 0;
}