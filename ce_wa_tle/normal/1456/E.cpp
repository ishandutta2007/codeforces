#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)((*#x!='/'||#x[1])&&(*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)))
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=2.1e6+7,mod=998244353,iz=1<<21,oz=1<<22;
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
cll IO_res=IO(),n=readll(),k=readll();
ll f[55][55][55][2][2][2][2],lf[55],rt[55],v[55];
int main(){
    rep(i,1,n)lf[i]=readll(),rt[i]=readll();
    rt[0]=rt[n+1]=-1ull>>1;
    ref(i,0,k)v[i]=readll();
    memset(f,0x3f,sizeof f);
    rep(i,0,n)rep(a,0,1)rep(c,0,1)f[k][i+1][i][a][0][c][0]=0;
    per(w,k-1,0)per(l,n+1,1)rep(r,l-1,n){//printf("???");
    rep(a,0,1)per(b,(rt[l-1]^lf[l-1])>>(w+1)&&(a?~lf[l-1]>>w&1:rt[l-1]>>w&1),0)
    rep(c,0,1)per(d,(rt[r+1]^lf[r+1])>>(w+1)&&(c?~lf[r+1]>>w&1:rt[r+1]>>w&1),0){
        //if(d==1)if(!((rt[r+1]^d<<w)>=lf[r+1]))printf("%lld %lld %lld %lld\n",lf[r+1],rt[r+1],(rt[r+1]^lf[r+1]),w);
        ll s=f[w+1][l][r][a][0][c][0]+(l!=1&&r!=n&&(((a?lf[l-1]:rt[l-1])^(c?lf[r+1]:rt[r+1]))>>w&1)^b^d?v[w]:0);
        //printf("s=%lld\n",s);
        rep(k,l,r)rep(o,0,1)rep(p,!!w,1)s=std::min(s,f[w][l][k-1][a][b][o][p]+f[w][k+1][r][o][p][c][d]);//,
        //printf("s=%lld %lld %lld\n",s,f[c][l][k-1][a][b][o][p],f[c][k+1][r][o][p][c][d]);
        f[w][l][r][a][b][c][d]=s;
        //printf("f[%lld][%lld][%lld][%lld][%lld][%lld][%lld]=%lld\n",w,l,r,a,b,c,d,f[w][l][r][a][b][c][d]);
    }}
    writell(f[0][1][n][0][0][0][0]);
    return 0;
}
/*
2 1
1 1
2 2
100
*/