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
const ll N=1e6+7,mod=1e9+7,iz=1<<21,oz=1<<21;
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
int readchar(int l=33,int r=12){
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
aN next,to,head,f,w,dfn,dis,a,st[22];
ll top,cnt;
void add(ll u,ll v,ll c=0){
    next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c;
}
ll find(ll u){
    return u^f[u]?f[u]=find(f[u]):f[u];
}
struct edge{
    ll u,v,c;
    void read(){
        u=readll(),v=readll(),c=readll();
    }
    void calc0(){
        add(u,v,c),add(v,u,c);
    }
    void calc2(){
        c+=dis[u]+dis[v];
    }
    operator ll()const{
        return c;
    }
}p[N];
struct node{
    ll dis,u;
    operator ll()const{
        return-dis;
    }
};
std::priority_queue<node>qu;
int qm(ll&a,ll b){
    return a>b?a=b,1:0;
}
ll max(ll x,ll y){
    return x>y?x:y;
}
void dfs(ll u){
    st[0][dfn[u]=++top]=a[u];
    rev(i,u,v)dfs(v),st[0][++top]=a[u];
}
int main(){
    IO();
    const ll n=readll(),m=readll(),k=readll(),q=readll();
    rep(i,1,n)f[i]=i;
    rep(i,1,m)p[i].read(),p[i].calc0();
    memset(dis,0x3f,sizeof dis);
    rep(i,1,k)qu.push((node){dis[i]=0,i});
    while(!qu.empty()){
        const ll u=qu.top().u,d=dis[u];
        qu.pop();
        rev(i,u,v)if(qm(dis[v],d+w[i]))qu.push((node){dis[v],v});
        while(!qu.empty()&&dis[qu.top().u]!=qu.top().dis)qu.pop();
    }
    memset(head,cnt=0,(n+1)<<3);
    rep(i,1,m)p[i].calc2();
    std::sort(p+1,p+m+1);
    rep(i,1,m){
        const ll u=find(p[i].u),v=find(p[i].v);
        if(u==v)continue;
        a[f[u]=f[v]=f[n+i]=n+i]=p[i].c,add(n+i,u),add(n+i,v);
    }
    dfs(find(1));
    rep(i,0,20)rep(u,1,top-(2<<i)+1)st[i+1][u]=max(st[i][u],st[i][u+(1<<i)]);
    rep(i,1,q){
        const ll u=readll(),v=readll();
        ll l=dfn[u],r=dfn[v];
        if(l>r)std::swap(l,r);
        const ll lg=__builtin_clzll(r-l+1)^63;
        writell(max(st[lg][l],st[lg][r-(1<<lg)+1]),10);
    }
    return 0;
}