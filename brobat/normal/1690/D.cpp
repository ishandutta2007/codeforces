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
        vector <int> p(n + 1);
        p[0] = 0;
        for(int i = 0; i < n; i++) {
            p[i + 1] = p[i];
            if(s[i] == 'B') {
                p[i + 1]++;
            }
        }
        int ans = (int)1E18;
        for(int i = 0; i <= n; i++) {
            if(i + k > n) break;
            ans = min(ans, k - p[i + k] + p[i]);
        }
        cout << ans << '\n';
    }
    
    return 0;
}