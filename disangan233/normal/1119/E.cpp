#include<bits/stdc++.h>
using namespace std;
#define re register int
#define un unsigned
#define ll un long long
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
ll n,ans,sum;
struct did{
	int x;
	bool operator < (did a) const {return x<a.x;}
}q[100005];
int main()
{
	n=read();
	for(re i=1;i<=n;i++)
	{
		ll a=read(),x=min(sum,a/2);
		ans+=x,sum-=x,a-=x*2;
		ans+=a/3,a%=3,sum+=a;
	}
	cout<<ans<<endl;
	return 0;
}