#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;
typedef unsigned long long ull;
const ll N=1e6+7,mod=998244353,iz=1<<21,oz=1<<22;
typedef ll aN[N];
char is[iz],*i1=is,*i2=is,os[oz],*o1=os,*o2=os+oz;
int fgc() {
    return i1==i2&&is==(i2=is+fread(i1=is,1,iz,stdin))?-1:*i1++;
}
void fout() {
    fwrite(os,o1-os,1,stdout),o1=os;
}
int fpc(int c) {
    if(o1==o2)fout();
    return*o1++=c;
}
int(*gc)()=getchar,(*pc)(int)=putchar,wt[126];
int readchar(int l=33,int r=126) {
    if(l>r)std::swap(l,r);
    int c=gc();
    for(; c<l||c>r; c=gc());
    return c;
}
ll readll() {
    ll x=0,w=1;
    int c=gc();
    for(; c<48||c>57; c=gc())c-45||(w=-w);
    for(; c>47&&c<58; c=gc())x=x*10+c-48;
    return x*w;
}
void writell(ll u,int c=32) {
    int t=0;
    rfor(ull n=u<0?pc(45),0ull-u:u; n; n/=10)wt[++t]=n%10^48;
    for(t||pc(48); t;)pc(wt[t--]);
    c&&pc(c);
}
int mygets(char*s,int c=0) {
    char*t=s+1;
    while((*s=gc())<33);
    while((*t=gc())>32)t++;
    c&&(*t++=c),*t=0;
    return t-s;
}
int myputs(const char*s,int c=10) {
    const char*t=s;
    while(*t)pc(*t++);
    c&&pc(c);
    return t-s+(c!=0);
}
struct ss{
    aN next,to,head;
    ll cnt,n;
    void clear(ll n_){
        memset(head,cnt=0,((n=n_)+1)<<3);
    }
    void add(ll u,ll v){
        next[++cnt]=head[u],to[head[u]=cnt]=v;
    }
}t1,t2;
#define revt(i,u,v,a)rfor(ll i=a.head[u],v;v=a.to[i],i;i=a.next[i])
struct bit{
    aN f;
    ll n;
    void set(ll n_){
        n=n_;
    }
    void update(ll u,ll c){
        for(;u<=n;u+=u&-u)f[u]^=c;
    }
    ll query(ll u){
        ll res=0;
        for(;u;u&=~-u)res^=f[u];
        return res;
    }
}t;
ll top;
aN dfn,sz;
void dfs0(ll u,ll fa){
    dfn[u]=++top,sz[u]=1;
    revt(i,u,v,t2)if(v^fa)dfs0(v,u),sz[u]+=sz[v];
//    printf("%lld->[%lld,%lld]\n",u,dfn[u],dfn[u]+sz[u]-1);
}
ll max,sum;
void update(ll u){
    if(u)t.update(dfn[u],u),t.update(dfn[u]+sz[u],u);
}
void dfs1(ll u,ll fa){
    ll f=t.query(dfn[u]);
    update(f),update(u);
    max=std::max(max,sum+=!!u-!!f);
    revt(i,u,v,t1)if(v^fa)dfs1(v,u);
    update(f),update(u);
    sum-=!!u-!!f;
}
void calc() {
    ll n=readll();
    max=sum=top=0;
    t.set(n),t1.clear(n),t2.clear(n);
    rep(i,2,n)t1.add(readll(),i);
    rep(i,2,n)t2.add(readll(),i);
    dfs0(1,0),dfs1(1,0);
//    rep(i,1,n)printf("%lld ",t.query(i));pc(10);
    writell(max,10);
}
int main() {
    IO();
    ll T=readll();
    while(T--)
        calc();
    return 0;
}