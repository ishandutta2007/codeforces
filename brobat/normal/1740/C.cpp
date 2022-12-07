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
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int ans = 0;
        for(int i = 1; i < n - 1; i++) {
            ans = max(ans, v[n - 1] - v[i - 1] + v[i] - v[i - 1]);
        }
        for(int i = n - 2; i > 0; i--) {
            ans = max(ans, v[i + 1] - v[i] + v[i + 1] - v[0]);
        }
        cout << ans << '\n';
    }
    
    return 0;
}