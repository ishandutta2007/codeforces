#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=1e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
    rfor(ull n=u<0?pc(45),0ull-u:u;n;n/=10)wt[++t]=n%10+48;
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
aN st[22];
aN p,np,next,to,head,tail,deep,fail,s,sl;
aN lans,rans,sans,cnts,type,mx,mn,l,r;
ll cnt,top;
static inline void add(cll u,cll v){
    //printf("%lld->%lld\n",u,v);
    to[tail[u]=next[tail[u]]=++cnt]=v;
    if(!head[u])head[u]=cnt;
}
static inline ll max(cll a,cll b){
    return a<b?b:a;
}
static inline ll min(cll a,cll b){
    return a<b?a:b;
}
static inline void qmax(ll&a,cll b){
    a<b&&(a=b);
}
static inline void qmin(ll&a,cll b){
    b<a&&(a=b);
}
static inline ll query_max(ll l,ll r){
    if(l>r)std::swap(l,r);
    cll lg=31^__builtin_clz(++r-l);
    return max(st[lg][l],st[lg][r-(1<<lg)]);
}
static inline ll min2(cll a,cll b){
    return deep[a]<deep[b]?a:b;
}
static inline ll query_lca(ll l,ll r){
    cll lg=31^__builtin_clz(r-l);
    //printf("%lld\n",min2(st[lg][l],st[lg][r-(1<<lg)]));
    return min2(st[lg][l],st[lg][r-(1<<lg)]);
}
ll dfs0(cll u){
    ll cnt=0,sum=0;
    rev(i,u,v)cnt&&(st[0][++top]=u),deep[v]=deep[u]+1,lans[v]=sum+lans[u]+(type[u]?cnt*(cnt-1)/2:0),sum+=dfs0(v),cnt++;
    cnts[u]=cnt;
    return rans[u]=(type[u]?cnt*(cnt-1)/2:1)+sum;
}
std::vector<ll>son[N];
ll dfs2(cll u){
    cll now=cnts[u];
    ll cnt=0;
    rev(i,u,v)sans[v]=sans[u]+(type[u]?++cnt,cnt*(now-cnt+1)-1:1),son[u].push_back(dfs2(v)),rans[u]=rans[v];
    if(!now)return rans[u]=-lans[u]-sans[u],np[u];
    else return son[u][0];
}
ll query(cll v,cll u){
    assert((ll)son[v].size()==cnts[v]);
    return std::upper_bound(son[v].begin(),son[v].end(),u)-son[v].begin();
}
ll query(cll lca,cll u,cll v){
    if(!type[lca])return 0;
    return query(lca,u)*(cnts[lca]-query(lca,v)+1)-1;
}
int main(){
    IO();
    //gc=getchar;
    cll n=readll();
    rep(i,1,n)st[0][p[i]=readll()]=i;
    rep(i,1,n)np[i]=st[0][i];
    rep(i,0,19)rep(j,1,n-(2<<i)+1)st[i+1][j]=max(st[i][j],st[i][j+(1<<i)]);
    sl[1]=n+1;rep(i,2,n)sl[i]=query_max(p[i],p[i-1]);
    ll now=n,t=0;
    rep(i,1,n){
        ll u=p[i];
        //printf("u=====%lld %lld\n",u,sl[i]);
        if(sl[i]>i){
            s[++t]=u,mx[t]=u,mn[t]=u,l[t]=i,fail[t]=t-1;
            continue;
        }
        ll mxvl=u,mnvl=u,lvl=i,failvl=t;
        rfor(ll g=t,v;v=s[g],g;g=fail[g]){
            //rep(i,1,t)printf("%lld ",s[i]);puts(" is s");
            //printf("v=%lld %lld\n",v,type[v]);
            if(max(mx[g],mxvl)-min(mn[g],mnvl)==i-l[g]){
                ll nxt;
                //printf("%lld %lld %lld %lld\n",mx[g],mn[g],lvl,l[g]);
                if(mx[g]-mn[g]==lvl-l[g]-1){
                    cll val=mx[g]<p[i]?1:2;
                   //printf("%lld %lld %lld\n",val,mx[g],type[v]);
                    if(type[v]==val)add(nxt=v,u);
                    else type[nxt=++now]=val,add(nxt,v),add(nxt,u);
                }else{
                    nxt=++now;
                    rep(i,g,t)add(nxt,s[i]);
                    assert(t-g+1>=3);
                    add(nxt,u);
                }
                qmax(mxvl,mx[g]),qmin(mnvl,mn[g]),lvl=l[g],failvl=fail[g];
                t=g-1,u=nxt;
            }
            if(sl[l[g]]>i){
                s[++t]=u,mx[t]=mxvl,mn[t]=mnvl,l[t]=lvl,fail[t]=failvl;
                break;
            }
            if(g!=t+1)qmax(mx[fail[g]],mx[g]),qmin(mn[fail[g]],mn[g]);
        }
    }
    assert(t==1);
    cll rt=s[t],ansrt=dfs0(rt);
    sans[rt]=1,dfs2(rt);
    rep(i,1,now)rans[i]+=ansrt;
    //rep(i,1,now)printf("%lld : %lld %lld %lld %lld %lld\n",i,type[i],lans[i],sans[i],rans[i],ansrt);
    rep(i,0,19)rep(j,1,n-(2<<i)+1)st[i+1][j]=min2(st[i][j],st[i][j+(1<<i)]);
    cll q=readll();
    rep(i,1,q){
        cll l=readll(),r=readll(),g=(l==1)<<1|(r==n);
        ll ans,lca;
        switch(g){
            case 0:lca=query_lca(l-1,r+1),
    //printf("%lld %lld %lld lca=%lld %lld %lld\n",rans[p[l-1]],lans[p[r+1]],sans[lca],lca,query(lca,l-1,r+1),ansrt),
    ans=rans[p[l-1]]+lans[p[r+1]]+sans[lca]+query(lca,l-1,r+1)-ansrt;break;
            case 1:ans=rans[p[l-1]];break;
            case 2:ans=lans[p[r+1]];break;
            case 3:ans=ansrt;break;
        }
        writell(ans,10);
    }
    return 0;
}
/*
4
1 4 2 3 
3
2 3
2 3
4 4
*/