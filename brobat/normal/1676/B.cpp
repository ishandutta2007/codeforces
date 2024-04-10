#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int x = *min_element(v.begin(), v.end());
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += v[i] - x;
        }
        cout << ans << '\n';
    }
    
    return 0;
}