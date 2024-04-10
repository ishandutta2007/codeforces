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
const ll N=2e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
ll a[16],t[16];
void update(ll u,ll c){
    for(;u<16;u+=u&-u)t[u]+=c;
}
ll kth(ll k){
    ll u=0;
    red(i,8)if(k>i-t[u+i])k-=i-t[u+=i];
    return u+1;
}
int main(){
    IO();
    ll n=readll(),q=readll(),k=0,l=-1;
    rep(i,1,q)if(readll()==2)k+=readll();
    else{
        if(k!=l){
            ll n=l=k;
            rep(i,1,14)a[15-i]=n%i,n/=i,t[i]=0;
            rep(i,1,14)update(a[i]=kth(a[i]+1),1);
        }
        ll l=readll(),r=readll(),ans=0;
        if(l<=n-14)ans=((n-14)*(n-13)-l*(l-1))/2,l=n-13;
        if(r<=n-14)ans-=((n-14)*(n-13)-r*(r+1))/2,r=n-14;
        l-=n-14,r-=n-14,ans+=(r-l+1)*(n-14);
        rep(i,l,r)ans+=a[i];
        writell(ans);
    }
    return 0;
}