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
cll N=2e5+7,mod=998244353,iv2=(mod+1)/2,g=3,iz=1<<21,oz=1<<22;
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
cll IO_res=IO(/),T=1;
ll pow(ll a,cll b,cll p=mod){
    ll res=1;
    red(i,b){
        if(i&1)res=res*a%p;
        a=a*a%p;
    }
    return res;
}
ll inv(ll a,ll b=mod){
    ll x=1,y=0;
    cll m=b;
    while(b){
        cll t=a/b,lb=b,ly=y;
        b=a-t*b,a=lb,y=x-t*y,x=ly;
    }
    return x<0?x+m:x;
}
namespace mypoly{
    namespace inside{
        typedef ull ll,aN[1<<20|7];
        typedef const ll cll;
        aN r,w,a;
        void init(ll z){
            cll n=z<<1,h=pow(g,(mod-1)/n);
            rfor(ll*i=w+z,x=1;i!=w+n;)*i++=x,x=x*h%mod;
            rfor(ll*i=r+z,*j=r+z;i!=r+n;)*i++=*j>>1,*i++=(z|*j++)>>1;
            rfor(ll*i=w+z-1,*j=w+n-2;i!=w;)*i--=*j--,j--;
            rfor(ll*i=r+z-1,*j=r+n-2;i!=r;)*i--=*j--,j--;
        }
        void ntt(ll*t,cll*s,cll n){
            rfor(cll*i=s,*j=r+n;i!=s+n;)a[*j++]=*i++;
            rfor(ll i=1;i!=n;i<<=1){
                rfor(ll*j=a;j!=a+n;j+=i<<1)rfor(ll*x=j,*y=j+i,*z=w+i,t;x!=j+i;)
                t=*z++**y%mod,*y++=*x+mod-t,*x+++=t;
                if(i==262144)rfor(ll*i=a;i!=a+n;)*i++%=mod;
            }
            rfor(ll*i=t,*j=a;i!=t+n;)*i++=*j++%mod; 
        }
        void itt(ll*t,cll*s,cll n){
            rfor(cll*i=s,*j=r+n;i!=s+n;)a[*j++]=*i++;
            rfor(ll i=1;i!=n;i<<=1){
                rfor(ll*j=a;j!=a+n;j+=i<<1)rfor(ll*x=j,*y=j+i,*z=w+i,t;x!=j+i;)
                t=*z++**y%mod,*y++=*x+mod-t,*x+++=t;
                if(i==262144)rfor(ll*i=a;i!=a+n;)*i++%=mod;
            }
            cll mul=mod-(mod-1)/n;
            a[n]=a[0];
            rfor(ll*i=t,*j=a+n;i!=t+n;)*i++=*j--*mul%mod; 
        }
    }
    using inside::init;
    using inside::ntt;
    using inside::itt;
}
//__attribute__((constructor))
void init_calc(){
    ull a[]={1,2,3,4,5,6,7,8};
    mypoly::init(8);
    mypoly::ntt(a,a,8);
    //mypoly::ntt(a,a,8);
    mypoly::itt(a,a,8);
    ref(i,0,8)writell(a[i],i==7?10:32);
    exit(0);
}
mypoly::inside::aN a;
void calc(){
    //cll n=15,k=200000,f=198756;
    cll n=readll(),k=readll(),f=readll();
    cll z=4<<(31^__builtin_clz(k));
    a[k]=1;
    rep(i,1,n){
        using namespace mypoly;
        ll x=0;
        per(i,z,0)x=(x+a[i])%mod,a[i]=i<=k?x:0;
        rep(i,0,k)a[i]=a[i]*(k+1-i)%mod;
        rep(i,0,k)a[i]=(a[i]-a[i+1]+mod)%mod;
        ntt(a,a,z);
        ref(i,0,z)a[i]=a[i]*a[i]%mod;
        itt(a,a,z);
    }
    writell(a[f]);
}
int main(){
    mypoly::init(1<<19);
    rep(i,1,T)calc();
    return 0;
}