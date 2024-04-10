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
        sort(v.begin(), v.end());
        vector <int> p(n);
        p[0] = v[0];
        for(int i = 1; i < n; i++) {
            p[i] = p[i - 1] + v[i];
        }
        vector <int> ans(n);
        for(int i = 0; i < n; i++) {
            if(x - p[i] < 0) ans[i] = -1;
            else ans[i] = (x - p[i])/(i + 1);
            // cout << ans[i] << " ";
        }
        int z = 0;
        for(int i = 0; i < n; i++) {
            z += (ans[i] + 1);
        }
        cout << z << '\n';
    }
    
    return 0;
}