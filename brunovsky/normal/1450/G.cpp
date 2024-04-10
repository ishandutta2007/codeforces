#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename O>
auto compress_string(const string& u) {
    int N = u.size();
    if (N == 0)
        return make_pair(0, vector<O>());

    vector<pair<char, int>> ps(N);
    for (int i = 0; i < N; i++) {
        ps[i] = {u[i], i};
    }
    sort(begin(ps), end(ps));

    vector<O> v(N);
    v[ps[0].second] = 0;
    for (int i = 1; i < N; i++) {
        v[ps[i].second] = v[ps[i - 1].second] + (ps[i].first != ps[i - 1].first);
    }
    int S = v[ps[N - 1].second] + 1;
    return make_pair(S, move(v));
}

inline void next_lexicographical_mask(unsigned& v) {
    unsigned c = v & -v, r = v + c;
    v = c ? (((r ^ v) >> 2) / c) | r : 0;
}
#define FOR_EACH_MASK(mask, size, max_size)                                            \
    for (unsigned mask = (1 << (size)) - 1, m##mask = 1 << (max_size); mask < m##mask; \
         next_lexicographical_mask(mask))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, a, b;
    string s;
    cin >> N >> a >> b >> s;
    auto [S, work] = compress_string<int8_t>(s);
    assert(S <= 20);
    N = s.size();

    vector<int> L(S), R(S), cnt(S);
    string name(S, '0');
    for (int i = 0; i < N; i++) {
        R[work[i]] = i, cnt[work[i]]++;
    }
    for (int i = N - 1; i >= 0; i--) {
        L[work[i]] = i, name[work[i]] = s[i];
    }

    vector<int> right(S);
    iota(begin(right), end(right), 0);
    sort(begin(right), end(right), [&](int i, int j) { return R[i] < R[j]; });

    vector<int8_t> convert(1 << S);
    for (int mask = 1; mask < (1 << S); mask++) {
        int l = N, r = 0, c = 0;
        for (int i = 0; i < S; i++) {
            if (mask >> i & 1) {
                l = min(l, L[i]);
                r = max(r, R[i]);
                c += cnt[i];
            }
        }
        convert[mask] = a * (r - l + 1) <= c * b;
    }
    convert[0] = true;

    // doesn't work for abc, gives 2 a c
    // reach[i] must already mean you will convert it, so forest not tree

    vector<int8_t> tree(1 << S), forest(1 << S);
    tree[0] = forest[0] = true;

    for (int mask = 1; mask < (1 << S) - 1; mask++) {
        for (int u = 0; u < S; u++) {
            tree[mask] |= (mask >> u & 1) && forest[mask ^ (1 << u)] && convert[mask];
        }
        forest[mask] |= tree[mask];
        int sub = 0, rest = mask;
        for (int u : right) {
            if (mask >> u & 1) {
                sub += 1 << u;
                rest -= 1 << u;
                forest[mask] |= forest[sub] & forest[rest];
            }
        }
    }

    vector<char> ans;
    for (int i = 0, full = (1 << S) - 1; i < S; i++) {
        int mask = full ^ (1 << i);
        if (forest[mask]) {
            ans.push_back(name[i]);
        }
    }

    int A = ans.size();
    cout << A << ' ';
    for (int i = 0; i < A; i++) {
        cout << ans[i] << " \n"[i + 1 == A];
    }
    return 0;
}