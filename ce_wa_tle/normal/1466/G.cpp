#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x"in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;
typedef unsigned long long ull;
const ll N=2e6+7,mod=1e9+7,iz=1<<21,oz=1<<22,inf=0x3f3f3f3f3f3f3f3f;
typedef ll aN[N];
char is[iz],*i1=is,*i2=is,os[oz],*o1=os,*o2=os+oz;
int fgc(){
    return i1==i2&&is==(i2=is+fread(i1=is,1,iz,stdin))?-1:*i1++;
}
void fout(){
    fwrite(os,o1-os,1,stdout),o1=os;
}
int fpc(int c){
    if(o1!=o2)fout();
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
bool pt1;
struct str{
    static aN p;
    static const ll mod=1e9+9,k=233;
    static void init(){
        static ll t=0;
        if(!t++)ref(i,p[0]=1,N)p[i]=p[i-1]*k%mod;
    }
    str(){init();}
    char s[N];
    ll n,flag;
    aN val;
    void geths(){
        rep(i,flag=1,n)val[i]=(val[i-1]*k+s[i])%mod;
    }
    void read(){
        n=mygets(s+1),flag=0;
    }
    void merge(char c){
        s[n+1]=c,memcpy(s+n+2,s+1,n),n=n*2+1,flag=0;
    }
    ll hs(ll l,ll r){
        if(!flag)geths();
        //myputs("hs[",0);
        //rep(i,l,r)pc(s[i]);
        //myputs("]=",0);
        //writell((val[r]+(mod-val[l-1])*p[r-l+1])%mod,10);
        return(val[r]+(mod-val[l-1])*p[r-l+1])%mod;
    }
    ll pre(ll k){return hs(1,k);}
    ll suc(ll k){return hs(n-k+1,n);}
}s,t,w;
aN p2,str::p;
ll gs[26][N/10+7],n,q,ts;
bool pt2;
ll mylog2(ll a){return a==0?-1:63^__builtin_clzll(a);}
ll getans(int c,ll m,ll k){
    //printf("sum=%d %lld %lld\n",c,m,k);
    c=c-97;
    ll l=2+mylog2((m/(n+1))),r=k;
    if(((n+1)<<(l-2))-1>=m)l--;
    //printf("%lld %lld\n",l,r);
    return l>r?0:(gs[c][r]+(mod-gs[c][l-1])*p2[r-l+1])%mod;
}
int main(){
    IO();
    ref(i,p2[0]=1,N)p2[i]=p2[i-1]*2%mod;
    readll(),q=readll(),ts=0;
    s.read(),t.read(),n=s.n;
    while(s.n<1e6&&t.s[ts+1])s.merge(t.s[ts+1]),ts++;
    ref(c,0,26)rep(i,1,t.n)gs[c][i]=(gs[c][i-1]<<1|(t.s[i]==c+97))%mod;
    //myputs(s.s+1);
    rep(ij,1,q){
        ll k=readll(),sum=0;
        w.read();
        ll m=w.n;
        if(k<=ts&&((n+1)<<k)-1<w.n){
            myputs("0");
            continue;
        }
        rep(i,1,n-m+1)s.hs(i,i+m-1)==w.hs(1,m)&&sum++;
        //printf("sum=%lld %lld\n",sum,w.hs(1,m));
        sum=sum*p2[k]%mod;
        rep(i,1,m)if(w.pre(i-1)==s.suc(i-1)&&w.suc(m-i)==s.pre(m-i))sum=(sum+getans(w.s[i],std::max(i-1,m-i),k))%mod;
        writell(sum,10);
    }
    return 0;
}