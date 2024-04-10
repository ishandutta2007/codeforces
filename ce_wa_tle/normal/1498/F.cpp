#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define red(i,f)rfor(ll i=f;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;const ll N=2e5+7,mod=998244353;typedef ll aN[N];char is[1<<22],os[1<<24],*i1=is,*i2=is,*o1=os;
int fpc(int c){return*o1++=c;}int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}
void fout(){fwrite(os,o1-os,1,stdout),o1=os;}int(*gc)()=getchar,(*pc)(int)=putchar;typedef unsigned long long ull;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}int wt[114];
int myputs(const char*s,int c=10){const char*t=s;while(*t)pc(*t++);c&&pc(c);return t-s;}
int mygets(char*s,int c=0){char*t=s;while((*t++=gc())>31);*(t[-1]>0&&c?t[-1]=c,t:--t)=0;return t-s;}
void writell(ll u,int c=32){ll t=0;rfor(ull n=u<0?pc(45),0uLL-u:u;n||!t;wt[++t]=n%10^48,n/=10);for(;t;pc(wt[t--]));c&&pc(c);}
aN next,head,to,a;ll f[N][40],tmp[40],cnt,k;void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}ll qm(ll a,ll b=2*k){return a-(b&-(a>=b));}
void dfs0(ll u,ll fa){f[u][0]=a[u];rev(i,u,v)if(v^fa){dfs0(v,u);ref(j,0,2*k)f[u][qm(j+1)]^=f[v][j];}}
void dfs1(ll u,ll fa){memcpy(tmp,f[u],320);if(fa)ref(j,0,2*k)f[u][qm(j+1)]^=f[fa][j]^tmp[qm(j-1+2*k)];rev(i,u,v)if(v^fa)dfs1(v,u);}
int main(){IO();
    ll n=readll(),u,v,x=0;k=readll();rep(i,2,n)u=readll(),v=readll(),add(u,v),add(v,u);rep(i,1,n)a[i]=readll();
    dfs0(1,0),dfs1(1,0);rep(i,1,n){x=0;ref(j,k,2*k)x^=f[i][j];writell(!!x);}return 0;
}