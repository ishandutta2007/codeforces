#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> p(n);
        for(int i = 0; i < n; i++) {
            cin >> p[i]; --p[i];
        }
        vector<vector<int>> x(n, vector<int>(n, 0));
        // No of values less than p[j], after index i.
        for(int i = n - 2; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                x[i][j] = x[i + 1][j];
                if(p[i + 1] < p[j]) {
                    x[i][j]++;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < n; j++) {
                x[i][j] += x[i][j - 1];
            }
        }
        int ans = 0;
        for(int a = 0; a < n - 3; a++) {
            for(int c = a + 2; c < n - 1; c++) {
                if(p[a] < p[c]) {
                    ans += x[c][c - 1] - x[c][a];
                }
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}