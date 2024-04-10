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
ll n,q,x,y;
struct mat{
    ll v[3][3];
    void set(cll b){
        memset(v[0],-0x3f,sizeof v[0]),v[0][2]=(x+y)*b;
        memset(v[1],-0x3f,sizeof v[1]),v[1][1]=v[1][2]=y*b;
        memset(v[2],0,sizeof v[2]);
    }
    void merge(const mat&a,const mat&b){
        ll c[3][3];
        //a.print(),b.print();
        memset(c,-0x3f,sizeof c);
        rep(i,0,2)rep(k,0,2)rep(j,0,2)c[i][j]=std::max(c[i][j],a.v[i][k]+b.v[k][j]);
        memcpy(v,c,sizeof c);
        //print();
    }
    void print(int c=10)const{
        rep(i,0,2)rep(j,0,2)writell(v[i][j],j==2?10:32);
        c&&pc(c);
    }
};
struct vec{
    ll v[3];
    void merge(const vec&a,const mat&b){
        ll c[3];
        memset(c,-0x3f,sizeof c);
        rep(k,0,2)rep(j,0,2)c[j]=std::max(c[j],a.v[k]+b.v[k][j]);
        memcpy(v,c,sizeof c);
    }
    void merge(const mat&a,const vec&b){
        ll c[3];
        memset(c,-0x3f,sizeof c);
        rep(i,0,2)rep(k,0,2)c[i]=std::max(c[i],a.v[i][k]+b.v[k]);
        memcpy(v,c,sizeof c);
    }
    friend ll merge(const vec&a,const vec&b){
        ll ans;
        //a.print(),b.print();
        memset(&ans,-0x3f,1<<3);
        rep(i,0,2)ans=std::max(ans,a.v[i]+b.v[i]);
        return ans;
    }
    void print(int c=10)const{
        rep(i,0,2)writell(v[i],i==2?10:32);
        c&&pc(c);
    }
};
aN a;
struct sgt{
    mat f[N];
    ll n;
    void set(cll n_,cll*a){
        n=2<<(31^__builtin_clz(n_+2));
        rep(i,1,n)f[n+i].set(a[i]);
        per(i,n-1,1)pushup(i);
    }
    void pushup(cll u){
        f[u].merge(f[u<<1],f[u<<1|1]);
    }
    void update(cll u,int c){
        f[n+u].set(c);
        red(i,(u+n)>>1)pushup(i);
    }
    ll query(ll l,ll r)const{
        vec sl={},sr={};
        for(l+=n-1,r+=n+1;l^r^1;l>>=1,r>>=1)
        ~l&1&&(sl.merge(sl,f[l^1]),0),r&1&&(sr.merge(f[r^1],sr),0);
        return merge(sl,sr);
    }
}dt;
typedef long double ld;
typedef const ld cld;
void writeld(cld u,int w=15,int c=10){
    int t=0;
    cld a=u<0?pc(45),-u:u;
    rfor(ull n=(ull)a;n;n/=10)wt[++t]=n%10^48;
    for(t||pc(48);t;)pc(wt[t--]);
    w&&pc('.');
    ld n=a-(ull)a;
    ull r;
    rep(i,1,15)n*=10,r=(ull)n,pc(r^48),n-=r;
    c&&pc(c);
}
void calc(){
    cll n=readll(),q=readll();
    x=readll(),y=readll();
    if(x>y)std::swap(x,y);
    cld mul=1.0L/y/(x+y);
    rep(i,1,n)a[i]=readll();
    dt.set(n,a);
    rep(i,1,q)if(readll()==1){
        cll x=readll();
        dt.update(x,readll());
    }else{
        cll l=readll(),r=readll();
        //writell(dt.query(l,r),10);
        writeld(dt.query(l,r)*mul);
    }
}
int main(){
    init();
    rep(i,1,T)calc();
    return 0;
}