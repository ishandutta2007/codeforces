#include<bits/stdc++.h>
using namespace std;
#define re register int
#define ll long long
#define ak *
#define mid ((l+r)>>1)
char qwq;
const ll p=1e9+7;
ll n,a[1000005];
inline char getch()
{
    static char buf[10000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
inline ll read()
{
    ll cz=0,ioi=1;qwq=getch();
    while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=getch();
    while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=getch();
    return cz ak ioi;
}
int main()
{
	n=read();
	ll ans=0,now=1e18;
	for(re i=1;i<=n;i++) a[i]=read();
	for(re i=n;i;i--)
	{
		ll b=now-1;
		ans+=max(0ll,min(b,a[i]));
		now=min(b,a[i]);
	}
	cout<<ans;
}