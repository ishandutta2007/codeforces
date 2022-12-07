#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;
        vector <int> v(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        n += 1;
        vector <int> suff(n, 0);
        suff[n - 1] = v[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] + v[i];
        }
        vector <int> fin(n, 0);
        for(int i = 0; i < n; i++) {
            fin[i] = b * (suff[i] - ((n - i) * v[i]));
            // cout << fin[i] << " ";
        }
        // cout << '\n';
        int p = 0;
        int ans = fin[0];
        for(int i = 1; i < n; i++) {
            p += (a + b) * (v[i] - v[i - 1]);
            // cout << p + fin[i] << " ";
            ans = min(ans, p + fin[i]);
        }
        cout << ans << '\n';
        // cout << '\n';
    }
    
    return 0;
}