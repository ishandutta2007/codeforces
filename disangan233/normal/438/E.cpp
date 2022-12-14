#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register int
#define ak *
#define in inline
in char getch()
{
    static char buf[1<<12],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<!2,stdin),p1==p2)?EOF:*p1++;
}
char qwq;
#define gc() getch()
in ll read(ll p=0)
{
    ll cz=0,ioi=1;qwq=gc();
    while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
    while(qwq>='0'&&qwq<='9') 
    {
        cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
        if(p) cz%=p;
    }
    return cz ak ioi;
}
#define init(x,n) static ll x[N];memset(x,0,sizeof(x));
const int N=5e5+5,p=998244353,G=3;
int n,m,len,L,rev[N],ny[N];
ll a[N],b[N],omg[N],_omg[N];
in ll qpow(ll x,ll y,ll p) {ll z=1;for(;y;y>>=1,x=x*x%p) if(y&1) z=x*z%p;return z;}
in void read(ll *a,re n) {for(re i=0;i<n;i++) a[i]=read();}
in void print(ll *a,re n) {for(re i=1;i<n;i++) printf("%lld\n",a[i]);puts("");}
in void calrev(re len,re L) 
{
	for(re i=1;i<=len;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(L-1));
	omg[0]=1;omg[1]=qpow(G,(p-1)/len,p);
	for(re i=2;i<=len;i++) omg[i]=(1ll*omg[1]*omg[i-1])%p;
	for(re i=0;i<len;i++) _omg[i]=omg[len-i];
}
in void ntt(ll *a,re n,re op)
{
	for(re i=0;i<n;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
	ll *w=(op==1)?omg:_omg;
	for(re i=1;i<n;i<<=1)
	for(re j=0;j<n;j+=(i<<1))
	for(re k=0;k<i;k++)
	{
		ll x=a[j+k],y=w[n/(i<<1)*k]*a[j+k+i]%p;
		a[j+k]=(x+y)%p;a[j+k+i]=(x-y+p)%p;
	}
	if(op==1) return;
	re inv=qpow(n,p-2,p);
	for(re i=0;i<n;i++) a[i]=a[i]*inv%p;
}
in void inter(ll *a,re n) {for(re i=n-1;i;i--) a[i]=a[i-1]*qpow(i,p-2,p)%p;a[0]=0;}
in void direv(ll *a,re n) {for(re i=1;i<n;i++) a[i-1]=a[i]*i%p;a[n-1]=0;}
in void mul(ll *a,ll *b)
{
    ntt(a,len,1);ntt(b,len,1);
    for(re i=0;i<len;i++) a[i]=a[i]*b[i]%p;
    ntt(a,len,-1);
}
void inv(ll *a,ll *b,re n)
{
    if(n==1) return b[0]=qpow(a[0],p-2,p),void();
    inv(a,b,(n+1)>>1);L=ceil(log2(2*n));len=1<<L;
    calrev(len,L);init(c,len);
    memcpy(c,a,sizeof(ll)*n);ntt(b,len,1);ntt(c,len,1);
    for(re i=0;i<len;i++) b[i]=(2-b[i]*c[i]%p+p)%p*b[i]%p;
    ntt(b,len,-1);memset(b+n,0,sizeof(ll)*(len));
}
in void inv(ll *a,re n) {init(b,n<<1);inv(a,b,n);memcpy(a,b,sizeof(ll)*n);}
in void ln(ll *a,re n)
{
    init(b,n<<1);memcpy(b,a,sizeof(ll)*n);
    direv(b,n);inv(a,n);
    L=ceil(log2(2*n));len=1<<L;calrev(len,L);
    mul(a,b);inter(a,n);memset(a+n,0,sizeof(ll)*len/2);
}
void exp(ll *a,ll *b,re n)
{
    if(n==1) return b[0]=1,void();
    exp(a,b,(n+1)>>1);init(c,n<<1);
    memcpy(c,b,sizeof(ll)*n);ln(c,n);
    L=ceil(log2(2*n));len=1<<L;calrev(len,L);
    for(re i=0;i<n;i++) c[i]=((a[i]-c[i]+(i==0))%p+p)%p;
    mul(b,c);memset(b+n,0,sizeof(ll)*(len>>1));
}
in void exp(ll *a,re n) {init(b,n<<1);exp(a,b,n);memcpy(a,b,sizeof(ll)*n);}
in void div(ll *a,ll *b,re n,re m)
{
	init(c,n<<1);memcpy(c,a,sizeof(ll)*n);
	init(d,n<<1);memcpy(d,b,sizeof(ll)*m);
    reverse(c,c+n);reverse(b,b+m);inv(b,n-m+1);
	L=ceil(log2(4*n));len=1<<L;calrev(len,L);
    mul(c,b);reverse(c,c+n-m+1);memset(c+(n-m+1),0,sizeof(ll)*(m-1));
    mul(d,c);for(re i=0;i<m;i++) b[i]=((a[i]-d[i])%p+p)%p;
    memcpy(a,c,sizeof(ll)*n);
}
in void sqrt(ll *a,ll *b,re n) 
{
	init(c,n<<1);init(d,n<<1);
    if(n==1) return b[0]=1,void();
	sqrt(a,b,(n+1)>>1);
    memcpy(c,b,sizeof(ll)*n);memcpy(d,a,sizeof(ll)*n);inv(c,n);
    L=ceil(log2(n*2));len=1<<L;calrev(len,L);
    ntt(b,len,1);ntt(c,len,1);ntt(d,len,1);
    for(re i=0;i<len;i++) b[i]=(b[i]+c[i]*d[i]%p)%p*qpow(2,p-2,p)%p;
    ntt(b,len,-1);memset(b+n,0,sizeof(ll)*(len>>1));
}
in void sqrt(ll *a,re n) {init(b,n<<1);sqrt(a,b,n);memcpy(a,b,sizeof(ll)*n);}
in void qpow(ll *a,re n,re k) {ln(a,n);for(re i=0;i<n;i++) a[i]=a[i]*k%p;exp(a,n);}
int main()
{
	n=read();m=read()+1; 
	for(re i=1;i<=n;i++) a[b[i]=read()]++;
	for(re i=0;i<m;i++) a[i]=p+(i==0)-a[i]*4%p;
	sqrt(a,m);a[0]++;inv(a,m);
	for(re i=0;i<m;i++) a[i]=a[i]*2%p;print(a,m);
}