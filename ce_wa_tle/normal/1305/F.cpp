#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout);
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
aN a,p,g;
ll tp,tg,ans,n;
void calc(ll n){
    if(!n)return;
    rep(i,1,tp)if(n%p[i]==0)for(g[++tg]=p[i];n%p[i]==0;n/=p[i]);
    if(n>1)g[++tg]=n;
}
void check(ll p){
    ll sum=0;
    rep(i,1,n){
        const ll r=a[i]%p;
        if(a[i]<p)sum+=p-a[i];
        else sum+=std::min(r,p-r);
        if(sum>ans)return;
    }
    ans=sum;
}
int main(){
    IO();
    srand(time(0));
    const ll n=::n=readll(),m=1e6;
    p[0]=mod,ans=n;
    rep(i,2,m)rep(j,p[i]||(p[++tp]=i),tp&&p[j]*i<=m&&i%p[j-1])p[i*p[j]]=1;
    rep(i,1,n)a[i]=readll();
    std::random_shuffle(a+1,a+n+1);
    rep(i,1,30){
        const ll p=(rand()*RAND_MAX|rand())%n+1;
        rep(j,-1,1)calc(a[p]+j);
    }
    std::sort(g+1,g+tg+1);
    const ll s=std::unique(g+1,g+tg+1)-g-1;
    rep(i,1,s)check(g[i]);
    writell(ans);
    return 0;
}