#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    vector<int> f(11, 0), g(11, 0);
    map<string, int> cnt;
    for(int i = 0; i < n; i++) {
        string x;
        cin >> x;
        ans += f[x[0] - 'a'] + g[x[1] - 'a'] - cnt[x] - cnt[x];
        f[x[0] - 'a']++;
        g[x[1] - 'a']++;
        cnt[x]++;
        // cout << f[x[0] - 'a'] << " " << g[x[1] - 'a'] << " " << cnt[x] << '\n';
        // cout << ans << '\n';
    }
    cout << ans << '\n'; 
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}