#include <bits/stdc++.h>

using namespace std;

const int small_bits = 8;
const int big_bits = 8;
const int ab = small_bits + big_bits;
const int small_cnt = (1 << small_bits);
const int big_cnt = (1 << big_bits);

int ptr, go[big_cnt * 2][2], res[big_cnt * 2];

void clear() {
    for (int i = 0; i < big_cnt * 2; ++i) {
        go[i][0] = -1;
        go[i][1] = -1;
        res[i] = 0;
    }
    ptr = 1;
}

void insert(int num) {
    int v = 0;
    for (int i = ab - 1; i >= small_bits; --i) {
        int bit = (num >> i) & 1;
        if (go[v][bit] == -1) {
            go[v][bit] = ptr;
            v = ptr;
            ptr++;
        }
        else
            v = go[v][bit];
    }
    res[v] = max(res[v], num & ((1 << small_bits) - 1));
}

int get(int num) {
    int v = 0, ans = 0;
    for (int i = ab - 1; i >= small_bits; --i) {
        int bit = (num >> i) & 1;
        if (go[v][bit ^ 1] != -1) {
            v = go[v][bit ^ 1];
            ans += (1 << i);
        }
        else
            v = go[v][bit];
    }
    ans += res[v];
    return ans;
}

const int mx = 100000;
int n, q, a[mx], p[mx], h[mx], up[mx], calc[mx][small_cnt];
vector<int> g[mx], children[mx];

void hang(int v, int pv, int hi) {
    p[v] = pv;
    h[v] = hi;
    for (auto v1 : g[v]) {
        if (v1 != pv) {
            children[v].push_back(v1);
            hang(v1, v, hi + 1);
        }
    }
}

int query(int u, int v, int dist) {
    if (h[u] - h[v] <= small_cnt) {
        int ans = 0;
        while (u != v) {
            ans = max(ans, dist ^ a[u]);
            u = p[u];
            dist++;
        }
        ans = max(ans, dist ^ a[u]);
        return ans;
    }
    else {
        int res = query(up[u], v, dist + small_cnt);
        return max(res, calc[u][dist >> small_bits]);
    }
}

int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    hang(0, 0, 0);
    for (int i = 0; i < n; ++i) {
        if (h[i] >= small_cnt) {
            int v = i;
            clear();
            insert(a[v]);
            for (int j = 0; j < small_cnt - 1; ++j) {
                v = p[v];
                insert(a[v] ^ (j + 1));
            }
            up[i] = p[v];
            for (int j = 0; j < big_cnt; ++j) {
                int y = (j << small_bits);
                calc[i][j] = get(y);
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        cout << query(v, u, 0) << endl;
    }
    return 0;
}