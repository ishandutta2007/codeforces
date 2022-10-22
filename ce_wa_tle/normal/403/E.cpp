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
const ll N=1e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
struct tree{
    aN f,next,to,head,dfn,rt,vis,h,t,st,d,max,min,nfd;
    ll n,cnt,top,ts;
    struct node{
        ll u,i;
        operator ll()const{
            return u;
        }
    }q[N];
    void add(ll u,ll v){
        next[++cnt]=head[u],to[head[u]=cnt]=v;
    }
    void pushup(ll u,ll l,ll r){
        if(l!=r)max[u]=std::max(max[u<<1],max[u<<1|1]),min[u]=std::min(min[u<<1],min[u<<1|1]);
    }
    void calc(ll u,ll l,ll){
        if(h[l]>t[l])max[u]=-mod,min[u]=mod;
        else min[u]=q[h[l]].u,max[u]=q[t[l]].u;
    }
    void build(ll u,ll l,ll r){
        if(l==r)return calc(u,l,r);
        ll m=(l+r)>>1;
        build(u<<1,l,m),build(u<<1|1,m+1,r),pushup(u,l,r);
    }
    void del(ll u){
        if(!vis[u])vis[st[++ts]=u]=1;
    }
    void query(ll u,ll l,ll r,ll ql,ll qr){
        if(ql<=min[u]&&max[u]<=qr)return;
        if(l==r){
            while(h[l]<=t[l]&&q[h[l]].u<ql)del(q[h[l]++].i);
            while(h[l]<=t[l]&&q[t[l]].u>qr)del(q[t[l]--].i);
            return calc(u,l,r);
        }
        ll m=(l+r)>>1;
        if(ql<=m)query(u<<1,l,m,ql,qr);
        if(qr>m)query(u<<1|1,m+1,r,ql,qr);
        pushup(u,l,r);
    }
    void dfs(ll u){
        nfd[dfn[u]=++top]=u;
        rev(i,u,v)dfs(v);
        rt[u]=top;
    }
    void read(ll n_){
        n=n_;
        rep(i,2,n)f[i]=readll(),add(f[i],i),d[i]++,d[f[i]]++;
        dfs(1);
    }
    void calc(const tree&b){
        rep(i,1,n)h[i]=t[i-1]+1,t[i]=h[i]+b.d[nfd[i]]-1;//,printf("%lld\n",b.d[nfd[i]]);
        rep(i,1,n)t[i]=h[i]-1;
        rep(i,2,n){
            ll u=dfn[i],v=dfn[b.f[i]];
            q[++t[u]]=(node){v,i},q[++t[v]]=(node){u,i};
//            printf("%lld-%lld %lld\n",u,v,i);
        }
        rep(i,1,n)assert(h[i]==t[i-1]+1);
//        rep(i,1,n)printf("%lld %lld\n",h[i],t[i]);
        rep(i,1,n)std::sort(q+h[i],q+t[i]+1);
        build(1,1,n);
    }
    void print(const char*s){
        myputs(s);
        std::sort(st+1,st+ts+1);
        rep(i,1,ts)writell(st[i]-1);
        pc(10);
    }
    void getans(const tree&b){
        ts=0;
        rep(i,1,b.ts)query(1,1,n,dfn[b.st[i]],rt[b.st[i]]);//,printf("[%lld,%lld]\n",dfn[b.st[i]],rt[b.st[i]]);
    }
}t[2],&t1=t[0],&t2=t[1];
int main() {
    IO();
    ll n=readll();
    t1.read(n),t2.read(n),t1.calc(t2),t2.calc(t1);
    t2.del(readll()+1);
//    t2.getans(t1);
//    t2.print("???");
    rfor(ll now=1;t[now].ts;now^=1)t[now].print(now?"Blue":"Red"),t[now^1].getans(t[now]);
    return 0;
}