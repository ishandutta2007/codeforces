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
const ll N=1.1e6+7,mod=998244353,iz=1<<21,oz=1<<22;
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
aN id,f;
char s[N];
template<ll mod,ll k>
struct hs{
    aN p,s;
    void calc(const ll*f,ll n){
        rep(i,1,n)s[i]=(s[i-1]*k+f[i])%mod;
        rep(i,p[0]=1,n)p[i]=p[i-1]*k%mod;
    }
    int cmp(ll l1,ll l2,ll w,ll rev)const{
        const ll z=p[w],h1=(s[l1+w]+(mod-z)*s[l1])%mod,h2=(s[l2+w]+(mod-z)*s[l2])%mod;
        if(rev)return(h1+h2)*(k-1)%mod==z-1;
        else return h1==h2;
    }
};
hs<1000000007,93>t1;
hs<1000000009,333>t2;
int main(){
    IO();
    const ll n=readll();
    mygets(s+1);
    ll t=0;
    rep(i,1,n)if(s[i]==49)id[i]=t;else f[id[i]=++t]=i&1;
    t1.calc(f,t),t2.calc(f,t);
    const ll m=readll();
    rep(i,1,m){
        const ll l1=readll(),l2=readll(),len=readll(),r1=l1+len,r2=l2+len;
        const ll l01=id[l1-1],r01=id[r1-1],l02=id[l2-1],r02=id[r2-1];
        if(r01-l01!=r02-l02){
            myputs("No");
            continue;
        }
        const ll w=r01-l01,g=(l1^l2)&1;
        myputs(t1.cmp(l01,l02,w,g)&&t2.cmp(l01,l02,w,g)?"Yes":"No");
    }
    return 0;
}
/*
10
0100001001
1
5 3 5
*/