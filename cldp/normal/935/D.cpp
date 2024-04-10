#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int qpow(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    int temp = qpow(1LL * a * a % INF, b / 2);
    if (b & 1) return 1LL * a * temp % INF;
    return temp;
}

int x[MAXN], y[MAXN];
int f[MAXN];
int inv[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) cin >> x[i];
    for (int i = 1; i <= N; ++i) cin >> y[i];
    for (int i = 1; i <= M; ++i) inv[i] = qpow(i, INF - 2);

    int ans = 0, prob = 1;
    for (int i = 1; i <= N; ++i) {
        if (x[i] != 0 && y[i] != 0) {
            if (x[i] < y[i]) break;
            if (x[i] > y[i]) {
                ans = (ans + prob) % INF;
                break;
            }
        } else
        if (x[i] == 0 && y[i] == 0) {
            ans = (ans + 1LL * M * (M - 1) % INF * inv[2] % INF * inv[M] % INF * inv[M] % INF * prob % INF) % INF;
            prob = 1LL * prob * inv[M] % INF;
        } else 
        if (x[i] == 0) {
            ans = (ans + 1LL * (M - y[i]) * prob % INF * inv[M] % INF) % INF;
            prob = 1LL * prob * inv[M] % INF;
        } else {
            ans = (ans + 1LL * (x[i] - 1) * prob % INF * inv[M] % INF) % INF;
            prob = 1LL * prob * inv[M] % INF;
        }
    }
    cout << ans << endl;
    return 0;
}