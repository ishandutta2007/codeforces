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
const ll N=2.1e5+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
    c&&pc(*t++=c),*t=0;
    return t-s;
}
int myputs(const char*s,int c=10){
    const char*t=s;
    while(*t)pc(*t++);
    c&&pc(c);
    return t-s+(c!=0);
}
aN next,to,head,w,dfn,f,g;
ll cnt,top;
void add(ll u,ll v,ll c){
    next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c;
}
const ll M=1<<17;
typedef ll aM[M];
aM a,b,c,d;
int qm(ll&a,ll b=mod){
    return a>=b?a-=b,1:0;
}
void FWT(ll*a){
    rfor(ll i=1;i<M;i<<=1)rfor(ll j=0;j<M;j+=i<<1)ref(k,0,i){
        const ll x=a[j|k],y=a[i|j|k];
        a[j|k]=x+y,a[i|j|k]=x-y;
    }
    ref(i,0,M)qm(a[i]=a[i]%mod+mod);
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
void dfs(ll u,ll fa){
    dfn[u]=++top,f[u]=fa;
    rev(i,u,v)if(!dfn[v])g[v]=w[i],dfs(v,u);
    else if(v!=fa&&dfn[v]<dfn[u]){
        memset(b,0,sizeof b),memset(d,0,sizeof d);
        rfor(ll now=u;now!=v;now=f[now])b[g[now]]++,d[g[now]]=rand();
        b[w[i]]++,d[w[i]]=rand(),FWT(b),FWT(d);
        ref(i,0,M)a[i]=a[i]*b[i]%mod,c[i]=c[i]*d[i]%mod;
    }
}
int main(){
    IO();
    const ll n=readll(),m=readll();
    ll sum=0;
    static_cast<void>(n);
    rep(i,1,m){
        const ll u=readll(),v=readll(),c=readll();
        sum^=c,add(u,v,c),add(v,u,c);
    }
    ref(i,0,M)a[i]=c[i]=1;
    dfs(1,0);
    FWT(a),FWT(c);
    ref(i,0,M)if(c[i^sum]||a[i^sum]){
        writell(i),writell(a[i^sum]*inv(M)%mod);
        return 0;
    }
    return 0;
}