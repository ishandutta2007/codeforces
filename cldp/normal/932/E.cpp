#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 5010;
const int INF = 1000000007;
const double PI = acos(-1.0);

long long f[MAXN][MAXN];

int qpow(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    int temp = qpow(1LL * a * a % INF, b / 2);
    if (b & 1) return 1LL * temp * a % INF;
    return temp;
}

int main() {
    ios_base::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    f[0][0] = 1;
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j <= K; ++j) {
            f[i + 1][j + 1] = (f[i + 1][j + 1] + f[i][j] * (N - j)) % INF;
            f[i + 1][j] = (f[i + 1][j] + f[i][j] * j) % INF;
        }
    }
    long long ans = 0;
    for (int i = 0; i <= K; ++i) {
        ans = (ans + f[K][i] * qpow(2, N - i)) % INF;
    }
    cout << ans << endl;
    return 0;
}