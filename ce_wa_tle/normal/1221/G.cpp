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
const ll N=2.2e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
ll d[44];
ll col[44],f[1<<20],g[1<<20],e[1<<20],ds[1<<20];
int dfs(ll u,ll c){
    col[u]=c;
    ll flag=1;
    rep(v,1,40)if(d[u]>>v&1)flag&=col[v]?col[v]!=c:dfs(v,c^1);
    return flag;
}
int main(){
    IO();
    const ll n=readll(),m=readll();
    if(!m)return!myputs("0");
    ll u,v,w=0,ws=1,dd=0;
    rep(i,1,m)u=readll()-1,v=readll()-1,d[u]|=1ll<<v,d[v]|=1ll<<u;
    ref(i,0,n)if(!col[i])ws&=dfs(i,2),dd+=!d[i],w++;
    //printf("%lld %lld\n",w,ws);
    ll sum=(1ll<<n)+(2ll<<dd)+((ws-1)<<w);
    const ll s=n/2,h=n-s;
    ref(i,0,s)ds[1<<i]=d[i],f[1<<i]=1;
    f[0]=g[0]=1;
    ref(i,0,1<<s)f[i]=f[i&~-i]&&!((i&~-i)&ds[i&-i]);
    ref(j,0,s)ref(i,0,1<<(s-1))f[(i+(i>>j<<j))|(1<<j)]+=f[i+(i>>j<<j)];
    ref(i,0,h)ds[1<<i]=d[i+s]>>s,g[1<<i]=1,e[1<<i]=d[i+s];
    w=0;
    ref(i,0,1<<h)e[i]=e[i&-i]|e[i&~-i],(g[i]=g[i&~-i]&&!((i&~-i)&ds[i&-i]))&&(w+=f[~e[i]&((1<<s)-1)]);
    //writell(sum);
    writell(sum-2*w);
    return 0;
}