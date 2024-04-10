#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
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
aN a,c;
int qm(ll&a,ll b) {
    return a<b?a=b,1:0;
}
struct sgt {
    aN f,t;
    ll n,m;
    void set(ll n_) {
        m=2ull<<(63^__builtin_clzll(n=n_+3));
    }
    void pushup_fa(ll l) {
        f[l>>1]=std::max(f[l]+t[l],f[l^1]+t[l^1]);
    }
    void update(ll l,ll r,ll c) {
        for(l+=m,r+=m+2; (l^r)>>1; l>>=1,r>>=1)
            ~l&1&&(t[l^1]+=c),pushup_fa(l), r&1&&(t[r^1]+=c),pushup_fa(r);
        red(i,l)pushup_fa(i);
    }
    ll query(ll l,ll r)const {
        ll lmax=-mod,rmax=-mod;
        for(l+=m,r+=m+2; (l^r)>>1; l>>=1,r>>=1)
            lmax+=t[l],~l&1&&qm(lmax,t[l^1]+f[l^1]),
                  rmax+=t[r], r&1&&qm(rmax,t[r^1]+f[r^1]);
        qm(lmax+=t[l],rmax+t[r]);
        red(i,l>>1)lmax+=t[i];
        return lmax;
    }
} t1,t2;
int cmp(ll x,ll y) {
    return a[x]<a[y];
}
aN ans;
int main() {
    IO();
    ll n=readll(),lst=1;
    rep(i,1,n)a[c[i]=i]=readll();
    std::sort(c+1,c+n+1,cmp);
    t1.set(n),t2.set(n);
    rep(i,1,n)t1.update(i,n,1),t2.update(i,n,-1);
    rep(s,1,n)if(s==n||a[c[s]]!=a[c[s+1]]) {
        rep(i,lst,s)qm(ans[c[i]],(t1.query(c[i],n)+t2.query(0,c[i]-1))/2);
        rep(i,lst,s)t1.update(c[i],n,-2),t2.update(c[i],n,2);
        rep(i,lst,s)qm(ans[c[i]],(t2.query(c[i],n)+t1.query(0,c[i]-1)-1)/2);
        lst=s+1;
    }
    rep(i,1,n)writell(ans[i]);
    return 0;
}