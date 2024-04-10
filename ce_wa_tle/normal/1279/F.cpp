#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(flush)
typedef long long ll;const ll N=5e6+7,inf=1e18L+7;typedef ll aN[N];char is[1<<22],os[1<<22],*i1=is,*i2=is,*o1=os;
int fpc(int c){return*o1++=c;}int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}
void flush(){fwrite(os,o1-os,1,stdout);}int(*gc)()=getchar,(*pc)(int)=putchar;int qmin(ll&a,ll b){return a>b?a=b,1:0;}
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=getchar());for(;c>=48&&c<=57;x=x*10+(c&15),c=getchar());return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}ll n,k,l;aN f,g,s,a;
void calc(ll m){ll j=0;rep(i,1,l)f[i]=m,g[i]=1;rep(i,1,n)s[i]=s[i-1]+a[i],f[j]-s[j]>f[i]-s[i]&&(j=i),
f[i+l]=f[j]-s[j]+s[i]+m,g[i+l]=g[j]+1;f[n]=f[n+l]-m,g[n]=g[n+l]-1;}
int main(){
    n=readll(),k=readll(),l=readll();rep(i,1,n)a[i]=readchar()<97;ll ans=n;
    rfor(ll l=0,r=n,m;m=(l+r)>>1,l<=r||(calc(r+1),qmin(ans,f[n]-(r+1)*k),0);calc(m=(l+r)>>1),g[n]<=k?r=m-1:l=m+1);
    rep(i,1,n)a[i]^=1;
    rfor(ll l=0,r=n,m;m=(l+r)>>1,l<=r||(calc(r+1),qmin(ans,f[n]-(r+1)*k),0);calc(m=(l+r)>>1),g[n]<=k?r=m-1:l=m+1);
    printf("%lld\n",ans);return 0;
}