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
const ll N=2e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
    rfor(ull n=u<0?pc(45),0ull-u:u; n; n/=10)wt[++t]=n%10+48;
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
struct ss{ll u,v;void read(){u=readll(),v=readll();}operator ll()const{return u;}
ss re()const{return(ss){v,u};}}s[N],fz[N];
aN t,d,head,next,to,p,q;
ll cnt,now;
void add(ll u,ll v){
    next[++cnt]=head[u],to[head[u]=cnt]=v;
} 
void dfs(ll u,ll fa,ll&now){
//    printf("%lld %lld %lld\n",u,fa,now);
    rev(i,u,v)if(v^fa)dfs(v,u,now);
    ll lnow=now;
    rev(i,u,v)if(v^fa&&p[v]==-1)p[v]=++now+1,q[v]=now;
//    printf("%lld:%lld %lld\n",u,p[u],q[u]);
    if(now!=lnow)p[u]=lnow+1,q[u]=++now;
//    printf("%lld:%lld %lld\n",u,p[u],q[u]);
}
void calc(){
    ll n=readll(),m=readll();
    rep(i,1,m)s[2*i-1].read(),s[2*i]=s[2*i-1].re();
    memset(head,cnt=now=0,(n+1)<<3);
    memset(t,0,(n+1)<<3);
    memset(d,0,(n+1)<<3);
    memcpy(fz+1,s+1,sizeof(ss)*2*m);
    rep(i,1,2*m)t[s[i].u]++;
    rep(i,1,n)t[i]+=t[i-1];
    rep(i,1,2*m)s[t[fz[i].u]--]=fz[i];
    ll i=1;
    rep(u,1,n){
        while(i<=2*m&&s[i].u==u)t[s[i++].v]=-u;
        ll fst=0;
        rep(v,1,n)if(v!=u&&t[v]!=-u){
            fst=v;break;
        }
        p[u]=q[u]=-1;
        if(!fst)p[u]=q[u]=++now;
        else if(!d[u])add(u,fst),add(fst,u),d[u]++,d[fst]++;
    }
    rep(i,1,n)if(d[i]==1&&p[i]==-1)rev(j,i,v)dfs(v,0,now);
    rep(i,1,n)writell(p[i]);pc(10);
    rep(i,1,n)writell(q[i]);pc(10);
}
int main() {
    IO();
    ll T=readll();
    while(T--)calc();
    return 0;
}