#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

struct state {
    int v, pos, cnt;

    state(int v, int pos, int cnt): v(v), pos(pos), cnt(cnt) {
    }
};

int n, sz[max_n];
long long k;
vector<int> g[max_n], a[max_n];
vector<state> all;

void dfs(int v, int p) {
    sz[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] == p) {
            swap(g[v][i], g[v].back());
            g[v].pop_back();
            --i;
            continue;
        }
        dfs(g[v][i], v);
        sz[v] += sz[g[v][i]];
    }
    for (int i = 0; i < g[v].size(); ++i) {
        all.push_back({v, i, min(sz[g[v][i]], n - sz[g[v][i]])});
    }
}

long long get_sum(int x) {
    long long res = 0;
    for (const state &s : all) {
        int y = s.cnt;
        if (y > x) {
            if (y % 2 == x % 2) {
                y = x;
            } else {
                y = x - 1;
            }
        }
        res += y;
    }
    return res;
}

void proc(int x) {
    int mx = 0;
    for (state &s : all) {
        if (s.cnt > x) {
            if (s.cnt % 2 == x % 2) {
                s.cnt = x;
            } else {
                s.cnt = x - 1;
            }
        }
        k -= s.cnt;
        mx = max(mx, s.cnt);
    }
    for (state &s : all) {
        if (s.cnt == mx && k < 0) {
            s.cnt -= 2;
            k += 2;
        }
    }
}

vector<int> ids[max_n];

int get(int id) {
    int res = ids[id].back();
    ids[id].pop_back();
    return res;
}

void solve(int v, int need) {
    int tot = 0;
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < g[v].size(); ++i) {
        //cout << v << " -> " << g[v][i] << ", a = " << a[v][i] << endl;
        solve(g[v][i], a[v][i]);
        assert(ids[g[v][i]].size() == a[v][i]);
        tot += a[v][i];
        q.push({a[v][i], g[v][i]});
    }
    ids[v].push_back(v);
    q.push({1, v});
    while (tot > need) {
        tot -= 2;
        pair<int, int> p1 = q.top();
        q.pop();
        pair<int, int> p2 = q.top();
        q.pop();
        printf("%d %d\n", get(p1.second) + 1, get(p2.second) + 1);
        --p1.first;
        --p2.first;
        if (p1.first) {
            q.push(p1);
        }
        if (p2.first) {
            q.push(p2);
        }
    }
    for (int to : g[v]) {
        if (ids[to].size() > ids[v].size()) {
            ids[v].swap(ids[to]);
        }
        for (int id : ids[to]) {
            ids[v].push_back(id);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%I64d", &n, &k);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1);
    long long tot_mx = 0, tot_mn = 0;
    for (const auto &s : all) {
        tot_mx += s.cnt;
        tot_mn += s.cnt % 2;
    }
    if (k < tot_mn || k > tot_mx || k % 2 != tot_mn % 2) {
        puts("NO");
        return 0;
    }
    puts("YES");
    int l = 0, r = n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (get_sum(mid) < k) {
            l = mid;
        } else {
            r = mid;
        }
    }
    proc(r);
    for (int i = 0; i < n; ++i) {
        a[i].resize(g[i].size());
    }
    for (const state &s : all) {
        a[s.v][s.pos] = s.cnt;
    }
    solve(0, 0);
    return 0;
}