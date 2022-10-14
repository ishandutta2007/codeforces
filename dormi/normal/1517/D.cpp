#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=501;
vector<pair<pii,ll>> adj[MN][MN];
ll dp[MN][MN][21];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    ll a;
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            cin>>a;
            adj[i][j-1].push_back({{i,j},a});
            adj[i][j].push_back({{i,j-1},a});
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a;
            adj[i-1][j].push_back({{i,j},a});
            adj[i][j].push_back({{i-1,j},a});
        }
    }
    if(k%2==1){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                printf("-1 ");
            }
            printf("\n");
        }
        return 0;
    }
    for(int ct=2;ct<=k;ct++){
        for(int i=0;i<n;i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j][ct]=LLONG_MAX;
                for(auto x:adj[i][j]){
                    dp[i][j][ct]=min(dp[i][j][ct],dp[x.first.first][x.first.second][ct-2]+x.second*ll(2));
                    dp[i][j][ct]=min(dp[i][j][ct],dp[i][j][ct-2]+x.second*ll(2));
                }
            }
        }
    }
    for(int i=0;i<n;i++) {
        for (int j = 0; j < m; j++) {
            printf("%lli ",dp[i][j][k]);
        }
        printf("\n");
    }
    return 0;
}