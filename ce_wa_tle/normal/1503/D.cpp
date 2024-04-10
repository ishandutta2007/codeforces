#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(flush)
typedef long long ll;const ll N=1e6+7,mod=1e9+7;typedef ll aN[N];char is[1<<22],os[1<<22],*i1=is,*i2=is,*o1=os;
int fpc(int c){return*o1++=c;}int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}
void flush(){fwrite(os,o1-os,1,stdout);}int(*gc)()=getchar,(*pc)(int)=putchar;typedef long double ld;const ld eps=1e-6;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}aN a,b,f,s,c;
int main(){
    ll n=readll();rep(i,1,n)if(a[i]=readll(),b[i]=readll(),a[i]<=n&&b[i]<=n)return puts("-1"),0;else 
    a[i]<b[i]?f[a[i]]=b[i],c[a[i]]=1:f[b[i]]=a[i];s[n+1]=0;per(i,n,1)s[i]=std::max(s[i+1],f[i]);
    ll sum=0,min=mod,p=mod,q=mod,cnt=0,ans=0;rep(i,1,n)if(f[i]>q)return puts("-1");else((f[i]<p)^c[i]?ans:cnt)++,
    (f[i]<p?p:q)=f[i],(min=std::min(min,f[i]))>=s[i+1]&&(sum+=std::min(ans,cnt),ans=cnt=0,p=q=mod);printf("%lld\n",sum);return 0;
}