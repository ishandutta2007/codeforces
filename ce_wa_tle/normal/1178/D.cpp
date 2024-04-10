#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(flush)
typedef long long ll;const ll N=1e6+7,mod=998244353;typedef ll aN[N];char is[1<<22],os[1<<22],*i1=is,*i2=is,*o1=os;
int fpc(int c){return*o1++=c;}int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}
void flush(){fwrite(os,o1-os,1,stdout);}int(*gc)()=getchar,(*pc)(int)=putchar;typedef long double ld;const ld eps=1e-6;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}aN u,v,p,d;ll cnt=0;
void link(ll a,ll b){u[++cnt]=a,v[cnt]=b,d[a]++,d[b]++;}
int main(){
    ll n=readll(),t=0;p[0]=mod;rep(i,2,2*n)rep(j,p[i]||(p[++t]=i),t&&p[j]*i<=n*2&&i%p[j-1])p[i*p[j]]=1;
    ll s=0;rep(i,1,t)if(p[i]>=n&&p[i]<=n*2){s=p[i];break;}t=s;rep(i,1,n)link(i,i%n+1);ll now=0;while(t-cnt>=9){
    rep(i,1,6)rep(j,i+2,6)if(i!=1||j!=6)link(i+now,j+now);now+=6;}ll f=0;while(t>cnt)link(now+1,now+3),
    now+=(f^=1)?1:3;printf("%lld\n",cnt);rep(i,1,cnt)printf("%lld %lld\n",u[i],v[i]);
    /*rep(i,1,n)printf("%lld\n",d[i]);*/return 0;
}