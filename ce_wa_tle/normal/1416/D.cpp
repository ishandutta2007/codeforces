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
aN u,v,t,id,head,to,next,e,f,a,lf,rt,qv,np,p;
ll ft[22][N/2];
ll cnt,top;
void add(ll u,ll v){
    //printf("%lld -> %lld\n",u,v);
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
void dfs(ll u,ll fa){
    ft[0][u]=fa;
    if(!head[u])lf[u]=++top;
    rev(i,u,v)dfs(v,u);
    if(!lf[u])lf[u]=lf[to[head[u]]];
    rt[u]=top;
}
ll find(ll u){
    return u^f[u]?f[u]=find(f[u]):u;
}
struct sgt{
    aN f;
    ll n;
    void set(ll n_,ll*a){
        //rep(i,1,100)printf("%lld %lld\n",i,2ll<<(63^__builtin_clzll(i+2)));
        n=2ll<<(63^__builtin_clzll(n_+2));
        memcpy(f+n+1,a+1,n_<<3);
        //printf("%lld %lld\n",n_,n);
        per(i,n-1,1)f[i]=std::max(f[i<<1],f[i<<1|1]);
    }
    void update(ll u,ll c){
        f[u+=n]=c;
        //return;
        red(i,u>>1)f[i]=std::max(f[i<<1],f[i<<1|1]);
    }
    ll query(ll l,ll r){
        ll ans=0;
        //rep(i,l,r)ans=std::max(ans,f[i+n]);
        //return ans;
        for(l+=n-1,r+=n+1;(l^r)>>1;l>>=1,r>>=1)~l&1&&(ans=std::max(ans,f[l^1])),r&1&&(ans=std::max(ans,f[r^1]));
        return ans;
    }
}ds;
int main(){
    IO();
    ll n=readll(),m=readll(),q=readll();
    //if(q==151)q=10;
    rep(i,1,n)np[p[i]=readll()]=i;
    rep(i,1,m)u[i]=readll(),v[i]=readll();
    rep(i,1,q)if(readll()==2)t[e[i]=readll()]=i;
    else qv[i]=readll();
    rep(i,1,n)f[i]=i;
    rep(i,1,m)if(!t[i]){
        const ll u=find(::u[i]),v=find(::v[i]);
        if(u==v)continue;
        add(i+n,u),add(i+n,v),f[u]=f[v]=f[i+n]=i+n;
        t[i]=mod;
    }
    per(i,q,1)if(const ll id=e[i]){
        const ll u=find(::u[id]),v=find(::v[id]);
        if(u==v)continue;
        add(id+n,u),add(id+n,v),f[u]=f[v]=f[id+n]=id+n;
    }
    //top=1;
    rep(i,1,n+m)if(find(i)==i)dfs(i,0);
    ref(i,0,20)rep(u,1,n+m)ft[i+1][u]=ft[i][ft[i][u]];
    rep(i,1,n)a[lf[i]]=p[i];
    //rep(i,1,n)printf("%lld\n",a[i]);
    ds.set(n,a);
    rep(i,1,q)if(const ll u=qv[i]){
        ll now=u;
        per(j,20,0)if(ft[j][now]&&t[ft[j][now]-n]>i)now=ft[j][now];
        //ll j=0;while(ft[j][now]&&t[ft[j][now]-n]>i)now=ft[j][now];
        //printf("%lld %lld %lld %lld\n",now,t[now-n],lf[now],rt[now]);
        const ll l=lf[now],r=rt[now],ans=ds.query(l,r);
        writell(ans,10);
        if(ans)p[np[ans]]=0,ds.update(lf[np[ans]],0);
    }
    return 0;
}
/*
3 2 4
1 2 3
1 2
2 3
1 1
2 1
1 1
1 1
*/