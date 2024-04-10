#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int MAXM = 10010;
const int INF = 1000000007;
const double PI = acos(-1.0);

long long f[MAXN][MAXM];
long long x[MAXN], c[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    long long W, B, X;
    cin >> N >> W >> B >> X;
    for (int i = 1; i <= N; ++i) cin >> x[i];
    for (int i = 1; i <= N; ++i) cin >> c[i];
    memset(f, -1, sizeof(f));
    int cnt = 0;
    f[0][0] = W;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= cnt; ++j) {
            if (f[i][j] == -1) continue;
            if (i > 0) {
                f[i + 1][j] = max(f[i + 1][j], min(W + j * B, f[i][j] + X));
            } else {
                f[i + 1][j] = max(f[i + 1][j], min(W + j * B, f[i][j]));
            }
        }
        for (int j = cnt; j >= 0; --j) {
            if (f[i + 1][j] == -1) continue;
            for (int k = j + 1; k <= j + x[i + 1]; ++k) {
                if (f[i + 1][j] < (k - j) * c[i + 1]) break;
                f[i + 1][k] = max(f[i + 1][k], f[i + 1][j] - (k - j) * c[i + 1]);
            }
        }
        cnt += x[i + 1];
    }
    
    for (int i = 10000; i >= 0; --i) {
        if (f[N][i] >= 0) {
            cout << i << endl;
            break;
        }
    }
    
    return 0;
}