#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int curr = m;
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(curr < v[i]) {
                res += v[i] - curr;
                curr = v[i];
            }
            curr -= v[i];
        }
        cout << res << '\n';
    }
    
    return 0;
}