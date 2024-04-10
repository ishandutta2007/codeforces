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
        int ans = (int)1E18;
        if(n % 2) {
            ans = 0;
            for(int i = 1; i < n; i += 2) {
                if(max(v[i - 1], v[i + 1]) >= v[i]) {
                    ans += 1 + max(v[i - 1], v[i + 1]) - v[i];
                }
            }
        } else {
            vector <int> p(1, 0), s(1, 0);
            for(int i = 1; i < n - 1; i += 2) {
                int x = 0;
                if(max(v[i - 1], v[i + 1]) >= v[i]) {
                    x = 1 + max(v[i - 1], v[i + 1]) - v[i];
                }
                p.push_back(p.back() + x);
            }
            for(int i = n - 2; i > 0; i -= 2) {
                int x = 0;
                if(max(v[i - 1], v[i + 1]) >= v[i]) {
                    x = 1 + max(v[i - 1], v[i + 1]) - v[i];
                }
                s.push_back(s.back() + x);
            }
            int m = p.size();
            for(int i = 0; i < m; i++) {
                ans = min(ans, p[i] + s[m - i - 1]);
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}