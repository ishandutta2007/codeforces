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
cll IO_res=IO(),n=readll(),k=readll();
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
        typedef const ull cll;
        cll N=8192;
        typedef ull ll,aN[N];
        aN r,w,a;
        void init(cll z){
            cll n=z<<1,h=pow(g,(mod-iv2)/z);
            rfor(ll*i=w+z,x=1;i!=w+n;)*i++=x,x=x*h%mod;
            rfor(ll*i=r+z,*j=r+z;i!=r+n;)*i++=*j>>1,*i++=(z|*j++)>>1;
            rfor(ll*i=w+z-1,*j=w+n-2;i!=w;)*i--=*j--,j--;
            rfor(ll*i=r+z-1,*j=r+n-2;i!=r;)*i--=*j--,j--;
        }
        void ntt(ll*t,cll*s,cll n){
            rfor(cll*i=r+n,*j=s;j!=s+n;)a[*i++]=*j++;
            rfor(ll i=1;i<n;i<<=1)rfor(ll*j=a;j!=a+n;j+=i<<1)
            rfor(ll*x=j,*y=j+i,*z=w+i,t;x!=j+i;)t=*z++**y%mod,*y++=*x+mod-t,*x+++=t;
            rfor(ll*i=t,*j=a;i!=t+n;)*i++=*j++%mod;
        }
        void itt(ll*t,cll*s,cll n){
            rfor(cll*i=r+n,*j=s;j!=s+n;)a[*i++]=*j++;
            rfor(ll i=1;i<n;i<<=1)rfor(ll*j=a;j!=a+n;j+=i<<1)
            rfor(ll*x=j,*y=j+i,*z=w+i,t;x!=j+i;)t=*z++**y%mod,*y++=*x+mod-t,*x+++=t;
            cll mul=mod-(mod-1)/n;
            *t=mul**a%mod;
            rfor(ll*i=t+1,*j=a+n-1;i!=t+n;)*i++=mul**j--%mod;
        }
    }
    using inside::init;
    using inside::ntt;
    using inside::itt;
};
ll sl=0,sumlen=0;
//__attribute__((constructor))
void init(){
    mypoly::init(4);
    ull a[]={1,2,3,4};
    mypoly::ntt(a,a,4);
    mypoly::itt(a,a,4);
    ref(i,0,4)printf("%lld\n",a[i]);
    exit(0);
}
struct poly{
    ll n,m;
    std::vector<std::vector<ull> >val;
    operator ll(){
        return n*sumlen+m*::n;
    }
    void print()const{
        ref(i,0,n){
            ref(j,0,m)writell(val[i][j]);
            pc(10);
        }
    }
    void merge(const poly&a,const poly&b){
        //puts("--------------");
        //a.print(),pc(10);
        //b.print(),pc(10);
        cll n=a.n+b.n-1,m=a.m+b.m-1;
        cll x=2<<(31^__builtin_clz(n)),y=2<<(31^__builtin_clz(m));
        ull c[x][y]={},d[x][y]={};
        ref(i,0,a.n){
            ref(j,0,a.m)c[i][j]=a.val[i][j];
            mypoly::ntt(c[i],c[i],y);
        }
        ref(i,0,b.n){
            ref(j,0,b.m)d[i][j]=b.val[i][j];
            mypoly::ntt(d[i],d[i],y);
        }
        ref(i,0,y){
            ull e[x]={},f[x]={};
            ref(j,0,a.n)e[j]=c[j][i];
            mypoly::ntt(e,e,x);
            ref(j,0,b.n)f[j]=d[j][i];
            mypoly::ntt(f,f,x);
            ref(j,0,x)e[j]=f[j]*e[j]%mod;
            mypoly::itt(e,e,x);
            ref(j,0,n)c[j][i]=e[j];
        }
        this->n=n,this->m=m;
        val.resize(n);
        ref(i,0,n){
            mypoly::itt(c[i],c[i],y);
            val[i]=std::vector<ull>(c[i],c[i]+m);
        }
        //print(),pc(10);
    }
}p[66];
ll q[66],ift[2222],ft[2222],a[66];
int main(){
    mypoly::init(4096);
    ll x=ft[0]=1;
    rep(i,1,2000)ft[i]=x=x*i%mod;
    x=inv(x);
    per(i,2000,0)ift[i]=x,x=x*i%mod;
    rep(i,1,n)a[i]=readll(),sl+=a[i];
    ll sum=0,ivl=inv(sl);
    rep(i,1,n){
        cll x=a[i],len=(x-1)/k+1;
        sumlen+=len-1;
        ull a[len],b[len];
        ll z;
        rep(i,0,(x-1)/k)z=(x-k*i)*ivl%mod,a[i]=i?i&1?(mod-ift[i-1])*pow(z,i-1)%mod:ift[i-1]*pow(z,i-1)%mod:0,
                    b[i]=i&1?(mod-ift[i])*pow(z,i)%mod:ift[i]*pow(z,i)%mod;
        p[i].val.push_back(std::vector<ull>(a,a+len));
        p[i].val.push_back(std::vector<ull>(b,b+len));
        p[i].n=2,p[i].m=len;
    }
    //printf("%lld %lld\n",sumlen,sl);
    ll l=1,r=n,h=1,t=0;
    while(r-l+1+t-h+1>1){
        cll a=l<=r&&(h>t||p[l]<p[q[h]])?l++:q[h++],b=l<=r&&(h>t||p[l]<p[q[h]])?l++:q[h++];
        q[++t]=a,p[a].merge(p[a],p[b]);
    }
    poly res=p[l<=r&&(h>t||p[l]<p[q[h]])?l++:q[h++]];
    ref(j,0,res.m){
        cll c=(sl-j*k)*ivl%mod;
        ll mul=inv(mod+1-c),now=pow(mul,mod-1+j-n+1);
        if(c!=1)ref(i,0,res.n)/*printf("a=%lld n=%lld m=%lld c=%lld now=%lld\n",res.val[i][j],i+j-n,sl-j*k,c,now),*/res.val[i][j]&&(sum=(sum+(mod-res.val[i][j])*ft[i+j-n]%mod*now)%mod),now=now*mul%mod;
    }
    writell(sum);
    return 0;
}