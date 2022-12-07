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
        vector <int> p(n - 1);
        for(int i = 0; i < n - 1; i++) {
            p[i] = (v[i] < 2 * v[i + 1]);
        }
        vector <int> q(n - 1);
        q[0] = p[0];
        for(int i = 1; i < n - 1; i++) {
            q[i] = q[i - 1] + p[i];
        }
        int ans = 0;
        for(int i = 0; i < n - 1; i++) {
            int b = i + k - 1;
            if(b >= n - 1) break;
            int a = i - 1;
            if(q[b] - (a < 0 ? 0 : q[a]) == k) ans++;
        }
        cout << ans << '\n';
    }
    
    return 0;
}