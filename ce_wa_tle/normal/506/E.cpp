#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout);
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=1e6+7,mod=1e4+7,iz=1<<21,oz=1<<22;
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
char s[N];
cll M=233;
ll f[M][M][M/2],ans[M][M],mul[M][M];
ll pow(ll a,cll b,cll p=mod){
    ll res=1;
    red(i,b){
        if(i&1)res=res*a%p;
        a=a*a%p;
    }
    return res;
}
aN inv;
int main(){
    IO();
    cll n=mygets(s+1),m=n+readll();
    //printf("%lld %lld\n",n,m);
    inv[1]=1;
    rep(i,2,n||i<=25)inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    ll p24=pow(24,m/2),p25=pow(25,m/2),C=1;
    rep(i,1,n)mul[0][i]=p24*C%mod,mul[i][0]=p25*C%mod,p24=p24*inv[24]%mod,p25=p25*inv[25]%mod,C=C*(m/2-i+1)%mod*inv[i]%mod;
    rep(i,1,n){ll x=mul[i][0];rep(j,1,n)mul[i][j]=x=(x+mod-mul[i-1][j])%mod;}
    //  25  25  25  24  24
    //  o-->o-->o-->o-->o
    //= 25  25  24  24  24
    //  o-->o-->o-->o-->o
    //          v   ^
    //          o---/
    //          25
    f[1][n][0]=1;
    rep(l,1,n)per(r,n,l)rep(a,0,n/2)if(cll c=f[l][r][a]%mod){
        cll b=n-(r-l+1)-2*a;
        //printf("f[%lld][%lld][%lld]=%lld\n",l,r,a,c);
        if(s[l]==s[r])
            f[l+1][r-1][a+1]+=c,
            ans[a+1][b]+=m&1?c*(26-(l==r)):c;
        else
            f[l+1][r][a]+=c,f[l][r-1][a]+=c,
            ans[a][b+1]+=m&1?c*26:c;
    }
    ll res=pow(26,(m+1)/2);
    rep(i,0,n/2+1)rep(j,0,n)if(cll c=ans[i][j]%mod)res=(res+(mod-c)*mul[i][j])%mod;
    writell(res);
    return 0;
}