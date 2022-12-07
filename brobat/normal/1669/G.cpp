#include <bits/stdc++.h>
using namespace std;
#define int long long

void convert(int n, int m, vector<vector<char>> v) {
    vector<vector<char>> res(n, vector<char>(m));
    res[n - 1] = v[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        for(int j = 0; j < m; j++) {

        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> v(n + 1, vector<char>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> v[i][j];
            }
        }
        for(int j = 0; j < m; j++) {
            v[n][j] = 'o';
        }
        vector<vector<char>> ans(n + 1, vector<char>(m, '.'));
        for(int j = 0; j < m; j++) {
            int cnt = 0;
            for(int i = 0; i <= n; i++) {
                if(v[i][j] == 'o') {
                    ans[i][j] = 'o';
                    for(int k = 0; k < cnt; k++) {
                        ans[i - k - 1][j] = '*';
                    }
                    cnt = 0;
                } else if(v[i][j] == '*') {
                    cnt++;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << ans[i][j];
            }
            cout << '\n';
        }
        cout << '\n';
    }
    
    return 0;
}