#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        if(k >= n) {
            int x = accumulate(v.begin(), v.end(), 0ll);
            for(int i = 0; i < n; i++) {
                x += (k - 1 - i);
            }
            cout << x << '\n';
        } else {
            vector <int> p(n);
            p[0] = v[0];
            for(int i = 1; i < n; i++) {
                p[i] = p[i - 1] + v[i];
            }
            int ans = p[k - 1];
            for(int i = k; i < n; i++) {
                ans = max(ans, p[i] - p[i - k]);
            }
            for(int i = 0; i < k; i++) {
                ans += i;
            }
            cout << ans << '\n';
        }
    }
    
    return 0;
}