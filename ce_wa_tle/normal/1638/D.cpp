#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=1e6+7,mod=998244353,iz=1<<21,oz=1<<22;
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
ll a[1111][1111];
aN x,y,c;
ll n,m;
ll check(ll i,ll j){
    if(i<=0||i>=n||j<=0||j>=m)return 0;
    ll c=0;
    rep(k,i,i+1)rep(l,j,j+1)if(a[k][l]){
    if(c&&a[k][l]!=c)return 0;else c=a[k][l];}
    if(c)rep(k,i,i+1)rep(l,j,j+1)a[k][l]=0;
    return c;
}
int main(){
    IO();
    //gc=getchar;
    cll n=::n=readll(),m=::m=readll();
    rep(i,1,n)rep(j,1,m)a[i][j]=readll();
    ll h=1,t=0;
    rep(i,1,n-1)rep(j,1,m-1)if(cll g=check(i,j))x[++t]=i,y[t]=j,c[t]=g;
    while(h<=t){
        cll i=x[h],j=y[h++];
        rep(k,i-1,i+1)rep(l,j-1,j+1)if(cll g=check(k,l))x[++t]=k,y[t]=l,c[t]=g;
    }
    rep(i,1,n)rep(j,1,m)if(a[i][j]!=0)return!myputs("-1");
    writell(t,10);
    per(i,t,1)writell(x[i]),writell(y[i]),writell(c[i],10);
    return 0;
}