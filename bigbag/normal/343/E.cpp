#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 211, inf = 1000111222;

struct Dinic {
    struct edge {
        int to, cap, flow;
    };
    vector<edge> e;
    vector<int> v[max_n];
    int d[max_n];
    int st[max_n];

    void add_edge_undir(int from, int to, int cap, int flow = 0) {
        v[from].PB(e.size());
        e.push_back(edge{to, cap, flow});
        v[to].PB(e.size());
        e.push_back(edge{from, cap, -flow});
    }

    bool bfs(int s, int t) {
        for (int i = 0; i < max_n; ++i) {
            d[i] = -1;
        }
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < v[cur].size(); ++i) {
                edge& ed = e[v[cur][i]];
                if (d[ed.to] == -1 && ed.cap > ed.flow) {
                    d[ed.to] = d[cur] + 1;
                    q.push(ed.to);
                }
            }
        }
        return d[t] != -1;
    }

    int dfs(int cur, int t, int flow) {
        if (cur == t) {
            return flow;
        }
        for (int& i = st[cur]; i < v[cur].size(); ++i) {
            edge& ed = e[v[cur][i]];
            if (ed.cap == ed.flow || d[ed.to] != d[cur] + 1) {
                continue;
            }
            int res = dfs(ed.to, t, min(flow, ed.cap - ed.flow));
            if (res > 0) {
                ed.flow += res;
                e[v[cur][i] ^ 1].flow = -ed.flow;
                return res;
            }
        }
        return 0;
    }

    int max_flow(int s, int t) {
        int ans = 0;
        while (bfs(s, t)) {
            memset(st, 0, sizeof(st));
            while (int res = dfs(s, t, inf)) {
                ans += res;
            }
        }
        return ans;
    }

    void clr() {
        for (int i = 0; i < e.size(); ++i) {
            e[i].flow = 0;
        }
    }
};

struct HomoryHu {
    Dinic dinic;
    int f[max_n][max_n];
    vector<pair<int, int>> v[max_n];
    int pr[max_n];

    int calc(int n) {
        int sum = 0;
        for (int i = 1; i < n; ++i) {
            pr[i] = 0;
        }
        for (int i = 1; i < n; ++i) {
            dinic.clr();
            int fl = dinic.max_flow(i, pr[i]);
            sum += fl;
            v[pr[i]].push_back(MP(i, fl));
            v[i].push_back(MP(pr[i], fl));
            //cout << "$ " << i << ' ' << pr[i] << endl;
            for (int j = i + 1; j < n; ++j) {
                if (pr[j] == pr[i] && dinic.d[j] != -1) {
                    pr[j] = i;
                }
            }
        }
        return sum;
    }

    int min_e = inf, mi, mj;
    set<pair<int, int>> del;

    void dfs(int cur, int pr) {
        for (int i = 0; i < v[cur].size(); ++i) {
            int to = v[cur][i].F, w = v[cur][i].S;
            if (to == pr || del.find(MP(cur, to)) != del.end()) {
                continue;
            }
            if (w < min_e) {
                min_e = w;
                mi = cur, mj = to;
            }
            dfs(to, cur);
        }
    }

    void solve(int st) {
        min_e = inf;
        dfs(st, -1);
        if (min_e == inf) {
            cout << st + 1 << ' ';
            return;
        }
        del.insert(MP(mi, mj));
        del.insert(MP(mj, mi));
        int a = mi, b = mj;
        solve(a);
        solve(b);
    }
};

int main() {
    //freopen("input.txt", "r", stdin);
    HomoryHu homory;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        homory.dinic.add_edge_undir(a, b, c);
    }
    int sum = homory.calc(n);
    cout << sum << endl;
    homory.solve(0);
    return 0;
}