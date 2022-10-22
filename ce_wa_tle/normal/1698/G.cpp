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
cll N=2.2e5+7,mod=998244353,iv2=(mod+1)/2,g=3,iz=1<<21,oz=1<<22;
#define iz 100
#define oz 100
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
cll IO_res=IO(),T=1;
void init(){
}
char a[126];
struct hash{
    static cll m=(1<<19)+3;
    ll k[m],v[m];
    mutable ll l;
    ll g(ll&b)const{
        if(b==0)b=48237759274838ll;
        if(k[l]==b)return l;
        ll n=b%m,x=0;
        while(k[n]&&k[n]!=b)n=(n+2*x+++1)%m;
        return l=n;
    }
    ll count(ll b)const{
        return k[g(b)]!=0;
    }
    ll getans(ll b)const{
        cll n=g(b);
        return k[n]?v[n]:0;
    }
    ll&operator[](ll b){
        cll n=g(b);
        return!k[n]?k[n]=b,v[n]=0:v[n];
    }
}dt;
ll s[3][1<<12];
cll base=(1<<12)-1;
void calc(){
    cll n=mygets(a+1);
    ll pre=1,t=0,mod=0,up=0;
    rep(i,1,n)if(a[i]=='0'&&i==pre)pre++;
    else a[i]=='1'?mod|=1ll<<(up=t++):t++;
    cll val=1ll<<up;
    if(!mod)return myputs("-1"),static_cast<void>(0);
    ll ans=-1,now=1%mod;
    //printf("%lld %lld %lld\n",mod,up,val);
    ref(i,0,1<<17)dt[now]=i,(now<<=1)&val&&(now^=mod);
    ref(i,0,34)s[i/12][1<<i%12]=now,(now<<=1)&val&&(now^=mod);
    ref(i,0,3)ref(j,3,1<<12)s[i][j]=s[i][j&-j]^s[i][j&~-j];
    now=1%mod;
    rep(i,1,1<<17){
        now=s[2][now>>24]^s[1][now>>12&base]^s[0][now&base];
        if(dt.count(now)){
            ans=(i<<17)-dt.getans(now);
            break;
        }
    }
    //if(ans==-1)return myputs("-1"),static_cast<void>(0);
    writell(pre),writell(pre+ans,10);
}
int main(){
    init();
    rep(i,1,T)calc();
    return 0;
}