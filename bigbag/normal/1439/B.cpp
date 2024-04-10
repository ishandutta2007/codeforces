#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef cc_hash_table<int, null_type, hash<int>> ht;

const int max_n = 100111, inf = 1000111222;

int t, n, m, k;
vector<int> g[max_n];
ht hg[max_n];

void clr() {
    for (int i = 0; i < n; ++i) {
        g[i].clear();
        hg[i].clear();
    }
}

int cnt[max_n], del[max_n];
const int max_k = 555;

void proc(int k) {
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        cnt[i] = g[i].size();
        del[i] = 0;
        if (cnt[i] < k) {
            q.push(i);
            del[i] = 1;
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v]) {
            --cnt[to];
            if (!del[to] && cnt[to] < k) {
                del[to] = 1;
                q.push(to);
            }
        }
    }
}

bool edge_exists(int u, int v) {
    return hg[u].find(v) != hg[u].end();
    auto it = lower_bound(g[u].begin(), g[u].end(), v);
    return it != g[u].end() && *it == v;
}

void solve() {
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (!del[i] && cnt[i] == k - 1) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (cnt[v] == k - 1) {
            vector<int> all{v};
            for (int to : g[v]) {
                if (!del[to]) {
                    all.push_back(to);
                }
            }
            if (all.size() == k) {
                sort(all.begin(), all.end());
                bool ok = 1;
                for (int a = 0; a < all.size() && ok; ++a) {
                    for (int b = a + 1; b < all.size() && ok; ++b) {
                        ok &= edge_exists(all[a], all[b]);
                    }
                }
                if (ok) {
                    cout << 2 << "\n";
                    assert(all.size() == k);
                    for (int x : all) {
                        cout << x + 1 << " ";
                    }
                    cout << "\n";
                    return;
                }
            }
        }
        del[v] = 1;
        for (int to : g[v]) {
            if (!del[to]) {
                --cnt[to];
                if (cnt[to] < k - 1) {
                    del[to] = 1;
                }
                if (cnt[to] == k - 1) {
                    q.push(to);
                }
            }
        }

    }
    cout << "-1\n";
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //scanf("%d", &t);
    cin >> t;
    while (t--) {
        //scanf("%d%d%d", &n, &m, &k);
        cin >> n >> m >> k;
        while (m--) {
            int u, v;
            cin >> u >> v;
            //scanf("%d%d", &u, &v);
            --u;
            --v;
            g[u].push_back(v);
            g[v].push_back(u);
            hg[u].insert(v);
            hg[v].insert(u);
        }
        for (int i = 0; i < n; ++i) {
            sort(g[i].begin(), g[i].end());
        }
        proc(k);
        int sz = accumulate(del, del + n, 0);
        if (sz != n) {
            cout << 1 << " " << n - sz << "\n";
            for (int i = 0; i < n; ++i) {
                if (!del[i]) {
                    cout << i + 1 << " ";
                }
            }
            cout << "\n";
        } else {
            proc(k - 1);
            solve();
        }
        clr();
    }
    return 0;
}