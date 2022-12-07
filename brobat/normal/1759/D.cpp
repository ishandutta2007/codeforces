#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int tn = 0, fn = 0;
        int x = n;
        while(x % 2 == 0) {
            tn++;
            x /= 2;
        }
        x = n;
        while(x % 5 == 0) {
            fn++;
            x /= 5;
        }
        int curr = min(tn, fn);
        int ans = m * n;
        for(int i = curr; i <= 30; i++) {
            int tk = i - tn;
            int fk = i - fn;
            if(tk < 0) tk = 0;
            if(fk < 0) fk = 0;
            int val = 1;
            for(int j = 0; j < tk; j++) {
                val *= 2;
                if(val > m) break;
            }
            for(int j = 0; j < fk; j++) {
                val *= 5;
                if(val > m) break;
            }
            if(val <= m) {
                ans = val * n;
            }
        }
        int mul = ans / n;
        ans *= m / mul;
        cout << ans << '\n';
    }
    
    return 0;
}