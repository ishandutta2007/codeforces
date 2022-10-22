#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000007;
const int MAXN = 401000;

typedef long long LL;

LL X[MAXN], Y[MAXN];
LL FAC[MAXN], IFAC[MAXN];

// The result guarantees that |x|+|y| is minimized
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

LL cal(LL a, LL b) {
    return (FAC[a + b] * IFAC[b - 1] % INF) * IFAC[a + 1] % INF;
}

int main() {
    ios_base::sync_with_stdio(false);
    string P;
    cin >> P;
    int N = P.size();
    FAC[0] = IFAC[0] = 1;
    for (int i = 1; i <= N + N; ++i) {
        FAC[i] = (FAC[i - 1] * i) % INF;
        IFAC[i] = modular_inverse(FAC[i], INF);
    }
    
    for (int i = 0; i < N; ++i) {
        if (P[i] == '(') X[i + 1] = X[i] + 1; else X[i + 1] = X[i];
    }
    for (int i = N - 1; i >= 0; --i) {
        if (P[i] == ')') Y[i + 1] = Y[i + 2] + 1; else Y[i + 1] = Y[i + 2];
    }
    
    LL ans = 0;
    for (int i = 0; i < N; ++i) {
        if (Y[i + 1] == 0) break;
        if (P[i] == '(') ans = (ans + cal(X[i + 1] - 1, Y[i + 1])) % INF;
    }
    cout << ans << endl;
    return 0;
}