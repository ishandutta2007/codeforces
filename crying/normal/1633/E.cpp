#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const ll MAXN=60,MAXM=310,MAXQ=1e7+10,INF=1e14;
int n,m,q,qry[MAXQ];
ll ans;
struct E{
    int u,v,w;
    bool operator<(const E& e2)const{return w<e2.w;}
}e[MAXM],e1[MAXM],e2[MAXM];
int m1,m2;
int fa[MAXN];
ll f[MAXM][MAXN];
void Reset(){rep(i,1,n)fa[i]=i;}
int Find(int x){if(fa[x]==x)return x;return fa[x]=Find(fa[x]);}
void Merge(int x,int y){fa[Find(y)]=Find(x);}
db D(ll n,ll m){
    return 1.00*n/m;
}
db pt[MAXM][MAXN];
ll opt[MAXM][MAXN],sz[MAXM],rp[MAXM];
pair<ll,ll> mst(int mid){
    rep(i,1,m1)e1[i].w+=mid;
    ll tot=0,sum=0,l=1,r=1;
    Reset();
    while(l<=m1 && r<=m2){
        if(e1[l].w<=e2[r].w){
            int u=e1[l].u,v=e1[l].v,w=e1[l].w;
            if(Find(u)!=Find(v)){
                tot++;sum+=w;Merge(u,v);
            }
            l++;
        }else{
            int u=e2[r].u,v=e2[r].v,w=e2[r].w;
            if(Find(u)!=Find(v)){
                sum+=w;Merge(u,v);
            }
            r++;
        }
    }
    while(l<=m1){
        int u=e1[l].u,v=e1[l].v,w=e1[l].w;
        if(Find(u)!=Find(v)){
            tot++;sum+=w;Merge(u,v);
        }
        l++;
    }
    while(r<=m2){
        int u=e2[r].u,v=e2[r].v,w=e2[r].w;
        if(Find(u)!=Find(v)){
            sum+=w;Merge(u,v);
        }
        r++;
    }
    rep(i,1,m1)e1[i].w-=mid;
    return mp(tot,sum);
}
ll calc(int x){
    //x
    int cnt=0;
    Reset();
    rep(i,1,m1){
        int u=e1[i].u,v=e1[i].v;
        if(Find(u)!=Find(v))Merge(u,v),cnt++;
    }
    if(cnt<x)return INF;
    int l=-2e8,r=2e8;
    ll ret=INF;
    while(l<=r){
        ll mid=(l+r)/2;
        pair<ll,ll> tmp=mst(mid);
        if(tmp.fr>=x){
            ret=tmp.se-mid*x;
            l=mid+1;
        }else r=mid-1;
    }
    return ret;
}
void solve(){  
    //part1
    per(i,m,1)e2[++m2]=e[i];
    reverse(e2+1,e2+1+m2);
    f[0][0]=calc(0);rep(i,1,n-1)f[0][i]=INF;
    reverse(e2+1,e2+1+m2);
    rep(i,1,m){
        m1++;e1[m1]=e2[m2];m2--;e1[m1].w=-e1[m1].w;
        reverse(e1+1,e1+1+m1);reverse(e2+1,e2+1+m2);
        rep(j,0,n-1)f[i][j]=(j<=i)?calc(j):INF;
        reverse(e1+1,e1+1+m1);reverse(e2+1,e2+1+m2);
    }
    //part2
    rep(i,0,m){
        per(j,n-1,0){
            pt[i][j]=INF;
            per(k,j-1,0){
                pt[i][j]=min(pt[i][j],D(f[i][j]-f[i][k],2*k-2*j));
            }
        //    printf("pt[%d][%d]:%.2f %lld\n",i,j,pt[i][j],f[i][j]);
        }
        ll premax=-INF;
        per(j,n-1,0){
            if(premax>=pt[i][j])continue;
            premax=pt[i][j];
            opt[i][++sz[i]]=j;
        }
    }

    //part3
    for(int i=1,r=0;i<=q;i++){
        while(r<m && e[r+1].w<=qry[i])r++;
        ll ret=INF;
        //
        while(rp[r]+1 <= sz[r] && pt[r][opt[r][rp[r]+1]] <= qry[i])rp[r]++;
        ll a=opt[r][rp[r]+1]; //a
        ret=f[r][a]+1ll*qry[i]*a-1ll*qry[i]*(n-1-a);
    //    printf("i:%d %lld %lld %lld(%lld,%lld)\n",i,ret,r,rp[r],qry[i],a);
        ans^=ret;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    rep(i,1,m)scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    sort(e+1,e+1+m);
    int p,a,b,c;
    scanf("%d%d%d%d%d",&p,&q,&a,&b,&c);
    rep(i,1,p)scanf("%d",&qry[i]);
    rep(i,p+1,q)qry[i]=(1ll*qry[i-1]*a+b)%c;
    sort(qry+1,qry+1+q);
    solve();
    printf("%lld",ans);
    return 0;
}