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
const ll N=3e5+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
aN next,to,head,w,f,dis,q,vis,cur,tag;
ll cnt=1;
void add_(ll u,ll v,ll c,ll d){
    next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c,f[cnt]=d;
}
void add(ll u,ll v,ll c,ll d){
    add_(u,v,c,d),add_(v,u,0,-d);
}
int qm(ll&a,ll b){
    return a>b?a=b,1:0;
}
int spfa(ll s,ll e,ll n){
    memcpy(cur,head,n<<3),memset(dis,0x3f,n<<3),dis[q[1]=s]=0;
    rfor(ll h=1,t=1,u;vis[u=q[h++]]=0,h<=t+1;)rev(i,u,v)if(w[i]&&qm(dis[v],dis[u]+f[i])&&vis[v]!=1)vis[q[++t]=v]=1;
    return dis[e]<mod;
}
ll tim=2,d;
ll dfs(ll u,ll t,ll flow){
    const static aN&head=cur;
    if(u==t)return flow;
    vis[u]=tim;
    ll now=flow;
    rev(i,u,v)if(vis[v]!=tim&&w[i]&&dis[v]==dis[u]+f[i]){
        const ll fl=dfs(v,t,std::min(now,w[i]));
        w[i]-=fl,w[i^1]+=fl,now-=fl;
        if(v!=t&&f[i]>0&&tag[i])add(u,v,1,f[i]+2*d),tag[i]=0;
        if(!now)break;
    }
    return flow-now;
}
int main(){
    IO();
    memset(tag,-1,sizeof tag);
    const ll n=readll(),m=readll(),k=readll(),c=readll(),d=::d=readll(),t=n+k,s=0,e=t*n+n+1;
    ref(s,0,t)add(s*n+1,e,mod,s*c);
    ref(s,1,t)rep(i,1,n)add((s-1)*n+i,s*n+i,mod,0);
    rep(i,1,k)add(s,readll(),1,0);
    rep(i,1,m){
        const ll u=readll(),v=readll();
        ref(s,1,t)add((s-1)*n+u,s*n+v,1,d),add((s-1)*n+v,s*n+u,1,d);
    }
    ll sum=0;
    while(spfa(s,e,e+1))++tim,sum+=dis[e]*dfs(s,e,mod);
    writell(sum);
    return 0;
}