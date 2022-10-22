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
const ll N=1e5+7,mod=998244353,iz=1<<21,oz=1<<22;
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
ll f[2][666],g[2][666];
aN a;
int qm(ll&a,ll b=mod){
    return a>=b?a-=b,1:0;
}
void calc(){
    ll n=readll(),sum=0;
    rep(i,1,n)a[i]=readll();
    a[n+1]=0;
    per(i,n,1){
        const ll x=a[i],nx=a[i+1];
        ll nnow=1,nl=1;
        rfor(ll l=1,now=1;l<=x;l=(x/(x/l))+1,now++){
            //printf("%lld %lld ",l,x);
            ll nf=0,ng=0,rt=x/l+1;
            while(nl<=nx&&nx/nl>=rt)qm(nf+=f[~i&1][nnow]),qm(ng+=g[~i&1][nnow]),nnow++,nl=(nx/(nx/nl))+1;
            g[i&1][now]=ng,f[i&1][now]=(nf+ng*(l-1))%mod;
            if(x%(x/(x/l))==0&&nl<=nx&&nx/nl==rt-1){
                qm(g[i&1][now]+=g[~i&1][nnow]),f[i&1][now]=(f[i&1][now]+f[~i&1][nnow]+g[~i&1][nnow]*(x/(x/l)-1))%mod,
                nnow++,nl=(nx/(nx/nl))+1;
            }
            if(l==1)qm(++g[i&1][now]);
            //printf("%lld %lld %lld %lld\n",ng,nf,f[i&1][now],g[i&1][now]);
            qm(sum+=f[i&1][now]);
        }
    }
    writell(sum,10);
}
int main(){
    IO();
    ll T=readll();
    while(T--)calc();
    return 0;
}
/*
4
3
5 4 3
4
3 2 1 4
1
69
8
7264 40515 28226 92776 35285 21709 75124 48163

*/