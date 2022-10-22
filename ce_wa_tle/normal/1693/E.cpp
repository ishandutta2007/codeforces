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
cll N=1e6+7,mod=1e9+7,iv2=(mod+1)/2,iz=1<<21,oz=1<<22;
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
#define $1(x...)x
#define $2(x...)x
cll IO_res=IO(),T=1;
void init(){
}
aN a,p;
int cmp(cll x,cll y){
    return a[x]<a[y];
}
struct bit{
    aN f;
    ll n;
    void set(cll n_){
        n=n_;
    }
    void update(ll u,cll c){
        for(;u<=n;u+=u&-u)f[u]+=c;
    }
    ll query(ll l,ll r)const{
        ll res=0;
        for(;r>l;r&=~-r)res+=f[r];
        for(;l>r;l&=~-l)res-=f[l];
        return res;
    }
}dt;
void calc(){
    cll n=readll();
    rep(i,1,n)a[i]=readll(),p[i]=i;
    std::sort(p+1,p+n+1,cmp);
    ll l=n+1,r=0,nl=n+1,nr=0,sum=0;
    dt.set(n);
    per(i,n,1){
        cll u=p[i];
        if(a[u]==0)break;
        dt.update(u,1),l=std::min(l,u),r=std::max(r,u);
        if(i==1||a[u]!=a[p[i-1]]){
            if(l>nr)nl=nr+1,nr=r;
            else if(r<nl)nr=nl-1,nl=l;
            else nl=l,nr=r;
            sum+=dt.query(nl-1,nr),l=n+1,r=0;
            //rep(j,1,n)pc(dt.query(j-1,j)==0?'.':"<?>"[(j>=nl)+(j>nr)]);pc(10);
        }
    }
    writell(sum,10);
}
int main(){
    init();
    rep(i,1,T)calc();
    return 0;
}