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
const ll N=2.2e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
struct pt{
    ll l,r,w;
    void read(){
        //#define readll() rand()
        l=readll(),r=readll(),w=readll();
        if(l>r)std::swap(l,r);
        //#undef readll
    }
    operator ll()const{
        return r;
    }
}p[N];
aN x;
int qm(ll&a,ll b){
    return a<b?a=b,1:0;
}
struct sgt{
    ll n;
    aN f,g,t;
    #define de if(0)
    void update(ll i){
        const ll s1=f[i<<1]+t[i<<1],s2=f[i<<1|1]+t[i<<1|1];
        if(s1>s2)f[i]=s1,g[i]=g[i<<1];else f[i]=s2,g[i]=g[i<<1|1];
    }
    void set(ll m){
        n=2<<(__builtin_clzll(m+2)^63);
        rep(i,1,m)g[i+n]=i;
        per(i,n-1,1)update(i);
    }
    void update(ll l,ll r,ll c){
        de{
            rep(i,l,r)f[i]+=c;
            return;
        }
        for(l+=n-1,r+=n+1;(l^r)>>1;l>>=1,r>>=1)
        ~l&1&&(t[l^1]+=c),r&1&&(t[r^1]+=c),update(l>>1),update(r>>1);
        red(i,l>>1)update(i);
    }
    ll query(ll&w){
        de{
            w=0;
            ll m=0;
            rep(i,1,n)if(qm(m,f[i]))w=i;
            return m;
        }
        return w=g[1],f[1];
    }
}t;
int main(){
    IO();
    const ll n=readll();
    rep(i,1,n)p[i].read(),x[i*2-1]=p[i].l,x[i*2]=p[i].r;
    std::sort(x+1,x+2*n+1),std::sort(p+1,p+n+1);
    const ll m=std::unique(x+1,x+2*n+1)-x-1;
    t.set(m);
    ll max=0,ml=2e9,mr=2e9,w,h=1;
    rep(i,1,n){
        while(h<=m&&x[h]<=p[i].r)t.update(h,h,x[h]),h++;
        const ll l=std::lower_bound(x+1,x+m+1,p[i].l)-x,r=h-1;
        t.update(1,l,p[i].w);
        if(i==n||p[i].r!=p[i+1].r)qm(max,t.query(w)-x[r])&&(ml=x[w],mr=x[r]);
    }
    writell(max,10),writell(ml),writell(ml),writell(mr),writell(mr);
    return 0;
}