#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 5010;
const int MAXM = 100010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int x[MAXN];
int f[MAXN][MAXN];
int g[MAXM], h[7];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> x[i];

    int ans = 2;
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= N; ++j) {
            if (j <= i) {
                f[i][j] = f[j][i];
                g[x[j]] = max(g[x[j]], f[i][j]);
                h[x[j] % 7] = max(h[x[j] % 7], f[i][j]);
                continue;
            }
            f[i][j] = max(f[i][j], h[x[j] % 7] + 1);
            f[i][j] = max(f[i][j], g[x[j] - 1] + 1);
            f[i][j] = max(f[i][j], g[x[j]    ] + 1);
            f[i][j] = max(f[i][j], g[x[j] + 1] + 1);
            f[i][j] = max(f[i][j], f[0][i] + 1);
            g[x[j]] = max(g[x[j]], f[i][j]);
            h[x[j] % 7] = max(h[x[j] % 7], f[i][j]);
            ans = max(ans, f[i][j]);
        }

        for (int j = 0; j <= N; ++j) g[x[j]] = 0;
        for (int j = 0; j < 7; ++j) h[j] = 0;
    }
    cout << ans << endl;
    return 0;
}