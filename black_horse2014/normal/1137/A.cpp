#include <bits/stdc++.h>
using namespace std;

const int N = 1100;

int a[N][N], b[N];
int rx[N][N], ry[N][N];
int cx[N][N], cy[N][N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    int bn = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) b[j-1] = a[i][j];
        sort(b, b + m);
        int bn = unique(b, b + m) - b;
        for (int j = 1; j <= m; j++) {
            rx[i][j] = lower_bound(b, b + bn, a[i][j]) - b;
            ry[i][j] = bn - rx[i][j] - 1;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) b[j-1] = a[j][i];
        sort(b, b + n);
        int bn = unique(b, b + n) - b;
        for (int j = 1; j <= n; j++) {
            cx[j][i] = lower_bound(b, b + bn, a[j][i]) - b;
            cy[j][i] = bn - cx[j][i] - 1;
        }
    }
    for (int i = 1; i <= n; i++, cout << endl) {
        for (int j = 1; j <= m; j++) {
            cout << max(cx[i][j], rx[i][j]) + max(cy[i][j], ry[i][j]) + 1 << ' ';
        }
    }
    return 0;
}