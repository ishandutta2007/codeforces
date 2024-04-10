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
aN next,to,head,w,q,cur,n,dis;
ll cnt=1;
void add_(ll u,ll v,ll c){
    next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c;
}
void add(ll u,ll v,ll c){
    add_(u,v,c),add_(v,u,0);
}
int qm(ll&a,ll b){
    return a>=b?a-=b,0:1;
}
int bfs(ll s,ll e,ll n){
    memcpy(cur,head,n<<3),memset(dis,-1,n<<3),dis[q[1]=s]=0;
    rfor(ll h=1,t=1,u;u=q[h++],h<=t+1;)rev(i,u,v)if(w[i]&&!~dis[v])dis[q[++t]=v]=dis[u]+1;
    return~dis[e];
}
ll dfs(ll u,ll e,ll flow){
    static aN&head=cur;
    if(u==e)return flow;
    ll now=flow;
    rev(i,u,v)if(w[head[u]=i]&&dis[v]==dis[u]+1){
        const ll f=dfs(v,e,std::min(w[i],now));
        now-=f,w[i]-=f,w[i^1]+=f;
        if(!now)break;
    }
    return flow-now;
}
int main(){
    IO();
    const ll n=readll(),h=readll(),m=readll(),s=0,g=n*(h+1),e=g+m+1;
    ll sum=h*h*n;
    rep(i,1,n)add(s,i,mod);
    ref(j,0,h)rep(i,1,n)add(j*n+i,(j+1)*n+i,h*h-j*j);
    rep(i,1,m){
        const ll l=readll(),r=readll(),w=readll()+1,id=i+g;
        add(id,e,readll());
        if(w>h)continue;
        rep(j,l,r)add(w*n+j,id,mod);
    }
    while(bfs(s,e,e+1))sum-=dfs(s,e,mod);
    writell(sum);
    return 0;
}