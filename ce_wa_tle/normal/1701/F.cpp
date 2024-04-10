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
struct sgt{
    struct node{
        ll v0,v1,v2,tag;
        void merge(const node&a,const node&b){
            v2=a.v2+(2*a.v1+a.v0*a.tag)*a.tag+b.v2+(2*b.v1+b.v0*b.tag)*b.tag;
            v1=a.v1+a.v0*a.tag+b.v1+b.v0*b.tag;
            v0=a.v0+b.v0;
        }
        void calc(){
            v0^=1;
        }
    }f[4<<(31^__builtin_clz(200000+7))];
    ll n;
    void set(cll n_){
        n=2<<(31^__builtin_clz(n_+2));
    }
    void pushup(cll u){
        f[u].merge(f[u<<1],f[u<<1|1]);
    }
    void update(ll l,ll r,cll c){
        for(l+=n-1,r+=n+1;l^r^1;pushup(l>>=1),pushup(r>>=1))
        ~l&1&&(f[l^1].tag+=c),r&1&&(f[r^1].tag+=c);
        red(i,l>>1)pushup(i);
    }
    void update(cll u){
        f[u+n].calc();
        red(i,(u+n)>>1)pushup(i);
    }
    ll query()const{
        return(f[1].v2-f[1].v1)/2;
    }
}dt;
aN t;
void calc(){
    dt.set(2e5);
    cll n=readll(),c=readll();
    rep(i,1,n){
        cll x=readll();
        dt.update(x);
        if((t[x]^=1)==1)dt.update(x+1,std::min(x+c,200000ll),1);
        else dt.update(x+1,std::min(x+c,200000ll),-1);
        writell(dt.query(),10);
    }
}
int main(){
    init();
    rep(i,1,T)calc();
    return 0;
}