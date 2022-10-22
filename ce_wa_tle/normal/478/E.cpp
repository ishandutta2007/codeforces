#include<bits/stdc++.h>
#include<complex.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(flush)
typedef long long ll;const ll N=2e6+7,mod=1e9+7;typedef ll aN[N];char is[1<<22],os[1<<22],*i1=is,*i2=is,*o1=os;
int fpc(int c){return*o1++=c;}int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}
void flush(){fwrite(os,o1-os,1,stdout);}int(*gc)()=getchar,(*pc)(int)=putchar;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}aN a;
const ll m=9260817;struct hs{ll v[m],k[m];ll operator[](ll b)const{ll n=g(b);return k[n]?v[n]:0;}
int count(ll b){return!!k[g(b)];}ll g(ll b)const{ll n=b%m;rfor(ll x=0;k[n]&&k[n]^b;n=(n+2*x+++1)%m);return n;}
ll&operator[](ll b){ll n=g(b);return!k[n]?k[n]=b,v[n]=0:v[n];}}h;const ll w=10,w6=1e6,w5=1e5,w7=1e7,w4=1e4;
ll getcnt(ll n,ll x){const ll s=(n-x*w7%n)%n*32,r=x%w,e=x/w?x/w%w>r:-1;ll res=0;
rep(t,0,19)if(r!=t/2&&(t&1)!=e&&(t/2<r)==(t&1))res+=h[s|t];return res;}
ll get(ll n,ll x,ll k,ll m,ll t){const ll s=(n-x*w7%n)%n,r=x%w,e=x/w?x/w%w>r:-1;ll b=0,f=0;rep(i,m,t)
if((f=a[i]/w6)!=r&&(f<a[i]/w5%w)==(a[i]/w4%w<a[i]/w5%w)&&a[i]%n==s&&(b=f<a[i]/w5%w)!=e&&(f<r)==b&&!--k)return a[i];return-1;}
int main(){//IO(b);
    ll n=readll(),k=readll(),t=0,x,m=0;rep(i,0,t&&a[i]<=w6)rep(j,0,9)if((x=a[i]%w)^j&&(!(a[i]/w)||(a[i]/w%w<x)==(j<x))&&
    (a[i]<w5&&(m=i+1),a[++t]=a[i]*w+j)%n==0&&!--k)return!printf("%lld\n",a[t]);
    rep(i,m,t)x=a[i]/w6,(x<a[i]/w5%w)==(a[i]/w4%w<a[i]/w5%w)&&h[a[i]%n*32|x*2|(x<a[i]/w5%w)]++;
    rep(i,1,t)if(k>(x=getcnt(n,a[i])))k-=x;else return!printf("%lld\n",a[i]*w7+get(n,a[i],k,m,t));return puts("-1"),0;
}