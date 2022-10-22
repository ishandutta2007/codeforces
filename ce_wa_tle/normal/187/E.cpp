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
int fgc() {
    return i1==i2&&is==(i2=is+fread(i1=is,1,iz,stdin))?-1:*i1++;
}
void fout() {
    fwrite(os,o1-os,1,stdout),o1=os;
}
int fpc(int c) {
    if(o1==o2)fout();
    return*o1++=c;
}
int(*gc)()=getchar,(*pc)(int)=putchar,wt[126];
int readchar(int l=33,int r=126) {
    if(l>r)std::swap(l,r);
    int c=gc();
    for(; c<l||c>r; c=gc());
    return c;
}
ll readll() {
    ll x=0,w=1;
    int c=gc();
    for(; c<48||c>57; c=gc())c-45||(w=-w);
    for(; c>47&&c<58; c=gc())x=x*10+c-48;
    return x*w;
}
void writell(ll u,int c=32) {
    int t=0;
    rfor(ull n=u<0?pc(45),0ull-u:u; n; n/=10)wt[++t]=n%10^48;
    for(t||pc(48); t;)pc(wt[t--]);
    c&&pc(c);
}
int mygets(char*s,int c=0) {
    char*t=s+1;
    while((*s=gc())<33);
    while((*t=gc())>32)t++;
    c&&(*t++=c),*t=0;
    return t-s;
}
int myputs(const char*s,int c=10) {
    const char*t=s;
    while(*t)pc(*t++);
    c&&pc(c);
    return t-s+(c!=0);
}
aN a,c,g,t;
ll ans=mod*mod;
struct cmp_t{
    int operator()(ll x,ll y)const {
        return a[x]==a[y]?x<y:a[x]<a[y];
    }
    const ll*a;
};
void calc(const ll*a,ll n,ll l,ll s,ll x) {
    rep(i,1,n)c[i]=i,t[i]=0;
    t[n+1]=0;
    const cmp_t cmp={a};
    std::sort(c+1,c+n+1,cmp);
    ll res=0;
    rep(i,1,n)res+=a[i];
    rep(i,1,s-1)res+=a[i],t[i]=1;
    t[s]=-1;
    if(l==n)return;
    if(l==0) {
        if(s==1) {
            ans=res;
            rep(i,1,n)g[i]=i+1;
            if(x==-1)rep(i,1,n)g[i]=n-g[i]+2;
        }
        return;
    }
//    printf("%lld %lld\n",l,s);rep(i,1,n)printf("%lld ",a[i]);puts("");
    if(l<=s-1) {
        if(res<ans) {
            ans=res;
            rep(i,1,l-1)g[i]=s-i;
            g[l]=1;
            rep(i,l+1,s-1)g[i]=i-l+1;
            rep(i,s,n)g[i]=i+1;
            if(x==-1)rep(i,1,n)g[i]=n-g[i]+2;
        }
        return;
    }
    rep(i,n-l+s,n)res+=a[i],t[i]=1;
    ll min=res,mini=n-l+s,now=1;
    rep(i,n-l+s,n){
        res-=a[i],t[i]=0;
        while(now<=n&&t[c[now]])now++;
        ll r=cmp(i,c[now])?i:c[now];
        res+=2*a[r],t[r]=2;
//    printf("%lld %lld %lld\n",r,now,i);
        if(res<min)min=res,mini=i+1;
    }
//    printf("%lld\n",min);
    if(min<ans){
        ans=min;
        rep(i,1,n)if(t[i]==2)t[i]=0;
        rep(i,n-l+s,n)t[i]=1;
        rep(i,1,s-1)g[i]=s-i;
        ll now=1;
        rep(i,n-l+s,mini-1){
            while(now<=n&&t[c[now]])now++;
            t[i]=0,t[cmp(i,c[now])?i:c[now]]=2;
        }
        ll lst=s;
        now=s-1;
//        rep(i,1,n+1)printf("%lld\n",t[i]);
        rep(i,s+1,n+1)if(t[i]==0){
            g[++now]=i;
            per(j,i-1,lst+1)g[++now]=j;
            lst=i;
        }
        assert(now==n);
        if(x==-1)rep(i,1,n)g[i]=n-g[i]+2;
    }
}
int main() {
    IO();
    ll n=readll(),l=readll(),s=readll();
    rep(i,1,n)a[i]=readll();
    per(i,n,1)a[i]-=a[i-1];
    calc(a+1,n-1,l,s,1);
//    if(ans==mod*mod)return!myputs("-1");
//    writell(ans,10);
//    rep(i,1,n-1)writell(g[i]);
    rep(i,2,(n+2)/2)std::swap(a[i],a[n+2-i]);
    calc(a+1,n-1,n-1-l,n-s+1,-1);
    if(ans==mod*mod)return!myputs("-1");
    writell(ans,10);
    rep(i,1,n-1)writell(g[i]);
    return 0;
}