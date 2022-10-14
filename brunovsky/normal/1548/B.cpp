#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

template <typename T>
struct gcd_rmq {
    vector<vector<T>> jmp;

    gcd_rmq() = default;
    explicit gcd_rmq(const vector<T>& v) : jmp(1, v) {
        for (int len = 1, k = 1, N = v.size(); 2 * len <= N; len *= 2, ++k) {
            int J = N - 2 * len + 1;
            jmp.emplace_back(J);
            for (int j = 0; j < J; j++) {
                const auto& l = jmp[k - 1][j];
                const auto& r = jmp[k - 1][j + len];
                jmp[k][j] = gcd(l, r);
            }
        }
    }

    T query(int a, int b) const /* [a,b) */ {
        static constexpr int BITS = CHAR_BIT * sizeof(int) - 1;
        assert(a < b); // or return inf if a == b
        int bits = BITS - __builtin_clz(b - a);
        const auto& l = jmp[bits][a];
        const auto& r = jmp[bits][b - (1 << bits)];
        return gcd(l, r);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<long> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        vector<long> b(N - 1);
        for (int i = 1; i < N; i++) {
            b[i - 1] = a[i] - a[i - 1];
        }
        gcd_rmq<long> rmq(b);

        int ans = 1;
        for (int i = 0; i + 1 < N; i++) {
            // find largest starting at i
            int L = i, R = N;
            while (L + 1 < R) {
                int M = (L + R) / 2;
                if (rmq.query(i, M) == 1) {
                    R = M;
                } else {
                    L = M;
                }
            }
            ans = max(ans, R - i);
        }

        cout << ans << '\n';
    }
    return 0;
}