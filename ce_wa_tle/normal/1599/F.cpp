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
const ll N=2e5+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
ll inv(ll a,ll b=mod){
    ll x=1,y=0,m=b;
    while(b){
        ll t=a/b;
        std::swap(a-=t*b,b),
        std::swap(x-=t*y,y);
    }
    return(x+m)%m;
}
ll pow(ll a,ll b,ll p=mod){
    ll res=1;
    red(i,b){
        if(i&1)res=res*a%p;
        a=a*a%p;
    }
    return res;
}
const ll k=52,iv2=inv(2);
aN s,a,sm,sp[k+1];
ll C[k+1][k+1];
int qm(ll&a,ll b=mod){
    return a>=b?a-=b,1:0;
}
void getpow(ll*res,ll a,ll k=::k,ll p=mod){
    rep(i,res[0]=1,k)res[i]=res[i-1]*a%p;
}
int main(){
    IO();
    ll n=readll(),q=readll();
    rep(i,1,n)qm(s[i]=s[i-1]+(a[i]=readll())),qm(sm[i]=sm[i-1]+pow(a[i],k));
    rep(i,sp[0][0]=1,n){
        ll now=1;
        rep(j,0,k)qm(sp[j][i]=sp[j][i-1]+now),now=now*i%mod;
    }
    rep(i,C[0][0]=1,k)rep(j,C[i][0]=1,i)qm(C[i][j]=C[i-1][j-1]+C[i-1][j]);
    rep(i,1,q){
        ll l=readll(),r=readll(),d=readll(),x=((s[r]-s[l-1]+mod)*inv(r-l+1)%mod+mod+(mod-r+l)*d%mod*inv(2))%mod,f1,f2=0;
        qm(f1=sm[r]-sm[l-1]+mod);
        static aN xp,dp;
        getpow(xp,x),getpow(dp,d);
        rep(j,0,k)f2=(f2+C[k][j]*xp[j]%mod*dp[k-j]%mod*sp[k-j][r-l])%mod;
        myputs(f1==f2?"Yes":"No");
    }
    return 0;
}