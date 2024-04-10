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

    // Prefix sum inclusive, [0..r]
    T prefix(int r) const {
        T accum = tree[0];
        for (int i = r + 1; i > 0; i -= i & -i) {
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
    int N, M;
    cin >> N >> M;
    vector<int> col(M);
    for (int i = 0; i < N; i++) {
        int c;
        cin >> c, c--;
        col[c] ^= 1;
    }

    int Q;
    cin >> Q;
    vector<array<int, 2>> queries(Q);
    for (auto& [L, R] : queries) {
        cin >> L >> R, L--;
    }

    vector<int> ans(Q), index(Q);
    iota(begin(index), end(index), 0);

    for (int k = 0; k < 20; k++) {
        int half = 1 << k, shift = 2 << k, mask = shift - 1;

        sort(begin(index), end(index), [&](int a, int b) {
            return (queries[a][0] & mask) < (queries[b][0] & mask);
        });

        bitree<int, bit_xor<int>> bit(M, bit_xor<int>{});

        for (int start = 0; start < M; start += shift) {
            for (int i = start + half; i < start + shift && i < M; i++) {
                bit.combine(i, col[i]);
            }
        }

        int pos = 0;

        for (int q : index) {
            auto [L, R] = queries[q];
            int m = (L & mask);
            while (pos < m) {
                for (int i = pos++; i < M; i += half) {
                    bit.combine(i, col[i]);
                }
            }
            ans[q] |= bit.prefix(L - 1) != bit.prefix(R - 1);
        }
    }

    string answer(Q, 'A');
    for (int q = 0; q < Q; q++) {
        answer[q] = ans[q] ? 'A' : 'B';
    }
    cout << answer<< '\n';
    return 0;
}