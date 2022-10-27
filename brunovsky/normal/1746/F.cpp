#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename T, typename BinOp>
struct bitree {
    int N;
    vector<T> tree;
    BinOp binop;

    explicit bitree(int N, T id = T()) : N(N), tree(N + 1, id), binop(BinOp()) {}

    explicit bitree(int N, const BinOp& op, T id = T())
        : N(N), tree(N + 1, id), binop(op) {}

    template <typename A>
    explicit bitree(int N, const vector<A>& arr, const BinOp& op = BinOp(), T id = T())
        : bitree(N, op, id) {
        for (int i = 1; i <= N; i++) {
            tree[i] = binop(arr[i - 1], tree[i]);
            if (int j = i + (i & -i); j <= N) {
                tree[j] = binop(tree[i], tree[j]);
            }
        }
    }

    void combine(int i, T v) {
        for (++i; i <= N; i += i & -i) {
            tree[i] = binop(tree[i], v);
        }
    }

    // Prefix sum exclusive, [0..r)
    T prefix(int r) const {
        T accum = tree[0];
        for (int i = r; i > 0; i -= i & -i) {
            accum = binop(tree[i], accum);
        }
        return accum;
    }

    // Find smallest i such that fn(prefix(i)) is true, or N otherwise.
    // fn should be F F F F ... T T T T, e.g. fn(sum) := x <= sum if sum is increasing
    template <typename Fn>
    int lower_bound(Fn&& fn) const {
        int i = 0;
        T accum = tree[0];
        for (int bit = 8 * sizeof(int) - __builtin_clz(N << 1); bit >= 0; bit--) {
            int next = i + (1 << bit);
            if (next <= N) {
                T combined = binop(accum, tree[next]);
                if (!fn(combined)) {
                    i = next;
                    accum = combined;
                }
            }
        }
        return i;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<array<int, 5>> queries(Q);
    vector<int> vals = a;
    for (auto& [t, i, j, k, ans] : queries) {
        if (cin >> t, t == 1) {
            cin >> i >> j, i--;
            vals.push_back(j);
        } else {
            cin >> i >> j >> k, i--;
            ans = 1;
        }
    }

    static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    static uniform_int_distribution<uint64_t> dist(1'000'000ULL, 1'000'000'000ULL);

    sort(begin(vals), end(vals));
    vals.erase(unique(begin(vals), end(vals)), end(vals));
    int V = vals.size();

    for (auto& v : a) {
        v = lower_bound(begin(vals), end(vals), v) - begin(vals);
    }
    for (auto& [t, i, v, k, ans] : queries) {
        if (t == 1) {
            v = lower_bound(begin(vals), end(vals), v) - begin(vals);
        }
    }

    for (int run = 0; run < 30; run++) {
        vector<int> b = a, mask(V);
        for (int i = 0; i < V; i++) {
            mask[i] = dist(rng);
        }

        bitree<uint64_t, plus<uint64_t>> bit(N);
        for (int i = 0; i < N; i++) {
            bit.combine(i, mask[b[i]]);
        }

        for (auto& [t, i, j, k, ans] : queries) {
            if (t == 1) {
                bit.combine(i, mask[j] - mask[b[i]]);
                b[i] = j;
            } else if (ans) {
                uint64_t sum = bit.prefix(j) - bit.prefix(i);
                ans &= sum % uint64_t(k) == 0;
            }
        }
    }

    for (auto& [t, i, j, k, ans] : queries) {
        if (t == 2) {
            cout << (ans ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}