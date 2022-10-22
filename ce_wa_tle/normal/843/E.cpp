#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=1e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
typedef ll aN[N];
char is[iz],*i1=is,*i2=is,os[oz],*o1=os,*o2=os;
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
aN head,to,next,w,cur,u,v,p,ys,dis,q;
ll cnt=1;
static inline void add_(cll u,cll v,cll c){
    next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c;
}
static inline void add(cll u,cll v,cll c,cll d){
    //printf("%lld %lld %lld %lld\n",u,v,c,d);
    add_(u,v,c),add_(v,u,d);
}
static inline int bfs(cll s,cll e,cll n){
    memcpy(cur,head,(n+1)<<3),memset(dis,-1,(n+1)<<3),dis[q[1]=s]=0;
    rfor(ll h=1,t=1,u;u=q[h],h++<=t;)rev(i,u,v)if(w[i]&&!~dis[v])dis[q[++t]=v]=dis[u]+1;
    return~dis[e];
}
static inline void change(cll x,cll l,cll r){
    p[u[x]]-=l,p[v[x]]+=l,ys[x<<1]+=l,w[x<<1]=r-l,w[x<<1|1]=0;
}
ll dfs(cll u,cll t,ll fl){
    if(u==t)return fl;
    ll now=fl;
    rfor(ll i=cur[u],v;v=to[i],i;i=next[i])if(dis[v]==dis[u]+1){
        cll f=dfs(v,t,std::min(w[i],now));
        now-=f,w[i]-=f,w[i^1]+=f;
        if(!now)break;
        if(w[i])dis[v]=mod;
    }
    return fl-now;
}
int main(){
    IO();
    cll n=readll(),m=readll(),s=readll(),t=readll();
    rep(i,1,m){
        cll u=::u[i]=readll(),v=::v[i]=readll();
        readll()?add(u,v,1,mod):add(u,v,mod,0);
    }
    ll fl=0;
    while(bfs(s,t,n))fl+=dfs(s,t,mod);
    writell(fl,10);
    //exit(0);
    memset(dis,0,(n+1)<<3),dis[q[1]=s]=1;
    rfor(ll h=1,t=1,u;u=q[h],h++<=t;)rev(i,u,v)if(w[i]&&!dis[v])dis[q[++t]=v]=1;
    rep(i,1,m)if(w[i<<1]+w[i<<1|1]==mod+1){
        if(dis[u[i]]&&!dis[v[i]])change(i,1e6,1e6);//,puts("???");
        else change(i,1,mod);
    }else change(i,0,0);
    //memset(dis,0,(n+1)<<3),dis[q[1]=s]=1;
    //rfor(ll h=1,t=1,u;u=q[h],h++<=t;)rev(i,u,v)if(w[i]&&!dis[v])dis[q[++t]=v]=1,printf("v=%lld\n",v);
    add(t,s,mod,0);
    cll ls=n+1,lt=n+2;
    fl=0;
    //rep(i,1,n)printf("p[%lld]=%lld\n",i,p[i]);
    rep(i,1,n)if(p[i]>0)add(ls,i,p[i],0),fl-=p[i];else add(i,lt,-p[i],0);
    //printf("%lld\n",fl);
    while(bfs(ls,lt,n+2))fl+=dfs(ls,lt,mod);
    //printf("%lld\n",fl);
    assert(!fl);
    rep(i,1,m)assert(w[i<<1|1]>=0),writell(ys[i<<1]+w[i<<1|1]),writell(!(w[i<<1]+w[i<<1|1])?1e6:1e9,10);
    return 0;
}