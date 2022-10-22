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
void flush(){fwrite(os,o1-os,1,stdout);}int(*gc)()=getchar,(*pc)(int)=putchar;int qmax(ll&a,ll b){return a<b?a=b,1:0;}
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}aN a,t,b,c,k,f,to;
aN next,head;ll cnt=0;void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}int cmp(ll a,ll b){return c[a]<c[b];}
int main(){
    ll n=readll(),m=readll(),s=readll(),u,v;rep(i,1,n)a[i-1]=s-readll(),s+=readll(),c[k[i]=t[i]=i]=readll();a[n]=s;
    per(i,n-1,0)a[i]=std::min(a[i+1],a[i]);if(a[0]<0)return puts("-1"),0;rep(i,1,m)u=readll(),v=readll(),qmax(t[v],u);
    std::sort(k+1,k+n+1,cmp);rep(i,1,n)add(t[i],i);rep(i,1,n)rev(k,i,v)per(j,a[i],1)qmax(f[j],f[j-1]+c[v]);
    ll ans=0;rep(i,1,a[n])qmax(ans,f[i]);printf("%lld\n",ans);return 0;
}