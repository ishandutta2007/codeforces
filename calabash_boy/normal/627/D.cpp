#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 100;
int n,k;
vector<int> E[maxn];
int a[maxn];
vector<int> vals;
int dp[maxn];
int size[maxn];
int sz[maxn];
int no[maxn];
void dfs_sz(int u,int fa){
    sz[u] = 1;
    for (int v : E[u]){
        if (v == fa)continue;
        dfs_sz(v, u);
        sz[u] += sz[v];
    }
}
int illegal;
int dfs(int u, int fa, int limit){
    int ret =0;
    dp[u] = 0;
    no[u] = (a[u] < limit?1:0);
   // cerr<<u<<" "<<no[u]<<" "<<limit<<endl;
    int mx1 = 0;
    int mx2 = 0;
    for (int v : E[u]){
        if (v == fa)continue;
       // cerr<<u<<" "<<no[u]<<endl;
        int temp_ret = dfs(v,u,limit);
        no[u] += no[v];
        ret = max(ret,temp_ret);
//        no[u] += no[v];
        if (dp[v] == sz[v]){
            dp[u] += dp[v];
        }else{
            if (dp[v] >= mx1){
                mx2 = mx1;
                mx1 = dp[v];
            }else{
                mx2 = max(mx2,dp[v]);
            }
        }
    }
    dp[u] += mx1;
    if (a[u] >= limit){
        dp[u] ++;
        ret = max(ret,dp[u] + mx2);
        if (no[u] == illegal){
            ret = max(ret,dp[u] + mx2 + n - sz[u]);
        }
    }else{
        dp[u] = 0;
    }
   // cerr<<u<<" "<<dp[u]<<" "<<ret<<" limit = "<<limit<<" "<<no[u]<<endl;
    return ret;
}
bool check(int limit){
    illegal = 0;
    for (int i=1;i<=n;i++){
        illegal += (a[i] < limit?1:0);
    }
    return dfs(1,0,limit) >= k;
}
int main(){
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++){
        scanf("%d",a+i);
        vals.push_back(a[i]);
    }
    sort(vals.begin(),vals.end());
    vals.erase(unique(vals.begin(),vals.end()),vals.end());
    for (int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs_sz(1,0);
    int l = 0;
    int r = vals.size() - 1;
    while (r-l > 1){
        int mid = l + r >> 1;
        if (check(vals[mid])){
            l = mid;
        }else{
            r = mid;
        }
    }
    for (int i=r;i>=l;i--){
        if (check(vals[i])){
            printf("%d\n",vals[i]);
            return 0;
        }
    }
    assert(0);
    return 0;
}