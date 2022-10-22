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
typedef int ll;
typedef unsigned long long ull;
typedef const ll cll;
cll N=2e6+7,M=4e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
typedef ll aM[M];
aM next,to;
aN head,l,st,dfn,low,cl;
ll cnt,top,col,ts;
void add_(cll u,cll v){
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
void add(cll u,cll v){
    add_(u,v),add_(v^1,u^1);
}
int qmin(ll&a,cll b){
    return a>b?a=b,1:0;
}
int qmax(ll&a,cll b){
    return a<b?a=b,1:0;
}
void dfs(cll u){
    low[u]=dfn[st[++ts]=u]=++top;
    rev(i,u,v)if(!dfn[v])dfs(v),qmin(low[u],low[v]);
    else if(!cl[v])qmin(low[u],dfn[v]);
    if(dfn[u]==low[u])for(cl[st[ts--]]=++col;st[ts+1]!=u;cl[st[ts--]]=col);
}
int main(){
    IO();
    cll m1=readll(),n=readll(),m=readll(),m2=readll();
    rep(i,2,m)add((n+i)<<1,(n+i-1)<<1);
    rep(i,1,m1){
        cll u=readll(),v=readll();
        add(u<<1,v<<1|1);
    }
    rep(i,1,n)l[i]=readll(),l[i]!=1&&(add(i<<1|1,(n+l[i]-1)<<1),0),add((n+readll())<<1,i<<1);
    rep(i,1,m2){
        cll u=readll(),v=readll();
        add(u<<1|1,v<<1);
    }
    rep(i,2,n*2+1)if(!dfn[i])dfs(i);
    rep(i,1,n)if(cl[i<<1]==cl[i<<1|1])return!myputs("-1");
    ll s=0,t=0;
    rep(i,1,n)if(cl[i<<1]>cl[i<<1|1])qmax(s,l[st[++t]=i]);
    writell(t),writell(s,10);
    rep(i,1,t)writell(st[i]);
    return 0;
}