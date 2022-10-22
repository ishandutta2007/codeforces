#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define red(i,f)rfor(ll i=f;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;const ll N=2e5+777,B=256,mod=998244353;typedef ll aN[N];char is[1<<22],os[1<<24],*i1=is,*i2=is,*o1=os;aN a,col,fst;
int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}int fpc(int c){return*o1++=c;}
void fout(){fwrite(os,o1-os,1,stdout),o1=os;}int(*gc)()=getchar,(*pc)(int)=putchar;typedef unsigned long long ull;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}int wt[114];
int myputs(const char*s,int c=10){const char*t=s;while(*t)pc(*t++);c&&pc(c);return t-s;}int qm(ll&a,ll b){return a<b?a=b,1:0;}
int mygets(char*s,int c=0){char*t=s;while((*t++=gc())>31);*(t[-1]>0&&c?t[-1]=c,t:--t)=0;return t-s;}
void writell(ll u,int c=32){ll t=0;rfor(ull n=u<0?pc(45),0uLL-u:u;n||!t;wt[++t]=n%10^48,n/=10);for(;t;pc(wt[t--]));c&&pc(c);}static inline void swap(ll a,ll b){writell(a),writell(b,10);}
int main(){IO();const ll n=readll();ll cnt=0,ans=n;rep(i,1,n)a[i]=readll();rep(i,1,n)if(i==a[i])fst[0]=i,ans--;else if(!col[i]){fst[col[i]=++cnt]=i;rfor(ll j=a[i];!col[j];j=a[j])col[j]=cnt;}
writell(ans+(cnt&1),10);rep(i,1,cnt/2){ll u=fst[i*2-1],v=fst[i*2];swap(u,v);rfor(ll j=a[u];j!=u;j=a[j])swap(j,v);rfor(ll j=a[v];j!=v;j=a[j])swap(u,j);swap(u,v);}
if(cnt&1){ll u=fst[cnt],v=a[u];if(a[v]==u){ll w=fst[0]?:fst[1];swap(u,w),swap(v,w),swap(u,w);}else{ll w=a[v];swap(u,v),swap(v,w),swap(u,w);rfor(ll j=a[w];j!=u;j=a[j])swap(j,v);swap(u,v);}}return 0;}