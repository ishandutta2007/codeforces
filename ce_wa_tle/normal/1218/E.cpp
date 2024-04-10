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
const ll N=2.2e6+7,mod=998244353,iz=1<<21,oz=1<<22;
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
const ll M=32768;
typedef ll aM[M<<1];
aM a,c,w,r;
ll pow(ll a,ll b,ll p=mod){
    ll res=1;
    red(i,b){
        if(i&1)res=res*a%p;
        a=a*a%p;
    }
    return res;
}
ll inv(ll a,ll b=mod){
    ll x=1,y=0;
    const ll m=b;
    while(b){
        const ll t=a/b;
        std::swap(x-=t*y,y),
        std::swap(a-=t*b,b);
    }
    return(x+m)%m;
}
void NTT(ll*b,ll n,ll x){
    static aN a;
    ref(i,0,n)a[i]=b[r[n|i]];
    rfor(ll i=1;i<n;i<<=1)rfor(ll j=0;j<n;j+=i<<1)ref(k,0,i){
        const ll x=a[j|k],y=1ull*a[i|j|k]*w[i|k]%mod;
        a[j|k]+=y,a[i|j|k]=x+mod-y;
    }
    if(~x){
        ref(i,0,n)b[i]=a[i]%mod;
        return;
    }
    const ll in=inv(n);
    b[0]=a[0]%mod*in%mod;
    ref(i,1,n)b[i]=a[n-i]%mod*in%mod;
}
void solve(ll l,ll r){
    if(l==r)return;
    const ll mid=(l+r)>>1,n=2<<(__builtin_clzll(r-l+2)^63);
    solve(l,mid),solve(mid+1,r);
    static aN a,b;
    a[0]=b[0]=1,memcpy(a+1,c+l,(mid-l+1)<<3),memcpy(b+1,c+mid+1,(r-mid)<<3),NTT(a,n,1),NTT(b,n,1);
    ref(i,0,n)a[i]=a[i]*b[i]%mod;
    NTT(a,n,-1),memcpy(c+l,a+1,(r-l+1)<<3),memset(a,0,n<<3),memset(b,0,n<<3);
}
int qm(ll&a,ll b=mod){
    return a>=b?a-=b,1:0;
}
int main(){
    IO();
    const ll n=readll(),k=readll();
    rep(i,1,n)a[i]=readll();
    const ll u=pow(3,(mod-1)/(M<<1));
    ref(j,w[M]=1,M)w[M|j]=w[M|(j-1)]*u%mod;
    per(i,M-1,1)w[i]=w[i<<1];
    ref(j,1,M)r[M|j]=r[M|j>>1]>>1|(M>>1&-(j&1));
    per(i,M-1,1)r[i]=r[i<<1];
    const ll q=readll();
    rep(i,1,q){
        memcpy(c+1,a+1,n<<3);
        const ll op=readll(),q=readll(),l=readll(),r=op==1?l:readll(),d=op==1?readll()-c[l]:readll();
        rep(i,l,r)qm(c[i]+=d);
        rep(i,1,n)qm(c[i]=q+mod-c[i]);
        solve(1,n);
        writell(c[k],10);
    }
    return 0;
}