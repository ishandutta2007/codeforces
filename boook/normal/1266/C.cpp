#include <bits/stdc++.h>
using namespace std;

int n, m;
int32_t main() {
    cin.tie(0), cout.sync_with_stdio(0);
    cin >> n >> m;
    if (n == 1 && m == 1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            int v1, v2;
            if (n < m) v1 = i, v2 = j + n;
            else v1 = i + m, v2 = j;
            cout << v1 * v2 << " ";
        }
        cout << "\n";
    }
    
    return 0;
}