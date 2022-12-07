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
        int mx = n;
        int my = m;
        char x[n][m];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> x[i][j];
                if(x[i][j] == 'R') {
                    mx = min(mx, i);
                    my = min(my, j);
                }
            }
        }
        cout << (x[mx][my] == 'R' ? "YES" : "NO") << '\n';
    }
    
    return 0;
}