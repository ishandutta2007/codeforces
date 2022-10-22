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
int qm(ll&a,ll b){
    return a>b?a=b,1:0;
}
struct sgt{
    aN f,t;
    ll n,m;
    void set(ll n_,ll*a){
        m=2ll<<(63^__builtin_clzll((n=n_+3))),
        memcpy(f+m+1,a,n_<<3),
        memset(t,0,(m+n+1)<<3);
        per(i,m,1)f[i]=std::min(f[i<<1],f[i<<1|1]);
    }
    void update(ll l,ll r,ll c){
        for(l+=m,r+=m+2;(l^r)>>1;l>>=1,r>>=1)
        ~l&1&&(t[l^1]+=c),f[l>>1]=std::min(f[l]+t[l],f[l^1]+t[l^1]),
         r&1&&(t[r^1]+=c),f[r>>1]=std::min(f[r]+t[r],f[r^1]+t[r^1]);
    }
    ll query(ll l,ll r)const{
        ll lans=mod,rans=mod;
        for(l+=m,r+=m+2;(l^r)>>1;l>>=1,r>>=1)
        lans+=t[l],~l&1&&qm(lans,f[l^1]+t[l^1]),
        rans+=t[r], r&1&&qm(rans,f[r^1]+t[r^1]);
        lans=std::min(lans+t[l],rans+t[r]);
        red(i,l>>1)lans+=t[i];
        return lans;
    }
}t;
aN lst,a,c;
ll f[111][35555];
int main() {
//    IO();
    ll n=readll(),k=readll(),x;
    rep(i,1,n)x=readll(),lst[i]=c[x],c[x]=i;
    memset(f[0],0x3f,sizeof f);
    f[0][0]=0;
    rep(i,1,k){
        t.set(n,f[i-1]);
        f[i][0]=f[0][1];
        rep(j,1,n){
            if(lst[j])t.update(0,lst[j]-1,j-lst[j]);
            f[i][j]=t.query(0,j-1);
        }
    }
    writell(f[k][n]);
    return 0;
}