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
        vector <int> e(n);
        e[n - 1] = 0;
        for(int i = n - 2; i >= 0; i--) {
            e[i] = e[i + 1];
            if(v[i] == v[i + 1]) e[i]++;
        }
        int cnt = e[0];
        int x = -1;
        int ans = 0;
        // cout << cnt << '\n';
        for(int i = 0; i < n - 2; i++) {
            if(cnt <= 1) break;
            if(v[i] == v[i + 1]) {
                cnt -= (v[i] == v[i + 1]);
                if(i != n - 3) cnt -= (v[i + 2] == v[i + 3]);
                // cout << i << " " << x << " " << cnt << '\n';
                cnt += (v[i + 1] != v[i + 2]);
                v[i + 1] = x;
                v[i + 2] = x;
                x--;
                ans++;
            }
        }
        cout << ans << '\n';
        // int cnt = 0;
        // for(int i = 0; i < n - 1; i++) {
        //     if(e[i + 1] == 0) {
        //         break;
        //     }
        //     if(v[i] == v[i + 1]) {
        //         v[i + 1] = 0;
        //         v[i + 2] = 0;
        //         e[i + 1]++;
        //     }
        // }
    }
    
    return 0;
}