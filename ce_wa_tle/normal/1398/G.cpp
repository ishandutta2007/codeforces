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
const ll N=1.1e6+7,mod=998244353,iz=1<<21,oz=1<<22;
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
    for(;c<48||c>57;c=gc());
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
aN a,b,ans,rev,pw;
ll inv(ll a,ll b=mod){
    const ll m=b;
    ll x=1,y=0;
    while(b){
        const ll t=a/b;
        std::swap(a-=t*b,b),
        std::swap(x-=t*y,y);
    }
    return(x+m)%m;
}
ll pow(ll a,ll b,ll p=mod){
    ll res=1;
    red(i,b){
        if(i&1)res=res*a%p;
        a=a*a%p;
    }
    return res;
}
int qm(ll&a,ll b=mod){
    return a>=b?a-=b,1:0;
}
void ntt(ll*a,const ll n,const ll f){
    static ll lst=0;
    if(n!=1<<lst){
        const ll w=pow(3,(mod-1)/n);
        rep(i,pw[0]=1,n)pw[i]=pw[i-1]*w%mod;
        ref(i,0,n)rev[i]=rev[i>>1]>>1|((n>>1)&-(i&1));
        lst=63^__builtin_clzll(n);
    }
    ref(i,0,n)if(i<rev[i])std::swap(a[i],a[rev[i]]);
    rfor(ll i=1,d=lst-1;i<n;i<<=1,d--)rfor(ll j=0;j<n;j+=i<<1)ref(k,0,i){
        const ll x=a[j|k],y=a[i|j|k]*(f==1?pw[k<<d]:pw[n-(k<<d)])%mod;
        qm(a[j|k]=x+y),qm(a[i|j|k]=x+mod-y);
    }
    if(!~f){
        const ll in=inv(n);
        ref(i,0,n)a[i]=a[i]*in%mod;
    }
}
int main(){
    IO();
    const ll n=readll(),x=readll(),y=readll();
    rep(i,0,n)a[readll()]++;
    rep(i,0,x)b[i]=a[x-i];
    //rep(i,0,32)printf("%lld ",a[i]);puts("");
    //rep(i,0,32)printf("%lld ",b[i]);puts("");
    const ll m=4ll<<(63^__builtin_clzll(x)),lim=5e5;
    //printf("%lld\n",m);
    ntt(a,m,1),ntt(b,m,1);
    //rep(i,0,32)printf("%lld ",a[i]);puts("");
    //rep(i,0,32)printf("%lld ",b[i]);puts("");
    ref(i,0,m)a[i]=a[i]*b[i]%mod;
    //rep(i,0,32)printf("%lld ",a[i]);puts("");
    ntt(a,m,-1);
    //rep(i,0,32)printf("%lld ",a[i]);puts("");
    rep(i,1,x)if(a[x-i])rfor(ll j=i+y;j<=lim;j+=i+y)ans[j]=i+y;
    const ll q=readll();
    rep(i,1,q){
        const ll l=readll();
        writell((l&1?0:ans[l>>1]<<1)?:-1,10);
    }
    return 0;
}