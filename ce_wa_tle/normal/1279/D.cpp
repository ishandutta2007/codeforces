#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(flush)
typedef long long ll;const ll N=5e6+7,mod=998244353;typedef ll aN[N];char is[1<<22],os[1<<22],*i1=is,*i2=is,*o1=os;
int fpc(int c){return*o1++=c;}int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}
void flush(){fwrite(os,o1-os,1,stdout);}int(*gc)()=getchar,(*pc)(int)=putchar;int qmax(ll&a,ll b){return a<b?a=b,1:0;}
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=getchar());for(;c>=48&&c<=57;x=x*10+(c&15),c=getchar());return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}aN t,a,f,ny;
ll pow(ll a,ll b=mod-2,ll p=mod){ll res=1;while(b){if(b&1)res=res*a%p;a=a*a%p,b>>=1;}return res;}
int main(){
    ll n=readll(),cnt=0,s=0;rep(i,1,n){ll k=readll();rep(j,1,k)t[a[++cnt]=readll()]++,f[cnt]=k;}
    ny[1]=1;rep(i,2,cnt)ny[i]=(mod-mod/i)*ny[mod%i]%mod;
    rep(i,1,cnt)s=(s+t[a[i]]*ny[f[i]])%mod;printf("%lld\n",s*ny[n]%mod*ny[n]%mod);return 0;
}