#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
pll arr[MN];
vector<int> adj[MN];
ll dp[MN][2];
void dfs(int loc, int parent){
    dp[loc][0]=dp[loc][1]=0;
    for(auto x:adj[loc]){
        if(x!=parent){
            dfs(x,loc);
            dp[loc][0]+=max(dp[x][0]+abs(arr[loc].first-arr[x].first),dp[x][1]+abs(arr[loc].first-arr[x].second));
            dp[loc][1]+=max(dp[x][0]+abs(arr[loc].second-arr[x].first),dp[x][1]+abs(arr[loc].second-arr[x].second));
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>arr[i].first>>arr[i].second;
            adj[i]=vector<int>();
        }
        for(int i=1;i<n;i++){
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1,0);
        printf("%lli\n",max(dp[1][0],dp[1][1]));
    }
    return 0;
}