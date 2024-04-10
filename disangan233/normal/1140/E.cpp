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
inline ll read()
{
    ll cz=0,ioi=1;qwq=getch();
    while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=getch();
    while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=getch();
    return cz ak ioi;
}
const int mod=998244353;
ll n,k,a[200005],b[200005],m,ans,p[200005],q[200005],s,lans;
inline ll qpow(ll a,ll b,ll c=1)
{
	for(;b;b>>=1,a=(a*a)%mod) c=(b&1)?c*a%mod:c;
	return c;
}
inline void solve()
{
	ll i,s=1ll,l,r;
	for(i=1;i<=b[0];i++)
	if(b[i]==-1) s*=(k-1),s%=mod;
	else break;
	if(i==b[0]+1) return ans=k*qpow(k-1,b[0]-1)%mod,void();
	l=i;
	for(i=b[0];i;i--)
	if(b[i]==-1) s*=(k-1),s%=mod;
	else break; r=i;
	for(i=l;i<r;)
	{
		re j;
		for(j=i+1;b[j]==-1;j++);
		if(b[i]==b[j]) s=s*p[j-i-1]%mod;
		else s=s*q[j-i-1]%mod;
		i=j;
	}
	ans=s;
}
int main()
{
	n=read(),k=read();
	for(re i=1;i<=n;i++) a[i]=read();
	for(re i=3;i<=n;i++)
	if(a[i]!=-1&&a[i]==a[i-2]) return puts("0"),0;
	q[0]=1,q[1]=k-2;
	for(re i=1;i<=n;i++) p[i]=(qpow(k-1,i)-p[i-1])%mod;
	for(re i=2;i<=n;i++) q[i]=(qpow(k-1,i)-q[i-1])%mod;
	for(re i=1;i<=n;i+=2) b[++b[0]]=a[i];
	solve();lans=ans;b[0]=0;
	for(re i=2;i<=n;i+=2) b[++b[0]]=a[i];
	solve();cout<<(lans*ans%mod+mod)%mod;
}