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
const ll N=1e6+7,mod=998244353,iz=1<<21,oz=1<<22;
typedef ll aN[N];
char is[iz],*i1=is,*i2=is,os[oz],*o1=os,*o2=os+oz;
int fgc(){
    //printf("???");
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
    while((*s=gc())<3);
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
aN f,p,s,c,a;
ll find(ll u){
    return f[u]^u?f[u]=find(f[u]):u;
}
struct hash{
    static const ll m=9260817;
    ll v[m],k[m];
    mutable ll l;
    ll g(ll b)const{
        if(k[l]==b)return l;
        ll n=b%m,x=0;
        while(k[n]&&k[n]!=b)n=(n+2*x+++1)%m;
        //printf("%lld->%lld\n",b,n);
        return l=n;
    }
    int count(ll b)const{
        return!!k[g(b)];
    }
    ll operator[](ll b)const{
        ll n=g(b);
        return k[n]?v[n]:0;
    }
    ll&operator[](ll b){
        ll n=g(b);
        return!k[n]?k[n]=b,v[n]=0:v[n];
    }
}hs;
int main(){
    IO();
    static const ll m=1e6+1;
    ll t=0;
    p[0]=mod;
    rep(i,2,m)rep(j,p[i]||(p[++t]=s[i]=i),t&&p[j]*i<=m&&i%p[j-1])p[i*p[j]]=1,s[i*p[j]]=p[j];
    ll n=readll(),q=readll();
    rep(i,1,n)c[a[i]=readll()]++;
    rep(i,1,m)f[i]=i;
    rep(i,1,t){
        const ll u=p[i];
        //if(u<=100)printf("%lld\n",u);
        rfor(ll x=u*2;x<=m;x+=u)if(c[x])f[find(x)]=u;
    }
    rep(i,1,n){
        ll g=a[i]+1;
        static aN st;
        ll t=1;
        st[1]=find(a[i]);
        while(g!=1)st[++t]=find(s[g]),g/=s[g];
        //rep(i,1,t)printf("%lld-%lld\n",i,st[i]);
        std::sort(st+1,st+t+1),t=std::unique(st+1,st+t+1)-st-1;
        rep(i,1,t)rep(j,1,t)hs[st[i]*mod+st[j]]=1;
    }
    rep(i,1,q){
        ll x=find(a[readll()]),y=find(a[readll()]);
        //printf("%lld %lld\n",x,y);
        writell(x==y?0:hs.count(x*mod+y)?1:2,10);
    }
    return 0;
}