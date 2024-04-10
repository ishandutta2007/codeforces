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
cll N=1e6+7,mod=998244353,iz=1<<21,oz=1<<22;
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
cll IO_res=IO(/),T=readll();
ll p[13],vis[13],f[13][24][13][13],iv[24];
ll inv(ll a,ll b=mod){
    ll x=1,y=0;
    cll m=b;
    while(b){
        cll t=a/b,lb=b,ly=y;
        y=x-t*y,x=ly,b=a-t*b,a=lb;
    }
    return(x+m)%m;
}
void calc(){
    cll n=readll(),k=readll(),x=readll();
    ll sum=0;
    rep(j,1,22){
        ll now=1;
        if(j>n)break;
        rep(i,1,x){
            if(i>=n||i>=j)break;
            cll g=f[i][j][k][x];
            now=now*(n+mod-j+i)%mod*iv[i]%mod;
            sum+=now*g%mod;
        }
    }
    writell(sum%mod);
}
cll d=13;
void dfs(cll u,cll a,cll b){
    //printf("%lld %lld %lld\n",u,a,b);
    if(a>d-1)return;
    ll max=0;
    rep(i,1,d-1)if(vis[i])max=i;
    if(max&&max==u-1){
        if(u>2){
            //assert(a>=u-1-1);
            //if(!b){rep(i,1,u-1)printf("%lld ",p[i]);puts("");}
            //assert(b),assert(a);
            ++f[1][u-1][a][b];
        }
        return;
    }
    ll gs=u-1;
    rep(i,1,d-1)if(!vis[i]){
        vis[i]=1,p[u]=i;
        dfs(u+1,a+gs,b+(i<p[u-1]));
        vis[i]=0;
    }else gs--;
}
int main(){
    dfs(1,0,0);
    //rep(i,1,11)rep(j,1,11)rep(k,1,11)rep(l,1,11)
    //ll i=1,j=10,k=9,l=1;
    //printf("f[%lld][%lld][%lld][%lld]=%lld\n",i,j,k,l,f[i][j][k][l]);
    rep(i,1,23)iv[i]=inv(i);
    rep(i,1,10){
        rep(a,0,12)rep(b,0,12)
        rep(c,0,12-a)rep(d,0,12-b)
        rep(e,0,22)rep(f,0,22-e)
        ::f[i+1][e+f][a+c][b+d]=(::f[i+1][e+f][a+c][b+d]+::f[i][e][a][b]*::f[1][f][c][d])%mod;
    }
    rep(i,1,T)calc();
    return 0;
}