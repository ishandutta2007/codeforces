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
const ll N=1e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
aN head,to,next,sz;
ll C[111][111],pn[111],f[111][111][2],res[111][2],g[111];
ll cnt=0;
void add(ll u,ll v){
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
int qm(ll&a,ll b=mod){
    return a>=b?a-=b,1:0;
}
void dfs(ll u,ll fa){
    sz[u]=0,f[u][0][0]=f[u][0][1]=1;
    rev(i,u,v)if(v^fa){
        dfs(v,u);
        rep(i,0,sz[u])rep(j,0,sz[v]){
            const ll h=f[u][i][0]*f[v][j][1];
            res[i+j][0]=(res[i+j][0]+h)%mod,
            res[i+j][1]=(res[i+j][1]+f[u][i][1]*f[v][j][1])%mod,
            res[i+j+1][0]=(res[i+j+1][0]+f[u][i][0]*f[v][j][0])%mod,
            res[i+j+1][1]=(res[i+j+1][1]+h+f[u][i][1]*f[v][j][0])%mod;
        }
        sz[u]+=sz[v]+1;
        memcpy(f[u],res,(sz[u]+1)*sizeof(res[0]));
        memset(res,0,(sz[u]+1)*sizeof(res[0]));
    }
}
int main(){
    IO();
    const ll n=readll();
    rep(i,pn[0]=1,n)pn[i]=pn[i-1]*n%mod;
    rep(i,C[0][0]=1,n)rep(j,C[i][0]=1,i)qm(C[i][j]=C[i-1][j]+C[i-1][j-1]);
    ll u,v;
    rep(i,2,n)u=readll(),v=readll(),add(u,v),add(v,u);
    dfs(1,0);
    ref(i,0,n-1)g[i]=pn[n-i-2]*f[1][i][1]%mod;
    g[n-1]=1;
    //ref(i,0,n)printf("g[%lld]=%lld\n",i,g[i]);
    ref(i,0,n){
        ll sum=0;
        ref(j,i,n)sum=(sum+((j^i)&1?-1:1)*C[j][i]*g[j])%mod;
        qm(sum+=mod),writell(sum);
    }
    return 0;
}