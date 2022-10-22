#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(flush)
typedef long long ll;const ll N=1e6+7,mod=1e9+7,m2=1e9+9;typedef ll aN[N];char is[1<<22],os[1<<22],*i1=is,*i2=is,*o1=os;
int fpc(int c){return*o1++=c;}int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}
void flush(){fwrite(os,o1-os,1,stdout);}int(*gc)()=getchar,(*pc)(int)=putchar;typedef long double ld;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}
ll exgcd(ll a,ll b,ll&x,ll&y){ll t;return b?t=exgcd(b,a%b,y,x),y-=a/b*x,t:(x=1,y=0,a);}aN a,b;
ll pow(ll a,ll b,ll p=mod){ll r=1;while(b){if(b&1)r=r*a%p;a=a*a%p,b>>=1;}return r;}void no(){puts("-1"),exit(0);}
ll smod(ll a,ll b){while(a%b==0)a/=b;return a;}ll sdiv(ll a,ll b){ll s=0;while(a%b==0)a/=b,s++;return s;}
ll sgcd(ll a,ll b){return a%b&&b%a?-1:b^1?sgcd(b,smod(a,b)):a;}void yes(ll u){printf("%lld\n",u),exit(0);}
void calc(ll n,ll m,ll s,ll f){rep(i,1,n)if(b[i]?a[i]>a[f]||(a[f]-a[i])%b[i]:a[i]!=a[f])no();yes(m*pow(s,a[f])%mod);}
ll find(ll x,ll y){ll p=a[x],q;rep(i,0,166){q=a[y];rep(j,0,166)if(p==q)return i;else q=q*b[y]%m2;p=p*b[x]%m2;}return-1;}
void solve(ll n,ll x,ll y){ll d=find(x,y),e;if(d==-1)no();ll an=a[x]*pow(b[x],d,m2)%m2;ld lg=logl(b[x])*d+logl(a[x]);
rep(i,1,n)if(e=((lg-logl(a[i]))/logl(b[i])+0.5),a[i]*pow(b[i],e,m2)%m2!=an)no();yes(a[x]*pow(b[x],d)%mod);}
int main(){
    ll n=readll(),s=1;rep(i,1,n)a[i]=readll(),b[i]=readll();rep(i,1,n)if((s=sgcd(s,b[i]))==-1)solve(n,1,i);
    if(s==1){rep(i,1,n)if(a[i]!=a[1])no();yes(a[1]);}ll m=smod(a[1],s);rep(i,2,n)if(smod(a[i],s)!=m)no();
    rep(i,1,n)a[i]=sdiv(a[i],s),b[i]=sdiv(b[i],s);ll u=0,v=1;
    rep(i,1,n){if(!b[i])calc(n,m,s,i);ll x,y,g=exgcd(v,b[i],x,y);if((a[i]-u)%g)no();ll w=b[i]/g,t=w*v,o=a[i]-u;
    x*=o/g,x%=w,u=u+x*v,x=std::max((-x+w-1)/w,(o-x*v+t-1)/t),u=u+x*(v=t);}yes(m*pow(s,u)%mod);return 0;
}//ans_x=m*s^{u+xv}(x=0,1,2,...)
//u+xv=a[i]+b[i]y
//xv-b[i]y=a[i]-u
//x'v-b[i]y'=a[i]-u
//x'>=0
//y'=(x'v+u-a[i])/b[i]>=0
//x'v+u-a[i]>=0
//x'=x0+k(b[i]/g)
//x0+k(b[i]/g)>=0

//x'>=0
//k>=-x0/(b[i]/g)

//k(b[i]/g)>=((a[i]-u)-x0*v)/(b[i]/g*v)