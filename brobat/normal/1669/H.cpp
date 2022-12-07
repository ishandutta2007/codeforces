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
        int k;
        cin >> k;
        vector <int> v(n);
        vector <int> cnt(31, 0);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            for(int j = 0; j < 31; j++) {
                if((v[i] >> j) & 1) cnt[j]++;
            }
        }
        for(int i = 30; i >= 0; i--) {
            if(n - cnt[i] <= k) {
                k -= (n - cnt[i]);
                cnt[i] = n;
            }
        }
        int ans = 0;
        for(int i = 0; i <= 30; i++) {
            if(cnt[i] == n) {
                ans += (1ll << i);
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}