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
cll N=1e6+7,mod=1e9+7,iv2=(mod+1)/2,iz=1<<21,oz=1<<22;
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
#define $1(x...)x
#define $2(x...)x
cll IO_res=IO(/),T=1;
aN ift,ft;
ll inv(ll a,ll b=mod){
    ll x=1,y=0;
    cll m=b;
    while(b){
        cll t=a/b,lb=b,ly=y;
        b=a-t*b,a=lb,y=x-t*y,x=ly;
    }
    return x<0?x+m:x;
}
ll C(cll a,cll b){
    return b<0||b>a?0:ft[a]*ift[b]%mod*ift[a-b]%mod;
}
void init(){
    cll n=1e6;
    ll x=ft[0]=1;
    rep(i,1,n)ft[i]=x=x*i%mod;
    x=inv(x);
    per(i,n,0)ift[i]=x,x=x*i%mod;
}
aN next,to,head,s,f,b;
ll cnt,n;
void add(cll u,cll v){
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
void dfs(cll u,cll fa){
    //printf("%lld %lld\n",u,fa);
    s[u]=1,f[u]=fa;
    rev(i,u,v)if(v^fa)dfs(v,u),s[u]+=s[v];
}
ll sz(cll u,cll v){
    return v==f[u]?n-s[u]:s[v];
}
void calc(){
    cll n=::n=readll(),k=readll();
    rep(i,2,n){
        cll u=readll(),v=readll();
        add(v,u),add(u,v);
    }
    dfs(1,0);
    ll sum=0;
    rep(i,0,n)b[i]=C(i,k);
    rep(u,1,n){
        ll s=0;
        rev(i,u,v)s=(s+b[sz(u,v)])%mod;
        s=mod-s;
        rev(i,u,v){
            cll c=sz(u,v);
            //printf("%lld %lld %lld %lld\n",u,v,c,f[2]);
            sum=(sum+c*(b[n-c]+s+b[c])%mod*(n-c))%mod;
        }
        sum=(sum+(b[n]+s)*n)%mod;
    }
    writell(sum,10);
}
int main(){
    init();
    rep(i,1,T)calc();
    return 0;
}