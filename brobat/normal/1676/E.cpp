#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end(), greater<int>());
        for(int i = 1; i < n; i++) {
            v[i] += v[i - 1];
        }
        for(int i = 0; i < q; i++) {
            int x; cin >> x;
            int y = lower_bound(v.begin(), v.end(), x) - v.begin();
            cout << (y + 1 > n ? -1 : y + 1) << '\n';
        }
    }
    
    return 0;
}