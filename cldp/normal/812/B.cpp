#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 210;
const int INF = 1000000007;
const double PI = acos(-1.0);

bool x[MAXN][MAXN];
int f[MAXN][2];

int main() {
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    M += 2;

    int T = 0;
    for (int i = N; i >= 1; --i) {
        char c;
        for (int j = 0; j < M; ++j) {
            cin >> c;
            if (c == '0') x[i][j] = false; else x[i][j] = true;
            if (x[i][j]) T = max(T, i);
        }
    }

    if (T == 0) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i <= N + 2; ++i) {
        for (int j = 0; j <= M; ++j) f[i][j] = INF;
    }
    
    int ans = INF;
    f[0][0] = -1;
    for (int i = 1; i <= N; ++i) {
        int L = M - 1, R = 0;
        for (int j = 0; j < M; ++j) {
            if (!x[i][j]) continue;
            L = min(L, j);
            R = max(R, j);
        }
        if (i == T) {
            ans = min(ans, f[i - 1][0] + R + 1);
            ans = min(ans, f[i - 1][1] + M - 1 - L + 1);
            break;
        }
        if (L > R) {
            f[i][0] = f[i - 1][0] + 1;
            f[i][1] = f[i - 1][1] + 1;
            continue;
        }
        f[i][0] = min(f[i][0], f[i - 1][0] + 1 + R + R);
        f[i][0] = min(f[i][0], f[i - 1][1] + 1 + M - 1);
        f[i][1] = min(f[i][1], f[i - 1][1] + 1 + (M - 1 - L) * 2);
        f[i][1] = min(f[i][1], f[i - 1][0] + 1 + M - 1);

    }
    cout << ans << endl;
    
    return 0;
}