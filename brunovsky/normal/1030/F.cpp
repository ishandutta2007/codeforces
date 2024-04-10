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
struct fenwick {
    int N;
    vector<T> tree;

    explicit fenwick(int N = 0) : N(N), tree(N + 1) {}

    T sum(int i) const {
        T sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= i & -i;
        }
        return sum;
    }

    void add(int i, T n) {
        if (i > 0) {
            while (i <= N) {
                tree[i] += n;
                i += i & -i;
            }
        }
    }

    int lower_bound(T n) const {
        int i = 0;
        int bits = CHAR_BIT * sizeof(int) - __builtin_clz(N << 1);
        for (int j = 1 << bits; j; j >>= 1) {
            if (i + j <= N && tree[i + j] < n) {
                n -= tree[i + j];
                i += j;
            }
        }
        return i + 1;
    }
};

constexpr int MOD = 1'000'000'007;
#define big __int128_t

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N + 1);
    vector<int> b(N + 1);
    vector<int> w(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        b[i] = a[i] - i;
    }
    for (int i = 1; i <= N; i++) {
        cin >> w[i];
    }

    fenwick<big> iota_tree(N);
    fenwick<long> simple_tree(N);

    for (int i = 1; i <= N; i++) {
        iota_tree.add(i, big(a[i] - i) * w[i]);
        simple_tree.add(i, w[i]);
    }

    while (Q--) {
        int l, r;
        cin >> l >> r;
        if (l < 0) {
            int i = -l;
            iota_tree.add(i, -big(a[i] - i) * w[i]);
            simple_tree.add(i, -w[i]);
            w[-l] = r;
            iota_tree.add(i, big(a[i] - i) * w[i]);
            simple_tree.add(i, w[i]);
        } else {
            long L = a[l] - 1, R = a[r] - (r - l) + 1;

            auto eval = [&](int x) {
                int mid = lower_bound(begin(b) + l, begin(b) + r, x - l) - begin(b);
                auto pos0 = iota_tree.sum(r) - iota_tree.sum(mid - 1);
                auto pos1 = (l - x) * big(simple_tree.sum(r) - simple_tree.sum(mid - 1));
                auto neg0 = iota_tree.sum(mid - 1) - iota_tree.sum(l - 1);
                auto neg1 = (l - x) *
                            big(simple_tree.sum(mid - 1) - simple_tree.sum(l - 1));
                auto sum = pos0 + pos1 - neg0 - neg1;
                return sum;
            };

            if (l == r) {
                cout << 0 << '\n';
                continue;
            }

            while (L + 2 < R) {
                long x = (2 * L + R) / 3;
                long y = (L + 2 * R + 2) / 3;

                auto fx = eval(x);
                auto fy = eval(y);

                if (fx < fy) {
                    R = y;
                } else {
                    L = x;
                }
            }

            assert(L + 2 == R);
            auto ans = eval(L + 1);
            cout << int(ans % MOD) << '\n';
        }
    }

    return 0;
}