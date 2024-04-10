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
typedef const ll cll;
aN next,to,head,st,dfn,low,a,f;
ll cnt,top,ts,col=mod;
void add(cll u,cll v){
    //printf("%lld --> %lld\n",u,v);
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
ll get(cll u){
    return u<0?-u<<1:u<<1|1;
}
int qm(ll&a,cll b){
    return a>b?a=b,1:0;
}
int dfs(cll u){
    dfn[st[++ts]=u]=low[u]=++top;
    rev(i,u,v)if(!dfn[v])if(!dfs(v))return 0;
    else qm(low[u],low[v]);else qm(low[u],dfn[v]);
    if(low[u]==dfn[u]){
        ll mn=u,mx=0,r=0,s=ts;++col;
        rfor(ll x=0;x!=u&&(x=st[ts--]);dfn[x]=col){
            if(dfn[x^1]==col)return 0;
            qm(mn,x);
            if(f[x]){if(mx)return 0;mx=x,f[x]=0;}
            if(!r)rev(i,x,v)if(dfn[v]>=mod&&f[v])r=1;
        }
        if(mx&&(mx!=mn||r))return 0;
        if(r||mx)per(i,s,ts+1)f[st[i]]=1;
    }
    return 1;
}
int calc(){
    cll n=readll(),m=readll(),sz=(n+2)<<4;
    memset(head,cnt=0,sz),memset(dfn,top=ts=0,sz);
    rep(i,1,n)f[i*2]=f[i*2+1]=readchar()==65;
    rep(i,1,m){
        cll u=get(readll()),v=get(readll());
        add(u^1,v),add(v^1,u);
    }
    rep(i,2,n*2+1)if(!dfn[i]&&!dfs(i))return 0;
    return 1;
}
int main(){
    IO();
    ll T=readll();
    while(T--)myputs(calc()?"TRUE":"FALSE");
    return 0;
}