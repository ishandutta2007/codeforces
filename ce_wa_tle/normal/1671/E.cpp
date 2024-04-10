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
cll N=1e6+7,mod1=1e9+7,mod2=1e9+9,mod3=998244353,iz=1<<21,oz=1<<22;
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
char s[N];
aN hs1,hs2,a,p2331,p2332,sz,f;
void calc(){
    cll n=readll(),m=(1<<n)-1;
    mygets(s+1);
    rep(i,1,m)s[i]=s[i]=='A';
    per(i,m,m/2+1)hs1[i]=hs2[i]=s[i],sz[i]=1,f[i]=1;
    per(i,m/2,1){
        sz[i]=sz[i<<1]+sz[i<<1|1]+1;
        ll u=i<<1,v=i<<1|1;
        if(hs1[u]<hs1[v])std::swap(u,v);
        if(hs1[u]==hs1[v]&&hs2[u]<hs2[v])std::swap(u,v);
        hs1[i]=((hs1[u]*p2331[sz[u]]+hs1[v])%mod1*233+s[i])%mod1,
        hs2[i]=((hs2[u]*p2332[sz[u]]+hs2[v])%mod2*233+s[i])%mod2,
        f[i]=hs1[u]==hs1[v]&&hs2[u]==hs2[v]?f[u]*f[v]%mod3:f[u]*f[v]*2%mod3;
    }
    writell(f[1]);
}
int main(){
    ll x=1;
    rep(i,1,1e6)p2331[i]=x,x=x*233%mod1; 
    x=1;
    rep(i,1,1e6)p2332[i]=x,x=x*233%mod2; 
    rep(i,1,T)calc();
    return 0;
}