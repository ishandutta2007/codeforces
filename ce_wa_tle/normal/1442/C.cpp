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
const ll N=4e5+7,mod=998244353,iz=1<<21,oz=1<<22;
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
aN next,head,to,w,d,dis[22];
ll q_[N*22],*q=q_+N;
ll cnt;
void add(ll u,ll v,ll c){
    next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c;
}
int qm(ll&a,ll b){
    return a>b?a=b,1:0;
}
void bfs0(ll s){
    memset(d,0x3f,sizeof d),d[q[1]=s]=0;
    rfor(ll h=1,t=1;const ll u=h<=t?q[h++]:0;)rev(i,u,v){
        const ll f=w[i]^(d[u]&1);
        qm(d[v],d[u]+f)&&(q[f?++t:--h]=v);
    }
}
void bfs1(ll s){
    memset(dis,0x3f,sizeof dis),dis[0][s]=0,q[1]=s<<5;
    rfor(ll h=1,t=1;const ll u=h<=t?q[h++]:0;)rev(i,u>>5,v){
        const ll f=(w[i]^u^d[u>>5])&1,up=d[u>>5]+f+(u&31);
        if((up-d[v]<=1||up<=19)&&qm(dis[up-d[v]][v],dis[u&31][u>>5]+1))q[++t]=v<<5|(up-d[v]);
    }
}
ll pow(ll a,ll b,ll p=mod){
    ll res=1;
    red(i,b){
        if(i&1)res=res*a%p;
        a=a*a%p;
    }
    return res;
}
int main(){
    IO();
    ll n=readll(),m=readll(),u,v,ans,now=1;
    rep(i,1,m)u=readll(),v=readll(),add(u,v,0),add(v,u,1);
    bfs0(1),bfs1(1);
    ans=(dis[0][n]+(now=pow(2,d[n]))-1)%mod;
    rep(i,1,19-d[n])if(~dis[i][n])qm(ans,dis[i][n]+(now=now<<1)-1);
    writell(ans);
    return 0;
}