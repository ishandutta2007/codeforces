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
        string s;
        cin >> s;
        int f = n;
        int l = -1;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                f = min(f, i);
                l = max(l, i);
                cnt++;
            }
        }
        if(f == n) {
            cout << 0 << '\n';
            continue;
        }
        int ans = 11*cnt;
        int fn = f;
        int sn = n - 1 - l;
        if(f == l) {
            // corner case?
            if(sn <= k) {
                ans -= 10;
            } else if(fn <= k) {
                ans -= 1;
            }
            cout << ans << '\n';
            continue;
        }
        if(sn <= k) {
            ans -= 10;
            k -= sn;
        }
        if(fn <= k) {
            ans -= 1;
        }
        cout << ans << '\n';

    }
    
    return 0;
}