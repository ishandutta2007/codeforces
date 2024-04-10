#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],v;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i=i>>1)
#define IO(x...)((*#x!='/'&&#x[1])&&(*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)))
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=3e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
void qm(ll&a,cll b=mod){
    a>=b&&(a-=b);
}
ll gcd(ll a,ll b){
    while(b){
        cll t=a/b,lb=b;
        b=a-t*b,a=lb;
    }
    return a;
}
void calc(){
    cll s0=readll(),d0=readll(),n0=readll(),l0=s0+(n0-1)*d0;
    cll s1=readll(),d1=readll(),n1=readll(),l1=s1+(n1-1)*d1;
    if(d1%d0||(s1-s0)%d0||s1<s0||l1>l0)return writell(0,10);
    if(n1<=1)return writell(-1,10);
    if(s1-d1<s0||l1+d1>l0)return writell(-1,10);
    ll s=d1/d0,sum=0;
    rfor(ll i=1;i*i<=d1;i++)if(d1%i==0){
        {
            cll u=i;
            if(gcd(s,u)==1)sum+=u*u%mod;
        }
        if(i*i!=d1){
            cll u=d1/i;
            if(gcd(s,u)==1)sum+=u*u%mod;
        }
    }
    writell(sum%mod,10);
}
int main(){
    rep(i,1,T)calc();
    return 0;
}