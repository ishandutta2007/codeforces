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
const ll N=2.1e5+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
    c&&pc(*t++=c),*t=0;
    return t-s;
}
int myputs(const char*s,int c=10){
    const char*t=s;
    while(*t)pc(*t++);
    c&&pc(c);
    return t-s+(c!=0);
}
aN next,to,head,vis,deep,ans,f,ft,z,c,t,x,y,a;
ll cnt,max,flag;
void add(ll u,ll v){
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
void dfs(ll u,ll fa){
    max=std::max(max,deep[u]=deep[ft[u]=fa]+1);
    rep(i,f[u],z[u]){
        const ll d=deep[u]+x[i];
        if(d<=max)ans[i]-=t[d];
    }
    t[deep[u]]++;
    rev(i,u,v)if(!deep[v])dfs(v,u);
    else flag=u;
    rep(i,f[u],z[u]){
        const ll d=deep[u]+x[i];
        if(d<=max)ans[i]+=t[d];
    }
}
void reva(ll*a,ll n){
    static aN b;
    rep(i,1,n)b[i]=a[c[i]];
    memcpy(a+1,b+1,n<<3);
}
void nreva(ll*a,ll n){
    static aN b;
    rep(i,1,n)b[c[i]]=a[i];
    memcpy(a+1,b+1,n<<3);
}
int main(){
    IO();
    const ll n=readll();
    rep(i,1,n)add(a[i]=readll(),i);
    const ll m=readll();
    rep(i,1,m)x[i]=readll(),t[y[i]=readll()]++;
    rep(i,1,n)f[i]=t[i-1]+1,z[i]=t[i]+=t[i-1];
    rep(i,1,m)c[++t[y[i]-1]]=i;
    reva(x,m);
    memset(t,0,(n+1)<<3);
    rep(i,1,n)if(!deep[i]){
        ll j=i;
        while(!vis[j])vis[j]=1,j=a[j];
        dfs(j,max=0);
        const ll now=flag,l=deep[now]-deep[j]+1;
        rep(i,l+1,max)t[i]+=t[i-l];
        rfor(ll u=now;u;u=ft[u])rep(i,f[u],z[u]){
            ll d=deep[u]+x[i]-l;
            if(d<=0)continue;
            if(d>max)d-=(d-max+l-1)/l*l;
            ans[i]+=t[d];
        }
        memset(t+1,0,max<<3);
    }
    nreva(ans,m);
    rep(i,1,m)writell(ans[i],10);
    return 0;
}
/*
10
3 1 2 1 4 5 6 7 2 3
15
1 2
2 2
3 2
4 2
5 2
6 2
7 2
8 2
9 2
10 2
11 2
12 2
13 2
14 2
15 2
*/