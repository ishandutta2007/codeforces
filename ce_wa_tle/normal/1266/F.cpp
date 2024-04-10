#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef int ll;const ll N=3e6+7,mod=1e9+7;typedef ll aN[N];char is[1<<22],os[1<<22],*i1=is,*i2=is,*o1=os;
int fpc(int c){return*o1++=c;}int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}aN a;
void fout(){fwrite(os,o1-os,1,stdout),o1=os;}int(*gc)()=getchar,(*pc)(int)=putchar;typedef unsigned long long ull;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}int wt[114];
int myputs(const char*s){const char*t=s;while(*t)pc(*t++);pc(10);return t-s;}int qm(ll&a,ll b){return a<b?a=b,1:0;}
void writell(ll u,int c=32){ll t=0;for(ull n=u<0?pc(45),0uLL-u:u;n||!t;wt[++t]=n%10^48,n/=10);for(;t;pc(wt[t--]));c&&pc(c);}
aN next,to,head,f,g,h,ms,s,l,d,ft;ll cnt,n;void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
ll qm(ll&a,ll&b,ll c){return c>a?b=a,a=c,2:c>b?b=c,1:0;}ll max(ll a,ll b){return((a^b)&-(a<b))^a;}
void dfs0(ll u,ll fa){ft[u]=fa;add(0+n,u);rev(i,u,v)if(v^fa)dfs0(v,u),qm(f[u],g[u],f[v]+1),add(f[v]+1+n,u);}
void dfs2(ll u,ll fa){if(fa)add(n+(h[u]=max(h[fa],f[u]+1==f[fa]?g[fa]:f[fa])+1),u);rev(i,u,v)if(v^fa)dfs2(v,u);}
int main(){ll n=readll(),u,v;::n=n+1;rep(i,2,n)u=readll(),v=readll(),add(u,v),add(v,u);
dfs0(1,0),dfs2(1,0);per(i,n,0)rev(j,i+::n,x)qm(ms[ft[x]],++s[x]),qm(d[i*2],s[x]+max(0ll,max(ms[x],s[ft[x]])-2)),
qm(d[(i+(i!=l[x]))*2-1],s[x]),l[x]=i;d[n+3]=d[n+4]=1;per(i,n+2,1)d[i]=max(d[i],d[i+2]);rep(i,1,n)writell(d[i]);return 0;}