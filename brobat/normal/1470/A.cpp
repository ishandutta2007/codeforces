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
        vector <int> v(n), c(m);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            --v[i];
        }
        for(int i = 0; i < m; i++) {
            cin >> c[i];
        }
        sort(v.begin(), v.end());
        int cost = 0;
        for(int i = 0; i < n; i++) {
            cost += c[v[i]];
        }
        int pre = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(pre == m) break;
            if(c[pre] <= c[v[i]]) {
                cost -= (c[v[i]] - c[pre]);
                pre++;
            } else break;
        }
        cout << cost << '\n';
    }
    
    return 0;
}