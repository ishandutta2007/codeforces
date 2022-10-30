#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
vector<pair<int,int> > E[maxn];
ll dp[maxn][2];
int n,k;
long long gao(vector<pair<ll,ll> > & nums,int cnt){
    long long sum = 0;
    vector<ll> del(0);
    for (auto pr : nums){
        ll x1,x2;
        tie(x1,x2) = pr;
        sum += x2;
        del.push_back(x1 -x2);
    }
    sort(del.begin(),del.end());
    reverse(del.begin(),del.end());
    for (int i=0;i<min(cnt,(int)del.size());i++){
        sum += max(0ll,del[i]);
    }
    return sum;
}
void dfs(int u,int fa){
    dp[u][0] = dp[u][1] = 0;
    vector<pair<ll,ll> > temp(0);
    for (auto e: E[u]){
        int v,w;
        tie(v,w) = e;
        if (v == fa)continue;
        dfs(v,u);
        temp.push_back(make_pair(dp[v][0] + w,dp[v][1]));
    }
    dp[u][0] = gao(temp,k-1);
    dp[u][1] = gao(temp,k);
}
void solve(){
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++){
        E[i].clear();
    }
    for (int i=1;i<n;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        E[u].push_back(make_pair(v,w));
        E[v].push_back(make_pair(u,w));
    }
    dfs(1,-1);
    cout<<max(dp[1][0],dp[1][1])<<endl;
}
int main(){
    int T;
    scanf("%d",&T);
    while (T--){
        solve();
    }
    return 0;
}