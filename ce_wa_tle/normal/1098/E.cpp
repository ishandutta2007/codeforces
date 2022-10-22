#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=1e6+7,mod=998244353,iz=1<<21,oz=1<<22;
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
static inline ll inv(ll a,ll b=mod){
    ll x=1,y=0;
    cll m=b;
    while(b){
        cll t=a/b,lb=b,ly=y;
        b=a-t*b,a=lb,y=x-t*y,x=ly;
    }
    return(x+m)%m;
}
static inline ll gcd(ll a,ll b){
    while(b){
        cll t=a/b,lb=b;
        b=a-t*b,a=lb;
    }
    return a;
}
static inline ll f(ll a,ll b,ll c,ll n){
    n++;
    ll res=0;
    while(n){
        cll da=a/c,db=b/c,dm=(a*n+b)/c,lc=c,m=dm-da*n-db;
        res+=n*(n-1)/2*da+n*db,b=a*n+b-c*dm,c=a-da*c,a=lc,n=m;
    }
    return res;
}
static inline ll mn(cll a,cll b){
    return a<b?a:b;
}
static inline ll n2(cll n){
    return n*(n+1)/2;
}
static inline ll calc(cll A,cll B,cll a,cll b,cll c){
    //0<=x<=A
    //0<=x<=B
    //ax+by<=c
    if(A<0||B<0||c<0)return 0;
    cll s=mn(A,c/a),t=mn(B,c/b),p=a*s+b*t-c-1,r=(s+1)*(t+1);
    if(p<0)return r;
    cll n=p/a;
    return r-f(a,p-a*n+b,b,n);
}
static inline ll calc(cll n,cll m){
    return m*(2*n-m+1)/2;
}
aN cnt,sum,c;
static inline ll check(ll mid){
    ll res=0,j=0;
    rep(i,1,1e5)if(c[i]){
        res+=calc(c[i],mn(c[i],(mid-1)/i));
        if(i<j)res+=c[i]*(cnt[j-1]-cnt[i])+calc(c[i]-1,c[j]-1,i,j,mid-(sum[j-1]-sum[i])-i-j-1);
        while(j<=1e5&&sum[j]-sum[i]<mid)
        if(i<++j)res+=calc(c[i]-1,c[j]-1,i,j,mid-(sum[j-1]-sum[i])-i-j-1);
    }
    return res;
}
int main(){
    IO();
    //gc=getchar;
    cll n=readll();
    ll v[26],w[26],fv[26],fw[26],t=0;
    rep(i,1,n){
        ll g=0,r=0,lst=i+1;
        v[++t]=readll(),w[t]=i;
        per(j,t,1){
            if(!g||v[j]%g)fv[++r]=g=gcd(g,v[j]);
            c[g]+=lst-w[j],lst=fw[r]=w[j];
        }
        for(t=0;r;)w[++t]=fw[r],v[t]=fv[r--];
    }
    ll x=0,y=0;
    rep(i,1,1e5)sum[i]=x+=c[i]*i,cnt[i]=y+=c[i];
    cll m=n2(n),z=n2(m),k=(z+1)/2;
    ll l=1,r=sum[100000];
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid)<k)l=mid+1;
        else r=mid-1;
    }
    writell(l-1);
    return 0;
}