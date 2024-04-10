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
cll N=4e5+7,mod=998244353,iv2=(mod+1)/2,g=3,iz=1<<21,oz=1<<22;
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
cll IO_res=IO(),T=1;
aN next,to,head,a,b,s,sz;
struct hash{
    static cll m=9260817;
    ull k[m];
    ll v[m];
    mutable ll l;
    ll g(ull&b)const{
        if(b==0)b=35243241;
        if(k[l]==b)return l;
        ll n=b%m,x=0;
        while(k[n]&&k[n]!=b)n=(n+2*x+++1)%m;
        return l=n;
    }
}dt;
struct map{
    map():id(0){}
    ull id;
    ll t;
    aN w;
    ll getans(ull b)const{
        ull d=id+b;
        cll n=dt.g(d);
        return dt.k[n]?dt.v[n]:0;
    }
    ll&operator[](ull b){
        ull d=id+b;
        cll n=dt.g(d);
        return!dt.k[n]?w[++t]=n,dt.k[n]=d,dt.v[n]=0:dt.v[n];
    }
    void clear(){
        while(t)dt.k[w[t--]]=0;
    }
};
map t;
ll cnt;
void add(cll u,cll v){
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
//aN dfn,end,st;
//ll top;
void dfs0(cll u,cll fa){
    sz[u]=1,s[u]=0,b[u]=b[fa]^a[u];
    //st[dfn[u]=++top]=u;
    rev(i,u,v)if(v^fa)dfs0(v,u),sz[u]+=sz[v],sz[v]>sz[s[u]]&&(s[u]=v);
    //end[u]=top;
}
int check(cll u,cll fa,cll x){
    if(a[u]==-1)return 0;
    //printf("%lld %lld %lld %lld %lld %lld\n",u,fa,x,b[u],b[u]^x,t[b[u]^x]);
    if(t.getans(b[u]^x))return 1;
    //t[b[u]]=1;
    rev(i,u,v)if(v^fa&&check(v,u,x))return 1;
    return 0;
}
void erase(cll u,cll fa){
    if(a[u]==-1)return;
    t[b[u]]=0;
    rev(i,u,v)if(v^fa)erase(v,u);
}
void insert(cll u,cll fa){
    if(a[u]==-1)return;
    t[b[u]]=1;
    rev(i,u,v)if(v^fa)insert(v,u);
}
//aN vis;
/*ll check(cll u,cll fa){
    static aN ss;
    ll t=1;ss[1]=u;
    rev(s,u,v)if(v^fa){
        rep(j,1,t){
            cll w=ss[j];
            rep(i,dfn[v],end[v])rep(j,dfn[w],(w==u?dfn[w]:end[w]))if(!vis[i]&&!vis[j]&&(b[st[i]]^b[st[j]])==a[u])return 0;
        }
        ss[++t]=v;
    }
    return 1;
}
void erase(cll u){
    rep(i,dfn[u],end[u])vis[i]=1;
}
ll dfs3(cll u,cll fa){
    ll now=0;
    rev(i,u,v)if(v^fa)now+=dfs3(v,u);
    if(!check(u,fa))return erase(u),now+1;
    return now;
}*/
ll dfs2(cll u,cll fa){
    ll now=0;
    rev(i,u,v)if(v^fa&&v^s[u])now+=dfs2(v,u),erase(v,u);
    //rep(i,0,1000)assert(t[i]==0);
    now+=s[u]?dfs2(s[u],u):0;
    if(t.getans(b[u]^a[u]))return /*printf("u=%lld\n",u),*/erase(u,fa),a[u]=-1,now+1;
    t[b[u]]=1;
    rev(i,u,v)if(v^fa&&v^s[u]){
        if(check(v,u,a[u]))return /*printf("u=%lld\n",u),*/erase(u,fa),a[u]=-1,now+1;
        insert(v,u);
    }
    return now;
}
std::mt19937 rd;
void calc(){
    cll n=readll();
    rep(i,1,n)a[i]=readll();
    //cll n=500;
    //rep(i,1,n)a[i]=rd();
    t.clear();
    memset(head,cnt=0,(n+1)<<3);
    //memset(vis,top=0,(n+1)<<3);
    //writell(n,10);
    //rep(i,1,n)writell(a[i],i==n?10:32);
    rep(i,2,n){
        cll u=readll(),v=readll();
        //cll u=i,v=rand()%(i-1)+1;
        //writell(u),writell(v,10);
        add(u,v),add(v,u);
    }
    dfs0(1,0);
    //cll f=dfs3(1,0);
    cll g=dfs2(1,0);
    //writell(f);
    writell(g,10);
    //assert(f==g);
    //rep(i,1,n)printf("%lld %lld %lld\n",a[i],b[i],s[i]);
    //writell(dfs2(1,0),10);
}
int main(){
    rep(i,1,T)calc();
    return 0;
}
/*
10
7 4 6 7 6 6 7 5 7 5
8 7
4 5
9 6
2 5
4 8
9 10
4 3
9 4
1 8
*/