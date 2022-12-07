#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector <int> p(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            p[i] = p[i - 1];
            if(v[i - 1] == 1) p[i]++;
        }
        if(p[n] < x) {
            cout << -1 << '\n';
            continue;
        }
        int ans = 0;
        for(int i = 0; i <= n; i++) {
            int a = p[i];
            int b = upper_bound(p.begin(), p.end(), x + a) - p.begin() - 1;
            if(b > n) break;
            ans = max(ans, b - i); 
        }
        cout << n - ans << '\n';
    }
    
    return 0;
}