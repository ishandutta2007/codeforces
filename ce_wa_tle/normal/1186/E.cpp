#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)for(ll i=l;i<r;i++)
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
ll n,m;
ll s[1111][1111];
ll get(ll a,ll b,ll x){
    static const ll n=::n,m=::m,tot=s[n][m];
    const ll ans=a<=n?b<=m?s[a][b]:s[a][m]+a*(b-m)-s[a][b-m]:b<=m?s[n][b]+(a-n)*b-s[a-n][b]:tot-s[a-n][m]-s[n][b-m]+s[a-n][b-m]+n*(b-m)+(a-n)*m;
    return x?a*b-ans:ans;
}
ll getans(ll x,ll y){
    static const ll n=::n<<1,m=::m<<1;
    const lldiv_t a=lldiv(x,n),b=lldiv(y,m);
    return((x*y-a.rem*b.rem)>>1)+get(a.rem,b.rem,__builtin_parityll(a.quot^b.quot));
}
int main(){
    IO();
    static const ll n=::n=readll(),m=::m=readll(),q=readll();
    rep(i,1,n)rep(j,1,m)s[i][j]=s[i][j-1]+(readchar()&1);
    rep(i,1,n)rep(j,1,m)s[i][j]+=s[i-1][j];
    rep(i,1,q){
        const ll lx=readll()-1,ly=readll()-1,rx=readll(),ry=readll();
        writell(getans(lx,ly)+getans(rx,ry)-getans(rx,ly)-getans(lx,ry),10);
    }
    return 0;
}