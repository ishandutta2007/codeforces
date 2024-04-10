#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 2010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int cnt[MAXN], fac[MAXN], inv[MAXN];

int poww(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    int temp = poww(1LL * a * a % INF, b / 2);
    if (b & 1) return 1LL * temp * a % INF;
    return temp;
}

int CC(int N, int M) {
    return (1LL * fac[N] * inv[M] % INF) * inv[N - M] % INF;
}

int main() {
    ios_base::sync_with_stdio(false);
    string P;
    int K;

    fac[0] = fac[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i <= 2000; ++i) {
        fac[i] = (1LL * fac[i - 1] * i) % INF;
        inv[i] = poww(fac[i], INF - 2);
    }
    for (int i = 1; i < 1024; ++i) {
        int a = i;
        while (a != 1) {
            ++cnt[i];
            a = __builtin_popcount(a);
        }
    }

    cin >> P >> K;
    if (P.size() <= 10) {
        int upb = 0;
        for (int i = 0; i < P.size(); ++i) {
            upb = upb + upb;
            if (P[i] == '0') continue;
            upb += 1;
        }
        int ans = 0;
        for (int i = 1; i <= upb; ++i) {
            if (cnt[i] == K) ++ans;
        }
        cout << ans << endl;
        return 0;
    }

    vector<int> X;
    int ans = 0;
    for (int i = 1; i < 1024; ++i) {
        if (cnt[i] == K) ++ans;
        if (cnt[i] == K - 1) X.push_back(i);
    }
    reverse(P.begin(), P.end());

    for (int i = 10; i + 1 < P.size(); ++i) {
        for (int j = 0; j < X.size(); ++j) {
            if (X[j] > i + 1) break;
            ans = (ans + CC(i, X[j] - 1)) % INF;
        }
    }

    int temp = 1;
    for (int i = P.size() - 2; i >= 0; --i) {
        if (P[i] == '0') continue;
        for (int j = 0; j < X.size(); ++j) {
            if (X[j] > i + temp) break;
            if (temp > X[j]) continue;
            ans = (ans + CC(i, X[j] - temp)) % INF;
        }
        temp += 1;
    }
    for (int j = 0; j < X.size(); ++j) {
        if (X[j] > temp) break;
        if (X[j] == temp) ans = (ans + 1) % INF;
    }
    cout << ans << endl;

    return 0;
}