#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int x = 0, y = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') x++;
            else y++;
        }
        long long ans = 1ll * x * y;
        int cnt = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] != s[i - 1]) {
                ans = max(ans, 1ll * cnt * cnt);
                cnt = 1;
            } else {
                cnt++;
            }
        }
        ans = max(ans, 1ll * cnt * cnt);
        cout << ans << '\n';
    }
    
    return 0;
}