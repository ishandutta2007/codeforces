#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout);
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
aN next,to,head,c,f,g,z,v[2],cl,ans;
ll cnt,sum;
void add(ll u,ll v){
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
int qm(ll&a,ll b){
    return a>b?a=b,1:0;
}
void dfs0(ll u,ll fa){
    g[u]=mod;
    rev(i,u,v)if(v^fa)dfs0(v,u),qm(g[u]+=f[v],f[u]+g[v]),f[u]+=f[v];
    if(!next[head[u]]&&fa)g[u]=0,f[u]=c[u];
    cl[u]=qm(f[u],g[u]+c[u]);
}
void dfs2(ll u,ll fa,ll x){//x=0/1 -> f/g
    //printf("%lld %lld %lld\n",u,fa,x);
    if(v[x][u])return;
    v[x][u]=1;
    switch(x){
        case 0:
            if(!cl[u])rev(i,u,v)if(v^fa)dfs2(v,u,0);
            if(f[u]==g[u]+c[u])return ans[u]=1,x=1,sum++,dfs2(u,fa,1);
            break;
        case 1:
            ll min=0,s=0;
            rev(i,u,v)if(v^fa)qm(min,g[v]-f[v]);
            rev(i,u,v)if(v^fa&&g[v]-f[v]==min)dfs2(v,u,1),s=s?-1:v;
            rev(i,u,v)if(v^fa&&v^s)dfs2(v,u,0);
    }
}
int main(){
    IO();
    const ll n=readll();
    rep(i,1,n)c[i]=readll();
    ll u,v;
    rep(i,2,n)u=readll(),v=readll(),add(u,v),add(v,u);
    dfs0(1,0),writell(f[1]),dfs2(1,0,0),writell(sum,10);
    rep(i,1,n)if(ans[i])writell(i);
    return 0;
}