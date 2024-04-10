#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct DSU {
    vector<int> par;
    vector<int> sizes;
    int max_size;
    DSU(const vector<int> &sizes_)
        : par(sizes_.size(), -1), sizes(sizes_),
          max_size(*max_element(sizes.begin(), sizes.end())) {}

    int find_set(int u) { return par[u] < 0 ? u : par[u] = find_set(par[u]); }

    void join(int u, int v) {
        u = find_set(u);
        v = find_set(v);
        if (u == v)
            return;
        if (-par[u] < -par[v])
            swap(u, v);
        sizes[u] += sizes[v];
        par[u] += par[v];
        par[v] = u;
        max_size = max(max_size, sizes[u]);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int w, h, n;
    cin >> w >> h >> n;

    struct Query {
        char type;
        int pos;
    };

    vector<Query> q(n);
    vector<int> hor_lines = {0, h};
    vector<int> ver_lines = {0, w};
    for (int i = 0; i < n; ++i) {
        cin >> q[i].type >> q[i].pos;
        if (q[i].type == 'H') {
            hor_lines.push_back(q[i].pos);
        } else {
            ver_lines.push_back(q[i].pos);
        }
    }
    sort(hor_lines.begin(), hor_lines.end());
    sort(ver_lines.begin(), ver_lines.end());

    auto cal_sizes = [&](const vector<int> &sorted_line) {
        vector<int> ans(sorted_line.size() - 1);
        for (int i = 1; i < (int)sorted_line.size(); ++i) {
            ans[i - 1] = sorted_line[i] - sorted_line[i - 1];
        }
        return ans;
    };

    DSU hor_dsu(cal_sizes(hor_lines));
    DSU ver_dsu(cal_sizes(ver_lines));

    vector<ll> ans(n);
    for (int i = n; i--;) {
        ans[i] = 1ll * hor_dsu.max_size * ver_dsu.max_size;
        if (q[i].type == 'H') {
            int pos = (int)(lower_bound(hor_lines.begin(), hor_lines.end(),
                                        q[i].pos) -
                            hor_lines.begin());
            hor_dsu.join(pos - 1, pos);
        } else {
            int pos = (int)(lower_bound(ver_lines.begin(), ver_lines.end(),
                                        q[i].pos) -
                            ver_lines.begin());
            ver_dsu.join(pos - 1, pos);
        }
    }
    for (auto i : ans)
        cout << i << '\n';

    return 0;
}