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
const ll N=4e6+7,mod=1e18L+7,iz=1<<21,oz=1<<22;
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
typedef long double ld;
const ld eps=1e-9L;
ld st[N];
struct lim{
    ld l,r;
    operator ld()const{
        return l;
    }
}g[N];
struct node{
    ll w,l,r;
    void read(){
        //#define readll() rand()
        l=readll(),r=readll(),w=readll();
        //#undef readll
    }
}p[N];
lim getxl(node a,node b){
    if(a.w==b.w)return(lim){};
    if(a.w>b.w)std::swap(a,b);
    const ll del=b.w-a.w;
    return(lim){1.0L*(b.l-a.r)/del+eps,(1.0L*b.r-a.l)/del-eps};
}
ll n;
ld check(ll mid){
    const ld w=st[mid];
    ld l=mod,r=-mod;
    rep(i,1,n)l=std::min(l,p[i].l-w*p[i].w),r=std::max(r,p[i].r-w*p[i].w);
    return r-l;
}
int main(){
    IO();
    const ll n=::n=readll();
    rep(i,1,n)p[i].read();
    ll t=0;
    rep(i,1,n)rep(j,1,i-1){
        const node&a=p[i],&b=p[j];
        if(a.w!=b.w)g[++t]=getxl(a,b);
    }
    if(t==0){
        ll l=p[1].l,r=p[1].r;
        rep(i,2,n)l=std::min(l,p[i].l),r=std::max(r,p[i].r);
        writell(r-l,10);
        return 0;
    }
    std::sort(g+1,g+t+1);
    //rep(i,1,t)printf("%Lf %Lf\n",g[i].l.to_ld(),g[i].r.to_ld());
    ll ts=1;
    st[1]=g[1].l;
    ld now=g[1].r;
    rep(i,2,t){
        if(now<=g[i].l)st[++ts]=now,st[++ts]=g[i].l;
        if(now<g[i].r)now=g[i].r;
    }
    st[++ts]=now;
    //rep(i,1,ts)printf("%Lf -> %Lf\n",st[i].to_ld(),check(i));
    ll l=1,r=ts;
    ld ans=mod;
    //rep(i,1,ts)ans=std::min(ans,check(i));
    while(l<r){
        const ll mid=(l+r)>>1,m2=mid+1;
        const ld rm=check(mid),r2=check(m2);
        if(rm>r2)l=m2+1,ans=std::min(ans,r2);
        else r=mid-1,ans=std::min(ans,rm);
    }
    if(l<=r)ans=std::min(ans,check(l));
    printf("%.18Lf\n",ans);
    return 0;
}