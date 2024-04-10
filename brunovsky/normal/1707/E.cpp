#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename T, typename BinOp>
struct sparse_table {
    vector<vector<T>> table;
    BinOp binop;

    sparse_table() = default;

    template <typename It>
    sparse_table(It first, It last, const BinOp& op = BinOp()) : binop(op) {
        table.emplace_back(first, last);
        int N = table[0].size();
        for (int len = 1, k = 1; 2 * len <= N; len *= 2, k++) {
            int J = N - 2 * len + 1;
            table.emplace_back(J);
            for (int j = 0; j < J; j++) {
                table[k][j] = binop(table[k - 1][j], table[k - 1][j + len]);
            }
        }
    }

    sparse_table(const vector<T>& v, const BinOp& op = BinOp())
        : sparse_table(begin(v), end(v), op) {}

    // query range [a,b)
    auto query(int a, int b) const {
        static constexpr int BITS = CHAR_BIT * sizeof(int) - 1;
        // assert(0 <= a && a < b && b <= int(table[0].size()));
        if (a + 1 == b) {
            return table[0][a];
        } else {
            int bits = BITS - __builtin_clz(b - a);
            return binop(table[bits][a], table[bits][b - (1 << bits)]);
        }
    }
};

using Data = array<int, 2>;

struct op {
    Data operator()(Data x, Data y) const {
        return Data{min(x[0], y[0]), max(x[1], y[1])};
    }
};

using RMQ = sparse_table<Data, op>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i], a[i]--;
        assert(0 <= a[i] && a[i] < N);
    }
    if (N == 1) {
        while (Q--) {
            int l, r;
            cin >> l >> r;
            cout << 0 << '\n';
        }
        return 0;
    }
    const int B = 36;
    array<RMQ, B> range_minmax;
    array<vector<int>, B> jump;
    {
        vector<int> loop = a;
        jump[0] = loop;
        for (int b = 1; b < B; b++) {
            vector<int> nxt(N);
            for (int i = 0; i < N; i++) {
                nxt[i] = loop[loop[i]];
            }
            swap(loop, nxt);
            jump[b] = loop;
        }
    }
    {
        vector<array<int, 2>> val(N - 1);
        for (int i = 0; i < N - 1; i++) {
            val[i] = {min(a[i], a[i + 1]), max(a[i], a[i + 1])};
        }
        range_minmax[0] = RMQ(val);
        for (int b = 1; b < B; b++) {
            vector<array<int, 2>> nxt(N - 1);
            for (int i = 0; i < N - 1; i++) {
                auto [l, r] = val[i];
                if (l == r) {
                    nxt[i] = {jump[b - 1][l], jump[b - 1][l]};
                } else {
                    nxt[i] = range_minmax[b - 1].query(l, r);
                }
            }
            swap(val, nxt);
            range_minmax[b] = RMQ(val);
        }
    }
    const int FULL = N - 1;
    while (Q--) {
        int l, r;
        cin >> l >> r, l--, r--;
        if (r - l == 0) {
            cout << -1 << '\n';
            continue;
        } else if (r - l == FULL) {
            cout << 0 << '\n';
            continue;
        }
        int64_t ans = 0;
        for (int b = B - 1; b >= 0; b--) {
            auto [L, R] = range_minmax[b].query(l, r);
            if (R - L == FULL) {
                continue;
            } else if (b == B - 1) {
                ans = -2;
                break;
            } else {
                ans += 1LL << b;
                l = L, r = R;
            }
        }
        cout << ans + 1 << '\n';
    }
    return 0;
}