#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=s&(i-1))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
bool p1;
typedef long long ll;
typedef unsigned long long ull;
const ll N=1e6+7,mod=1e9+7;
typedef ll aN[N];
char is[1<<21],os[1<<23],*i1=is,*i2=is,*o1=os;
int fgc() {
    return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;
}
int fpc(int c) {
    return*o1++=c;
}
void fout() {
    fwrite(os,o1-os,1,stdout),o1=os;
}
int(*gc)()=getchar,(*pc)(int)=putchar,wt[122];
int readchar(int l=33,int r=122) {
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
    ll t=0;
    for(ull n=u<0?pc(45),0ull-u:u; n; n/=10)wt[++t]=n%10;
    for(t||pc(48); t;)pc(wt[t--]^48);
    c&&pc(c);
}
int mygets(char*s,int c=0) {
    char*t=s;
    while((*t=gc())>32)t++;
    c&&(*t++=c),*t=0;
    return t-s;
}
int myputs(const char*s,int c=10) {
    const char*t=s;
    while(*t)pc(*t++);
    c&&pc(c);
    return t-s;
}
aN next,to,head,a,st[24],deep,dfn;
ll cnt,top;
std::mt19937_64 rd(1);
ull val[N];
void add(ll u,ll v) {
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
static inline mylog2(ll u) {
    return __builtin_clzll(u)^63;
}
struct sgt {
    typedef ll aM[N*23];
    typedef int aS[N*23];
    int rt[N];
    aM f;
    aS ls,rs;
    ll cnt,n;
    void set(ll n_) {
        n=n_;
    }
    void update(int&u,ll v,ll l,ll r,ll q,ll c) {
        u=++cnt;
        if(l==r) {
            f[u]=f[v]^c;
            return;
        }
        ll m=(l+r)>>1;
        q<=m?update(ls[u],ls[v],l,m,q,c),rs[u]=rs[v]:(update(rs[u],rs[v],m+1,r,q,c),ls[u]=ls[v]);
        f[u]=f[ls[u]]^f[rs[u]];
    }
    ll min(ll u,ll v,ll l,ll r,ll ql,ll qr)const {
        if(qr<l||r<ql||f[u]==f[v])return 0;
        if(l==r)return l;
        ll m=(l+r)>>1;
        return min(ls[u],ls[v],l,m,ql,qr)?:min(rs[u],rs[v],m+1,r,ql,qr);
    }
    ll query(ll u,ll l,ll r,ll ql,ll qr)const {
        if(qr<l||r<ql||!u)return 0;
        if(ql<=l&&r<=qr)return f[u];
        ll m=(l+r)>>1;
        return query(ls[u],l,m,ql,qr)^query(rs[u],m+1,r,ql,qr);
    }
    void update(ll u,ll v,ll c) {
//        printf("t[%lld]=t[%lld]+%lld\n",u,v,c);
        update(rt[u],rt[v],1,n,c,val[c]);
    }
    ll min(ll u,ll v,ll l,ll r)const {
        ll res=l>r?0:min(rt[u],rt[v],1,n,l,r);
//        printf("(t[%lld]^t[%lld])[%lld-%lld]=%lld\n",u,v,l,r,res);
        return res;
    }
    ll query(ll u,ll l,ll r)const {
        ll res=l>r?0:query(rt[u],1,n,l,r);
//        printf("t[%lld][%lld-%lld]=%lld\n",u,l,r,res);
        return res;
    }
} t;
void dfs(ll u,ll fa) {
    deep[u]=deep[fa]+1,t.update(st[0][dfn[u]=++top]=u,fa,a[u]);
    rev(i,u,v)if(v^fa)dfs(v,u),st[0][++top]=u;
}
ll min_2(ll a,ll b) {
    return deep[a]<deep[b]?a:b;
}
ll lca(ll u,ll v) {
    if((u=dfn[u])>(v=dfn[v]))std::swap(u,v);
    ll lg=mylog2(v-u+1);
    return min_2(st[lg][u],st[lg][v-(1<<lg)+1]);
}
bool p2;
int main() {
//    fprintf(stderr,"%.2fMib\n",(&p2-&p1)/1048576.0);
    IO();
    ll n=readll(),q=readll(),u,v,c,l,r;
    rep(i,1,n)val[i]=rd(),a[i]=readll();
    rep(i,2,n)u=readll(),v=readll(),add(u,v),add(v,u);
    t.set(n),dfs(1,0);
    ref(u,0,22)rep(i,1,top)st[u+1][i]=min_2(st[u][i],st[u][i+(1<<u)]);
    rep(i,1,q)u=readll(),v=readll(),l=readll(),r=readll(),c=a[lca(u,v)],
    writell((c<l||c>r?t.min(u,v,l,r):t.min(u,v,l,c-1)?:t.query(u,c,c)==t.query(v,c,c)?c:t.min(u,v,c+1,r))?:-1,10);
    return 0;
}