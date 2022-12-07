#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int ans = 0;
        for(int p = 0; p <= min(m - 1, k); p++) {
            // assume we tell p people to choose from the front.
            int temp = 1E9;
            int q = min(m - 1, k) - p; // q people choose from the back.
            int rem = m - 1 - p - q; 
            // cout << p << ' ' << q << ":\n";
            for(int j = 0; j <= rem; j++) {
                // cout << p + j << ' ' << n - 1 - q - (rem - j) << ',';
                temp = min(temp, max(v[p + j], v[n - 1 - q - (rem - j)]));
            }
            // cout << '\n';
            ans = max(ans, temp);
        }
        cout << ans << '\n';
    }
    
    return 0;
}