#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    b = abs(b);
    while (b) {
        int r = a % b;
        a = b; b = r;
    }
    return a;
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    
    int k = 0;
    for (int u = 0; u < n; ++u) {
        for (int l = 0; l < m; ++l) {
            for (int d = u + 1; d < n; ++d) {
                for (int r = l + 1; r < m; ++r) {
                    int now = a[u][l] + a[d][r] - a[u][r] - a[d][l];
                    k = gcd(k, now);
                }
            }
        }
    }
    
    if (!k) k = 2e9 + 15;
        
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (k <= a[i][j]) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
    cout << k << '\n';
    for (int i = 0; i < n; ++i) {
        cout << a[i][0] << " ";
    }
    cout << '\n';
    for (int i = 0; i < m; ++i) {
        int now = ((long long)a[0][i] - a[0][0] + k) % k;
        cout << now << " ";
    }
    cout << '\n';

    return 0;
}