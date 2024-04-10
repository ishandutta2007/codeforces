#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, k;
int mx[max_n], pmx[max_n];
int mx2[max_n], pmx2[max_n];
int mx3[max_n], pmx3[max_n];
vector<int> g[max_n], d[max_n];

void dfs(int v, int p) {
    pmx[v] = -1;
    pmx2[v] = -1;
    pmx3[v] = -1;
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (to != p) {
            dfs(g[v][i], v);
            if (mx[v] < mx[g[v][i]] + d[v][i]) {
                mx[v] = mx[g[v][i]] + d[v][i];
                pmx[v] = i;
            }
        }
    }
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (to != p && i != pmx[v]) {
            if (mx2[v] < mx[g[v][i]] + d[v][i]) {
                mx2[v] = mx[g[v][i]] + d[v][i];
                pmx2[v] = i;
            }
        }
    }
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (to != p && i != pmx[v] && i != pmx2[v]) {
            if (mx3[v] < mx[g[v][i]] + d[v][i]) {
                mx3[v] = mx[g[v][i]] + d[v][i];
                pmx3[v] = i;
            }
        }
    }
}

int get_d(int v, int num) {
    if (num == 1) {
        return d[v][pmx[v]];
    } else if (num == 2) {
        return d[v][pmx2[v]];
    } else {
        return d[v][pmx3[v]];
    }
}

vector<int> find_all(int v, int add = -1) {
    vector<int> all;
    if (add != -1) {
        all.push_back(add);
    }
    while (true) {
        all.push_back(v);
        if (pmx[v] == -1) {
            break;
        }
        v = g[v][pmx[v]];
    }
    return all;
}

ostream& operator << (ostream &os, const vector<int> &v) {
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        if (i) {
            os << ", ";
        }
        os << v[i];
    }
    os << "]";
    return os;
}

vector<int> get_res(const vector<int> &all) {
    vector<int> res;
    for (int i = 0; i < all.size(); ++i) {
        if (i + 1 < all.size()) {
            res.push_back(mx2[all[i + 1]]);
        } else {
            res.push_back(0);
        }
    }
    //cout << "1. " << res << endl;
    for (int i = res.size() - 2; i >= 0; --i) {
        res[i] = max(res[i], res[i + 1]);
    }
    //cout << "2. " << res << endl;
    for (int i = 0; i < res.size(); ++i) {
        res[i] = max(res[i], mx3[all[i]]);
    }
    //cout << "3. " << res << endl;
    int x = mx2[all[0]];
    for (int i = 1; i < res.size(); ++i) {
        x += get_d(all[i - 1], 1);
        res[i] = max(res[i], x);
        x = max(x, mx2[all[i]]);
    }
    //cout << "4. " << res << endl;
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; ++i) {
        int u, v, dist;
        scanf("%d%d%d", &u, &v, &dist);
        g[u].push_back(v);
        g[v].push_back(u);
        d[u].push_back(dist);
        d[v].push_back(dist);
    }
    dfs(1, -1);
    vector<int> all = find_all(1);
    vector<int> res = get_res(all);
    int ans = inf;
    for (int i = 0; i < all.size(); ++i) {
        int v = all[i];
        if (pmx2[v] == -1) {
            //cout << v << ": " << max(res[i], mx[all[min((int) all.size() - 1, i + k - 1)]]) << endl;
            ans = min(ans, max(res[i], mx[all[min((int) all.size() - 1, i + k - 1)]]));
        } else {
            vector<int> all2 = find_all(g[v][pmx2[v]], v);
            int y = mx3[v];
            for (int j = 1; j < all2.size(); ++j) {
                y = max(y, mx2[all2[j]]);
            }
            for (int j = 0; j < all2.size() && j < k; ++j) {
                int x = max(res[i], mx[all[min((int) all.size() - 1, i + k - 1 - j)]]);
                x = max(x, y);
                if (j) {
                    x = max(x, mx[all2[j]]);
                } else {
                    x = max(x, mx2[all2[j]]);
                }
                //cout << v << " " << j << ": " << x << endl;
                ans = min(ans, x);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}