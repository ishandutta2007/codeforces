#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 2000100;
const long long INF = 1000000007;

int f[MAXN], p[MAXN];

int poww(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    int temp = poww(1LL * a * a % INF, b / 2);
    if (b & 1) return 1LL * temp * a % INF;
    return temp;
}

int main() {
    ios_base::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= K; ++i) p[i] = poww(i, N);
    int ans = 0, sum = 0;
    for (int i = 1; i <= K; ++i) {
        f[i] = (INF + f[i] + p[i] - p[i - 1]) % INF;
        sum = (sum + f[i]) % INF;
        ans = (ans + (sum ^ i)) % INF;
        for (int j = i + i; j <= K; j += i) f[j] = (INF + f[j] - f[i]) % INF;
    }
    cout << ans << endl;

    return 0;
}