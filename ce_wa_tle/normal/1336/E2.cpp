#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=2e5+7,mod=998244353,iz=1<<21,oz=1<<22;
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
    rfor(ull n=u<0?pc(45),0ull-u:u;n;n/=10)wt[++t]=n%10+48;
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
ll v[55],p[66],C[55][55],a[55];
#define inline __attribute__((always_inline))inline
inline ll inv(ll a,ll b=mod){
    cll m=b;
    ll x=1,y=0;
    while(b){
        cll t=a/b,lb=b,ly=y;
        b=a-t*b,a=lb,y=x-t*y,x=ly;
    }
    return(x+m)%m;
}
inline ll pow(ll a,ll b,cll p=mod){
    ll res=1;
    if(b<0)a=inv(a,p),b=-b;
    red(i,b){
        if(i&1)res=res*a%p;
        a=a*a%p;
    }
    return res;
}
inline void get(ll t){
    ll x=0;
    ll g[512];
    rep(i,0,t)x=a[i]^=x;
    if(t<=18){
        p[x=0]++;
        ref(i,1,1<<t)p[__builtin_popcountll(x^=a[__builtin_ctz(i)])]++;
        return;
    }
    x=g[0]=0;ref(i,1,512)g[i]=x^=a[__builtin_ctz(i)];
    ref(i,x=0,1<<(t-9)){
        ref(k,0,512)p[__builtin_popcountll(x^g[k])]++;
        x^=a[__builtin_ctz(i+1)+9];
    }
}
int main(){
    IO();
    cll n=readll(),m=readll();
    ll k=0;
    rep(i,1,n){
        ll x=readll();
        ref(j,0,m)if(x>>j&1){
            if(!v[j]){
                v[j]=x;k++;break;
            }
            x^=v[j];
        }
    }
    if(k<=m-k+1){
        ll t=0,mul=pow(2,n-k)%mod;
        ref(i,0,m)if(v[i]>>i&1)a[t++]=v[i];
        get(t);
        rep(i,0,m)writell(mul*p[i]%mod);
    }else{
        ref(i,0,m)if(v[i]>>i&1)ref(j,0,i)if(v[j]>>i&1)v[j]^=v[i];
        ref(i,0,m)rep(j,0,m)if(v[i]>>j&1)v[j]|=1ll<<i;
        ll t=0,mul=pow(2,n-m)%mod;
        ref(i,0,m)if(~v[i]>>i&1)a[t++]=v[i]|1ll<<i;
        get(t);
        rep(i,C[0][0]=1,m)rep(j,C[i][0]=1,i)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        rep(i,0,m){
            ll sum=0;
            rep(j,0,m){
                ll s=0;
                rep(k,0,i&&k<=j)s=(s+(k&1?-1:1)*C[j][k]*C[m-j][i-k])%mod;
                sum=(sum+(s+mod)*p[j])%mod;
            }
            writell(sum*mul%mod);
        }
    }
    return 0;
}