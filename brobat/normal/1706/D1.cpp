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
        int cost = (int)1E9;
        for(int mx = 1; mx <= 3000; mx++) {
            // assume this is the maximum cost allowed.
            int mn = (int)1E9;
            int curr = 1;
            for(int i = 0; i < n; i++) {
                while(v[i]/curr > mx) {
                    curr++;
                }
                if(curr > k) {
                    mn = -1;
                }
                mn = min(mn, v[i]/curr);
            }
            // cerr << mn << " " << mx << '\n';
            if(mn != -1) cost = min(cost, mx - mn);
        }
        cout << cost << '\n';
    }
    
    return 0;
}