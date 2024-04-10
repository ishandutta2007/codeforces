#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

struct disjoint_set {
    int N, S;
    vector<int> next, size;

    explicit disjoint_set(int N = 0) : N(N), S(N), next(N), size(N, 1) {
        iota(begin(next), end(next), 0);
    }

    void assign(int N) { *this = disjoint_set(N); }
    bool same(int i, int j) { return find(i) == find(j); }
    bool unit(int i) { return i == next[i] && size[i] == 1; }
    bool root(int i) { return find(i) == i; }
    void reroot(int u) {
        if (int r = find(u); u != r) {
            size[u] = size[r];
            next[u] = next[r] = u;
        }
    }

    int find(int i) {
        while (i != next[i]) {
            i = next[i] = next[next[i]];
        }
        return i;
    }

    bool join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            if (size[i] < size[j]) {
                swap(i, j);
            }
            next[j] = i;
            size[i] += size[j];
            S--;
            return true;
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, d;
    cin >> N >> d;

    vector<array<int, 2>> links(d);
    for (int i = 0; i < d; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        links[i] = {u, v};
    }

    disjoint_set dsu(N);
    multiset<int, greater<int>> sizes;
    int extra = 0;

    for (int u = 0; u < N; u++) {
        sizes.insert(1);
    }

    auto get_ans = [&]() {
        auto it = sizes.begin();
        int n = extra + 1;
        int ans = 0;
        while (n-- && it != sizes.end()) {
            ans += *it++;
        }
        return ans - 1;
    };

    for (int i = 0; i < d; i++) {
        int u = dsu.find(links[i][0]);
        int v = dsu.find(links[i][1]);
        if (dsu.same(u, v)) {
            extra++;
        } else {
            sizes.erase(sizes.find(dsu.size[u]));
            sizes.erase(sizes.find(dsu.size[v]));
            dsu.join(u, v);
            u = dsu.find(u);
            sizes.insert(dsu.size[u]);
        }
        cout << get_ans() << '\n';
    }

    return 0;
}