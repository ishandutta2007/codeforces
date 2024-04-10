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
aN next,head,to,v,f,ans,vis,x,y;
ll cnt=1,t=0,n;
void add(ll u,ll v){
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
ll find(ll u){
    return u^f[u]?f[u]=find(f[u]):u;
}
void dfs(ll u){
    rfor(ll i=head[u],v;v=to[i],head[u]=next[i],i;i=head[u])
    if(!vis[i>>1])vis[i>>1]=1,dfs(v),ans[t|(i&1)]=i&~1,ans[t|(~i&1)]=(i&~1)-1,t+=2;
}
int check(ll k){
    const ll up=(1<<k)-1;
    rep(i,0,up)f[i]=i,v[i]=0;
    ll cnt=0;
    rep(i,1,n){
        const ll a=x[i]&up,b=y[i]&up;
        cnt-=v[a]+v[b];
        f[find(a)]=find(b),v[a]^=1,v[b]^=1;
        cnt+=v[a]+v[b];
    }
    if(cnt)return 0;
    const ll g=find(x[1]&up);
    rep(i,1,n)if(find(x[i]&up)!=g||find(y[i]&up)!=g)return 0;
    return 1;
}
int main(){
    IO();
    const ll n=::n=readll();
    rep(i,1,n)x[i]=readll(),y[i]=readll();
    ll l=1,r=20;
    while(l<=r){
        const ll mid=(l+r)>>1;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
    const ll k=l-1,up=(1<<k)-1;
    writell(k,10);
    rep(i,1,n){
        const ll a=x[i]&up,b=y[i]&up;
        add(a,b),add(b,a);
    }
    dfs(x[1]&up);
    ref(i,0,2*n)writell(ans[i],i==2*n-1?10:32);
    return 0;
}