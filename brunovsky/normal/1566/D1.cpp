#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename T, typename BinaryOperation>
struct bitree {
    int N;
    vector<T> tree;
    BinaryOperation binop;

    explicit bitree(int N, const BinaryOperation& op, T id = T())
        : N(N), tree(N + 1, id), binop(op) {}

    template <typename A>
    explicit bitree(int N, const vector<A>& arr, const BinaryOperation& op, T id = T())
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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, M, P;
        cin >> N >> M, P = N * M;
        vector<int> a(P);
        for (int i = 0; i < P; i++) {
            cin >> a[i];
        }
        vector<int> index(P);
        iota(begin(index), end(index), 0);
        sort(begin(index), end(index),
             [&](int u, int v) { return make_pair(a[u], u) < make_pair(a[v], v); });

        using fenwick = bitree<int, plus<int>>;
        vector<fenwick> rows(N, fenwick(M, plus<int>{}, 0));

        vector<vector<int>> seats(N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                seats[i].push_back(i * M + j);
            }
            reverse(begin(seats[i]), end(seats[i]));
        }

        vector<int> where(P);
        int l = 0;
        int row = 0;
        while (l < P) {
            int r = l + 1;
            while (r < P && a[index[l]] == a[index[r]]) {
                r++;
            }
            int i = l;
            while (i < r) {
                if (seats[row].empty()) {
                    row++;
                }
                int S = seats[row].size();
                if (r - i <= S) {
                    for (int j = r - 1; j >= i; j--) {
                        where[index[j]] = seats[row].back();
                        seats[row].pop_back();
                    }
                    break;
                } else {
                    for (int j = i + S - 1; j >= i; j--) {
                        where[index[j]] = seats[row].back();
                        seats[row].pop_back();
                    }
                    i += S;
                }
            }
            l = r;
        }
        debug(where);

        int ans = 0;
        for (int i = 0; i < P; i++) {
            int W = where[i];
            int r = W / M;
            int c = W % M;
            ans += rows[r].prefix_exclusive(c);
            rows[r].combine(c, 1);
        }
        cout << ans << '\n';
    }
    return 0;
}