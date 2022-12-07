#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> func(vector<vector<int>> &v, int n) {
    vector<vector<int>> w(n, vector<int>(n));
    for(int i = -n/2; i <= n/2; i++) {
        for(int j = -n/2; j <= n/2; j++) {
            w[n/2 + j][n/2 - i] = v[n/2 + i][n/2 + j];
        }
    }
    return w;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int g[n + 1][n + 1];
        memset(g, 0, sizeof(g));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                char x;
                cin >> x;
                int a = i;
                int b = j;
                if(n % 2 == 0 && i >= n/2) a++;
                if(n % 2 == 0 && j >= n/2) b++;
                g[a][b] = x - '0';
            }
        }
        int ans = 0;
        if(n % 2 == 0) n++;
        vector<vector<vector<int>>> v(4, vector<vector<int>>(n, vector<int>(n)));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                v[0][i][j] = g[i][j];
            }
        }
        for(int i = 1; i < 4; i++) {
            v[i] = func(v[i - 1], n);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int cnt = 0;
                for(int k = 0; k < 4; k++) {
                    cnt += v[k][i][j];
                }
                ans += min(cnt, 4 - cnt);
            }
        }
        cout << ans/4 << '\n';
    }
    
    return 0;
}