#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define ld long double

// so the expected number of inversions for the whole thing is (n choose 2)/2
/**
 * pick a range. number of inversions is
 * inversions on the left -> prefix
 * inversions on the right -> suffix
 * inversions in the middle -> (L choose 2)/2
 * inversions left with middle -> same as original, fenwick tree
 * inversions right with middle -> same as original, fenwick tree
 * inversions left with right same as original
 */
// pick a range, inversions on the left + on the right + with the range

template <typename T>
struct fenwick {
    int N;
    vector<T> tree;

    explicit fenwick(int N = 0) : N(N), tree(N + 1) {}

    template <typename O>
    explicit fenwick(int N, const vector<O>& arr) : fenwick(N) {
        assert(N == int(arr.size()) - 1);
        for (int i = 1; i <= N; i++) {
            tree[i] += arr[i];
            if (int j = i + (i & -i); j <= N) {
                tree[j] += tree[i];
            }
        }
    }

    T sum_inclusive(int l, int r) const {
        assert(0 <= l && l <= N + 1 && 0 <= r && r <= N);
        if (l > r) {
            return 0;
        } else {
            return sum(r) - sum(l - 1);
        }
    }

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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cout << setprecision(11) << fixed << showpoint;

    int N;
    cin >> N;
    vector<int> p(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> p[i];
    }

    ld ans = 0;

    fenwick<int> tree;
    ld sum;

    // L|L
    tree = fenwick<int>(N);
    sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += tree.sum_inclusive(p[i], N);
        tree.add(p[i], 1);
        ans += sum * (N - i);
    }

    // R|R
    tree = fenwick<int>(N);
    sum = 0;
    for (int i = N; i >= 1; i--) {
        sum += tree.sum_inclusive(1, p[i]);
        tree.add(p[i], 1);
        ans += sum * (i - 1);
    }

    // L|...
    tree = fenwick<int>(N);
    sum = 0;
    for (int i = 1; i <= N; i++) {
        tree.add(p[i], 1);
    }
    for (int i = 1; i <= N; i++) {
        tree.add(p[i], -1);
        sum -= N - p[i] - tree.sum_inclusive(p[i], N);
        sum += tree.sum_inclusive(1, p[i]);
        ans += sum * (N - i);
    }

    // M|R
    tree = fenwick<int>(N);
    fenwick<int64_t> ltree(N);
    sum = 0;
    for (int i = 1; i <= N; i++) {
        ltree.add(p[i], i);
    }
    for (int i = N; i >= 1; i--) {
        ltree.add(p[i], -i);
        int mates = tree.sum_inclusive(1, p[i]);
        sum -= 1LL * mates * i;
        sum += ltree.sum_inclusive(p[i], N);
        ans += sum;
        tree.add(p[i], 1);
    }

    // M|M
    for (int i = 1; i <= N; i++) {
        ld E = 0.25 * i * (i - 1);
        ans += (N - i + 1) * E;
    }

    ans /= 1LL * N * (N + 1) / 2;
    cout << ans << '\n';

    return 0;
}