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
cll N=1e6+7,mod=998244353,iv2=(mod+1)/2,g=3,iz=1<<21,oz=1<<22;
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
cll IO_res=IO();
//cll n=10000,m=10000;
cll n=readll(),m=readll();
aN next,to,head,id,cur,dis,q,w;
ll cnt=1;
void add_(cll u,cll v,cll c){
    next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c;
}
ll add(cll u,cll v,cll w){
    //printf("%lld -> %lld %lld\n",u,v,w);
    add_(u,v,w);
    cll res=cnt;
    add_(v,u,0);
    return res;
}
int bfs(cll s,cll e,cll n){
    memset(dis,-1,(n+1)<<3);
    memcpy(cur,head,(n+1)<<3);
    ll t=1;
    q[1]=s,dis[s]=0;
    rep(h,1,t){
        cll u=q[h];
        rev(i,u,v)if(w[i]&&!~dis[v])dis[q[++t]=v]=dis[u]+1;
    }
    return dis[e]!=-1;
}
ll dfs(cll u,cll t,cll f){
    static aN&head=cur;
    if(u==t)return f;
    ll n=f;
    rev(i,u,v)if(w[i]&&dis[v]==dis[u]+1){
        cll z=dfs(v,t,std::min(n,w[i]));
        n-=z,w[i]-=z,w[i^1]+=z;
        if(!n)break;
        if(w[i])dis[v]=mod;
        head[u]=next[i];
    }
    return f-n;
}
aN b,s,a,u,v,e;
int main(){
    ll s0=n+2,t0=n+3,s1=0,t1=n+1;
    add(t1,s1,mod);
    
    rep(i,1,n)s[i]=readll();
    rep(i,1,n)a[i]=readll();
    rep(i,1,m){
        u[i]=readll(),v[i]=readll();
        b[u[i]]++,b[v[i]]--,id[i]=add(v[i],u[i],1);
    }
    
    /*rep(i,1,m)u[i]=rand()%n+1,v[i]=rand()%n+1,b[u[i]]++,b[v[i]]--,id[i]=add(v[i],u[i],1);
    rep(i,1,m)if(rand()%2)a[u[i]]++,a[v[i]]--;else a[u[i]]--,a[v[i]]++;
    rep(i,1,n)s[i]=rand()%2;*/
    
    /*rep(i,1,n)writell(s[i],i==n?10:32);
    rep(i,1,n)writell(a[i],i==n?10:32);
    rep(i,1,m)writell(u[i]),writell(v[i],10);*/
    
    rep(i,1,n)if(s[i]){
        if((a[i]^b[i])&1)return!myputs("NO");
        else if(b[i]-a[i]>0)e[t1]-=(b[i]-a[i])/2,e[i]+=(b[i]-a[i])/2;
        else e[s1]-=(b[i]-a[i])/2,e[i]+=(b[i]-a[i])/2;
    }else add(s1,i,mod),add(i,t1,mod);
    ll f=0;
    rep(i,s1,t1){
        if(e[i]>0)add(i,t0,e[i]),f+=e[i];
        if(e[i]<0)add(s0,i,-e[i]);
    }
    //exit(0);
    while(bfs(s0,t0,t0))f-=dfs(s0,t0,mod);
    if(f)return!myputs("NO");
    
    myputs("YES");
    rep(i,1,m)if(w[id[i]]==1)writell(v[i]),writell(u[i],10);
    else writell(u[i]),writell(v[i],10);
    
    /*memset(b,0,sizeof b);
    rep(i,1,m)if(w[id[i]]==1)b[u[i]]++,b[v[i]]--;
    else b[u[i]]--,b[v[i]]++;
    rep(i,1,n)assert(s[i]==0||b[i]==a[i]);*/
    return 0;
}