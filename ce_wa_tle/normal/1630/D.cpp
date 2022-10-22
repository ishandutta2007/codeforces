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
typedef const ll cll;
typedef unsigned long long ull;
cll N=1e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
aN a,t,r,h;
ll gcd(ll a,ll b){
    while(b)std::swap(a%=b,b);
    return a;
}
void calc(){
    cll n=readll(),m=readll();
    ll s=0;
    memset(t,0x3f,(n+1)<<3);
    memset(h,0,(n+1)<<3);
    rep(i,1,n){
        a[i]=readll(),
        r[i]=a[i]<0;
        if(r[i])a[i]=-a[i];
        s+=a[i];
    }
    ll g=0;
    rep(i,1,m)g=gcd(g,readll());
    rep(i,1,n)if(a[i]<t[i%g])t[i%g]=a[i];
    rep(i,1,n)h[i%g]^=r[i];
    ll d1=0,d2=0;
    ref(i,0,g)if(h[i])d1+=t[i];
    else d2+=t[i];
    //writell(s),
    writell(s-2*std::min(d1,d2),10);
}
int main(){
    IO();
    //gc=getchar;
    cll T=readll();
    rep(i,1,T)calc();
    return 0;
}
/*
6
1 2 3 1 2 3
0 1 0 1 1 0
6
1 2 1 3 2 3
*/