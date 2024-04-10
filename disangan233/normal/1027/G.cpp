#pragma GCC optimize(2,3,"Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
#define ull unsigned ll
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0,ny;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in ll read()
	{
		ll x=0;ny=1;while(nc=gc(),(nc<48||nc>57)&&nc!=EOF)if(nc==45)ny=-1;Bi=1;if(nc<0)return nc;
		x=nc-48;while(nc=gc(),47<nc&&nc<58&&nc!=EOF)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*ny;
	}
	in db gf() {int a=read(),y=ny,b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi)*y:a);}
	in int gs(char *s) {char c,*t=s;while(c=gc(),c<32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
	in void ot() {fwrite(sr,1,C+1,stdout);C=-1;}
	in void flush() {if(C>1<<22) ot();}
	template <typename T>
	in void write(T x,char t)
	{
		int y=0;if(x<0)y=1,x=-x;while(z[++Z]=x%10+48,x/=10);
		if(y)z[++Z]='-';while(sr[++C]=z[Z],--Z);sr[++C]=t;flush();
	}
	in void write(char *s) {int l=strlen(s);for(int i=0;i<l;i++)sr[++C]=*s++;sr[++C]='\n';flush();}
};
using namespace fast_io;
const int N=5e4+5;
ll n,m,x,tot,tp,a[N],b[N],p[N],f[N],l[N];mt19937 rnd(time(0));
unordered_map<ll,int>mp;
#define mytz __builtin_ctzll
in ll gcd(ll a,ll b)
{
	if(!a) return b; if(!b) return a;
	ll t=mytz(a|b);a>>=mytz(a);
	do{b>>=mytz(b);if(a>b)a^=b^=a^=b;b-=a;}while(b);
	return a<<t;
}
in ll rd(ll a,ll b) {return rnd()%(b-a+1)+a;}
in ll ml(ll a,ll b,ll p) {a%=p,b%=p;ll t=(a*b-(ll)((long double)a/p*b+1.0e-8)*p)%p;return t<0?t+p:t;}
in ll qpow(ll a,ll b,ll p) {a%=p;ll s=1;while(b) s=(b&1)?ml(s,a,p):s,b>>=1,a=ml(a,a,p);return s;}
in int mr(ll n)
{
	if(n==2) return 1;if(n<2||!(n&1)) return 0;
	ll m=n-1,k=0,cnt=10;while(!(m&1)) k++,m>>=1;
	for(int i=1;i<=cnt;i++)
	{   
		ll a=rd(1,n-1),x=qpow(a,m,n),y=0;
		for(int j=1;j<=k;j++) {y=ml(x,x,n);if(y==1&&x!=1&&x!=n-1) return 0;x=y;}
		if(y^1) return 0;
	}return 1;
}
in ll pr(ll n,ll c)
{
	ll x=rd(1,n-1),i=1,k=2,y=x,z=1,d;
	while(1)
	{
		i++;x=(ml(x,x,n)+c)%n;z=ml(z,abs(y-x),n);if(!z||x==y) return n;
		if(!(i%127)||i==k) {d=gcd(z,n);if(d>1)return d;if(i==k) y=x,k<<=1;}
	}
}
in void find(ll n,ll c)
{
	if(n==1) return; if(mr(n)) return b[++tot]=n,void();
	ll p=n;while(p>=n) p=pr(p,c--);find(p,c),find(n/p,c);
}
int main()
{
	m=read(),x=read();
	for(ll i=1;i*i<=m;i++) if(!(m%i)) {a[++n]=i;if(i*i!=m)a[++n]=m/i;}
	sort(a+1,a+n+1);for(int i=1;i<=n;i++) mp[a[i]]=i;ll t=m;
	for(ll i=2;i*i<=t;i++) if(!(t%i)) {p[++tp]=i;while(!(t%i))t/=i;}
	if(t>1) p[++tp]=t;
	for(int i=1;i<=n;i++) f[i]=m/a[i]-1;
	for(int j=1;j<=tp;j++) for(int i=1;i<=n;i++) if(!(a[i]%p[j])) f[mp[a[i]/p[j]]]-=f[i];
	for(int i=n;i;i--)
	{
		l[i]=a[i];
		for(int j=1;j<=tp;j++) if(!(l[i]%p[j])) l[i]=l[i]/p[j]*(p[j]-1);
		tot=0;find(l[i],1e7+7);sort(b+1,b+tot+1);tot=unique(b+1,b+tot+1)-b-1;
		for(int j=1;j<=tot;j++) while(!(l[i]%b[j])&&qpow(x,l[i]/b[j],a[i])==1) l[i]/=b[j];
	}
	ll ans=1;
	for(int i=1,j=1;i<n;i++) {j=1;while(a[j]!=m/a[i]) j++;ans+=f[i]/l[j];}
	write(ans,'\n');
	return ot(),0;
}
//Author: disangan233