#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

struct Data {
    static constexpr int64_t ninf = INT64_MIN / 3, z = 0;
    int64_t sum = 0, pref = ninf, suff = ninf, best = ninf;

    Data(int64_t v) : sum(v), pref(max(z, v)), suff(max(z, v)), best(max(z, v)) {}

    void pushup(Data& a, Data& b) {
        sum = a.sum + b.sum;
        pref = max(a.pref, a.sum + b.pref);
        suff = max(b.suff, b.sum + a.suff);
        best = max({a.best, b.best, a.suff + b.pref});
    }
};

struct binary_trie {
    int n, root;
    vector<Data> data;
    vector<array<int, 2>> kids;

    binary_trie(const vector<int64_t>& a) : n(a.size()) { root = build_dfs(0, n, a); }

    int make() {
        int u = data.size();
        data.push_back(0);
        kids.push_back({0, 0});
        return u;
    }

    int build_dfs(int l, int r, const vector<int64_t>& a) {
        int u = make();
        debug(u, l, r);
        if (l + 1 == r) {
            data[u] = Data(a[l]);
            return u;
        }
        int m = (l + r) / 2;
        int x = build_dfs(l, m, a);
        int y = build_dfs(m, r, a);
        kids[u] = {x, y};
        data[u].pushup(data[x], data[y]);
        return u;
    }

    int64_t get() { return data[root].best; }

    void flip(int k) { flip_dfs(root, k, 0, n); }

    void flip_dfs(int u, int k, int l, int r) {
        auto [a, b] = kids[u];
        if (k == 0) {
            kids[u] = {b, a};
            data[u].pushup(data[b], data[a]);
        } else {
            assert(r - l > 1);
            int m = (l + r) / 2;
            flip_dfs(a, k - 1, l, m);
            flip_dfs(b, k - 1, m, r);
            data[u].pushup(data[a], data[b]);
        }
    }
};

inline void reverse_bits(unsigned& v) {
    v = ((v >> 1) & 0x55555555) | ((v & 0x55555555) << 1);
    v = ((v >> 2) & 0x33333333) | ((v & 0x33333333) << 2);
    v = ((v >> 4) & 0x0F0F0F0F) | ((v & 0x0F0F0F0F) << 4);
    v = ((v >> 8) & 0x00FF00FF) | ((v & 0x00FF00FF) << 8);
    v = (v >> 16) | (v << 16);
}

inline auto first_gray_code(int size, int max_size) {
    assert(0 <= size && size <= max_size && max_size <= 31);
    return make_tuple((1u << size) - 1, (1u << max_size) - 1, 0u, -1, -1);
}
inline void next_gray_code(unsigned& u, unsigned i, int& in, int& out) {
    assert(i > 0);
    unsigned b = u ^ i ^ (i >> 1);
    if (u & b) {
        in = -1, out = __builtin_ctz(b);
    } else {
        in = __builtin_ctz(b), out = -1;
    }
    u ^= b;
}
#define FOR_ALL_MASKS_GRAY_CODE(mask, max_size, in, out)                      \
    for (auto [mask, max##in, i##in, in, out] = first_gray_code(0, max_size); \
         i##in <= max##in; i##in++, next_gray_code(mask, i##in, in, out))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    const int N = 1 << n;
    vector<int64_t> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    binary_trie bit(a);
    vector<int64_t> ans(N);
    int x = 0;
    FOR_ALL_MASKS_GRAY_CODE(mask, n, in, out) {
        if (in != -1) {
            x ^= 1 << (n - 1 - in);
            bit.flip(in);
        } else if (out != -1) {
            x ^= 1 << (n - 1 - out);
            bit.flip(out);
        }
        ans[x] = bit.get();
    }

    int cur = 0;
    int Q;
    cin >> Q;
    while (Q--) {
        int K;
        cin >> K;
        cur ^= 1 << K;
        cout << ans[cur] << '\n';
    }
    return 0;
}