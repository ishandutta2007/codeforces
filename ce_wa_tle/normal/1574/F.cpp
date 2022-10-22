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
const ll N=2e6+7,mod=998244353,iz=1<<21,oz=1<<22;
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
    while((*s=gc())<3);
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
aN in,out,f,sz,a,ans;
ll find(ll u){
    return f[u]^u?f[u]=find(f[u]):u;
}
void add(ll u,ll v){
    //printf("%lld %lld\n",u,v);
    if(u==v)return static_cast<void>(f[find(u)]=0);
    if(out[u]==v)return;
    if(out[u]||in[v]||find(u)==find(v))return static_cast<void>(f[find(u)]=f[find(v)]=0);
    out[u]=v,in[v]=u;
    u=find(u),v=find(v);
    if(!u)std::swap(u,v);
    f[u]=v;
    if(v!=0)sz[v]+=sz[u];
}
ll pow(ll a,ll b,ll p=mod){
    ll res=1;
    red(i,b){
        if(i&1)res=res*a%p;
        a=a*a%p,b>>=1;
    }
    return res;
}
ll inv(ll a,ll b=mod){
    ll x=1,y=0,m=b;
    while(b){
        ll t=a/b;
        std::swap(a-=t*b,b),
        std::swap(x-=t*y,y);
    }
    return(x+m)%m;
}
int qm(ll&a,ll b=mod){
    return a>=b?a-=b,1:0;
}
void NTT(ll*a,ll n,ll x){
    static ll lst;
    static const ll g=3,ng=inv(g);
    static aN wnk,rev;
    if(lst!=n){
        ref(i,0,n)rev[i]=(rev[i>>1]|(n&-(i&1)))>>1;//,printf("%lld->%lld\n",i,rev[i]);
        lst=n;
    }
    ref(i,0,n)if(i<rev[i])std::swap(a[i],a[rev[i]]);
    rfor(ll m=1;m<n;m<<=1){
        const ll wn=pow(~x?g:ng,(mod-1)/m/2);
        ref(i,wnk[0]=1,m)wnk[i]=wnk[i-1]*wn%mod;
        rfor(ll i=0;i<n;i+=m<<1)ref(j,0,m){
            const ll x=a[i|j],y=a[i|j|m]*wnk[j]%mod;
            qm(a[i|j]=x+y),qm(a[i|j|m]=x+mod-y);
        }
    }
    if(!~x){
        ll ivn=inv(n);
        ref(i,0,n)a[i]=a[i]*ivn%mod;
    }
}
int main(){
    IO();
    ll n=readll(),m=readll(),k=readll();
    rep(i,1,k)f[i]=i,sz[i]=1;
    rep(i,1,n){
        ll k=readll(),lst=readll(),x;
        rep(i,2,k)x=readll(),add(lst,x),lst=x;
    }
    rep(i,1,k)if(f[i]==i)a[sz[i]]++;
    rep(i,a[0]=1,m)a[i]=a[i]?mod-a[i]:0;
    //exit(0);
    ans[0]=1;
    //rep(i,0,m)writell(a[i]);pc(10);
    rfor(ll s=1;s<=m;s<<=1){
        //writell(s,10);
        static aN b;
        //a=xxxxxxxxxxxxxx|0000000000000
        //s=xxxxxxx|000000|0000000000000
        memcpy(b,a,s<<4);
        //ref(i,0,s<<2)writell(b[i]);pc(10);
        NTT(b,s<<2,1),NTT(ans,s<<2,1);
        //ref(i,0,s<<2)writell(b[i]);pc(10);
        //ref(i,0,s<<2)writell(ans[i]);pc(10);
        ref(i,0,s<<2)ans[i]=(2+(mod-b[i])*ans[i])%mod*ans[i]%mod;
        //ref(i,0,s<<2)writell(ans[i]);pc(10);
        NTT(ans,s<<2,-1);
        //ref(i,0,s<<2)writell(ans[i]);pc(10);
        memset(ans+(s<<1),0,s<<4);
        //ref(i,0,s<<2)writell(ans[i]);pc(10);
    }
    writell(ans[m]);
    return 0;
}