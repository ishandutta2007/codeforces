#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename T, typename BinaryFn>
struct bitree {
    int N;
    vector<T> tree;
    BinaryFn binop;

    explicit bitree(int N, const BinaryFn& op = BinaryFn(), T id = T())
        : N(N), tree(N + 1, id), binop(op) {}

    template <typename A>
    explicit bitree(int N, const vector<A>& arr, const BinaryFn& op = BinaryFn(),
                    T id = T())
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

    T prefix_exclusive(int r) const {
        T accum = tree[0];
        for (int i = r; i > 0; i -= i & -i) {
            accum = binop(tree[i], accum);
        }
        return accum;
    }

    T prefix_inclusive(int r) const { return prefix_exclusive(r + 1); }

    // Find smallest i such that fn(prefix_inclusive(i)) is true, or N otherwise.
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

template <typename O, typename T>
auto compress(const vector<T>& u, T s = 0) {
    int N = u.size();
    if (N == 0)
        return vector<O>();

    vector<pair<T, int>> ps(N);
    for (int i = 0; i < N; i++) {
        ps[i] = {u[i], i};
    }
    sort(begin(ps), end(ps));

    vector<O> v(N);
    v[ps[0].second] = s;
    for (int i = 1; i < N; i++) {
        v[ps[i].second] = v[ps[i - 1].second] + (ps[i].first != ps[i - 1].first);
    }
    return v;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }

        debug(a);
        a = compress<int>(a);
        debug(a);

        bitree<int, plus<int>> bit(N + 1);
        int64_t ans = 0;
        for (int i = 0; i < N; i++) {
            int before = bit.prefix_exclusive(a[i]);
            int after = i - bit.prefix_inclusive(a[i]);
            ans += min(before, after);
            bit.combine(a[i], 1);
        }
        cout << ans << '\n';
    }
    return 0;
}