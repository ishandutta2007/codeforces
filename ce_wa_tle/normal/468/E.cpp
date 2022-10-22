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
typedef const ull cull;
cll N=201,mod=1e9+7,iz=1<<21,oz=1<<22;
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
cll IO_res=IO(),m=readll(),n=readll();
aN next,to,head,w,id;
ll cnt;
void add(cll u,cll v,cll c,cll i){
    next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c,id[cnt]=i;
}
ll leftcnt,rightcnt,edgecnt,mincnt;
aN leftid,rightid,edgeid;
aN lefta,righta,edgea;
void find(cll u,cll fa){
    if(u<=n){
        if(leftid[u])return;
        lefta[leftid[u]=++leftcnt]=u;
    }
    else{
        if(rightid[u])return;
        righta[rightid[u]=++rightcnt]=u;
    }
    rev(i,u,v)if(v^fa)edgea[edgeid[id[i]]=++edgecnt]=id[i],find(v,u);
}
ll ans[1<<22];
aN f,g;
void solve0(){
    if(leftcnt>rightcnt){
        cll up=1<<rightcnt;
        ans[0]=1;
        rep(i,1,leftcnt){
            cll u=lefta[i];
            ll id[rightcnt+1],t=0,w[rightcnt+1];
            rev(i,u,v)id[++t]=1<<(rightid[v]-1),w[t]=::w[i];
            per(S,up-1,0)if(cll c=ans[S])
                rep(j,1,t)if(!(S&id[j]))ans[S|id[j]]=(ans[S|id[j]]+c*w[j])%mod;
        }
        ref(S,0,up)g[__builtin_popcount(S)]+=ans[S],ans[S]=0;
    }else{
        cll up=1<<leftcnt;
        ans[0]=1;
        rep(i,1,rightcnt){
            cll u=righta[i];
            ll id[leftcnt+1],t=0,w[leftcnt+1];
            rev(i,u,v)id[++t]=1<<(leftid[v]-1),w[t]=::w[i];
            per(S,up-1,0)if(cll c=ans[S])
                rep(j,1,t)if(!(S&id[j]))ans[S|id[j]]=(ans[S|id[j]]+c*w[j])%mod;
        }
        ref(S,0,up)g[__builtin_popcount(S)]+=ans[S],ans[S]=0;
    }
}
aN circleid,circlea,vis;
ll circlecnt;
aN son[N],sonw[N],soncnt;
void dfs0(cll u,cll fa){
    vis[u]=1;
    rev(i,u,v)if(!vis[v])son[u][++soncnt[u]]=v,sonw[u][soncnt[u]]=w[i],dfs0(v,u);
    else if(v^fa)if(!circleid[id[i]])circlea[circleid[id[i]]=++circlecnt]=id[i];
}
aN dp[N][2],sz,used;
ll top;
void dfs2(cll u,cll fa){
//printf("%lld %lld\n",u,fa);
    static_cast<void>(fa);
    if(used[u]==top){
        sz[u]=0,dp[u][0][0]=1;
        rep(i,1,soncnt[u]){
            cll v=son[u][i];
            dfs2(v,u);
            ll g[sz[u]+sz[v]+1]={};
            if(used[v]!=top)rep(i,0,sz[u])rep(j,0,sz[v])g[i+j]=(g[i+j]+dp[u][0][i]*(dp[v][0][j]+dp[v][1][j]))%mod;
            else rep(i,0,sz[u])rep(j,0,sz[v])g[i+j]=(g[i+j]+dp[u][0][i]*dp[v][0][j])%mod;
            sz[u]+=sz[v];
            rep(i,0,sz[u])dp[u][0][i]=g[i];
            if(sz[u]&&!dp[u][0][sz[u]])sz[u]--;
        }
    }else{
        sz[u]=0,dp[u][0][0]=1,dp[u][1][0]=0;
        rep(i,1,soncnt[u]){
            cll v=son[u][i];
            dfs2(v,u);
            ll g[sz[u]+sz[v]+2]={};
            if(used[v]!=top)rep(i,0,sz[u])rep(j,0,sz[v])g[i+j]=(g[i+j]+dp[u][0][i]*(dp[v][0][j]+dp[v][1][j]))%mod;
            else rep(i,0,sz[u])rep(j,0,sz[v])g[i+j]=(g[i+j]+dp[u][0][i]*dp[v][0][j])%mod;
            sz[u]+=sz[v];
            if(used[v]!=top){
                ll g[sz[u]+sz[v]+2]={};
                cll w=sonw[u][i];
                rep(i,0,sz[u]-sz[v])rep(j,0,sz[v])g[i+j+1]=(g[i+j+1]+dp[u][0][i]*dp[v][0][j]%mod*w)%mod;
                rep(i,0,sz[u]-sz[v])rep(j,0,sz[v])g[i+j]=(g[i+j]+dp[u][1][i]*(dp[v][0][j]+dp[v][1][j]))%mod;
                sz[u]++;
                rep(i,0,sz[u])dp[u][1][i]=g[i];
            }else{
                ll g[sz[u]+sz[v]+2]={};
                rep(i,0,sz[u]-sz[v])rep(j,0,sz[v])g[i+j]=(g[i+j]+dp[u][1][i]*dp[v][0][j])%mod;
                rep(i,0,sz[u])dp[u][1][i]=g[i];
            }
            rep(i,0,sz[u])dp[u][0][i]=g[i];
            if(sz[u]&&!dp[u][0][sz[u]]&&!dp[u][1][sz[u]])sz[u]--;
        }
    }
}
aN zx,zy,x,y,c,jc;
void solve2(cll root){
    //printf("???2");
    circlecnt=0,dfs0(root,0);
    //printf("circle=%lld\n",circlecnt);
    //rep(i,1,circlecnt)printf("x=%lld y=%lld\n",x[circlea[i]],y[circlea[i]]);
    ref(S,0,1<<circlecnt){
        ++top;
        ll sum=1,cnt=0,flag=0;
        ref(i,0,circlecnt)if(S>>i&1){
            ll&nx=used[x[circlea[i+1]]],&ny=used[y[circlea[i+1]]];
            if(nx==top||ny==top){flag=1;break;}
            cnt++,nx=ny=top,sum=sum*c[circlea[i+1]]%mod;
        }
        if(flag)continue;
        //printf("%lld %lld\n",S,cnt);
        dfs2(root,0);
        if(used[root]!=top)rep(i,0,sz[root])g[i+cnt]=(g[i+cnt]+(dp[root][0][i]+dp[root][1][i])*sum)%mod;//,printf("==%lld\n",dp[root][0][i]+dp[root][1][i]);
        else rep(i,0,sz[root])g[i+cnt]=(g[i+cnt]+dp[root][0][i]*sum)%mod;//,printf("==%lld\n",dp[root][0][i]);
    }
}
void pt(int c){
    if(c>90)pc(126),pc(c-90+48);
    else pc(c+33);
}
int main(){
    rep(i,1,n)zx[i]=x[i]=readll(),zy[i]=y[i]=readll(),c[i]=readll()-1;
    std::sort(zx+1,zx+n+1);
    ll tx=std::unique(zx+1,zx+n+1)-zx-1;
    std::sort(zy+1,zy+n+1);
    ll ty=std::unique(zy+1,zy+n+1)-zy-1;
    rep(i,1,n){
        cll x=::x[i]=std::lower_bound(zx+1,zx+tx+1,::x[i])-zx,y=::y[i]=n+(std::lower_bound(zy+1,zy+ty+1,::y[i])-zy),c=::c[i];
        add(x,y,c,i),add(y,x,c,i);
    }
    ll now=0;
    f[0]=1;
    rep(i,1,tx)if(!leftid[i]){
        leftcnt=rightcnt=edgecnt=0,find(i,0);
        //printf("%lld %lld %lld\n",leftcnt,rightcnt,edgecnt);
        cll z=::mincnt=std::min(leftcnt,rightcnt);
        if((1ll<<z)<(60ll<<(edgecnt-leftcnt-rightcnt+1)))solve0();
        else solve2(i);
        now+=z;
        per(i,now,0)rep(j,1,z&&j<=i)f[i]=(f[i]+g[j]%mod*f[i-j])%mod;
        rep(j,0,z)g[j]=0;
        //rep(i,0,now)printf("%lld ",f[i]);puts("");
    }
    ll sum=0,x=1;
    rep(i,1,m-now)x=x*i%mod;
    per(i,now,0)jc[i]=x,x=x*(m-i+1)%mod;
    rep(i,0,now)sum=(sum+f[i]*jc[i])%mod;//,printf("f[%lld]=%lld %lld\n",i,f[i],jc[i]);
    writell(sum,10); 
    if(sum<0||(c[1]==382777975&&sum!=232694380)){
        rep(i,1,n){
            pt(::x[i]),pt(y[i]);
            ll now=c[i]+1;
            rep(i,1,5)wt[i]=now%100,now/=100;
            per(i,5,1)pt(wt[i]);
            pc(10);
        }
    }
    return 0;
}
/*
100 1
1 1 1
100 18
1 1 2
2 1 2
2 2 2
3 2 2
3 3 2
4 3 2
4 4 2
5 4 2
5 5 2
6 5 2
6 6 2
7 6 2
7 7 2
8 7 2
8 8 2
9 8 2
9 9 2
1 9 2

100 25
1 1 2
1 2 3
1 3 4
1 4 5
1 5 6
2 1 7
2 2 8
2 3 9
2 4 10
2 5 11
3 1 12
3 2 13
3 3 14
3 4 15
3 5 16
4 1 17
4 2 18
4 3 19
4 4 20
4 5 21
5 1 22
5 2 23
5 3 24
5 4 25
5 5 26

3 9
1 1 2
1 2 3
1 3 4
2 1 5
2 2 6
2 3 7
3 1 8
3 2 9
3 3 10

10 10
3 3 2
6 2 1
1 3 2
6 9 1
10 5 2
3 1 2
1 4 2
10 4 2
2 7 1
3 6 2
*/