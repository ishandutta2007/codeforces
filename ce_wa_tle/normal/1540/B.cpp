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
const ll N=1e6+7,mod=1e9+7,m2=5e8+4,iz=1<<21,oz=1<<22;
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
aN next,to,head,dfn,sz,nfd,ft,d;
ll cnt,top;
void add(ll u,ll v){
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
void dfs(ll u,ll fa){
    d[u]=d[ft[u]=fa]+(sz[nfd[dfn[u]=++top]=u]=1);
    rev(i,u,v)if(v^fa)dfs(v,u),sz[u]+=sz[v];
}
ll inv(ll a,ll b=mod){
    ll x=1,y=0,m=b;
    while(b){
        ll t=a/b;
        std::swap(a,b),
        std::swap(x,y),
        b-=t*a,
        y-=t*x;
    }
    return(x+m)%m;
}
ll f[222][222];
int main() {
    IO();
    ll n=readll(),u,v,sum=0;
    rep(i,2,n)u=readll(),v=readll(),add(u,v),add(v,u);
    rep(j,1,n)f[0][j]=1;
    rep(i,1,n)rep(j,1,n)f[i][j]=(f[i-1][j]+f[i][j-1])*m2%mod;
    rep(u,1,n){
        dfs(u,0);
        rev(i,u,v)rep(j,dfn[v],dfn[v]+sz[v]-1)if(nfd[j]>u){
            ll w=nfd[j],d=::d[w]-1,cnt=0,l=0;
            while(w!=u)sum=(sum+(sz[w]-l)*f[cnt][d-cnt])%mod,cnt++,l=sz[w],w=ft[w];
        }
    }
    writell(sum*inv(n)%mod);
    return 0;
}