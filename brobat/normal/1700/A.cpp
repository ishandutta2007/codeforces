#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int ans = 0;
        for(int i = 1; i < m; i++) ans += i;
        for(int i = m; i <= n*m; i += m) ans += i;
        cout << ans << '\n';
    }
    
    return 0;
}