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
namespace{
    const ll N=61,M=1830;
    ll f[33][N+1][M+1],d[N+1],u[N+1],g[N+1][N+1],a[N+1];
}
int main(){
    IO();
    cll n=readll();
    rep(i,1,n)a[i]=readll();
    std::sort(a+1,a+n+1),f[0][0][0]=1;
    rep(i,1,n)rep(j,1,M)rep(k,std::max(a[i],j*(j-1)/2),M)if(f[i-1][j-1][k-a[i]]||f[i][j-1][k-a[i]])f[i][j][k]=1;//,printf("%lld %lld %lld\n",i,j,k);
    ll ni=n,nj=0,nk=0;
    rep(j,1,M)if(f[n][j][j*(j-1)/2]){nj=j,nk=j*(j-1)/2;break;}
    if(!nj)return!myputs(")=");
    cll rn=nj;
    writell(nj,10);
    while(nj){
        nk-=d[nj--]=a[ni--];
        if(!f[ni][nj][nk])ni++;
    }
    rep(i,1,rn)rep(j,1,rn)g[i][j]=i>j;
    rep(i,1,rn)u[i]=i-1;
    while(1){
        ll i=1;
        //rep(i,1,rn)printf("u=%lld d=%lld\n",u[i],d[i]);
        while(i<=rn&&d[i]==u[i])i++;
        if(i>rn)break;
        while(u[i+1]==u[i])i++;
        ll j=i+1;
        while(u[j]<=d[j])j++;
        ll p=1;
        while(g[i][p]||!g[j][p])p++;
        g[i][p]=g[p][j]=1,g[p][i]=g[j][p]=0;
        ++u[i],--u[j];
    }
    rep(i,1,rn){rep(j,1,rn)pc(48^g[i][j]);pc(10);}
    return 0;
}