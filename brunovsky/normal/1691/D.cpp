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

    template <typename It>
    sparse_table(It first, It last, const BinOp& op) : binop(op) {
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

    sparse_table(const vector<T>& v, const BinOp& op)
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

int64_t maxop(int64_t a, int64_t b) { return max(a, b); }
int64_t minop(int64_t a, int64_t b) { return min(a, b); }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> a(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
        }
        vector<int64_t> p(N + 2), s(N + 2);
        for (int i = 1; i <= N; i++) {
            p[i] = p[i - 1] + a[i];
        }
        for (int i = N; i >= 1; i--) {
            s[i] = s[i + 1] + a[i];
        }
        vector<int> order(N);
        iota(begin(order), end(order), 1);
        sort(begin(order), end(order), [&](int i, int j) { return a[i] < a[j]; });
        set<int> indices;
        for (int i = 0; i <= N + 1; i++) {
            indices.insert(end(indices), i);
        }

        sparse_table prmq(p, &maxop), srmq(s, &maxop);

        bool ok = true;

        for (int i : order) {
            auto pos = indices.find(i);
            int r = *next(pos);
            int l = *prev(pos);
            indices.erase(pos);
            debug(i, l, r);
            debug(i, s[i], srmq.query(l + 1, i + 1));
            debug(i, p[i], prmq.query(i, r));
            ok &= srmq.query(l + 1, i + 1) == s[i];
            ok &= prmq.query(i, r) == p[i];
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}