#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=4e5+1;
const ll mod=1e9+7;
bool gone[MN];
vector<int> adj[MN];
int arr[MN][2];
void dfs(int loc){
    gone[loc]=true;
    for(auto x:adj[loc])if(!gone[x])dfs(x);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)cin >> arr[i][0],adj[i]=vector<int>(),gone[i]=false;
        for (int i = 1; i <= n; i++)cin >> arr[i][1];
        for (int i = 1; i <= n; i++) {
            adj[arr[i][0]].push_back(arr[i][1]), adj[arr[i][1]].push_back(arr[i][0]);
        }
        ll ans = 1;
        for (int i = 1; i <= n; i++) {
            if (!gone[i]) {
                ans = ans * ll(2) % mod;
                dfs(i);
            }
        }
        printf("%lli\n", ans);
    }
    return 0;
}