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
cll N=1e6+7,mod=998244353,g=3,iv2=(mod+1)/2,iz=1<<21,oz=1<<22;
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
cll IO_res=IO(),n=readll(),m=readll();
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
    return(x+m)%m;
}
namespace mypoly{
    namespace inside{
        typedef ull ll,aN[N];
        typedef const ull cll;
        aN r,w,a,b,c,f;
        void init(cll z){
            cll n=z*2,h=pow(g,(mod-iv2)/z);
            rfor(ll*i=w+z,x=1;i!=w+n;)*i++=x,x=x*h%mod;
            rfor(ll*i=r+z,*j=i;i!=r+n;)*i++=*j>>1,*i++=(*j++|z)>>1;
            rfor(ll*i=w+z-1,*j=w+n-2;i!=w;)*i--=*j--,j--;
            rfor(ll*i=r+z-1,*j=r+n-2;i!=r;)*i--=*j--,j--;
        }
        void cpy(ll*a,cll*b,cll n){
            memcpy(a,b,n<<3);
        }
        void set(ll*a,cll m,cll n){
            memset(a+m,0,(n-m)<<3);
        }
        void fix(ll*a,ll*b,cll n){
            cpy(a+n,b+n,n),cpy(b,a,n);
        }
        void ntt(ll*t,cll*s,cll n){
            rfor(cll*i=r+n,*j=s;j!=s+n;)a[*i++]=*j++;
            rfor(ll i=1;i<n;i<<=1){
                rfor(ll*j=a;j!=a+n;j+=i<<1)rfor(ll*x=j,*y=j+i,*z=w+i,t;x!=j+i;)t=*z++**y%mod,*y++=*x+mod-t,*x+++=t;
                if(i==262144)rfor(ll*i=a;i!=a+n;)*i++%=mod;
            }
            rfor(ll*i=t,*j=a;i!=t+n;)*i++=*j++%mod;
        }
        void itt(ll*t,cll*s,cll n){
            rfor(cll*i=r+n,*j=s;j!=s+n;)a[*i++]=*j++;
            rfor(ll i=1;i<n;i<<=1){
                rfor(ll*j=a;j!=a+n;j+=i<<1)rfor(ll*x=j,*y=j+i,*z=w+i,t;x!=j+i;)t=*z++**y%mod,*y++=*x+mod-t,*x+++=t;
                if(i==262144)rfor(ll*i=a;i!=a+n;)*i++%=mod;
            }
            cll mul=mod-(mod-1)/n;
            *t=mul**a%mod;
            rfor(ll*i=t+1,*j=a+n-1;i!=t+n;)*i++=mul**j--%mod;
        }
        void inv(ll*t,cll*s,cll g){
            *c=*f=::inv(*s);
            rfor(ll m=1;m<g;m<<=1){
                cll n=m<<1 ;
                set(f,m,n) ;
                ntt(f,f,n) ;
                ntt(b,s,n) ;
                ref(i,0,n) b[i]=(mod-b[i])*f[i]%mod;
                itt(b,b,n) ;
                set(b,0,m) ;
                ntt(b,b,n) ;
                ref(i,0,n) b[i]=b[i]*f[i]%mod;
                itt(f,b,n) ;
                fix(c,f,m) ;
            }
            cpy(t,c,g);
        }
    }
    using inside::init;
    using inside::ntt;
    using inside::itt;
    using inside::inv;
    using inside::set;
}
//__attribute__((constructor))
void init(){
    mypoly::init(8);
    ull a[8]={1,1,2,3},b[8]={};
    mypoly::ntt(b,a,8);
    mypoly::inv(a,a,4);
    mypoly::ntt(a,a,8);
    ref(i,0,8)a[i]=a[i]*b[i]%mod;
    mypoly::itt(a,a,8);
    ref(i,0,8)printf("%llu\n",a[i]);
    exit(0);
}
int main(){
    mypoly::inside::aN f,g,iv;
    cll y=1<<(31^__builtin_clz(n)),z=y<<1;
    mypoly::init(z);
    mypoly::set(f,0,z);
    mypoly::set(g,0,z);
    mypoly::set(iv,0,z);
    ull x=1;
    rfor(ull*i=iv+1,j=1;i!=iv+n+1;)*i++=x,x=x*j++%mod;
    x=inv(x);
    rfor(ull*i=iv+n,j=n;i!=iv;)*i=*i*x%mod,x=x*j--%mod,i--;
    switch(n&1){
        case 0:{
            cll s=n>>1;
            ll C_mplusi_2i=1;
            f[0]=1;
            rep(i,1,s)C_mplusi_2i=C_mplusi_2i*(m+i)%mod*(m-i+1)%mod*iv[2*i-1]%mod*iv[2*i]%mod,f[i]=C_mplusi_2i,g[i]=f[i]*i%mod;
            mypoly::inv(f,f,y);
            mypoly::ntt(f,f,z);
            mypoly::ntt(g,g,z);
            ref(i,0,z)f[i]=f[i]*g[i]%mod;
            mypoly::itt(f,f,z);
            writell(s&1?f[s]:(mod-f[s])%mod);
            return 0;
        }
        case 1:{
            cll s=n>>1,t=m>>1;
            ll C_tplusi_2i=1;
            f[0]=1,g[0]=t;
            rep(i,1,s)C_tplusi_2i=C_tplusi_2i*(t+i)%mod*(t-i+1)%mod*iv[2*i-1]%mod*iv[2*i]%mod,f[i]=C_tplusi_2i,g[i]=f[i]*(t-i)%mod*iv[2*i+1]%mod;
            //ref(i,0,z)printf("%lld %lld %lld\n",f[i],g[i],i*iv[i]%mod);puts("");
            mypoly::inv(f,f,y);
            //ref(i,0,z)printf("%lld %lld %lld\n",f[i],g[i],i*iv[i]%mod);puts("");
            mypoly::ntt(f,f,z);
            mypoly::ntt(g,g,z);
            ref(i,0,z)f[i]=f[i]*g[i]%mod;
            mypoly::itt(f,f,z);
            mypoly::set(f,y,z);
            f[0]=m-t;
            rep(i,1,s)if(i&1)f[i]=mod-f[i];
            //ref(i,0,z)printf("%lld %lld %lld\n",f[i],g[i],i*iv[i]%mod);puts("");
            mypoly::set(g,0,z);
            rep(i,0,s)g[i]=f[i]*(2*i+1)%mod;
            //ref(i,0,z)printf("%lld %lld %lld\n",f[i],g[i],i*iv[i]%mod);puts("");
            mypoly::ntt(f,f,z);
            ref(i,0,z)f[i]=f[i]*f[i]%mod;
            mypoly::itt(f,f,z);
            mypoly::set(f,y,z);
            per(i,y-1,1)f[i]=mod-f[i-1];
            f[0]=1;
            mypoly::inv(f,f,y);
            //ref(i,0,z)printf("%lld %lld %lld\n",f[i],g[i],i*iv[i]%mod);puts("");
            mypoly::ntt(f,f,z);
            mypoly::ntt(g,g,z);
            ref(i,0,z)f[i]=f[i]*g[i]%mod;
            mypoly::itt(f,f,z);
            mypoly::set(f,y,z);
            writell(f[s]);
            return 0;
        }
    }
    __builtin_unreachable();
}