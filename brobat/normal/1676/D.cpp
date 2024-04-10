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
        int grid[n][m];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            // row
            for(int j = 0; j < m; j++) {
                // column
                int sum = 0;
                for(int x = 0; x < n; x++) {
                    // diagonal row
                    int y = i + j - x;
                    if(y >= 0 && y < m) sum += grid[x][y];
                }
                for(int x = 0; x < n; x++) {
                    int y = x - i + j;
                    if(y >= 0 && y < m) sum += grid[x][y];
                }
                sum -= grid[i][j];
                ans = max(ans, sum);
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}