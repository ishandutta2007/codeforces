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
const ll N=1.1e6+7,mod=998244353,iz=1<<21,oz=1<<22;
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
    for(;c<48||c>57;c=gc());
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
aN jc,njc,e,a,l,r,vis,maxl,minr;
ll sum[41][N/2];
ll C(ll n,ll m){
    return n<0||n>m?0:jc[m]*njc[n]%mod*njc[m-n]%mod;
}
ll inv(ll a,ll b=mod){
    const ll m=b;
    ll x=1,y=0;
    while(b){
        const ll t=a/b;
        std::swap(a-=t*b,b),
        std::swap(x-=t*y,y);
    }
    return(x+m)%m;
}
int qm(ll&a,ll b=mod){
    return a>=b?a-=b,1:0;
}
int main(){
    IO();
    const ll n=readll(),m=readll();
    rep(i,1,n)a[l[i]=readll()]++,a[(r[i]=readll())+1]--;
    rep(i,1,n)a[i]+=a[i-1];
    rep(i,jc[0]=1,n)jc[i]=jc[i-1]*i%mod;
    njc[n]=inv(jc[n]);
    per(i,n,1)njc[i-1]=njc[i]*i%mod;
    ll cnt=0,sum=0;
    ref(i,0,m){
        const ll u=readll(),v=readll();
        const ll a=vis[u]?:vis[u]=++cnt,b=vis[v]?:vis[v]=++cnt;
        maxl[1<<i]=std::max(l[u],l[v]),
        minr[1<<i]=std::min(r[u],r[v]),
        e[1<<i]=1ll<<a|1ll<<b;
    }
    rep(i,0,cnt)rep(j,1,n)qm(::sum[i][j]=::sum[i][j-1]+C(j-i,a[j]-i));
    maxl[0]=1,minr[0]=n;
    ref(i,0,1<<m){
        maxl[i]=std::max(maxl[i&-i],maxl[i&~-i]),
        minr[i]=std::min(minr[i&-i],minr[i&~-i]),
        e[i]=e[i&-i]|e[i&~-i];
        if(maxl[i]<=minr[i]){
            const ll*pre=::sum[__builtin_popcountll(e[i])];
            sum+=(__builtin_parityll(i)?-1:1)*(pre[minr[i]]-pre[maxl[i]-1])+mod;
        }
    }
    writell(sum%mod);
    return 0;
}