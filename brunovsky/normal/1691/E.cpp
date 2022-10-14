#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

struct disjoint_set {
    int N, S;
    vector<int> nxt, siz;

    explicit disjoint_set(int N = 0) : N(N), S(N), nxt(N), siz(N, 1) {
        iota(begin(nxt), end(nxt), 0);
    }

    void assign(int n) { *this = disjoint_set(n); }
    void reset() { *this = disjoint_set(N); }
    int size(int n) { return siz[n]; }
    bool same(int i, int j) { return find(i) == find(j); }
    bool isroot(int i) { return find(i) == i; }
    void reroot(int u) {
        if (int r = find(u); u != r) {
            siz[u] = siz[r];
            nxt[u] = nxt[r] = u;
        }
    }

    int find(int i) {
        while (i != nxt[i]) {
            i = nxt[i] = nxt[nxt[i]];
        }
        return i;
    }

    bool join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            if (siz[i] < siz[j]) {
                swap(i, j);
            }
            nxt[j] = i;
            siz[i] += siz[j];
            S--;
            return true;
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<array<int, 3>> segs(N);
        for (auto& [l, r, c] : segs) {
            cin >> c >> l >> r, r++;
        }
        sort(begin(segs), end(segs), [&](auto x, auto y) {
            return make_tuple(x[1], x[0]) < make_tuple(y[1], y[0]);
        });

        vector<int> color[2] = {};
        for (int i = 0; i < N; i++) {
            color[segs[i][2]].push_back(i);
        }

        vector<int> nxt(N + 1, N);
        for (int c : {0, 1}) {
            for (int i = 0, R = color[c].size(); i + 1 < R; i++) {
                nxt[color[c][i]] = color[c][i + 1];
            }
        }

        auto find = [&](int c, int x) {
            int S = color[c].size();
            int L = -1, R = S;
            while (L + 1 < R) {
                int M = (L + R) / 2;
                int i = color[c][M];
                segs[i][1] >= x ? R = M : L = M;
            }
            return R == S ? N : color[c][R];
        };

        disjoint_set dsu(N);
        for (int i = 0; i < N; i++) {
            auto [l, r, c] = segs[i];
            int j = find(1 - c, l + 1);
            int k = j;
            while (k < i) {
                dsu.join(i, k);
                k = nxt[k];
            }
            if (j < i) {
                nxt[j] = k;
            }
        }
        cout << dsu.S << '\n';
    }
    return 0;
}