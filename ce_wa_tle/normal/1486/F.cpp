#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define red(i,f)rfor(ll i=f;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
#define reva(i,u,v,a)rfor(ll i=a.head[u],v;v=a.to[i],i;i=a.next[i])
typedef long long ll;const ll N=1e6+7,mod=998244353;typedef ll aN[N];char is[1<<22],os[1<<24],*i1=is,*i2=is,*o1=os;char a[N];
int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}int fpc(int c){return*o1++=c;}typedef long double ld;
void fout(){fwrite(os,o1-os,1,stdout),o1=os;}int(*gc)()=getchar,(*pc)(int)=putchar;typedef unsigned long long ull;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}int wt[114];
int myputs(const char*s,int c=10){const char*t=s;while(*t)pc(*t++);c&&pc(c);return t-s;}static inline int qm(ll&a,ll b=mod){return a>b?a=b,1:0;}
int mygets(char*s,int c=0){char*t=s;while((*t++=gc())>31);*(t[-1]>0&&c?t[-1]=c,t:--t)=0;return t-s;}
void writell(ll u,int c=32){ll t=0;rfor(ull n=u<0?pc(45),0uLL-u:u;n||!t;wt[++t]=n%10^48,n/=10);for(;t;pc(wt[t--]));c&&pc(c);}
aN deep,dfn,f,p,st,t;ll top,ans;struct ss{aN next,to,head;ll cnt;void clear(){memset(head,cnt=0,sizeof head);}void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}}e,q;
struct sd{ll x,y,lca,a,b;void calc0(ll i){if(dfn[x=readll()]>dfn[y=readll()])std::swap(x,y);q.add(y,i);}
void calc2(ll i){q.add(x,i),p[x]++,p[y]++,p[lca]-=2,ans+=t[lca]++;}void calc3(ll){ans+=!!a+!!b+p[lca]-p[a]-p[b];if(a)q.add(a,b);if(b)q.add(b,a);}}l[N];
void dfs0(ll u,ll fa){dfn[u]=++top,deep[u]=deep[fa]+1;reva(i,u,v,e)if(v^fa)dfs0(v,u);}ll find(ll u){return u^f[u]?f[u]=find(f[u]):u;}
void dfs2(ll u,ll fa){st[deep[u]]=f[u]=u;reva(i,u,v,e)if(v^fa)dfs2(v,u),f[v]=u;reva(i,u,v,q)l[v].b=u==(l[v].lca=find(l[v].x))?0:st[deep[l[v].lca]+1];}
void dfs3(ll u,ll fa){st[deep[u]]=u;reva(i,u,v,e)if(v^fa)dfs3(v,u),p[u]+=p[v];reva(i,u,v,q)l[v].a=u==l[v].lca?0:st[deep[l[v].lca]+1];}
int main(){IO();ll n=readll(),u,v;rep(i,2,n)u=readll(),v=readll(),e.add(u,v),e.add(v,u);ll m=readll();dfs0(1,0);rep(i,1,m)l[i].calc0(i);dfs2(1,0);q.clear();rep(i,1,m)l[i].calc2(i);
memset(t,0,sizeof t);dfs3(1,0);q.clear();rep(i,1,m)l[i].calc3(i);rep(i,1,n){ll cns=0;reva(j,i,v,q)ans+=(i<v?t[v]++:0)+cns++;reva(j,i,v,q)t[v]=0;}writell(ans);return 0;}