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
const ll N=2e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
aN next,to,head,lst,deep,f,vis;
ll cnt=0,tim=0;
void add(ll u,ll v){
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
void dfs(ll u,ll fa){
    deep[u]=deep[f[u]=fa]+1,vis[u]=tim;
    rev(i,u,v)if(vis[v]!=tim)dfs(v,u);
}
void calc(){
    const ll n=readll(),m=readll(),g=(n+1)/2;
    ll u,v,now=0;
    memset(head,cnt=0,(n+1)<<3);
    rep(i,1,m)u=readll(),v=readll(),add(u,v),add(v,u);
    dfs(1,0);
    rep(i,1,n)if(deep[i]>=g){
        myputs("PATH"),writell(g,10);
        ll u=i;
        rep(i,1,g)writell(u),u=f[u];
        pc(10);
        return;
    }
    memset(lst,0,(g+1)<<3),myputs("PAIRING"),writell((g+1)/2,10);
    rep(i,1,n)if(ll&s=lst[deep[i]]){
        writell(s),writell(i,10),s=0;
        if(++now==(g+1)/2)return;
    }else s=i;
}
int main(){
    IO();
    ll T=readll();
    while(T--)++tim,calc();
    return 0;
}