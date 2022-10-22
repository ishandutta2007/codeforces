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
aN a,v[4];
ll t[4],now[4],ansi[4],sum;
ll cnt;
int cmp(ll x,ll y){
    return a[x]<a[y];
}
ll vl(ll u){
    return a[v[u][now[u]+1]];
}
template<ll u>
void add(){
    sum+=a[v[u][++now[u]]],cnt++;
}
template<ll u>
void del(){
    if(!now[u])return;
    sum-=a[v[u][now[u]--]],cnt--;
}
void add(){
    const ll g=vl(1)<vl(0),f=vl(2)<vl(g)?2:g;
    sum+=a[v[f][++now[f]]],cnt++;
}
int qm(ll&a,ll b){
    return a>b?a=b,1:0;
}
int main(){
    IO();
    const ll n=readll(),m=readll(),k=readll();
    rep(i,1,n){
        const ll x=readll(),a=readll(),b=readll(),id=a<<1|b;
        ::a[v[id][++t[id]]=i]=x;
    }
    ref(i,0,4)std::sort(v[i]+1,v[i]+t[i]+1,cmp);
    a[0]=mod;
    const ll min=std::max(std::max(0ll,2*k-m),std::max(k-std::min(t[1],t[2]),m-(n-t[3]))),max=std::min(t[3],m);
    if(min>max)return!myputs("-1");
    ll ans=mod*mod;
    rep(i,1,min)add<3>();
    rep(i,1,k-min)add<1>(),add<2>();
    while(cnt<m)add();
    if(qm(ans,sum))memcpy(ansi,now,sizeof ansi);
    rep(i,min+1,max){
        add<3>(),del<1>(),del<2>(),del<0>();
        while(cnt<m)add();
        if(qm(ans,sum))memcpy(ansi,now,sizeof ansi);
    }
    writell(ans,10);
    ref(i,0,4)rep(j,1,ansi[i])writell(v[i][j]);
    pc(10);
    return 0;
}
/*
6 5 3
6 0 0
11 1 0
9 0 1
21 1 1
10 1 0
8 0 1
*/