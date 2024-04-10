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
cll N=1e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
cll IO_res=IO(),T=readll();
aN s,x;
void qmax(ll&a,cll b){
    a<b&&(a=b);
}
struct bit{
    aN f;
    ll n;
    void set(ll n_){
        memset(f,-0x3f,((n=n_)+1)<<3);
    }
    void update(ll u,cll c){
        for(;u<=n;u+=u&-u)qmax(f[u],c);
    }
    ll query(ll u)const{
        ll res=-mod;
        for(;u;u&=~-u)qmax(res,f[u]);
        return res;
    }
}dt1,dt2;
aN dt3,f;
void add(cll u,cll t){
    dt1.update(s[u],f[u]-u);
    dt2.update(t-s[u]+1,f[u]+u);
    qmax(dt3[s[u]],f[u]);
}
void getans(cll u,ll t){
    f[u]=dt3[s[u]];
    qmax(f[u],dt1.query(s[u]-1)+u);
    qmax(f[u],dt2.query(t-s[u])-u);
}
void calc(){
    cll n=readll();
    ll now=0;
    x[n+1]=s[0]=0;
    rep(i,1,n)x[i]=s[i]=now+=readll();
    std::sort(x+1,x+n+2);
    cll t=std::unique(x+1,x+n+2)-x-1;
    rep(i,0,n)s[i]=std::lower_bound(x+1,x+t+1,s[i])-x;
    dt1.set(t),dt2.set(t);
    memset(dt3,-0x3f,(t+1)<<3);
    f[0]=0,add(0,t);
    rep(i,1,n)getans(i,t),add(i,t);
    writell(f[n],10);
}
int main(){
    rep(i,1,T)calc();
    return 0;
}