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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> arr(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    int V = *max_element(begin(arr), end(arr));

    fenwick<long> sum(N);
    fenwick<long> value(V);
    fenwick<int> cnt(V);
    vector<bool> vis(V + 1);

    auto add = [&](int i) {
        sum.add(i, arr[i]);
        value.add(arr[i], arr[i]);
        cnt.add(arr[i], 1);
        vis[arr[i]] = true;
    };
    auto sum_inclusive = [&](int l, int r) {
        l = clamp(l, 0, N);
        r = clamp(r, 0, N);
        if (l > r) {
            return long(0);
        } else {
            return sum.sum(r) - sum.sum(l - 1);
        }
    };
    auto value_inclusive = [&](int l, int r) {
        l = clamp(l, 0, V);
        r = clamp(r, 0, V);
        if (l > r) {
            return long(0);
        } else {
            return value.sum(r) - value.sum(l - 1);
        }
    };
    auto count_inclusive = [&](int l, int r) {
        l = clamp(l, 0, V);
        r = clamp(r, 0, V);
        if (l > r) {
            return 0;
        } else {
            return cnt.sum(r) - cnt.sum(l - 1);
        }
    };

    add(1);
    vector<long> p(N + 1);

    for (int k = 2; k <= N; k++) {
        long a = long(k - 1) * arr[k] + sum_inclusive(1, k - 1);
        long b = 0, c = 0, d = 0;

        for (int i = arr[k], f = 1; i <= V; i += arr[k], f++) {
            b += 1LL * arr[k] * f * count_inclusive(i, i + arr[k] - 1);
        }
        int M = 1;
        while ((M + 1) * (M + 1) <= arr[k]) {
            M++;
        }
        // consider small j
        for (int v = 1, R = arr[k] / M; v <= R; v++) {
            if (vis[v]) {
                c += 1LL * v * (arr[k] / v);
            }
        }

        // consider j such that floor(arr[k]/arr[j])=v
        for (int v = 1; v < M; v++) {
            int lo = 1 + arr[k] / (v + 1);
            int hi = arr[k] / v;
            d += v * value_inclusive(lo, hi);
        }

        p[k] = p[k - 1] + a - b - c - d;
        add(k);
    }

    for (int i = 1; i <= N; i++) {
        cout << p[i] << " \n"[i == N];
    }

    return 0;
}