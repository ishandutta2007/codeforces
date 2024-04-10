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
cll N=1e6+7,mod=998244353,iv2=(mod+1)/2,g=3,iz=1<<21,oz=1<<22;
typedef ll aN[N];
char is[iz],*i1=is,*i2=is,os[oz],*o1=os,*o2=os+oz;
int fgc(){
    return i1==i2&&is==(i2=is+fread(is,1,iz,stdin))?-1:*i1++;
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
cll IO_res=IO(),T=readll();
void init(){
}
ll cnt,cl,top,ts;
aN next,to,head,dfn,low,col,st,ans;
void add_(cll u,cll v){
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
void add(cll u,cll v){
    add_(u,v),add_(v^1,u^1);
}
void dfs(cll u){
    dfn[u]=low[u]=++top,st[ts++]=u;
    rev(i,u,v)if(!dfn[v])dfs(v),low[u]=std::min(low[u],low[v]);
    else if(!col[v])low[u]=std::min(low[u],dfn[v]);
    if(low[u]==dfn[u])for(col[st[--ts]]=++cl;st[ts]!=u;col[st[--ts]]=cl);
}
#define $(x...)
$(aN op,x,y,z;)
void calc(){
    cll n=readll(),m=readll(),k=readll();
    memset(head,cnt=0,n*k<<4);
    memset(dfn,top=0,n*k<<4);
    memset(col,cl=0,n*k<<4);
    ts=0;
    ref(i,0,n)ref(j,0,k-2)add((i*(k-1)+j+1)<<1,(i*(k-1)+j)<<1);
    ref(i,0,n-1)ref(j,0,k)add((i*(k-1)+j)<<1,((i+1)*(k-1)+j)<<1);
    ref(i,0,m)switch(readll()){
        case 1:{
            cll x=readll()-1,y=readll();
            $(op[i]=1,::x[i]=x,::y[i]=y;)
            if(y==1)add_(x*(k-1)<<1|1,x*(k-1)<<1);
            else if(y==k)add_((x*(k-1)+k-2)<<1,(x*(k-1)+k-2)<<1|1);
            else add((x*(k-1)+y-2)<<1,(x*(k-1)+y-1)<<1);
            break;
        }
        case 2:{
            cll x=readll()-1,y=readll()-1,z=readll();
            $(op[i]=2,::x[i]=x,::y[i]=y,::z[i]=z;)
            if(z<k+1)add_((x*(k-1)+z-2)<<1,(x*(k-1)+z-2)<<1|1),add_((y*(k-1)+z-2)<<1,(y*(k-1)+z-2)<<1|1);
            ref(i,0,k-1)if(i+2<z&&i+2+k>z)add((x*(k-1)+i)<<1,(y*(k-1)+z-i-3)<<1|1);
            break;
        }
        case 3:{
            cll x=readll()-1,y=readll()-1,z=readll();
            $(op[i]=3,::x[i]=x,::y[i]=y,::z[i]=z;)
            if(z>k+1)add_((x*(k-1)+z-k-2)<<1|1,(x*(k-1)+z-k-2)<<1),add_((y*(k-1)+z-k-2)<<1|1,(y*(k-1)+z-k-2)<<1);
            ref(i,0,k-1)if(i+2<z&&i+2+k>z)add((x*(k-1)+i)<<1|1,(y*(k-1)+z-i-3)<<1);
            break;
        }
    }
    ref(i,0,n*k*2)if(!dfn[i])dfs(i);
    ref(i,0,n){
        ans[i]=1;
        ref(j,0,k-1){
            cll a=col[(i*(k-1)+j)<<1],b=col[(i*(k-1)+j)<<1|1];
            if(a==b)return static_cast<void>(myputs("-1"));
            if(a<b)ans[i]=j+2;
        }
    }
    //puts("-----------------------");
    ref(i,0,n)writell(ans[i],i==n-1?10:32);
    $(ref(i,0,n)assert(1<=ans[i]&&ans[i]<=k);)
    $(ref(i,0,n-1)assert(ans[i]<=ans[i+1]);)
    $(ref(i,0,m)op[i]==1?assert(ans[x[i]]!=y[i]):op[i]==2?assert(ans[x[i]]+ans[y[i]]<=z[i]):assert(ans[x[i]]+ans[y[i]]>=z[i]);)
}
int main(){
    init();
    rep(i,1,T)calc();
    return 0;
}
/*

*/