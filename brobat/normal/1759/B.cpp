#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, s;
        cin >> n >> s;
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int mn = 100;
        int mx = 0;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            mn = min(mn, v[i]);
            mx = max(mx, v[i]);
            sum += v[i];
        }
        if(mx * (mx + 1) / 2 - sum == s) {
            cout << "YES" << endl;
            continue;
        }
        int needed = s - (mx * (mx + 1)/2) + sum;
        int it = mx + 1;
        bool done = false;
        while(needed >= 0) {
            if(needed == 0) {
                cout << "YES" << endl;
                done = true;
                break;
            } else {
                needed -= it;
                it++;
            }
        }
        if(!done) cout << "NO" << endl;
    }
    
    return 0;
}