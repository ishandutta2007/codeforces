#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define red(i,f)rfor(ll i=f;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;const ll N=1e6+7,mod=1e9+7;typedef ll aN[N];char is[1<<22],os[1<<24],*i1=is,*i2=is,*o1=os;
int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}int fpc(int c){return*o1++=c;}typedef long double ld;
void fout(){fwrite(os,o1-os,1,stdout),o1=os;}int(*gc)()=getchar,(*pc)(int)=putchar;typedef unsigned long long ull;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}int wt[114];
int myputs(const char*s,int c=10){const char*t=s;while(*t)pc(*t++);c&&pc(c);return t-s;}static inline int qm(ll&a,ll b){return a<b?a=b,1:0;}
int mygets(char*s,int c=0){char*t=s;while((*t++=gc())>31);*(t[-1]>0&&c?t[-1]=c,t:--t)=0;return t-s;}
void writell(ll u,int c=32){ll t=0;rfor(ull n=u<0?pc(45),0uLL-u:u;n||!t;wt[++t]=n%10^48,n/=10);for(;t;pc(wt[t--]));c&&pc(c);}
aN next,to,head,t,c,g,f,d,a;ll cnt=0;void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}void dfs(ll u,ll fa){d[u]=d[f[u]=fa]+1;rev(i,u,v)if(v^fa)dfs(v,u);}
void calc(){ll n=readll(),x;memset(head,cnt=0,(n+1)<<3);rep(i,2,n)add(i,x=readll()),add(x,i);dfs(t[1]=1,0);rep(i,2,n)a[i]=readll(),t[d[i]]++;rep(i,1,n)t[i]+=t[i-1];rep(i,1,n)c[t[d[i]]--]=i;rep(i,1,n)t[i]=0;c[n+1]=0;
ll lst=2,s1=0,s2=0,s3=0,s4=0,s5=0;rep(i,2,n)if(d[c[i]]!=d[c[i+1]]){rep(j,lst,i){ll i=c[j];g[i]=g[f[i]]+a[f[i]]+s1,qm(g[i],g[f[i]]+s2-a[f[i]]),qm(g[i],a[f[i]]+s3),qm(g[i],s4-a[f[i]]);}
s1=s2=s3=s4=-mod;rep(j,lst,i){ll i=c[j];qm(s1,-a[i]),qm(s2,a[i]),qm(s3,-a[i]+g[i]),qm(s4,a[i]+g[i]);}rep(j,lst,i){ll i=c[j];qm(s5,g[i]+a[i]+s1),qm(s5,g[i]+s2-a[i]);}lst=i+1;}writell(s5,10);}int main(){IO();ll T=readll();while(T--)calc();return 0;}