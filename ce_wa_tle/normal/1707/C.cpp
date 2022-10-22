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
cll N=4e5+7000,mod=998244353,iv2=(mod+1)/2,g=3,iz=1<<21,oz=1<<22;
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
    for(ull n=u<0?pc(45),0ull-u:u;n;n/=10)wt[++t]=n%10^48;
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
aN f,c;
aN next,to,head,/*st[23],*/dfn,end,deep,d,u,v,ft[23];
ll cnt,top=0;
void add(cll u,cll v){
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
ll min2(cll u,cll v){
    return deep[u]<deep[v]?u:v;
}
void dfs(cll u,cll fa){
    //st[0][dfn[u]=++top]=u,
    dfn[u]=++top;
    deep[u]=deep[ft[0][u]=fa]+1;
    rev(i,u,v)if(v^fa)dfs(v,u);//,st[0][++top]=u;
    end[u]=top;
}
void dfs2(cll u,cll fa){
    d[u]+=d[fa];
    rev(i,u,v)if(v^fa)dfs2(v,u);
}
/*ll lca(ll u,ll v){
    if((u=dfn[u])>(v=dfn[v]))std::swap(u,v);
    cll lg=31^__builtin_clz(v-u+1);
    return min2(st[lg][u],st[lg][v-(1<<lg)+1]);
}*/
ll find(cll u){
    return u^f[u]?f[u]=find(f[u]):u;
}
void calc(){
    cll n=readll(),m=readll();
    rep(i,1,m)u[i]=readll(),v[i]=readll();
    rep(i,1,n)f[i]=i;
    rep(i,1,m){
        cll x=find(u[i]),y=find(v[i]);
        if(x!=y)f[x]=y,c[i]=1,add(u[i],v[i]),add(v[i],u[i]);//,printf("%lld < - > %lld\n",u[i],v[i]);
        else c[i]=0;
    }
    dfs(1,0);
    rep(i,0,21)rep(j,1,n)ft[i+1][j]=ft[i][ft[i][j]];
    //rep(i,1,m)printf("%lld %lld\n",u[i],v[i]);
    //rep(i,0,22)rep(j,1,top-(2<<i)+1)st[i+1][j]=min2(st[i][j],st[i][j+(1<<i)]);
    ll s=0;
    rep(i,1,m)if(c[i]==0){
        ll u=::u[i],v=::v[i];
        if(deep[u]>deep[v])std::swap(u,v);
        if(dfn[u]<=dfn[v]&&end[v]<=end[u]){
            cll k=deep[v]-deep[u]-1;
            ll z=v;
            per(i,22,0)if(k>>i&1)z=ft[i][z];
            d[v]++,d[z]--;
        }else d[u]++,d[v]++,s++;//printf("u=%lld v=%lld\n",u,v); 
    }
    dfs2(1,0);
    rep(i,1,n)pc(d[i]==s?49:48);
    pc(10);
} 
int main(){
    rep(i,1,T)calc();
    return 0;
}