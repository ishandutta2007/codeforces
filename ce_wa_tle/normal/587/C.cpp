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
const ll N=1.1e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
struct node{
    ll v[10];
    node(){memset(v,0x3f,sizeof v);}
    void merge(const node&a,const node&b){
        //myputs("???");
        //a.print(10),b.print(10);
        ll p1=0,p2=0;
        ll g[10];
        ref(i,0,10){
            const ll ga=a.v[p1],gb=b.v[p2];
            g[i]=std::min(ga,gb);
            if(ga==g[i])++p1;
            if(gb==g[i])++p2;
        }
        memcpy(v,g,80);
        //print(10);
    }
    void print(ll a,int c=10)const{
        ll t=0;
        ref(i,0,a)if(v[i]<mod)t++;
        writell(t);
        ref(i,0,a)if(v[i]<mod)writell(v[i]);
        c&&pc(c);
    }
}a[N/10],st[17][N/10];
ll top,cnt;
aN next,to,now,head,z,s,dfn,deep,t,f;
void add(ll u,ll v){
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
void dfs0(ll u,ll fa){
    z[u]=1;
    rev(i,u,v)if(v^fa)dfs0(v,u),z[u]+=z[v],z[v]>z[s[u]]&&(s[u]=v);
}
void dfs2(ll u,ll fa){
    t[u]=s[fa]==u?t[fa]:u,st[0][dfn[u]=++top]=a[u],deep[u]=deep[f[u]=fa]+1;
    if(t[u]!=u)a[u].merge(a[u],a[fa]);
    if(s[u])dfs2(s[u],u);
    rev(i,u,v)if(v^fa&&v^s[u])dfs2(v,u);
}
int main(){
    IO();
    const ll n=readll(),m=readll(),q=readll();
    ll u,v;
    rep(i,2,n)u=readll(),v=readll(),add(u,v),add(v,u);
    rep(i,1,m){
        const ll u=readll();
        if(now[u]<=9)a[u].v[now[u]++]=i;
    }
    dfs0(1,0),dfs2(1,0);
    rep(i,0,15)rep(u,1,n-(1<<i))st[i+1][u].merge(st[i][u],st[i][u+(1<<i)]);
    rep(i,1,q){
        ll u=readll(),v=readll();
        const ll lm=readll();
        node now;
        while(t[u]!=t[v]){
            if(deep[t[u]]<deep[t[v]])std::swap(u,v);
            now.merge(now,a[u]),u=f[t[u]];
        }
        if(deep[u]>deep[v])std::swap(u,v);
        u=dfn[u],v=dfn[v];
        const ll lg=__builtin_clzll(v-u+1)^63;
        now.merge(now,st[lg][u]),now.merge(now,st[lg][v-(1<<lg)+1]),now.print(lm);
    }
    return 0;
}