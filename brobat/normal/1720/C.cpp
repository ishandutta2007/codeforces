#include <bits/stdc++.h>
using namespace std;

char grid[505][505];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int cnt = 0;
        for(int i = 0; i < n + 5; i++) {
            for(int j = 0; j < m + 5; j++) {
                grid[i][j] = '1';
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> grid[i][j];
                if(grid[i][j] == '1') cnt++;
            }
        }
        if(cnt == n*m) {
            cout << n*m - 2 << '\n';
            continue;
        }
        bool cons = false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') continue;
                if(grid[i + 1][j] == '0' || grid[i][j + 1] == '0') {
                    cons = true;
                }
                if(j > 0 && grid[i + 1][j - 1] == '0') cons = true;
                if(grid[i + 1][j + 1] == '0') cons = true;
            }
        }
        cout << (cons ? cnt : cnt - 1) << '\n';
    }
    
    return 0;
}