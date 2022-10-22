#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)((*#x!='/'||#x[1])&&(*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)))
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=2.1e6+7,mod=998244353,iz=1<<21,oz=1<<22;
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
void writell(cll u,int c=32){
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
cll IO_res=IO(),n=readll(),m=readll(),k=readll();
aN lx,ly,rx,ry,x;
struct mtx{
    ll l,r,w,c;
    operator ll()const{
        return w;
    }
}p[N];
struct sgt{
    aN f,w,m;
    ll n;
    ll getans(cll u=1)const{
        return f[u]?m[u]:w[u];
    }
    void pushup(cll u){
        cll t=std::min(f[u<<1],f[u<<1|1]);
        f[u<<1]-=t,f[u<<1|1]-=t,f[u]+=t,w[u]=getans(u<<1)^getans(u<<1|1);
    }
    void set(ll n_,cll*a){
        n=2<<(31^__builtin_clz(n_+2));
        rep(i,1,n_)m[i+n]=a[i]^a[i-1];
        per(i,n-1,1)m[i]=m[i<<1]^m[i<<1|1];
    }
    void update(ll l,ll r,cll c){
        for(l+=n-1,r+=n+1;l^r^1;l>>=1,r>>=1,pushup(l),pushup(r))
        ~l&1&&(f[l^1]+=c),r&1&&(f[r^1]+=c);
        red(i,l>>1)pushup(i);
    }
}dt;
int main(){
    rep(i,1,m)x[2*i-1]=lx[i]=readll()-1,ly[i]=readll()-1,x[2*i]=rx[i]=readll(),ry[i]=readll();
    std::sort(x+1,x+2*m+1);
    cll tx=std::unique(x+1,x+2*m+1)-x-1;
    rep(i,1,m){
        cll l=std::lower_bound(x+1,x+tx+1,lx[i])-x,
            r=std::lower_bound(x+1,x+tx+1,rx[i])-x;
        p[2*i-1]=(mtx){l,r,ly[i],1},p[2*i]=(mtx){l,r,ry[i],-1};
    }
    std::sort(p+1,p+2*m+1);
    ll ans=0,lst=0;
    dt.set(tx,x);
    rep(i,1,2*m){
        ans^=dt.getans()&(p[i].w^lst),lst=p[i].w,
        dt.update(p[i].l+1,p[i].r,p[i].c);
    }
    /*ll a[555][555]={};
    rep(i,1,m)rep(x,lx[i]+1,rx[i])rep(y,ly[i]+1,ry[i])a[x][y]=1;
    ll ans2=0;
    rep(i,1,22){rep(j,1,22){
        if(a[i][j])ans2^=(i^(i-1))&(j^(j-1));
        printf("%lld ",(i^(i-1))&(j^(j-1)));}puts("");}
    printf("%lld %lld %lld\n",ans,(2ll<<(31^__builtin_clz(k)))-1,ans2);*/
    myputs(ans&((2<<(31^__builtin_clz(k)))-1)?"Hamed":"Malek");
    return 0;
}
/*
12 1 1
1 2 2 2
*/