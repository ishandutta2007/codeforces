#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n = 8;
        char grid[n][n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
        int x, y;
        for(int i = 1; i < 7; i++) {
            for(int j = 1; j < 7; j++) {
                if(grid[i][j] == '#') {
                    if(grid[i + 1][j + 1] == '#' && grid[i + 1][j - 1] == '#' && grid[i - 1][j + 1] == '#' && grid[i - 1][j - 1] == '#') {
                        x = i + 1;
                        y = j + 1;
                    }
                }
            }
        }
        cout << x << " " << y << '\n';
    }
    
    return 0;
}