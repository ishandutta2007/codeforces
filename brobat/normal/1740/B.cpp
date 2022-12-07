#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> v(n);
        int mx = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            cin >> v[i].first >> v[i].second;
            mx = max(mx, v[i].first);
            mx = max(mx, v[i].second);
            ans += min(v[i].first, v[i].second);
        }
        cout << (ans + mx)*2 << '\n';
    }
    
    return 0;
}