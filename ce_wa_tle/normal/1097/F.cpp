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
char is[iz],*i1=is,*i2=is,os[oz],*o1=os,*o2=os;
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
int (*gc)()=getchar,(*pc)(int)=putchar,wt[126];
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
    c&&(*t++=c);
    return t-s;
}
int myputs(const char*s,int c=10){
    const char*t=s;
    while(*t)pc(*t++);
    c&&pc(c);
    return t-s+(c!=0);
}
aN p,mu,s;
ll ts;
struct bitset{
    static const ll g=4,bc=64*g,size=7000;
    static const ll sz=(size+bc-1)/bc;
    typedef ull type __attribute__((vector_size(g*8)));
    type val[sz];
    bitset&operator&=(const bitset&b){
        ref(i,0,sz)val[i]&=b.val[i];
        return*this;
    }
    bitset&operator^=(const bitset&b){
        ref(i,0,sz)val[i]^=b.val[i];
        return*this;
    }
    void set(ll w){
        val[w/bc][w>>6&(g-1)]|=1ull<<(w&63);
    }
    int parity()const{
        type ans={};
        ref(i,0,sz)ans^=val[i];
        ull sum=0;
        ref(i,0,g)sum^=ans[i];
        return __builtin_parityll(sum);
    }
}v[N/10],g1[7001],g2[7001],fz;
int main(){
    IO();
    const ll n=readll(),m=readll();
    static_cast<void>(n);
    ll t=0;
    p[0]=mod,mu[1]=1;
    rep(i,2,7000)rep(j,p[i]||(mu[p[++t]=i]=1),t&&p[j]*i<=7000&&i%p[j-1])mu[i*p[j]]=mu[i]&&i%p[j],p[i*p[j]]=1;
    rep(i,1,7000)if(mu[i])s[++ts]=i;
    rep(i,1,7000)rfor(ll j=i;j<=7000;j+=i)g1[j].set(i-1);
    rep(i,1,7000)rep(j,1,ts&&s[j]*i<=7000)g2[i].set(i*s[j]-1);
    rep(i,1,m){
        ll f=readll()-1,x=readll(),y=readll(),z=(f^f>>1)&1?readll():0;
        if(z==x)std::swap(y,z);
        switch(f){
            case 0:v[x]=g1[y];break;
            case 1:if(x!=y)v[x]=v[y];v[x]^=v[z];break;
            case 2:if(x!=y)v[x]=v[y];v[x]&=v[z];break;
            case 3:fz=g2[y],fz&=v[x];pc(fz.parity()^48);break;
        }
    }
    return 0;
}