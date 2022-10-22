#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define red(i,f)rfor(ll i=f;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
#define define(x)static inline ull x tos
#define tos(x...)(x)toss
#define toss(x...){return x;}
typedef long long ll;const ll N=4e5+7,mod=998244353;typedef ll aN[N];char is[1<<22],os[1<<24],*i1=is,*i2=is,*o1=os;
int fpc(int c){return*o1++=c;}int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}typedef unsigned long long ull;define(np)(ull a,ull b)(!(a<<(b^63)))define(ns)(ull a,ull b)(!(a>>b))
define(lhb)(ull x)(63^__builtin_clzll(x))define(llb)(ull x)(__builtin_ctzll(x))define(wl)(ull a,ull b)(lhb(a&-1ull>>(63^b)))define(wr)(ull a,ull b)(llb(a&-1ull<<b))
void fout(){fwrite(os,o1-os,1,stdout),o1=os;}int(*gc)()=getchar,(*pc)(int)=putchar;typedef unsigned long long ull;aN next,to,head,tail,a,b,h,st[21],d,dfn,stk,f;ll cnt,top;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}int wt[114];
int myputs(const char*s,int c=10){const char*t=s;while(*t)pc(*t++);c&&pc(c);return t-s;}int qm(ll&a,ll b){return a<b?a=b,1:0;}
int mygets(char*s,int c=0){char*t=s;while((*t++=gc())>31);*(t[-1]>0&&c?t[-1]=c,t:--t)=0;return t-s;}static inline ll min(ll a,ll b){return((a^b)&-(a>b))^a;}
void writell(ll u,int c=32){ll t=0;rfor(ull n=u<0?pc(45),0uLL-u:u;n||!t;wt[++t]=n%10^48,n/=10);for(;t;pc(wt[t--]));c&&pc(c);}
void add(ll u,ll v){to[head[u]?tail[u]=next[tail[u]]=++cnt:head[u]=tail[u]=++cnt]=v;}static inline ll min2(ll a,ll b){return((a^b)&-(d[a]>d[b]))^a;}
struct trie{ull a,b[64],c[4096];void ins(ll u){c[u>>6]|=1ull<<(u&63),b[u>>12]|=1ull<<(u>>6&63),a|=1ull<<(u>>12&63);}
void del(ll u){(c[u>>6]&=~(1ull<<(u&63)))||(b[u>>12]&=~(1ull<<(u>>6&63)))||(a&=~(1ull<<(u>>12&63)));}int count(ll u)const{return c[u>>6]>>(u&63)&1;}
ll pre(ll u){np(c[u>>6],u&63)&&(u=(u&0x3ffc0)-0x01),np(b[u>>12],u>>6&63)&&(u=(u&0x3f000)-0x0001),u=wl(a,u>>12)<<12|(u&0xfff),u=wl(b[u>>12],u>>6&63)<<6|(u&0x3f03f),u=wl(c[u>>6],u&63)|(u&0x3ffc0);return u;}
ll suc(ll u){ns(c[u>>6],u&63)&&(u=(u&0x3ffc0)+0x40),ns(b[u>>12],u>>6&63)&&(u=(u&0x3f000)+0x1000),u=wr(a,u>>12)<<12|(u&0xfff),u=wr(b[u>>12],u>>6&63)<<6|(u&0x3f03f),u=wr(c[u>>6],u&63)|(u&0x3ffc0);return u;}}t;ll n;
void dfs0(ll u){a[u]-=b[u];st[0][dfn[u]=++top]=u;rev(i,u,v)dfs0(v),a[st[0][++top]=u]+=b[v]+min(0,a[v]);}void dfs2(ll u){rev(i,u,v)d[v]=d[u]+1,a[v]=a[u]+(a[v]&-(a[v]>0)),dfs2(v);}
ll lca(ll u,ll v){if((u=dfn[u])>(v=dfn[v]))std::swap(u,v);ll lg=lhb(v-u+1);return min2(st[lg][u],st[lg][v-(1<<lg)+1]);}ll dis(ll u,ll v){if(v==n+1)v=0;return a[u]+a[v]-2*a[lca(u,v)];}
int main(){IO();ll n=::n=readll(),q=readll(),top=0,x,p,s,ans;rep(i,1,n){h[i]=readll();while(top&&h[i]>h[stk[top]])top--;add(f[i]=stk[top],i),stk[++top]=i;}//add(0,n+1);
rep(i,1,n)a[i]=readll();rep(i,1,n)b[i]=readll();dfs0(0),dfs2(0),ans=a[0]*2;rep(i,1,20)rep(u,1,n*2)st[i][u]=min2(st[i-1][u],st[i-1][u+(1<<(i-1))]);t.ins(0),t.ins(n+1);
rep(i,1,q)writell((ans+=(x=readll())!=1?p=t.pre(x-1),s=t.suc(x+1),t.count(x)?t.del(x),dis(f[p],f[s])-dis(f[p],f[x])-dis(f[x],f[s]):(t.ins(x),dis(f[p],f[x])+dis(f[x],f[s])-dis(f[p],f[s])):0)/2,10);return 0;}