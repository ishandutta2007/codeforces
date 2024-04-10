#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
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
    rfor(ull n=u<0?pc(45),0ull-u:u;n;n/=10)wt[++t]=n%10+48;
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
static inline void qm(ll&a,cll b=mod){
    a>=b&&(a-=b);
}
struct node{
    ll a,b,c;
    //a+by+c^2/2y^2
    node&operator*=(const node&m){
        c=(c*m.a+2*b*m.b+a*m.c)%mod,b=(b*m.a+m.b*a)%mod,a=a*m.a%mod;
        return*this;
    }
    void operator-=(const node&m){
        qm(a+=mod-m.a),qm(b+=mod-m.b),qm(c+=mod-m.c);
    }
}f[1000000];
int main(){
    IO();
    cll n=readll();
    ref(i,0,1000000)f[i].a=1;
    rep(i,1,n){
        ll x=readll();
        f[x]*=(node){2,x,x*x};
    }
    rfor(ll i=1;i<1000000;i*=10)for(ll j=0;j<1000000;j+=i*10)ref(k,0,i){
        node now={1,0,0};
        rfor(ll l=k+9*i+j,s=0;s<10;s++,l-=i)f[l]=now*=f[l];
    }
    rfor(ll i=1;i<1000000;i*=10)for(ll j=0;j<1000000;j+=i*10)ref(k,0,i)
        rfor(ll l=k+j,s=0;s<9;s++,l+=i)f[l]-=f[l+i];
    ll sum=0;
    ref(i,0,1000000)sum^=i*(f[i].c%mod);
    writell(sum);
    return 0;
}