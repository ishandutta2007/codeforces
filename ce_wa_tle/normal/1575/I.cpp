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
int fgc(){
    return i1==i2&&is==(i2=is+fread(i1=is,1,iz,stdin))?-1:*i1++;
}
void fout(){
    fwrite(os,o1-os,1,stdout),o1=os;
}
int fpc(int c){
    if(o1==o2)fout();
    return*o1++=c;
}
int(*gc)()=getchar,(*pc)(int)=putchar,wt[126];
int readchar(int l=33,int r=126){
    if(l>r)std::swap(l,r);
    int c=gc();
    for(;c<l||c>r;c=gc());
    return c;
}
ll readll(){
    ll x=0,w=1;
    int c=gc();
    for(;c<48||c>57;c=gc())c-45||(w=-w);
    for(;c>47&&c<58;c=gc())x=x*10+c-48;
    return x*w;
}
void writell(ll u,int c=32){
    int t=0;
    rfor(ull n=u<0?pc(45),0ull-u:u;n;n/=10)wt[++t]=n%10^48;
    for(t||pc(48);t;)pc(wt[t--]);
    c&&pc(c);
}
int mygets(char*s,int c=0){
    char*t=s+1;
    while((*s=gc())<33);
    while((*t=gc())>32)t++;
    c&&(*t++=c),*t=0;
    return t-s;
}
int myputs(const char*s,int c=10){
    const char*t=s;
    while(*t)pc(*t++);
    c&&pc(c);
    return t-s+(c!=0);
}
aN next,to,head,deep,a,st[22],lf,rt,dfn,f;
struct ss{
    aN f;
    ll n;
    void set(ll n_){
        n=n_;
    }
    void update(ll u,ll c){
        for(;u<=n;u+=u&-u)f[u]+=c;
    }
    ll query(ll u)const{
        ll res=0;
        for(;u;u&=~-u)res+=f[u];
        return res;
    }
}t;
ll cnt,top,tot;
void add(ll u,ll v){
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
void dfs(ll u,ll fa){
    deep[st[0][dfn[u]=++tot]=u]=deep[f[u]=fa]+1,lf[u]=++top;
    rev(i,u,v)if(v^fa)dfs(v,u),st[0][++tot]=u;
    rt[u]=top,t.update(lf[u],a[u]),t.update(rt[u]+1,-a[u]);
}
ll min2(ll a,ll b){
    return deep[a]<deep[b]?a:b;
}
ll lca(ll u,ll v){
    u=dfn[u],v=dfn[v];
    if(u>v)std::swap(u,v);
    ll lg=__builtin_clzll(v-u+1)^63;
    return min2(st[lg][u],st[lg][v-(1<<lg)+1]);
}
int main(){
    IO();
    ll n=readll(),q=readll(),u,v;
    t.set(n);
    rep(i,1,n)a[i]=llabs(readll());
    rep(i,2,n)u=readll(),v=readll(),add(u,v),add(v,u);
    dfs(1,0);
    //rep(i,1,n)printf("<%lld %lld %lld\n",lf[i],rt[i],deep[i]);
    rep(i,0,20)rep(u,1,n*2-(1<<(i+1)))st[i+1][u]=min2(st[i][u],st[i][u+(1<<i)]);
    rep(i,1,q){
        ll o=readll(),u=readll(),c=llabs(readll());
        if(o==1)c-=a[u],t.update(lf[u],c),t.update(rt[u]+1,-c),a[u]+=c;
        else o=lca(u,c),writell((t.query(lf[u])+t.query(lf[c])-2*t.query(lf[o])+a[o])*2-a[u]-a[c],10);
    }
    return 0;
}
/*
7 1
1 2 3 4 5 6 7
1 2
1 3
2 4
2 5
3 6
3 7
2 4 7
*/