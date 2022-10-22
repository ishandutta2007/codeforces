#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010000;
const int INF = 1000000007;
const double PI = acos(-1.0);

int qpow(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    int temp = qpow(1LL * a * a % INF, b / 2);
    if (b & 1) return 1LL * temp * a % INF;
    return temp;
}

int x[MAXN];
int f[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    f[0] = f[1] = 1;
    for (int i = 2; i <= 1000000; ++i) f[i] = (1LL * f[i - 1] * i) % INF;

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> x[i];
    sort(x, x + N);

    int ans = 0;
    for (int i = 0; i < N; ) {
        int j = i;
        while (j < N && x[j] == x[i]) ++j;
        int temp = 1LL * f[N] * qpow(N - i, INF - 2) % INF;
        if (j != N) ans = (ans + 1LL * temp * (j - i) % INF * x[i]) % INF;
        i = j;
    }
    cout << ans << endl;

    return 0;
}