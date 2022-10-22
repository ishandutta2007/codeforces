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
const ll N=3e6+7,mod=1e9+7,m2=5e8+4,iz=1<<21,oz=1<<22;
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

int qm(ll&a,ll b){
    return a>b?a=b,1:0;
}
#define max min
struct sgt{
    aN f,t;
    ll n,m;
    mutable ll ls,nl,nr;
    void set(ll n_){
        m=2ll<<(63^__builtin_clzll((n=n_+2))),
        memset(f,0,(m+n+1)<<3),
        memset(t,0,(m+n+1)<<3);
    }
    void update(ll l,ll r,ll c){
//        rep(i,l,r)f[i]+=c;return;
//        printf("[%lld %lld]+=%lld\n",l,r,c);
        for(l+=m-1,r+=m+1;(l^r)>>1;l>>=1,r>>=1)
        ~l&1&&(t[l^1]+=c),f[l>>1]=std::max(f[l]+t[l],f[l^1]+t[l^1]),
         r&1&&(t[r^1]+=c),f[r>>1]=std::max(f[r]+t[r],f[r^1]+t[r^1]);
         ls=-1;
    }
    ll query(ll l,ll r)const{
//        ll ans=mod;
//        rep(i,l,r)ans=std::max(ans,f[i]);
//        return ans;
//        printf("q=%lld %lld\n",l,r);
        if(ls!=-1&&nl==l&&nr==r)return ls;
        nl=l,nr=r;
        ll lans=mod,rans=mod;
//        rep(i,1,n+m)printf("[%lld]=%lld\n",i,t[i]);
        for(l+=m-1,r+=m+1;(l^r)>>1;l>>=1,r>>=1)
        lans+=t[l],~l&1&&qm(lans,f[l^1]+t[l^1]),
        rans+=t[r], r&1&&qm(rans,f[r^1]+t[r^1]);
        lans=std::max(lans+t[l],rans+t[r]);
        red(i,l>>1)lans+=t[i];
//        printf("lans=%lld\n",lans);
        return ls=lans;
    }
}t;
aN a,b,c;
void calc() {
    ll n=readll(),m=readll();
    rep(i,1,n)a[i]=readll(),c[i]=i;
    struct cmp_t {
        operator()(ll x,ll y) {
            return a[x]==a[y]?x<y:a[x]<a[y];
        }
        const ll*a;
    } cmp {a};
    std::sort(c+1,c+n+1,cmp);
    rep(i,1,m)b[i]=readll();
    std::sort(b+1,b+m+1),t.set(n+1);
    rep(i,1,n)t.update(i+1,n+1,1);
    ll sum=0,w=1,lst=1;
    rep(j,1,n)if(j==n||a[c[j]]!=a[c[j+1]]){
        #define i c[s]
        ll s=j;
        while(w<=m&&b[w]<a[i])sum+=t.query(1,n+1)*2,w++;
        rep(s,lst,j)t.update(i+1,n+1,-1);
        while(w<=m&&b[w]==a[i])sum+=t.query(1,n+1)*2,w++;//,printf("%lld\n",t.query(1,1));
        rep(s,lst,j)sum+=t.query(i,i);
//        exit(0);
        rep(s,lst,j)t.update(1,i,1);
        lst=j+1;
    }
    writell(sum/2,10);
}
int main() {
//    IO();
    ll T=readll();
    while(T--)calc();
    return 0;
}
/*
6 
6 0
2 4 3 2 1 1
6 1
2 4 3 2 1 1
1
3 4
1 2 3
4 3 2 1
3 3
3 2 1
1 2 3
5 4
1 3 5 3 1
4 3 6 1
5 4
4 4 3 1 1
4 2 4 3
14

*/