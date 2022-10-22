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
const ll N=1e5+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
const ll M=3e6+7;
typedef ll aM[M];
typedef const ll cll;
aM next,to,head,cl,st,low,dfn;
aN deep,l,s,t,w,f;
ll cnt,top,ts,col;
void add(cll u,cll v){
    //printf("%lld->%lld\n",u,v);
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
void add2(cll u,cll v){
    add(u,v),add(v^1,u^1);
}
int qmax(ll&a,cll b){
    return a<b?a=b,1:0;
}
int qmin(ll&a,cll b){
    return a>b?a=b,1:0;
}
void dfs0(cll u,cll fa){
    deep[u]=deep[f[u]=fa]+1;
    rev(i,u,v)if(v^fa)dfs0(v,u),qmax(l[u],l[v])&&(s[u]=v);
    l[u]++;
}
void dfs2(cll u,cll fa){
    dfn[u]=++top,t[u]=s[fa]==u?t[fa]:u;
    if(s[u])dfs2(s[u],u);
    rev(i,u,v)if(v^fa&&s[u]^v)dfs2(v,u);
}
typedef std::vector<ll>vll;
vll e[N],g[N],h[N<<2];
void update(cll u,cll l,cll r,cll ql,cll qr,cll c){
    if(ql<=l&&r<=qr)return h[u].push_back(c);
    cll mid=(l+r)>>1;
    if(ql<=mid)update(u<<1,l,mid,ql,qr,c);
    if(qr>mid)update(u<<1|1,mid+1,r,ql,qr,c);
}
ll now;
void solve(cll u,cll l,cll r,ll lst){
    cll v=h[u].size();
    ref(i,0,v){
        cll x=++now<<1;
        add2(x,lst),add2(h[u][i],lst),
        add2(h[u][i],x|1),lst=x;
    }
    if(l==r)return;
    cll mid=(l+r)>>1;
    solve(u<<1,l,mid,lst);
    solve(u<<1|1,mid+1,r,lst);
}
void dfs3(cll u){
    dfn[st[++ts]=u]=low[u]=++top;
    rev(i,u,v)if(!dfn[v])dfs3(v),qmin(low[u],low[v]);
    else if(!cl[v])qmin(low[u],dfn[v]);
    if(dfn[u]==low[u])for(cl[st[ts--]]=++col;st[ts+1]!=u;cl[st[ts--]]=col);
}
int main(){
    IO();
    cll n=readll();
    rep(i,2,n){
        cll u=readll(),v=readll();
        add(u,v),add(v,u);
    }
    dfs0(1,0),dfs2(1,0),memset(head,cnt=0,(n+1)<<3);
    cll m=readll();
    rep(i,2,2*m+1){
        ll u=readll(),v=readll();
        //printf("%lld %lld\n",v,u);
        while(t[u]!=t[v]){
            if(deep[t[u]]<deep[t[v]])std::swap(u,v);
            e[dfn[u]].push_back((ll)i),u=f[t[u]];
        }
        if(deep[u]<deep[v])std::swap(u,v);
        if(v==u)continue;
        //printf("%lld  %lld\n",v,u);
        update(1,1,n,dfn[v]+1,dfn[u],i);
        g[dfn[v]+1].push_back((ll)i);
    }
    //exit(0);
    now=m;
    rep(i,1,n)if(t[i]==i)w[dfn[i]]=l[i];
    rep(i,1,n)if(cll l=w[i]){
        ll lst=++now<<1;
        ref(j,i,i+l){
            cll v=g[j].size();
            ref(i,0,v)add2(g[j][i],lst|1);
            cll u=e[j].size();
            ref(i,0,u){
                cll x=++now<<1;
                add2(x,lst),add2(e[j][i],lst),
                add2(e[j][i],x|1),lst=x;
            }
        }
    }
    //printf("???");
    solve(1,1,n,++now<<1),memset(dfn,top=0,(n+1)<<3);
    rep(i,1,now*2)if(!dfn[i])dfs3(i);
    rep(i,1,m)if(cl[i<<1]==cl[i<<1|1])return!myputs("NO");
    myputs("YES");
    rep(i,1,m)writell(cl[i<<1]<cl[i<<1|1]?1:2,10);
    return 0;
}
/*
 1---> 1---> 1---> 1---> 1
0 <---0 <---0 <---0 <---0
|^    |^    |^    |^    |^
|| \\ || \\ || \\ || \\ ||
v|    v|    v|    v|    v|
01    01    01    01    01

 1
0|
^|
||
||
||    01
||    ^|
||____||
\______/
*/