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
const ll N=1.1e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
aN next,to,head,c1,c0,c2,id,w,st,a,link,in,dfn,low,vis;
ll cnt,top,ts,col;
void add(ll u,ll v,ll i=0){
    //if(!i)printf("%lld %lld\n",u,v);
    next[++cnt]=head[u],to[head[u]=cnt]=v,id[cnt]=i;
}
int qmin(ll&a,ll b){
    return a>b?a=b,1:0;
}
int qmax(ll&a,ll b){
    return a<b?a=b,1:0;
}
void dfs(ll u){
    in[st[++ts]=u]=1,dfn[u]=low[u]=++top;
    rev(i,u,v)if(!dfn[v])dfs(v),qmin(low[u],low[v]);
    else if(in[v])qmin(low[u],dfn[v]);
    if(low[u]==dfn[u])for(in[st[ts]]=0,c2[st[ts--]]=++col;st[ts+1]!=u;ts--)in[st[ts]]=0,c2[st[ts]]=col;
}
int check(ll mid,ll l,ll r,ll r2){
    col=0,memset(dfn+l,0,(r2-l+1)<<3);
    static aN cur;
    static ll curcnt=0;
    if(!curcnt){
        curcnt=cnt,memcpy(cur+l,head+l,(r2-l+1)<<3);
    }
    memcpy(head+l,cur+l,(r2-l+1)<<3),cnt=curcnt;
    rep(i,l,r)if(a[i]>mid)add(i,i^1);
    rep(i,l,r)if(!dfn[i])dfs(i);
    rep(i,l,r)if(c2[i]==c2[i^1])return 0;
    return 1;
}
void dfs0(ll u,ll c,ll lk){
    if(c1[u]!=c)return;
    rev(i,u,v)if(c0[id[i]]==c&&!link[id[i]])link[id[i]]=lk,dfs0(v,c,lk^1);
}
aN cp;
int main(){
    IO();
    const ll n=readll(),m=readll(),fst=(n&~1)+2;
    ll cntl=n&~1;
    rep(i,1,m){
        const ll u=readll(),v=readll();
        cp[i]=c0[i]=readll(),w[i]=readll();
        add(u,v,i),add(v,u,i);
    }
    std::sort(cp+1,cp+m+1);
    rep(i,1,m)c0[i]=std::lower_bound(cp+1,cp+m+1,c0[i])-cp;
    rep(u,1,n){
        rev(i,u,v)if(ll&a=vis[c0[id[i]]])if(c1[u])return!myputs("No");
        else c1[u]=c0[id[i]];else a=1,static_cast<void>(v);
        rev(i,u,v)vis[c0[id[i]]]=0,static_cast<void>(v);
    }
    rep(u,1,n)rev(i,u,v)if(c0[id[i]]!=c1[u]&&c0[id[i]]==c1[v]&&!link[id[i]])link[id[i]]=(cntl+=2),dfs0(v,c1[v],cntl^1);
    rep(u,1,n)rev(i,u,v)if(c0[id[i]]==c1[u]&&!link[id[i]])link[id[i]]=(cntl+=2),dfs0(v,c1[u],cntl^1);
    const ll end=cntl+1;
    ll now=end;
    rep(u,1,n){
        static aN st;
        ll t=0;
        rev(i,u,v)if(c0[id[i]]!=c1[u]&&c0[id[i]]==c1[v])st[++t]=link[id[i]];
        //rep(i,1,t)printf("%lld ",st[i]);puts("");
        if(c1[u])rep(i,1,t)add(st[i],st[i]^1);
        else{
            ref(i,1,t)add(++now,st[i]^1),add(st[i+1],now),i==1||(add(now,now-1),0);
            ref(i,1,t)add(++now,st[t-i+1]^1),add(st[t-i],now),i==1||(add(now,now-1),0);
        }
    }
    rep(i,1,m)qmax(a[link[i]],w[i]);
    //rep(i,1,n)printf("%lld ",c1[i]);puts("");
    //rep(i,1,m)printf("%lld ",link[i]);puts("");
    //rep(i,fst,end)printf("%lld ",a[i]);puts("");
    //exit(0);
    ll l=0,r=mod*mod;
    while(l<=r){
        const ll mid=(l+r)>>1;
        if(check(mid,fst,end,now))r=mid-1;
        else l=mid+1;
    }
    const ll ans=r+1;
    if(ans>=mod*mod)return!myputs("No");
    myputs("Yes");
    writell(ans);
    check(ans,fst,end,now);
    ll t=0;
    rep(i,fst,end)if(c2[i]<c2[i^1])a[i]=-1;
    //rep(i,fst,end)printf("a[%lld]=%lld ",i,a[i]);
    rep(i,1,m)if(!~a[link[i]])t++;
    writell(t,10);
    rep(i,1,m)if(!~a[link[i]])writell(i);
    return 0;
}