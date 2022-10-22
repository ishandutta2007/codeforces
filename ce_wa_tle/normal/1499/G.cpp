#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define red(i,f)rfor(ll i=f;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;const ll N=3e6+7,mod=998244353;typedef ll aN[N];char is[1<<22],os[1<<24],*i1=is,*i2=is,*o1=os;
int fpc(int c){return*o1++=c;}int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}
void fout(){fwrite(os,o1-os,1,stdout),o1=os;}int(*gc)()=getchar,(*pc)(int)=putchar;typedef unsigned long long ull;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}int wt[114];
int myputs(const char*s,int c=10){const char*t=s;while(*t)pc(*t++);c&&pc(c);return t-s;}
int mygets(char*s,int c=0){char*t=s;while((*t++=gc())>31);*(t[-1]>0&&c?t[-1]=c,t:--t)=0;return t-s;}
void writell(ll u,int c=32){ll t=0;rfor(ull n=u<0?pc(45),0uLL-u:u;n||!t;wt[++t]=n%10^48,n/=10);for(;t;pc(wt[t--]));c&&pc(c);}
aN f,g,d,c;ll ans,cnt,w=1;ll find(ll u){ll rt=0;return u^f[u]?rt=find(f[u]),g[u]^=g[f[u]],f[u]=rt:u;}ll add(){d[++cnt]=w=w*2%mod;return f[cnt]=cnt;}
ll link(ll u,ll v,ll c){ll res=0;return c&&(d[u]=-(res=d[u]),++g[u]),d[f[u]=v]=(d[v]+d[u])%mod,res;}ll merge(ll u,ll v){return find(u)!=find(v)?link(f[u],f[v],g[u]==g[v]):0;}
void calc(ll y,ll x=cnt){c[y]=c[y]?ans=(ans+merge(x,c[y])+mod)%mod,0:x;}void putans(){ll s=0;rep(i,1,cnt)find(i),s+=g[i];writell(s);rep(i,1,cnt)if(g[i])writell(i);pc(10);}
int main(){
    ll n1=readll(),n2=readll(),m=readll();rep(i,1,m)add(),calc(readll()),calc(readll()+n1);m=readll();rep(i,1,m)readll()==1?
    add(),calc(readll()),calc(readll()+n1),writell(ans,10):putans(),fflush(stdout);return 0;static_cast<void>(n1),static_cast<void>(n2);
}