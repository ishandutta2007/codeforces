#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=;i;i>>=1)
#define IO(x...)((*#x!='/'||#x[1])&&(*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)))
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=1e6+7,mod=1e9+7,iv2=(mod+1)/2,g=3,iz=1<<21,oz=1<<22;
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
cll IO_res=IO();
cll n=readll();
//cll n=18;
aN q,vis,ans;
struct node{
    ll l,r,m,s;
    void set(cll a){
        l=r=m=std::max(a,0ll),s=a;
    }
    void merge(const node&a,const node&b){
        cll L=std::max(a.l,a.s+b.l),R=std::max(a.r+b.s,b.r),M=std::max(std::max(a.m,b.m),a.r+b.l),S=a.s+b.s;
        l=L,r=R,m=M,s=S;
    }
}f[N];
void pushup(cll u,cll x){
    //printf("%lld %lld %lld %lld\n",u,x,u<<1^x,u<<1^x^1);
    f[u].merge(f[u<<1^x],f[u<<1^1^x]);
    //printf("%lld %lld %lld %lld\n",f[u].l,f[u].r,f[u].m,f[u].s);
}
void calc(cll n,cll x){
    //printf("n=%lld x=%lld\n",n,x);
    per(i,n-1,0)ref(j,1<<i,2<<i)pushup(j,x>>i&1);
}
int main(){
    ref(i,0,1<<n)f[(1<<n)+i].set(readll());//,printf("%lld\n",(1<<n)+i);
    //ref(i,0,1<<n)f[(1<<n)+i].set(rand()*(rand()&1?1:-1));//,printf("%lld\n",(1<<n)+i);
    calc(n,0),ans[0]=f[1].m;
    //printf("ans[0]=%lld\n",ans[0]);
    cll m=readll();
    rep(i,1,m)vis[q[i]=q[i-1]^(1<<(n-1-readll()))]=1;
    //cll m=1000;
    //rep(i,1,m)vis[q[i]=q[i-1]^(1<<(n-1-(rand()%n)))]=1;
    ll lst=0;
    rep(i,1,1<<n)if(vis[i])calc(32-__builtin_clz(i^lst),i),ans[i]=f[1].m,lst=i;
    rep(i,1,m)writell(ans[q[i]],10);
    /*rep(i,1,m){
        writell(ans[q[i]],10);
        node now={};
        ll s=0;
        ref(j,0,n)if(q[i]>>j&1)s^=1<<(n-1-j);
        //printf("%lld %lld\n",i,s);
        ref(j,0,1<<n)now.merge(now,f[(1<<n)+(j^s)]);//,printf("%lld %lld %lld\n",now.m,ans[q[i]],j^s);
        assert(now.m==ans[q[i]]);
    }*/
    return 0;
}