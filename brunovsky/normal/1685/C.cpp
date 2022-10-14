#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename T>
struct max_rmq {
    vector<vector<T>> jmp;

    max_rmq() = default;
    explicit max_rmq(const vector<T>& v) : jmp(1, v) {
        for (int len = 1, k = 1, N = v.size(); 2 * len <= N; len *= 2, ++k) {
            int J = N - 2 * len + 1;
            jmp.emplace_back(J);
            for (int j = 0; j < J; j++) {
                const auto& l = jmp[k - 1][j];
                const auto& r = jmp[k - 1][j + len];
                jmp[k][j] = l > r ? l : r; // prefers last
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
        return l > r ? l : r;
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
        int S = s.size();
        vector<array<int, 2>> swaps;

        vector<int> sum(S + 1);
        for (int i = 0; i < S; i++) {
            sum[i + 1] = sum[i] + (s[i] == '(' ? +1 : -1);
        }
        max_rmq<int> rmq(sum);

        int left = 0;
        for (int l = 1; l <= S; l++) {
            if (sum[l] == -1) {
                int valley = l;
                int peak = left;
                int right = l;
                for (int r = l + 1; r <= S; r++) {
                    int got = rmq.query(r, S + 1);
                    if (sum[left] + got - sum[peak] < 0) {
                        break;
                    } else {
                        right = r;
                        if (sum[r] < sum[valley]) {
                            valley = r;
                        }
                        if (sum[r] >= sum[peak]) {
                            peak = r;
                        }
                    }
                }
                swaps.push_back({left, right});
                left = right - (valley - left);
                l = right;
            } else if (sum[l] >= sum[left]) {
                left = l;
            }
        }

#ifdef LOCAL
        for (auto [l, r] : swaps) {
            reverse(begin(s) + l, begin(s) + r);
        }
        vector<int> b(S + 1);
        for (int i = 0; i < S; i++) {
            b[i + 1] = b[i] + (s[i] == '(' ? +1 : -1);
        }
        debug(b);
#endif

        int K = swaps.size();
        cout << K << '\n';
        for (int i = 0; i < K; i++) {
            auto [l, r] = swaps[i];
            cout << l + 1 << ' ' << r << '\n';
        }
    }
    return 0;
}