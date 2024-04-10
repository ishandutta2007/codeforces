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
char s[N];
aN jc,njc,f,g;
ll t[53],y[53],ans[53][53];
ll inv(ll a,ll b=mod){
    ll x=1,y=0;
    const ll m=b;
    while(b){
        const ll t=a/b;
        std::swap(a-=t*b,b),
        std::swap(x-=t*y,y);
    }
    return(x+m)%m;
}
int main(){
    IO();
    const ll n=mygets(s+1)>>1,q=readll();
    rep(i,jc[0]=1,n)jc[i]=jc[i-1]*i%mod;
    njc[n]=inv(jc[n]);
    per(i,n,1)njc[i-1]=njc[i]*i%mod;
    rep(i,1,n*2)t[s[i]=(s[i]<<1&62)-(s[i]>>5&1)]++;
    ll tt=0;
    rep(i,1,52)if(t[i])t[++tt]=t[i],y[i]=tt;
    rep(i,1,n*2)s[i]=y[s[i]];
    f[0]=1;
    ll ml=jc[n]*jc[n]%mod;
    rep(i,1,tt){
        const ll d=t[i];
        ml=ml*njc[d]%mod;
        per(i,n-d,0)f[i+d]+=f[i];
    }
    const ll ss=f[n]%mod*ml%mod;
    rep(i,1,tt){
        const ll d=t[i];
        ans[i][i]=ss;
        memcpy(g,f,(n+1)<<3);
        rep(i,d,n)g[i]-=g[i-d];
        ref(j,1,i){
            const ll d=t[j];
            ll sum=0;
            rfor(ll i=n%d;i<=n;i+=d)__builtin_prefetch(g+i+d,0,3),sum=g[i]-sum;
            ans[i][j]=ans[j][i]=(sum*2%mod+mod)*ml%mod;
        }
    }
    rep(i,1,q)writell(ans[s[readll()]][s[readll()]],10);
    return 0;
}