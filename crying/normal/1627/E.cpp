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
#define ppi pair<pi,int>
#define pii pair<int,pi>
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
const ll MAXN=2e5+10,INF=1e18;
int T;
int n,m,k,x[MAXN],a[MAXN],b[MAXN],c[MAXN],d[MAXN],h[MAXN];
int tot;
ll dis[MAXN],tmp[MAXN];
vector<pi>pts[MAXN],e[MAXN];
vector<int>idx[MAXN];
map<int,int>ord[MAXN];
void qwq(){
    rep(i,1,tot)dis[i]=INF;
    dis[1]=1;
    int sz=pts[1].size();
    rep(j,1,sz-1){
        int val=pts[1][j].fr;
        int u=idx[1][j];
        dis[u]=1ll*x[1]*(val-1);
    }
    rep(i,2,n){
        int sz=pts[i].size();
        rep(j,0,sz-1){
            int u=idx[i][j];
            tmp[u]=INF;
            for(auto p:e[u]){
                int v=p.fr,w=p.se;
                if(dis[v]==INF)continue;
                tmp[u]=min(tmp[u],dis[v]+w);
            }
            dis[u]=min(dis[u],tmp[u]);
        }
        ll minn=2*INF;
        rep(j,0,sz-1){
            int val=pts[i][j].fr;
            int u=idx[i][j];
            dis[u]=min(dis[u],1ll*val*x[i]+minn);
            minn=min(minn,tmp[u]-1ll*val*x[i]);
        }
        minn=2*INF;
        per(j,sz-1,0){
            int val=pts[i][j].fr;
            int u=idx[i][j];
            dis[u]=min(dis[u],minn-1ll*val*x[i]);
            minn=min(minn,tmp[u]+1ll*val*x[i]);
        }
    }
}  
void solve(){
    scanf("%d%d%d",&n,&m,&k);
    rep(i,1,n)scanf("%d",&x[i]);
    rep(i,1,n)pts[i].clear(),ord[i].clear(),idx[i].clear();
    rep(i,1,k){
        scanf("%d%d%d%d%d",&a[i],&b[i],&c[i],&d[i],&h[i]);
        pts[a[i]].pb(mp(b[i],i));
        pts[c[i]].pb(mp(d[i],i));
    }
    pts[1].pb(mp(1,0));
    pts[n].pb(mp(m,0));
    tot=0;
    rep(i,1,n){
        sort(pts[i].begin(),pts[i].end());
        int sz=pts[i].size();
        rep(j,0,sz-1){
            tot++;
            e[tot].clear();
            ord[i][pts[i][j].fr]=tot;
            idx[i].pb(tot);
        }
    }
    rep(i,1,k){
        int u=ord[a[i]][b[i]],v=ord[c[i]][d[i]];
        e[v].pb(mp(u,-h[i]));
    }
    qwq();
    if(dis[tot]==INF)printf("NO ESCAPE\n");
    else printf("%lld\n",dis[tot]);
}
int main(){
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}