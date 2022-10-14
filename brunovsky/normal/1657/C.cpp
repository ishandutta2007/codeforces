#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename Vec>
auto build_manachers(const Vec& s) {
    int N = s.size();
    array<vector<int>, 2> lp{vector<int>(N + 1), vector<int>(N)};
    for (int b : {0, 1}) {
        for (int i = 0, l = 0, r = -1; i < N; i++) {
            int k = (i > r) ? b : min(lp[b][l + r - i + !b], r - i + 1);
            while (0 <= i - k - !b && i + k < N && s[i - k - !b] == s[i + k]) {
                k++;
            }
            lp[b][i] = k--;
            if (i + k > r) {
                l = i - k - !b;
                r = i + k;
            }
        }
    }
    return lp;
}

template <typename T>
struct min_rmq {
    vector<vector<T>> jmp;

    min_rmq() = default;
    explicit min_rmq(const vector<T>& v) : jmp(1, v) {
        for (int len = 1, k = 1, N = v.size(); 2 * len <= N; len *= 2, ++k) {
            int J = N - 2 * len + 1;
            jmp.emplace_back(J);
            for (int j = 0; j < J; j++) {
                const auto& l = jmp[k - 1][j];
                const auto& r = jmp[k - 1][j + len];
                jmp[k][j] = l < r ? l : r; // prefers last
            }
        }
    }

    // query range [a,b)
    T query(int a, int b) const {
        static constexpr int BITS = CHAR_BIT * sizeof(int) - 1;
        // assert(a < b);
        int bits = BITS - __builtin_clz(b - a);
        const auto& l = jmp[bits][a];
        const auto& r = jmp[bits][b - (1 << bits)];
        return l < r ? l : r;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        string s;
        cin >> N >> s;
        auto lp = build_manachers(s);

        vector<int> height(N + 1);
        for (int h = 0, i = 0; i < N; i++) {
            height[i + 1] = h += s[i] == '(' ? 1 : -1;
        }
        min_rmq<int> rmq(height);

        int L = 0;
        int ops = 0;
        for (int i = 1; i < N && 2 * i - L <= N; i++) {
            int R = 2 * i - L;
            // Try an even palindrome
            if (i - lp[0][i] <= L) {
                i = L = R, ops++;
                continue;
            }
            // Try an even regular bracket sequence
            if (height[L] == height[R] && rmq.query(L, R) == height[L]) {
                i = L = R, ops++;
                continue;
            }
            // Try an odd palindrome
            if (i - lp[1][i] < L) {
                i = L = R + 1, ops++;
                continue;
            }
        }
        cout << ops << ' ' << (N - L) << '\n';
    }
    return 0;
}