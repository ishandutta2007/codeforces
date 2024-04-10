#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)r(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;
typedef unsigned long long ull;
const ll N=1e6+7,mod=998244353,iz=1<<21,oz=1<<22;
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
aN next,to,head,q,a,vis,d,f;
ll cnt=0;
void add(ll u,ll v){
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
ll inv(ll a,ll b=mod){
    ll x=1,y=0,m=b;
    while(b){
        const ll t=a/b;
        std::swap(a-=t*b,b),
        std::swap(x-=t*y,y);
    }
    return(x+m)%m;
}
ll pow(ll a,ll b,ll p=mod){
    ll res=1;
    red(i,b){
        if(i&1)res=res*a%p;
        a=a*a%p;
    }
    return res;
}
int qm(ll&a,ll b=mod){
    return a>=b?a-=b,1:0;
}
int main(){
    IO();
    ll n=readll(),m=readll(),h=1,t=0,u,v;
    rep(i,1,m)u=readll(),v=readll(),add(u,v),d[v]++;
    rep(i,1,n)if(!d[i])q[++t]=i;
    while(h<=t)rev(i,q[h++],v)if(!--d[v])q[++t]=v;
    per(i,n,1){
        const ll u=q[i];
        rev(j,u,v)vis[a[v]]=i;
        a[u]=0;
        while(vis[a[u]]==i)a[u]++;
    }
    const ll in=inv(n+1),mul=inv(512);
    rep(i,1,n)f[a[i]]++;
    ref(j,0,9)
    ref(i,0,256){
        const ll ia=i+(i>>j<<j),ib=ia|1<<j,a=f[ia],b=f[ib];
        qm(f[ia]=a+b),qm(f[ib]=a-b+mod);
    }
    ref(i,0,512)f[i]=(1+(mod-in)*inv(1-f[i]*in%mod+mod))%mod;
    ref(j,0,9)
    ref(i,0,256){
        const ll ia=i+(i>>j<<j),ib=ia|1<<j,a=f[ia],b=f[ib];
        qm(f[ia]=a+b),qm(f[ib]=a-b+mod);
    }
    writell(f[0]*mul%mod);
    return 0;
}