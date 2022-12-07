#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.length();
        int a = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') a++;
        }
        if(a == 0 || a == n) {
            cout << 0 << '\n';
            continue;
        }
        vector <int> p(n, 0), q(n, 0);
        if(s[0] == '1') p[0]++;
        for(int i = 1; i < n; i++) {
            p[i] = p[i - 1];
            if(s[i] == '1') p[i]++;
        }
        if(s[n - 1] == '1') q[n - 1]++;
        for(int i = n - 2; i >= 0; i--) {
            q[i] = q[i + 1];
            if(s[i] == '1') q[i]++;
        }
        int ans = (int)1E9;
        for(int i = 0; i < n; i++) {
            int x = 0;
            if(i > 0) x += p[i - 1];
            if(i + a < n) x += q[i + a];
            ans = min(ans, x);
        }
        cout << ans << '\n';
    }
    
    return 0;
}