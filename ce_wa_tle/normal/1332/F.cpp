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
aN next,to,head;
ll f[N][4],cnt;
void add(ll u,ll v){
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
int qm(ll&a,ll b=mod){
    return a>=b?a-=b,1:0;
}
void dfs(ll u,ll fa){
    ll(&now)[4]=f[u],cnt=1;
    ref(i,0,4)now[i]=1;
    rev(i,u,v)if(v^fa){
        dfs(v,u);
        const ll(&lst)[4]=f[v];
        now[0]=now[0]*(lst[0]+lst[1]+lst[2]+lst[3])%mod;
        now[1]=now[1]*(lst[0]+lst[1]+lst[2])%mod;
        now[2]=now[2]*(lst[0]+lst[1]+lst[2]+lst[3])%mod;
        now[3]=now[3]*(lst[0]+lst[1]+lst[2])%mod;
        cnt=cnt*(lst[0]+lst[1])%mod;
    }
    now[1]=(now[1]+mod-cnt)%mod;
}
int main(){
    IO();
    const ll n=readll();
    ll u,v;
    rep(i,2,n)u=readll(),v=readll(),add(u,v),add(v,u);
    dfs(1,0);
    writell((f[1][0]+f[1][1]-1)%mod);
    return 0;
}