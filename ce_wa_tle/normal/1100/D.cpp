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
static const ll m=666,n=999,mid=(n+1)/2;
int vis[n+1][n+1];
struct pt{
    ll x,y;
    void read(){
        x=readll(),y=readll();
    }
    void print()const{
        writell(x),writell(y);
    }
    void set(ll u)const{
        vis[x][y]+=u;
    }
}a,b[m+1];
void move(ll dx,ll dy){
    a.x+=dx,a.y+=dy;
    if(__builtin_expect(vis[a.x][a.y],0))a.y-=dy;
    a.print(),fout(),fflush(stdout);
    const ll k=readll();
    if(__builtin_expect(!~k,0))exit(0);
    b[k].set(-1),b[k].read(),b[k].set(1);
}
int main(){
    IO(),gc=getchar;
    a.read();
    rep(i,1,m)b[i].read(),b[i].set(1);
    while(a.x<500)move(1,0);
    while(a.x>500)move(-1,0);
    while(a.y<500)move(0,1);
    while(a.y>500)move(0,-1);
    ll a=0,b=0,c=0,d=0;
    #define check if(__builtin_expect_with_probability(vis[i][j],1,666/(999*999.0)))
    rep(i,1,499)rep(j,1,499)check a++;
    rep(i,1,499)rep(j,501,999)check b++;
    rep(i,501,999)rep(j,1,499)check c++;
    rep(i,501,999)rep(j,501,999)check d++;
    if(d<167)while(1)move(-1,-1);
    if(c<167)while(1)move(-1,1);
    if(b<167)while(1)move(1,-1);
    if(a<167)while(1)move(1,1);
    return 0;
}