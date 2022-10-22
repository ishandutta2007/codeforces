#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define red(i,f)rfor(ll i=f;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
bool p1;typedef long long ll;const ll N=2e6+77,mod=1e9+7;typedef ll aN[N];char is[1<<22],os[1<<24],*i1=is,*i2=is,*o1=os;ll f[666][666],u[666*666],v[666*666],l[666][666],can[666][666];
int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}int fpc(int c){return*o1++=c;}typedef long double ld;
void fout(){fwrite(os,o1-os,1,stdout),o1=os;}int(*gc)()=getchar,(*pc)(int)=putchar;typedef unsigned long long ull;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}int wt[114];
int myputs(const char*s,int c=10){const char*t=s;while(*t)pc(*t++);c&&pc(c);return t-s;}static inline ll qm(ll&a,ll b){return a>b?a=b,1:0;}
int mygets(char*s,int c=0){char*t=s;while((*t++=gc())>31);*(t[-1]>0&&c?t[-1]=c,t:--t)=0;return t-s;}
void writell(ll u,int c=32){ll t=0;rfor(ull n=u<0?pc(45),0uLL-u:u;n||!t;wt[++t]=n%10^48,n/=10);for(;t;pc(wt[t--]));c&&pc(c);}
int main(){/*IO();*/memset(f,0x3f,sizeof f);rep(i,1,665)f[i][i]=0;ll n=readll(),m=readll(),ans=0;rep(i,1,m)u[i]=readll(),v[i]=readll(),f[u[i]][v[i]]=f[v[i]][u[i]]=readll();memcpy(can,f,sizeof can);rep(k,1,n)rep(i,1,n)rep(j,1,n)qm(f[i][j],f[i][k]+f[k][j]);
ll q=readll(),x,y;rep(i,1,q)x=readll(),y=readll(),l[x][y]=l[y][x]=readll();rep(u,1,n)rep(y,1,n){ll mx=-mod;rep(x,1,n)mx=std::max(mx,l[x][y]-f[u][x]);rep(v,1,n)if(~can[u][v]&&can[u][v]+f[v][y]<=mx)can[u][v]=-1;}rep(i,1,m)ans+=!~can[u[i]][v[i]];writell(ans);return 0;}