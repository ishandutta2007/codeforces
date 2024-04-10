#include <bits/stdc++.h>
using namespace std;
#define MAXN 1505

int n, s, m, k;
int arr[MAXN];
vector<int> segend[MAXN];
vector<int> segbegin[MAXN];
int dp[MAXN][MAXN];

bool calc(int mid){
    int sum[n+1];
    sum[0] = 0;
    for(int i = 1; i<=n; i++) sum[i] = sum[i-1] + (arr[i] <= mid);
    for(int i = 0; i<=n; i++) dp[i][0] = 0;
    for(int i = 0; i<=m; i++) dp[0][i] = 0;
    set<pair<int, int>> st;
    for(int i = 1; i<=n; i++){
        for(auto j : segend[i-1]) st.erase({j, i-1});
        for(auto j : segbegin[i]) st.insert({i, j});
        for(int j = 1; j<=m; j++){
            if(st.empty()) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[(*st.begin()).first-1][j-1]+sum[i]-sum[(*st.begin()).first-1]);
        }
    }
    return dp[n][m] >= k;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s >> m >> k;
    for(int i = 0; i<n; i++) cin >> arr[i+1];
    for(int i = 0; i<s; i++){
        int a, b; cin >> a >> b;
        segend[b].push_back(a);
        segbegin[a].push_back(b);
    }
    int lo = 1, hi = 1000000009;
    while(lo < hi){
        int mid = lo+(hi-lo)/2;
        if(calc(mid)) hi = mid;
        else lo =  mid+1;
    }
    // calc(2);
    // cout << dp[4][2] << endl;
    // cout << lo << endl;
    if(!calc(lo)) cout << -1 << endl;
    else cout << lo << endl;
}