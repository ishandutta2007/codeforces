#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)r(ll i=s;i;i=(i-1)&(s))
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
char st[90][20][N/10+7];
aN a,lst,p;
ll pp[99][24];
ll mylog2(ll u){
    return 63^__builtin_clzll(u);
}
struct sgt{
    int s[N<<4],ls[N<<4],rs[N<<4],rt[N];
    ll cnt,n;
    void set(ll n_){
        n=n_;
    }
    void pushup(ll u,ll l,ll r){
        if(l<r)s[u]=1ll*s[ls[u]]*s[rs[u]]%mod;
    }
    ll query(int u,ll l,ll r,ll ql,ll qr)const{
        if(qr<l||r<ql||!u)return 1;
        if(ql<=l&&r<=qr)return s[u];
        const ll mid=(l+r)>>1;
        return 1ll*query(ls[u],l,mid,ql,qr)*query(rs[u],mid+1,r,ql,qr)%mod;
    }
    ll query(ll u,ll l,ll r)const{
        return query(rt[u],1,n,l,r);
    }
    void update(int&u,ll v,ll l,ll r,ll q,ll c){
        if(!u)u=++cnt;
        if(l==r)return static_cast<void>(s[u]=c);
        const ll mid=(l+r)>>1;
        if(q<=mid)update(ls[u],ls[v],l,mid,q,c),rs[u]=rs[v];
        else update(rs[u],rs[v],mid+1,r,q,c),ls[u]=ls[v];
        pushup(u,l,r);
    }
    void update(ll u,ll v,ll q,ll c){
        if(!q)rt[u]=rt[v];
        else update(rt[u],rt[v],1,n,q,c);
    }
    void build(int&u,ll l,ll r,const ll*a){
        if(!u)u=++cnt;
        if(l==r)return static_cast<void>(s[u]=a[l]);
        const ll mid=(l+r)>>1;
        build(ls[u],l,mid,a),build(rs[u],mid+1,r,a),pushup(u,l,r);
    }
    void build(ll u,const ll*a){
        build(rt[u],1,n,a);
    }
}tr;
int main(){
    IO();
    static const ll m=sqrtl(2e5L+1e-7L);
    ll t=0;
    p[0]=mod;
    rep(i,2,m)rfor(ll j=p[i]||(p[++t]=i);j<=t&&p[j]*i<=m&&i%p[j-1];j++)p[i*p[j]]=1;
    //rep(j,1,t)printf("%lld\n",p[j]);
    const ll n=readll();
    rep(i,1,n){
        ll x=readll();
        rep(j,1,t)while(x%p[j]==0)st[j][0][i]++,x/=p[j];
        a[i]=x;
    }
    rep(j,1,t)rep(i,pp[j][0]=1,22)pp[j][i]=pp[j][i-1]*p[j]%mod;
    rep(j,1,t)rep(i,0,18)rep(u,1,n-(1<<i)+1)st[j][i+1][u]=std::max(st[j][i][u],st[j][i][u+(1<<i)]);
    tr.set(n),tr.build(0,a);
    rep(i,1,n){
        ll&s=lst[a[i]];
        tr.update(i,i-1,s,1),s=i;
    }
    const ll q=readll();
    rep(i,1,q){
        static ll lans=0;
        ll l=(readll()+lans)%n+1,r=(readll()+lans)%n+1,ans=1;
        if(l>r)std::swap(l,r);
        const ll lg=mylog2(r-l+1),v=r-(1<<lg)+1;
        rep(j,1,t)ans=ans*pp[j][std::max(st[j][lg][l],st[j][lg][v])]%mod;
        writell(lans=ans*tr.query(r,l,r)%mod,10);
    }
    return 0;
}