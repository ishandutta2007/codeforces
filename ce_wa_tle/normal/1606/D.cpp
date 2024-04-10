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
const ll N=1e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
struct matrix{
    ll n,m;
    ll s[N];
    void set(ll n_,ll m_){
        n=n_,m=m_;
    }
    ll*operator[](ll b){
        return s+b*m-m-1;
    }
    const ll*operator[](ll b)const{
        return s+b*m-m-1;
    }
}a;
int qm(ll&a,ll b,ll x){//1i0a
    return x^(a<b)?a=b,1:0;
}
ll cmp(ll x,ll y){
    return a[x][1]<a[y][1];
}
aN lmin,rmax,c;
void calc(){
    ll n=readll(),m=readll();
    a.set(n,m);
    rep(i,1,n)rep(j,1,m)a[i][j]=readll();
    rep(i,1,n)c[i]=i;
    std::sort(c+1,c+n+1,cmp);
    ll s=0;
    while(s<m-1&&a[c[1]][s+1]<a[c[n]][s+1])s++;
    lmin[n+1]=mod,rmax[n+1]=0;
    //printf("s=%lld\n",s);
    per(i,n,1){
        lmin[i]=lmin[i+1],rmax[i]=rmax[i+1];
        rep(j,1,m)qm(j<=s?lmin[i]:rmax[i],a[c[i]][j],j<=s);
    }
    ll lmax=0,rmin=mod;
    rep(i,1,n-1){
        rep(j,1,m)qm(j<=s?lmax:rmin,a[c[i]][j],j>s);
        if(lmax<lmin[i+1]&&rmax[i+1]<rmin){
            myputs("YES");
            static char ans[N];
            ans[n+1]=0;
            memset(ans+1,'R',n);
            while(i)ans[c[i--]]='B';
            myputs(ans+1,32),writell(s,10);
            return;
        }
    }
    myputs("NO");
}
int main(){
    IO();
    ll T=readll();
    while(T--)calc();
    return 0;
}