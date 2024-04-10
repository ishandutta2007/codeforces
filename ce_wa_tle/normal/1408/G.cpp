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
const ll N=3e6+7,mod=998244353,iz=1<<21,oz=1<<22;
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
    for(;c<48||c>57;c=gc());
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
aN f,ne,s1,s2,sz,fz,head,to,next;
ll cnt;
void add(ll u,ll v){
    //printf("%lld->%lld\n",u,v);
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
ll find(ll u){
    return u^f[u]?f[u]=find(f[u]):u;
}
int sum[3211][1611];
void dfs(ll u){
    //printf("%lld==%lld\n",u,sz[u]);
    const ll flag=sz[u];
    sz[u]=0;
    if(head[u])sum[u][0]++;
    else sz[u]++;
    rev(i,u,v){
        dfs(v);
        rep(i,0,sz[u])rep(j,0,sz[v])fz[i+j]=(fz[i+j]+1ll*sum[u][i]*sum[v][j])%mod;
        sz[u]+=sz[v];
        rep(i,0,sz[u])sum[u][i]=fz[i],fz[i]=0;
    }
    if(flag)sum[u][1]++;
    //rep(i,0,sz[u])printf("sum[%lld][%lld]=%lld\n",u,i,sum[u][i]);
}
int main(){
    IO();
    const ll n=readll(),m=n*n;
    //ll now=0;
    rep(i,1,n)rep(j,1,n)ne[readll()/*i<=j?0:++now*/]=(i-1)*n+j;
    rep(i,1,n)f[i]=i,sz[i]=1,s1[i]=1;
    ll cnt=n;
    rep(i,1,n*(n-1)/2){
        ll u=find((ne[i]-1)/n+1),v=find((ne[i]-1)%n+1),id=ne[i]+n;
        if(u!=v)id=++cnt,f[v]=f[u]=f[id]=id,s1[id]=s1[u]+s1[v],s2[id]=s2[u]+s2[v],add(id,u),add(id,v),u=id;
        ++s2[u]==s1[u]*(s1[u]-1)/2&&sz[u]++;
    }
    ll rt=0;
    rep(i,1,n+m)if(find(i)==i)rt=i;
    dfs(rt);
    rep(i,1,n)writell(sum[rt][i]);
    return 0;
}