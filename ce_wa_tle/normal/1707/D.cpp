#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)((*#x!='/'||#x[1])&&(*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)))
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=1e6+7,iz=1<<21,oz=1<<22;
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
cll IO_res=IO(),T=1;
ll n,mod,cnt;
struct qmod_t{
    ull s,t;
    void set(cll b){
        s=b,t=((__int128)1<<64)/b;
    }
    ll operator()(ull b)const{
        ull res=b-((__int128)b*t>>64)*s;
        //assert(b%s==(res>=s?res-s:res));
        return res>=s?res-s:res;
    }
    ll operator[](ull b)const{
        return b>=s?b-s:b;
    }
}qmod;
struct node{
    ll val[2001];
    void merge_mul(const node&a,const node&b){
        rep(i,1,n)val[i]=qmod(a.val[i]*b.val[i]);
    }
    void merge_add(const node&a,const node&b){
        rep(i,1,n)val[i]=qmod[a.val[i]+b.val[i]];
    }
    void calc(const node&a){
        ll x=0;
        rep(i,1,n)val[i]=x=qmod[x+a.val[i]];
    }
    void print(cll u)const{
        writell(u,':');
        rep(i,1,n)writell(val[i],i==n?10:32);
    }
}f[2001],s[2001],g[2001],I;
aN head,to,next,d,ft,ift,pre;
ll pow(ll a,cll b,cll p=mod){
    ll res=1;
    red(i,b){
        if(i&1)res=res*a%p;
        a=a*a%p;
    }
    return res;
}
ll inv(ll a,ll b=mod){
    ll x=1,y=0;
    cll m=b;
    while(b){
        cll t=a/b,lb=b,ly=y;
        b=a-t*b,a=lb,y=x-t*y,x=ly;
    }
    return x<0?x+m:x;
}
ll C(ll n,ll m){
    return m<0||m>n?0:qmod(qmod(ft[n]*ift[m])*ift[n-m]);
}
void add(cll u,cll v){
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
void dfs(cll u,cll fa){
    ll lst=0;
    rev(i,u,v)if(v^fa)dfs(v,u),lst?g[v].merge_mul(g[lst],s[v]):(g[v]=s[v],void()),pre[v]=lst,lst=v;
    if(lst){
        f[u]=g[lst];
        node now=I;
        rfor(ll v=lst;v;v=pre[v]){
            ll ss=0;
            rep(i,1,n)f[u].val[i]=qmod(f[u].val[i]+f[v].val[i]*(ss=qmod(ss+now.val[i-1]*g[pre[v]].val[i-1])));
            v==lst?now=s[v],void():now.merge_mul(now,s[v]);
        }
    }else rep(i,1,n)f[u].val[i]=1;
    s[u].calc(f[u]);
    //f[u].print(u);
}
void calc(){
    cll n=::n=readll(),mod=::mod=readll();
    rep(i,1,n)I.val[i]=1;
    qmod.set(mod);
    rep(i,2,n){
        cll u=readll(),v=readll();
        add(u,v),add(v,u),d[u]++,d[v]++;
    }
    ll lst=0;
    g[lst]=I;
    rev(i,1,v)dfs(v,1),lst?g[v].merge_mul(g[lst],s[v]):(g[v]=s[v],void()),pre[v]=lst,lst=v;
    const node&res=g[lst];
    //res.print(1);
    ll x=ft[0]=1;
    rep(i,1,n)ft[i]=x=qmod(x*i);
    x=inv(x);
    //printf("%lld\n",x);
    per(i,n,0)ift[i]=x,x=qmod(x*i);
    rep(i,1,n-1){
        ll sum=0;
        rep(j,0,i)sum=qmod(sum+res.val[j]*((i^j)&1?mod-C(i,j):C(i,j)));
        writell(sum,i==n-1?10:32);
    }
}
int main(){
    rep(i,1,T)calc();
    return 0;
}