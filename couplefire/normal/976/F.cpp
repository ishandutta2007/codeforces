#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

#define sz(a) int((a).size())
#define x first
#define y second

const int INF = int(1e9);
const int N = 4221;

struct edge {
    int to, c, f, id;

    edge(int to = 0, int c = 0, int f = 0, int id = -1) : to(to), c(c), f(f), id(id) {}
};

vector<edge> es;
vector<int> g[N];

void add_edge(int fr, int to, int cap, int id) {
    g[fr].push_back(sz(es));
    es.emplace_back(to, cap, 0, id);
    g[to].push_back(sz(es));
    es.emplace_back(fr, 0, 0, id);
}

int pw[N];
int n1, n2, m;

inline bool read() {
    if(!(cin >> n1 >> n2 >> m))
        return false;

    fore(id, 0, m) {
        int u, v;
        assert(cin >> u >> v);
        u--, v--;

        pw[u]++;
        pw[n1 + v]++;

        add_edge(u, n1 + v, 1, id);
    }
    return true;
}

int d[N], q[N], hd, tl;
inline bool bfs(int s, int t, int n) {
    fore(i, 0, n)
        d[i] = INF;
    hd = tl = 0;

    d[s] = 0;
    q[tl++] = s;
    while(hd != tl) {
        int v = q[hd++];
        if(v == t)
            break;

        for(int id : g[v]) {
            if(es[id].c - es[id].f == 0)
                continue;

            int to = es[id].to;
            if(d[to] > d[v] + 1) {
                d[to] = d[v] + 1;
                q[tl++] = to;
            }
        }
    }
    return d[t] < INF;
}

int nxt[N];

int dfs(int v, int t, int mx) {
    if(v == t) return mx;
    if(mx == 0) return 0;

    int sum = 0;
    for(; nxt[v] < sz(g[v]); nxt[v]++) {
        int id = g[v][nxt[v]];
        int rem = es[id].c - es[id].f;
        int to = es[id].to;

        if(rem == 0 || d[to] != d[v] + 1)
            continue;

        int cur = 0;
        if((cur = dfs(to, t, min(mx - sum, rem))) > 0) {
            es[id].f += cur;
            es[id ^ 1].f -= cur;
            sum += cur;
        }

        if(sum == mx)
            break;
    }
    return sum;
}

inline int dinic(int s, int t, int n) {
    int mf = 0;
    while(bfs(s, t, n)) {
        fore(i, 0, n)
            nxt[i] = 0;

        int cf = 0;
        while((cf = dfs(s, t, INF)) > 0)
            mf += cf;
    }
    return mf;
}

vector<int> res[N];

inline void getCert(int k) {
    fore(v, 0, n1) {
        for(int id : g[v]) {
            if(es[id].to < n1 || es[id].to >= n1 + n2)
                continue;
            assert(es[id].c > 0);
            if(es[id].f > 0)
                continue;

            res[k].push_back(es[id].id);
        }
    }
}

void solve() {
    int cnt = *min_element(pw, pw + n1 + n2);

    int s = n1 + n2; int t = s + 1;
    fore(i, 0, n1)
        add_edge(s, i, pw[i] - cnt, -1);
    fore(i, n1, n1 + n2)
        add_edge(i, t, pw[i] - cnt, -1);

    int mf = 0, mn = cnt;
    while(mn >= 0) {
        mf += dinic(s, t, n1 + n2 + 2);
        getCert(mn);

        if(mn > 0) {
            for (int id : g[s]) {
                assert(es[id].id < 0);
                assert((id & 1) == 0);
                es[id].c++;
            }
            for (int id : g[t]) {
                assert(es[id].id < 0);
                assert(es[id].c == 0);
                es[id ^ 1].c++;
            }
        }
        mn--;
    }

    fore(i, 0, cnt + 1) {
        printf("%d ", sz(res[i]));
        for(int id : res[i])
            printf("%d ", id + 1);
        puts("");
    }
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif

    if(read()) {
        solve();
    }
    return 0;
}