#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 505555, inf = 1011111111;

struct edge {
    int u, v, d, num;
    edge() {
    }
    void read() {
        scanf("%d%d%d", &u, &v, &d);
    }
    bool operator < (const edge &e) const {
        return d < e.d;
    }
};

int n, m, q, pos[max_n], block[max_n], cnt;
edge e[max_n];
int ans[max_n];
vector<pair<int, int>> all[max_n];
int parent[max_n], sz[max_n];
int from[max_n], to[max_n];

int find_set(int v) {
    if (v == parent[v]) {
        return v;
    }
    return find_set(parent[v]);
}

vector<int> upd;

void union_set(int v1, int v2) {
    v1 = find_set(v1);
    v2 = find_set(v2);
    if (sz[v1] > sz[v2]) {
        swap(v1, v2);
    }
    parent[v1] = v2;
    sz[v2] += sz[v1];
    upd.push_back(v1);
}

void restore() {
    reverse(upd.begin(), upd.end());
    for (int v : upd) {
        sz[parent[v]] -= sz[v];
        parent[v] = v;
    }
    upd.clear();
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        e[i].read();
        e[i].num = i;
    }
    sort(e, e + m);
    for (int i = 0; i < m; ++i) {
        pos[e[i].num] = i;
        //cout << e[i].u << " " << e[i].v << "   " << e[i].d << endl;
    }
    for (int i = 0; i < m; ) {
        int st = i;
        while (i < m && e[i].d == e[st].d) {
            block[i] = cnt;
            ++i;
        }
        from[cnt] = st;
        to[cnt] = i;
        ++cnt;
    }
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int k;
        ans[i] = 1;
        scanf("%d", &k);
        while (k--) {
            int num;
            scanf("%d", &num);
            --num;
            all[block[pos[num]]].push_back(make_pair(i, pos[num]));
        }
    }
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        sz[i] = 1;
    }
    for (int bl = 0; bl < cnt; ++bl) {
        sort(all[bl].begin(), all[bl].end());
        upd.clear();
        for (int i = 0; i < all[bl].size(); ) {
            restore();
            int st = i;
            while (i < all[bl].size() && all[bl][i].first == all[bl][st].first) {
                //cout << bl << "  " << i << ": " << all[bl][i].first << " " << all[bl][i].second << endl;
                if (ans[all[bl][i].first] == 0) {
                    ++i;
                    continue;
                }
                int num = all[bl][i].second;
                //cout << "f: " << find_set(e[num].u) << " " << find_set(e[num].v) << endl;
                if (find_set(e[num].u) == find_set(e[num].v)) {
                    ans[all[bl][i].first] = 0;
                } else {
                    union_set(e[num].u, e[num].v);
                }
                ++i;
            }
        }
        restore();
        for (int i = from[bl]; i < to[bl]; ++i) {
            int v1 = find_set(e[i].u);
            int v2 = find_set(e[i].v);
            if (v1 != v2) {
                union_set(v1, v2);
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        if (ans[i]) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}