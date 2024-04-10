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
cll N=1.2e6+7,mod=998244353,iv2=(mod+1)/2,g=3,iz=1<<21,oz=1<<22;
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
cll IO_res=(IO(),gc=getchar,0),n1=readll(),n2=readll(),m=readll(),T=readll();
aN next,to,head,w,x,cur,q,dis,p,z,vis;
ll cnt=1;
void add_(cll u,cll v,cll c,cll id){
    next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c,x[cnt]=id;
}
void add(cll u,cll v,cll w,cll id=0){
    add_(u,v,w,id),add_(v,u,0,id);
}
int bfs(cll s,cll e,cll n){
    ll t=1;
    memset(dis,-1,(n+1)<<3),memcpy(cur,head,(n+1)<<3),q[1]=s,dis[s]=0;
    rep(h,1,t){
        cll u=q[h];
        rev(i,u,v)if(w[i]&&!~dis[v])dis[q[++t]=v]=dis[u]+1;
    }
    //rep(i,0,n)printf("%lld\n",dis[i]);
    return dis[e]!=-1;
}
ll dfs(cll u,cll t,cll f){
    //printf("%lld %lld %lld\n",u,t,f);
    static aN&head=cur;
    if(u==t)return f;
    ll n=f;
    rev(i,u,v)if(dis[v]==dis[u]+1){
        cll z=dfs(v,t,std::min(w[i],n));
        w[i]-=z,w[i^1]+=z,n-=z;
        if(!n)break;
        head[u]=next[i];
        if(w[i])dis[v]=mod;
    }
    return f-n;
}
int main(){
    ll s=0,e=n1+n2+1;
    rep(i,1,m){
        cll u=readll(),v=readll();
        add(u,v+n1,mod,i);
    }
    rep(i,1,n1)add(s,i,1);
    rep(i,1,n2)add(i+n1,e,1);
    ll f=0;
    while(bfs(s,e,e))f+=dfs(s,e,mod);
    ll sum=0;
    rep(u,1,n1+n2)rev(i,u,v)if(w[i]==1&&w[i^1]==mod-1)sum+=x[i],p[u]=v,p[v]=u,z[u]=z[v]=x[i];
    bfs(s,e,e);
    ll t=0;
    rev(i,s,v)if(dis[v]==-1)q[++t]=v;
    rev(i,e,v)if(dis[v]!=-1)q[++t]=v;
    //rep(i,1,t)writell(q[i]);
    rep(i,1,T)if(readll()==1)writell(1,10),writell(q[t]<=n1?q[t]:-(q[t]-n1),10),writell(sum-=z[q[t--]],10),fout(),fflush(stdout);
    else{
        writell(t,10);
        rep(i,1,t)writell(z[q[i]],i==t?10:32);
        fout(),fflush(stdout);
    }
    return 0;
}
/*
4 3 4 4
2 2
3 1
1 2
4 3
1
2
1
2
*/