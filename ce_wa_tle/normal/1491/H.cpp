#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define red(i,f)rfor(ll i=f;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;const ll N=1e5+777,B=256,mod=998244353;typedef ll aN[N];char is[1<<22],os[1<<24],*i1=is,*i2=is,*o1=os;aN a;
int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}int fpc(int c){return*o1++=c;}
void fout(){fwrite(os,o1-os,1,stdout),o1=os;}int(*gc)()=getchar,(*pc)(int)=putchar;typedef unsigned long long ull;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}int wt[114];
int myputs(const char*s,int c=10){const char*t=s;while(*t)pc(*t++);c&&pc(c);return t-s;}int qm(ll&a,ll b){return a<b?a=b,1:0;}
int mygets(char*s,int c=0){char*t=s;while((*t++=gc())>31);*(t[-1]>0&&c?t[-1]=c,t:--t)=0;return t-s;}
void writell(ll u,int c=32){ll t=0;rfor(ull n=u<0?pc(45),0uLL-u:u;n||!t;wt[++t]=n%10^48,n/=10);for(;t;pc(wt[t--]));c&&pc(c);}
static inline m0(ll a){return-(a>=0)&a;}aN f,t,b,z;static inline rf(ll u){return m0(f[u]+z[u/B]);}static inline rb(ll u){return t[u/B]==B?rf(u):b[u];}
void bd(ll u){if(t[u]>=B)return;const ll l=u*B,r=l+B;ref(i,l+t[u],r)if(f[i]>=l){t[u]=i-l;break;}if(f[l+t[u]]<l){t[u]=B;return;}ref(i,l,r)b[i]=f[i]>=l?b[f[i]]:f[i];}
void up(ll l,ll r,ll x){const ll bl=l/B,br=r/B;if(bl==br){rep(i,l,r)f[i]=m0(f[i]-x);return bd(bl);}up(l,bl*B+B-1,x),up(br*B,r,x);ref(i,bl+1,br)t[i]==B?z[i]-=x,(void)0:up(i*B,i*B+B-1,x);}
ll lca(ll u,ll v){while(1){if(u<v)std::swap(u,v);if(u==v)return u;if(u/B!=v/B)u=rb(u);else if(rb(u)^rb(v))u=rb(u),v=rb(v);else{while(u^v){if(u<v)std::swap(u,v);u=rf(u);}return u;}}}
int main(){IO();const ll n=readll(),m=readll();ll l,r,t;ref(i,1,n)f[i]=readll()-1;rep(i,0,n/B)bd(i);rep(i,1,m)t=readll(),l=readll()-1,r=readll()-1,t==1?up(l,r,readll()):writell(lca(l,r)+1,10);return 0;}