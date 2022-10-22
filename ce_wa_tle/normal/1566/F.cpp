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
struct ss{
    ll l,r;
    void read(){
        l=readll(),r=readll();
    }
    operator ll()const{
        return r*mod-l;
    }
}s[N];
aN a,f[2];
ll qm(ll&a,ll b){
    return a>b?a=b,1:0;
}
void calc(){
    ll n=readll(),m=readll();
    rep(i,1,n)a[i]=readll();
    std::sort(a+1,a+n+1);
    rep(i,1,m)s[i].read();
    std::sort(s+1,s+m+1);
    ll t=0,l=-mod,p=0;
    rep(i,1,m){
        while(p<n&&a[p+1]<=s[i].r)l=std::max(l,a[++p]);
        if(s[i].l>l)s[++t]=s[i],l=s[t].l;
    }
    //rep(i,1,n)printf("a[%lld]=%lld\n",i,a[i]);
    //rep(i,1,t)printf("s[%lld]=[%lld,%lld]\n",i,s[i].l,s[i].r);
    p=0,a[0]=-mod*mod,a[n+1]=mod*mod,f[0][0]=f[1][0]=0;
    rep(i,1,n+1){
        ll lst=0,x;
        f[0][i]=f[1][i]=mod*mod;
        #define work(a,b)qm(f[a][i],f[b][i-1]+(b?lst:lst<<1)+(a?x<<1:x))
        while(p<t&&s[p+1].r<=a[i])x=a[i]-s[++p].r,/*printf("%lld,%lld %lld\n",x,lst,i),*/work(0,0),work(0,1),work(1,0),work(1,1),lst=s[p].l-a[i-1];
        x=0,/*printf("%lld,%lld %lld\n",x,lst,i),*/work(0,0),work(0,1),work(1,0),work(1,1);
       // printf("f[0][%lld]=%lld f[1][%lld]=%lld\n",i,f[0][i],i,f[1][i]);
    }
    writell(f[0][n+1],10);
}
int main(){
    IO();
    ll T=readll();
    while(T--)calc();
    return 0;
}