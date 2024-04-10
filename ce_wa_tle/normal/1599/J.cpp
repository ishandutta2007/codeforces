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
const ll N=2e5+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
aN a,p,sl,sr;
const ll M=1.3e7;
int id[M];
std::vector<ll>h[14];
int main(){
    IO();
    ll n=readll(),f=0;
    rep(i,1,n)a[i]=readll(),a[i]&1||(f=i);
    if(n==2)return a[1]==a[2]?myputs("YES\n0",32),writell(a[1]),0:!myputs("NO");
    if(n==3&&(a[1]^a[2]^a[3])&1)return!myputs("No");
    if(n==3)a[4]=1;
    if(f){
        myputs("Yes");
        std::swap(a[f],a[1]);
        if(n>=4&&~(a[2]^a[4])&1)std::swap(a[3],a[4]);
        if(n>=4&&~(a[3]^a[4])&1)std::swap(a[2],a[4]);
        ll x=(a[1]+a[3]-a[2])/2;
        rep(i,1,n)writell(x=a[i]-x);
        return 0;
    }
    ll m=std::min(n,26ll),g=m/2,l=m/2,r=m-l;
    ref(i,0,r)p[1<<i]=1,sr[1<<i]=a[l+1+i];
    ref(i,0,1<<r)h[p[i]=p[i&-i]+p[i&~-i]].push_back((ll)i),sr[i]=sr[i&-i]+sr[i&~-i];
    ref(i,0,l)sl[1<<i]=a[i+1];
    ref(i,0,(1<<l)){
        sl[i]=sl[i&-i]+sl[i&~-i];
        const std::vector<ll>&h=::h[g-p[i]];
        rfor(ll j=0,up=h.size();j<up;j++)
        if(int&tm=id[sl[i]+sr[h[j]]]){
            myputs("Yes");
            ll x=h[j]<<l|i,y=tm,z=x&y;
            x&=~z,y&=~z;
            static aN b;
            ll t=-1;
            ref(i,0,m)if(x>>i&1)b[t+=2]=a[i+1],a[i+1]=-1;
            ref(i,t=0,m)if(y>>i&1)b[t+=2]=a[i+1],a[i+1]=-1;
            x=0;
            rep(i,1,t)writell(x=b[i]-x);
            rep(i,1,n)if(~a[i])writell(x=a[i]-x);
            return 0;
        }else tm=h[j]<<l|i;
    }
    myputs("NO");
    return 0;
}