#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
const int INF = 1000000007;
const double PI = acos(-1.0);

typedef long long LL;

LL f[MAXN], g[MAXN];

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

LL finv(LL a, LL P) {
    return modular_inverse(a, P);
}

LL C(int N, int i, int j, LL P, int t, LL F) {
    LL cnt = g[N] - g[N - i] - g[i - j] - g[j];
    LL ans = f[N] * finv(f[N - i], F) % F;
    ans = ans * finv(f[i - j], F) % F;
    ans = ans * finv(f[j], F) % F;

    if (cnt >= t) return 0;
    LL K = 1;
    for (int i = 1; i <= t - cnt; ++i) K *= P;
    return ans % K * (F / K);
}

LL cal(int N, int L, int R, LL P, int t, LL F) {
    f[0] = 1;
    g[0] = 0;
    for (int i = 1; i <= N; ++i) {
        int temp = i;
        g[i] = g[i - 1];
        while (temp % P == 0) {
            temp /= P;
            ++g[i];
        }
        f[i] = f[i - 1] * temp % F;
    }
    LL ans = 0;
    for (int i = L; i <= N; ++i) {
        int a = L, b = min(R, i);
        if ((a + i) % 2 == 1) ++a;
        if ((b + i) % 2 == 1) --b;
        if (a > b) continue;
        LL temp = C(N, i, (i + a) / 2, P, t, F);
        if (b < i) temp = (temp - C(N, i, (i + b + 2) / 2, P, t, F) + F) % F;
        ans = (ans + temp) % F;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int N, L, R;
    LL P;
    cin >> N >> P >> L >> R;
    vector<pair<LL, LL> > X;
    for (int i = 2; i * i <= 2000000009; ++i) {
        if (P % i != 0) continue;
        int t = 0;
        long long F = 1;
        while (P % i == 0) {
            ++t;
            P /= i;
            F *= i;
        }
        LL ans = cal(N, L, R, i, t, F);
        X.push_back(make_pair(F, ans));
    }
    if (P != 1) {
        LL ans = cal(N, L, R, P, 1, P);
        X.push_back(make_pair(P, ans));
        P = 1;
    }

    for (int i = 0; i < X.size(); ++i) P = P * X[i].first;

    LL ans = 0;
    for (int i = 0; i < X.size(); ++i) {
        LL Wi = P / X[i].first;
        LL y = finv(Wi, X[i].first);
        ans = (ans + y * Wi % P * X[i].second) % P;
    }
    cout << ans << endl;

    return 0;
}