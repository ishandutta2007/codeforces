#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define red(i,f)rfor(ll i=f;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;const ll N=2005,inf=1e18;typedef ll aN[N];char is[1<<22],os[1<<24],*i1=is,*i2=is,*o1=os;
int fpc(int c){return*o1++=c;}int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}ll min(ll a,ll b){return((a^b)&-(a>b))^a;}
void fout(){fwrite(os,o1-os,1,stdout),o1=os;}int(*gc)()=getchar,(*pc)(int)=putchar;typedef unsigned long long ull;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}int wt[114];
int myputs(const char*s){const char*t=s;while(*t)pc(*t++);pc(10);return t-s;}int qm(ll&a,ll b){return a>b?a=b,1:0;}
void writell(ll u,int c=32){ll t=0;for(ull n=u<0?pc(45),0uLL-u:u;n||!t;wt[++t]=n%10^48,n/=10);for(;t;pc(wt[t--]));c&&pc(c);}
ll q,now;aN ans;ll vis[N*N];struct ss{ll c[11],d[11],t;ll getans(ll i,ll j)const{return min(i,t<=q?j:min(j,d[q]));}ss(){memset(this,0,sizeof*this);}ss(ll x){memset(this,0,sizeof*this),c[0]=x,t=1;}
void merge(const ss&a,const ss&b,ll n=0,ll m=0){++now;t=0;rfor(ll i=0,j=0;(i<a.t||j<b.t)&&t<=q;)
i<a.t&&(j>=b.t||a.d[i]+n<=b.d[j]+m)?vis[a.c[i]]!=now?vis[d[t]=a.d[i]+n,c[t++]=a.c[i++]]=now:i++:vis[b.c[j]]!=now?vis[d[t]=b.d[j]+m,c[t++]=b.c[j++]]=now:j++;}}f[2][N],z0,z1;
int main(){IO();
    ll n=readll();q=readll();rep(i,1,n)rep(j,1,n)z0.merge(f[~i&1][j-1],f[~i&1][j]),z1.merge(f[i&1][j-1],readll(),1,0),
    f[i&1][j].merge(z0,z1,1,0),ans[f[i&1][j].getans(i,j)]++;per(i,n,1)ans[i]+=ans[i+1];rep(i,1,n)writell(ans[i],10);return 0;
}