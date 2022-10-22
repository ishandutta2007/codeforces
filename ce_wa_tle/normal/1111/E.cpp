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
aN next,to,head,l,s,d,c,a,end,st;
ll cnt,top,f[333];
void add(ll u,ll v){
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
void dfs(ll u,ll fa){
    c[++s[u]]=++top;
    rev(i,u,v)if(v^fa)dfs(v,u);
    if(!c[s[fa]+1])end[++top]=c[s[fa]],c[++s[fa]]=top;
}
int main(){
    IO();
    const ll n=readll(),q=readll(),m=n*2-2;
    rep(i,2,n){
        const ll u=readll(),v=readll();
        add(u,v),add(v,u),d[u]++,d[v]++;
    }
    rep(i,1,n)s[i+1]=s[i]+d[i],l[i]=s[i]+1;
    dfs(1,0);
    rep(i,1,n)end[c[l[i]]]=c[s[i]]-m,end[c[l[i]]+m]=c[s[i]];
    rep(i,1,q){
        const ll k=readll(),up=readll(),r=c[l[readll()]];
        rep(i,1,k){
            const ll u=readll();
            a[i]=r>c[s[u]]?c[l[u]]+m:*std::lower_bound(c+l[u],c+s[u]+1,r);
        }
        std::sort(a+1,a+k+1);
        ll t=0,sum=0;
        memset(f+1,0,up<<3),f[0]=1;
        rep(i,1,k){
            const ll x=a[i]==r?mod:end[a[i]];
            while(t&&st[t]<x)t--;
            per(j,up,t+1)f[j]=(f[j-1]+f[j]*(j-t))%mod;
            f[t]=0,st[++t]=x;
        }
        rep(i,1,up)sum+=f[i];
        writell(sum%mod,10);
    }
    return 0;
}