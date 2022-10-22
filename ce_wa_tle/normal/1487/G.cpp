#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define red(i,f)rfor(ll i=f;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef int ll;const ll N=102,mod=998244353;typedef ll aN[N];char is[1<<22],os[1<<24],*i1=is,*i2=is,*o1=os;ll f1[N][N],f2[N][N],g1[N],t[N];
int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}int fpc(int c){return*o1++=c;}typedef long double ld;
void fout(){fwrite(os,o1-os,1,stdout),o1=os;}int(*gc)()=getchar,(*pc)(int)=putchar;typedef unsigned long long ull;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}int wt[114];
int myputs(const char*s,int c=10){const char*t=s;while(*t)pc(*t++);c&&pc(c);return t-s;}static inline int qm(ll&a,ll b=mod){return a>=b?a-=b,1:0;}
int mygets(char*s,int c=0){char*t=s;while((*t++=gc())>31);*(t[-1]>0&&c?t[-1]=c,t:--t)=0;return t-s;}static inline ll m0(ll u){return-(u>=0)&u;}
void writell(ll u,int c=32){ll t=0;rfor(ull n=u<0?pc(45),0uLL-u:u;n||!t;wt[++t]=n%10^48,n/=10);for(;t;pc(wt[t--]));c&&pc(c);}
ll f[N*2][N][N][3],g[N*2][N][2],h[N*2];void init(){h[1]=26;ref(i,2,N*2)h[i]=h[i-1]*25ll%mod;f[1][1][0][0]=f[1][0][1][1]=1,f[1][0][0][2]=24;ref(i,2,N*2)rep(j,0,(i+1)/2)rep(k,0,(i+1)/2&&j+k<=i)
i-j-k&&(f[i][j][k][2]=(24ll*(f[i-1][j][k][0]+f[i-1][j][k][1])+23ll*f[i-1][j][k][2])%mod),j&&qm(f[i][j][k][0]=f[i-1][j-1][k][1]+f[i-1][j-1][k][2]),
k&&qm(f[i][j][k][1]=f[i-1][j][k-1][0]+f[i-1][j][k-1][2]);g[1][1][0]=1,g[1][0][1]=25;ref(i,2,N*2)rep(j,0,(i+1)/2)j&&(g[i][j][0]=g[i-1][j-1][1]),i-j&&(g[i][j][1]=(25ll*g[i-1][j][0]+24ll*g[i-1][j][1])%mod);}
int main(){IO();init();const ll n=readll(),a=n/2,b=n-a,c=(a+1)/2,d=(b+1)/2;ll ans=1ll*h[a]*h[b]%mod;rep(i,1,26)t[i]=readll();rep(j,0,c)qm(g1[j]=g[a][j][0]+g[a][j][1]);
rep(j,0,c)rep(k,0,c&&j+k<=a)f1[j][k]=(0ll+f[a][j][k][0]+f[a][j][k][1]+f[a][j][k][2])%mod;rep(j,0,d)rep(k,0,d&&j+k<=b)f2[j][k]=(0ll+f[b][j][k][0]+f[b][j][k][1]+f[b][j][k][2])%mod;
per(j,c-1,0)qm(g1[j]+=g1[j+1]);per(j,c,0)per(k,std::min(c,a-j)-1,0)qm(f1[j][k]+=f1[j][k+1]);per(j,c-1,0)per(k,std::min(c,a-j),0)qm(f1[j][k]+=f1[j+1][k]);
rep(i,1,26)if(c+d>t[i])rep(j,m0(t[i]-c+1),d)ans=(ans+1ll*(g[b][j][0]+g[b][j][1])*(mod-g1[m0(t[i]-j+1)]))%mod;
rep(u,1,26)if(c+d>t[u])rep(v,u+1,26)if(c+d>t[v])rep(j,m0(t[u]-c+1),d)rep(k,m0(t[v]-c+1),d&&j+k<=b)if(m0(t[u]-j+1)+m0(t[v]-k+1)<=a)ans=(ans+1ll*f2[j][k]*f1[m0(t[u]-j+1)][m0(t[v]-k+1)])%mod;
writell(ans);return 0;}
/*,printf("f[%d][%d][%d]={%d,%d,%d}\n",i,j,k,f[i][j][k][0],f[i][j][k][1],f[i][j][k][2])*/