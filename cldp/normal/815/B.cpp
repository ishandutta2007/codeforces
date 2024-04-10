#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 400010;
const long long INF = 1000000007;

typedef long long LL;

LL extended_euclidean(LL a, LL b, LL &x, LL &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    LL res = extended_euclidean(b, a % b, y, x);
    y -= a / b * x;
    return res;
}

LL modular(LL x, LL m) {
    if (x < 0) x += abs(x / m) * m + m;
    return x % m;
}

LL modular_inverse(LL a, LL m) {
    LL x, y;
    extended_euclidean(a, m, x, y);
    return modular(x, m);
}


LL FAC[MAXN], INV[MAXN];
LL x[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    FAC[0] = INV[0] = FAC[1] = INV[1] = 1;
    // big enough???
    for (int i = 2; i <= 300000; ++i) {
        FAC[i] = (1LL * FAC[i - 1] * i) % INF;
        INV[i] = modular_inverse(FAC[i], INF);
    }

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> x[i];
    if (N % 4 == 0) {
        int T = N / 2 - 1;
        LL ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
        for (int i = 0; i < N; i += 2) {
            ans1 = (ans1 + ((1LL * x[i] * FAC[T] % INF) * INV[i / 2] % INF) * INV[T - i / 2]) % INF;
            ans2 = (ans2 + ((1LL * x[i + 1] * FAC[T] % INF) * INV[i / 2] % INF) * INV[T - i / 2]) % INF;
            ans3 = (ans3 + ((1LL * x[i + 2] * FAC[T] % INF) * INV[i / 2] % INF) * INV[T - i / 2]) % INF;
            ans4 = (ans4 + ((1LL * x[i + 2] * FAC[T] % INF) * INV[i / 2] % INF) * INV[T - i / 2]) % INF;
        }
        ans1 = (ans1 + ans2) % INF;
        ans2 = (ans2 - ans3 + INF) % INF;
        ans3 = (ans3 + ans4) % INF;
        ans1 = (ans1 - ans2 + INF) % INF;
        ans2 = (ans2 + ans3) % INF;
        ans1 = (ans1 - ans2 + INF) % INF;
        cout << ans1 << endl;
    } else
    if (N % 4 == 1) {
        int T = (N - 1) / 2;
        LL ans = 0;
        for (int i = 0; i < N; i += 2) {
            ans = (ans + ((1LL * x[i] * FAC[T] % INF) * INV[i / 2] % INF) * INV[T - i / 2]) % INF;
        }
        cout << (ans + INF) % INF << endl;
    } else 
    if (N % 4 == 2) {
        int T = (N - 1) / 2;
        LL ans1 = 0, ans2 = 0;
        for (int i = 0; i < N; i += 2) {
            ans1 = (ans1 + ((1LL * x[i] * FAC[T] % INF) * INV[i / 2] % INF) * INV[T - i / 2]) % INF;
            ans2 = (ans2 + ((1LL * x[i + 1] * FAC[T] % INF) * INV[i / 2] % INF) * INV[T - i / 2]) % INF;
        }
        cout << (ans1 + ans2) % INF << endl;
    } else 
    if (N % 4 == 3) {
        int T = N / 2 - 1;
        LL ans1 = 0, ans2 = 0, ans3 = 0;
        for (int i = 0; i < N; i += 2) {
            ans1 = (ans1 + ((1LL * x[i] * FAC[T] % INF) * INV[i / 2] % INF) * INV[T - i / 2]) % INF;
            ans2 = (ans2 + ((1LL * x[i + 1] * FAC[T] % INF) * INV[i / 2] % INF) * INV[T - i / 2]) % INF;
            ans3 = (ans3 + ((1LL * x[i + 2] * FAC[T] % INF) * INV[i / 2] % INF) * INV[T - i / 2]) % INF;
        }
        ans1 = (ans1 + ans2) % INF;
        ans2 = (ans2 - ans3 + INF) % INF;
        cout << (ans1 + ans2) % INF << endl;
    }


    return 0;
}