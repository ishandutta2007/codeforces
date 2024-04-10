#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;typedef long double ld;const ll N=(1<<18)+7,w=1e9,m1=1e9+7,k=11451411;typedef ll aN[N*2];
inline ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
#define op(r)pt operator r(const pt&a,const pt&b){return(pt){a.x r b.x,a.y r b.y};}
struct fs{
	ll a,b;fs(double s){ll t=s*w,j;rep(i,1,2000)if(labs((j=(i*t+w/2)/w)*w/i-t)<=3){a=j,b=i;break;}}
	fs(ll x=0,ll y=0):a(x),b(y){ll g=gcd(a,b);if(b*g<0)g=-g;if(g)a/=g,b/=g;}fs operator*(ld k)const{return fs(a*k,b);}
	fs operator-(const fs&y)const{return fs(a*y.b-b*y.a,b*y.b);}
	fs operator+(const fs&y)const{return fs(a*y.b+b*y.a,b*y.b);}ll hash()const{return((a<0?a+m1:a)*k+b)%m1;}
};struct pt{fs x,y;void print()const{printf("(%lld/%lld,%lld/%lld)",x.a,x.b,y.a,y.b);} 
void read(){double a,b;scanf("%lf %lf",&a,&b),x=fs(a),y=fs(b);}
ll hash(ll h){return(x.hash()*k+h)%m1*m1+y.hash();}};op(+)op(-);
pt operator*(const pt&a,ll b){return(pt){a.x*b,a.y*b};}
struct hash{
	#define gs ll now=b%mod,x=0;while(key[now]&&key[now]!=b)now=(now+2*x+++1)%mod
	static const ll mod=19260817;ll val[mod],key[mod];ll operator[](ll b)const{gs;return key[now]?val[now]:0;}
	int count(ll b){gs;return!!key[now];}ll&operator[](ll b){gs;return!key[now]?key[now]=b,val[now]=0:val[now];}
}hs;inline ll calc(ll u){return u*u;}aN h,x,y,s;
void getans(ll a,ll b,ll n){//printf("%lld %lld\n",a,b);
	static char s[114];rep(i,1,n)s[n-i+1]=a&1?')':'(',a>>=1;rep(i,1,n)s[n+i]=b&1?'(':')',b>>=1;puts(s+1);
}int main(){
	ll n=readll()/2,h1=0,h2=0;pt zx;zx.read();//printf("%.10lf %.10lf\n",(double)zx.x.a/zx.x.b,(double)zx.y.a/zx.y.b); 
	rep(j,1,n)per(i,(1<<j)-1,0)if(~(h2=h[i]=~(h1=h[i>>1])?h1-(i<<1&2)+1:-1))
	s[i]=s[i>>1]+h1+h2,x[i]=x[i>>1]+h1*(j*3-2)+h2*(j*3-1),y[i]=y[i>>1]+calc((h1+h2)/2)*3+(h1+h2)/2*3+1;
	ref(i,0,(1<<n))if(h[i]>=0){pt now=zx+((pt){fs(x[i],3),fs(y[i],3)}-zx*s[i]);
//	if(i==5979)now.print(),printf("%lld %lld\n",h[i],now.hash(h[i]));
	hs[now.hash(h[i])]=i;}zx.x=fs(n*2,1)-zx.x;
	ref(i,0,(1<<n))if(h[i]>=0){pt now=zx-((pt){fs(x[i],3),fs(y[i],3)}-zx*s[i]);now.x=fs(n*2,1)-now.x;
//	if(i==11731)now.print(),printf("%lld %lld\n",h[i],now.hash(h[i]));
	if(hs.count(now.hash(h[i])))return getans(hs[now.hash(h[i])],i,n),0;}return 0;
}
//6 3.4 0.6
//14 7.2926829268 1.9105691057