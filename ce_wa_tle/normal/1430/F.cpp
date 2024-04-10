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
const ll N=4e5+7,mod=1e18+7,iz=1<<21,oz=1<<22;
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
ll f[2][2555][2555];
aN s;
int qm(ll&a,ll b){
    return a>b?a=b,1:0;
}
int main(){
    IO();
    ll n=readll(),k=readll(),lr=-1;
    rep(i,1,n){
        const ll l=readll(),r=readll(),a=readll();
        s[i]=(s[i-1]+a)%k;
        rep(p,0,1)rep(j,1,i){
            f[p][i][j]=mod;
            rep(q,0,1)qm(f[p][i][j],(q||l!=lr?k-(s[i-1]-s[j-1]+k)%k:(s[j-1]-s[i-1]+k)%k)+(r-p-l)*k>=a?f[q][i-1][j]+a:mod);
        }
        //,printf("%lld %lld %d %lld\n",p,q,(q||l!=lr?k-(s[i-1]-s[j-1]+k)%k:(s[j-1]-s[i-1]+k)%k)+(r-p-l)*k>=a,f[q][i-1][j]);
        rep(p,0,1){
            f[p][i][i+1]=mod;
            rep(j,1,i)qm(f[p][i][i+1],f[p][i][j]+(k+s[j-1]-s[i])%k);
        }
        lr=r;
        //rep(p,0,1)rep(j,1,i+1)printf("f[%lld][%lld][%lld]=%lld\n",p,i,j,f[p][i][j]);
    }
    ll res=mod;
    rep(i,1,n)qm(res,f[0][n][i]);
    writell(res>=mod?-1:res);
    return 0;
}