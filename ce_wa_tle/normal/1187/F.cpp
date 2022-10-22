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
const ll N=3e5+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
aN l,r,s,w;
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
ll qm(ll&a,ll b=mod){
    return a>=b?a-=b,1:0;
}
int main(){
    IO();
    const ll n=readll();
    rep(i,1,n)l[i]=readll();
    rep(i,1,n)r[i]=readll()+1;
    rep(i,1,n)w[i]=r[i]-l[i];
    s[0]=1;
    rep(i,1,n)s[i]=s[i-1]*w[i]%mod;
    ll now=inv(s[n]);
    per(i,n,1)s[i]=s[i-1]*now%mod,now=now*w[i]%mod;
    ll s2=0,s1=0;
    const ll d=std::min(r[1],r[2])-std::max(l[1],l[2]);
    ll lst=d<=0?0:s[1]*s[2]%mod*d%mod;
    ref(i,2,n){
        const ll z=s[i]*s[i+1]%mod,tl=std::max(l[i],l[i+1]),tr=std::min(r[i],r[i+1]),g=tl<tr?(tr-tl)*z%mod:0;
        s2+=s1*g,qm(s1+=lst),lst=g;
        if(tl<=tr){
            const ll n=std::min(tr,r[i-1])-std::max(tl,l[i-1]);
            if(n>0)s2+=(z*s[i-1])%mod*n;
        }
        s2%=mod;
    }
    qm(s1+=lst),writell((n*n+(mod+1-2*n)*s1+s2*2)%mod);
    return 0;
}