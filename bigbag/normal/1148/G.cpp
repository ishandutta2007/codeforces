#include <bits/stdc++.h>

using namespace std;

const int max_n = 100011, inf = 1000111222;
const int max_x = 10001110;
const int max_c = 511;

int n, k, a[max_n], used[max_n], sz[max_n];
vector<int> full, big_p, all[max_x], p[max_n];
bitset<max_n> b[max_n * 8 / max_c], cur;
int mn[max_x], cnt[max_x];
vector<int> all_v, ans, g[max_n];
vector<vector<int>> comp;

void get_all_p() {
    for (int i = 2; i < max_x; ++i) {
        if (!mn[i]) {
            mn[i] = i;
            if (1LL * i * i < max_x) {
                for (int j = i * i; j < max_x; j += i) {
                    if (!mn[j]) {
                        mn[j] = i;
                    }
                }
            }
        }
    }
}

void dfs(int v) {
    used[v] = 1;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
    all_v.push_back(v);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_p();
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        while (a[i] > 1) {
            int x = mn[a[i]];
            while (a[i] % x == 0) {
                a[i] /= x;
            }
            p[i].push_back(x);
            ++cnt[x];
            all[x].push_back(i);
        }
    }
    for (int i = 0; i < max_x; ++i) {
        if (cnt[i] > max_c) {
            for (int pos : all[i]) {
                b[big_p.size()][pos] = 1;
            }
            big_p.push_back(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        cur.reset();
        for (int x : p[i]) {
            if (cnt[x] > max_c) {
                cur |= b[lower_bound(big_p.begin(), big_p.end(), x) - big_p.begin()];
            } else {
                for (int pos : all[x]) {
                    cur[pos] = 1;
                }
            }
        }
        if (0) {
            for (int j = 0; j < n; ++j) {
                cout << cur[j];
            }
            cout << endl;
        }
        if (cur.count() == n) {
            full.push_back(i);
        } else {
            cur.flip();
            for (int pos = cur._Find_first(); pos < n && g[i].size() < 4; pos = cur._Find_next(pos)) {
                g[i].push_back(pos);
                g[pos].push_back(i);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        sort(g[i].begin(), g[i].end());
        g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
        if (g[i].size() == 1 && i < g[i][0]) {
            full.push_back(i);
        }
    }
    if (full.size() >= k) {
        for (int i = 0; i < k; ++i) {
            printf("%d ", full[i] + 1);
        }
        return 0;
    }
    int tot = 0;
    for (int i = 0; i < n; ++i) {
        sort(g[i].begin(), g[i].end());
        g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
        tot += (g[i].size() > 0);
    }
    assert(tot >= k);
    for (int i = 0; i < n; ++i) {
        if (!used[i] && g[i].size()) {
            all_v.clear();
            dfs(i);
            comp.push_back(all_v);
        }
    }
    for (const vector<int> &v : comp) {
        //cout << "#" << v.size() << endl;
        if (v.size() == 2 && k >= 5) {
            for (int pos : v) {
                ans.push_back(pos);
            }
            k -= 2;
        }
    }
    for (const vector<int> &v : comp) {
        if (v.size() != 2) {
            if (k == v.size() || k >= v.size() + 2) {
                for (int pos : v) {
                    ans.push_back(pos);
                }
                k -= v.size();
            } else if (k) {
                int need = k;
                if (need == v.size() + 1) {
                    need = v.size() - 1;
                }
                for (int i = v.size() - need; i < v.size(); ++i) {
                    ans.push_back(v[i]);
                }
                k -= need;
            }
        }
    }
    for (int v : ans) {
        printf("%d ", v + 1);
    }
    puts("");
    return 0;
}