#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;

short used[100005];
long long dp[100005][17];
long long dp2[100005];
vector<long long> v[100005],vv[100005];
long long pred[100005];
long long kol[100005];
long long all;
long long clr[100005];
long long timer,tin[100005],tout[100005];
long long n,m,x,y;

void dfs(long long x,long long y){
    used[x]=1;
    pred[x]=y;
    for (long long i=0;i<v[x].size();++i) {
        long long to=v[x][i];
        if (to==y) continue;
        if (used[to]==1) {
            long long z=x;
            clr[x]=++all;
            while (true) {
                clr[z]=clr[x];
                if (z==to) break;
                z=pred[z];
            }
        } else if (used[to]==0) {
            dfs(to,x);
        }
    }
    used[x]=2;
    if (!clr[x]) clr[x]=++all;
    return;
}
void dfs2(long long x,long long y){
    dp[x][0]=y;
    dp2[x]=dp2[y]+(kol[x]>1 ? 1 : 0);
    tin[x]=++timer;
    for (long long i=1;i<=16;++i)
        dp[x][i]=dp[dp[x][i-1]][i-1];
    used[x]=1;
    for (long long i=0;i<vv[x].size();++i) {
        long long to=vv[x][i];
        if (used[to]==0) dfs2(to,x);
    }
    tout[x]=++timer;
}
inline bool is_pred(long long x,long long y){
    return (tin[x]<=tin[y] && tout[x]>=tout[y]);
}
inline long long p(long long x,long long y){
    long long res=1;
    while (y) {
        if (y&1) res=(res*x)%md;
        x=(x*x)%md;
        y>>=1;
    }
    return res;
}
inline long long lca(long long x,long long y){
    if (is_pred(x,y)) return x;
    if (is_pred(y,x)) return y;
    bool t=false;
    if (x==1 && y==5) t=true;
    for (long long i=16;i>=0;--i)
        if (dp[x][i] && !(is_pred(dp[x][i],y))) x=dp[x][i];
    return dp[x][0];
}
inline long long solve(long long x,long long y){
    long long c=lca(x,y);
    long long res=p(2,dp2[x]+dp2[y]-dp2[c]*2+(kol[c]>1 ? 1 : 0));
    return res;
}
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (long long i=1;i<=m;++i) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (long long i=1;i<=n;++i)
        if (used[i]==0) dfs(i,0);
    for (long long i=1;i<=n;++i) {
        ++kol[clr[i]];
        for (long long j=0;j<v[i].size();++j) {
            long long to=v[i][j];
            if (clr[to]!=clr[x]) {
                vv[clr[i]].push_back(clr[to]);
                vv[clr[to]].push_back(clr[i]);
            }
        }
    }
    for (long long i=1;i<=n;++i)
        used[i]=0;
    dfs2(1,0);
    cin>>m;
    for (long long i=1;i<=m;++i) {
        long long x,y;
        cin>>x>>y;
        x=clr[x];
        y=clr[y];
        cout<<solve(x,y)<<'\n';
    }
}