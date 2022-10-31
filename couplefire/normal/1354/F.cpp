#include <bits/stdc++.h>
using namespace std;

const int N = 75+5;
const int INF = 1000000009;

int n, k;
array<int, 3> arr[N];
int dp[N][N], trans[N][N], vis[N];
vector<int> ans;

void solve(){
    ans.clear();
    memset(vis, 0, sizeof vis);
    cin >> n >> k;
    for(int i = 0; i<n; i++) cin >> arr[i][1] >> arr[i][0], arr[i][2] = i;
    sort(arr, arr+n);
    for(int i = 0; i<n; i++) for(int j = 0; j<=k; j++) dp[i][j] = -INF;
    dp[0][0] = 0;
    for(int i = 0; i<n; i++) dp[0][0] += arr[i][0]*(k-1);
    dp[0][1] = dp[0][0]-arr[0][0]*(k-1)+arr[0][1];
    for(int i = 1; i<n; i++){
        dp[i][0] = dp[i-1][0];
        for(int j = 1; j<=k; j++){
            int v1 = dp[i-1][j], v2 = dp[i-1][j-1]-arr[i][0]*(k-1)+arr[i][1]+arr[i][0]*(j-1);
            if(v1 > v2) dp[i][j] = v1, trans[i][j] = trans[i-1][j];
            else dp[i][j] = v2, trans[i][j] = i;
        }
    }
    int cur = n-1;
    for(int i = k; i>=1; i--){
        ans.push_back(arr[trans[cur][i]][2]+1);
        cur = trans[cur][i]-1;
        vis[ans.back()] = 1;
    }
    reverse(ans.begin(), ans.end());
    int tmp = ans.back(); ans.pop_back();
    for(int i = 1; i<=n; i++) if(!vis[i]) ans.push_back(i), ans.push_back(-i);
    ans.push_back(tmp);
    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " ";
    cout << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}