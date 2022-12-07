#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            char c; cin >> c;
            v[i] = c - '0';
        }
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            vector <int> cnt(10, 0);
            for(int j = i; j < n; j++) {
                if(j - i > 105) break;
                cnt[v[j]]++;
                int d = 0;
                for(int k = 0; k < 10; k++) {
                    if(cnt[k] > 0) d++;
                }
                bool pos = true;
                for(int k = 0; k < 10; k++) {
                    if(cnt[k] > d) pos = false;
                }
                if(pos) ans++;
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}