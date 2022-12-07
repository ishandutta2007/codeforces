#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = (int)1E18;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++) {
            int y; 
            cin >> y;
            v[i] = {y - x, y + x};
        }
        int ans = 0;
        int l = -INF;
        int r = INF;
        for(int i = 0; i < n; i++) {
            l = max(l, v[i].first);
            r = min(r, v[i].second);
            if(l > r) {
                // cout << i << " ";
                ans++;
                l = v[i].first;
                r = v[i].second;
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}