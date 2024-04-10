#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

vector<vector<int>> G;
int dis[505][505];

void add_edge(int u, int v) {
    G[u].pb(v);
    G[v].pb(u);
}

int query(int x) {
    cout << x + 1 << endl;
    string rt;
    cin >> rt;
    if (rt == "FOUND") return -1;
    cin >> x, --x;
    return x;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    G.resize(n);
    while (m--) {
        int k, lst = -1;
        cin >> k;
        while (k--) {
            int x;
            cin >> x, --x;
            if (lst != -1) add_edge(lst, x);
            lst = x;
        }
    }
    for (int i = 0; i < n; ++i) {
        queue<int> q;
        fill(dis[i], dis[i] + n, -1);
        q.push(i), dis[i][i] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int j : G[u])
                if (!~dis[i][j])
                    dis[i][j] = dis[i][u] + 1, q.push(j);
        }
    }

    auto psb = [&](vector<int> &nw, int s, int t) {
        vector<int> rt;
        for (int j : nw)
            if (dis[t][j] < dis[s][j])
                rt.pb(j);
        return rt;
    };

    for (int ct = 0; ct < n; ++ct) {
        int stamp = 0;
        vector<int> nw(n), live(n);
        vector<vector<int>> curG(G);
        iota(ALL(nw), 0);
        while (true) {
            vector<int> val(SZ(nw));
            for (int i = 0; i < SZ(nw); ++i)
                for (int j : curG[nw[i]])
                    val[i] = max(val[i], SZ(psb(nw, nw[i], j)));
            int mi = nw[min_element(ALL(val)) - val.begin()];
            int res = query(mi);
            if (res == -1) break;
            psb(nw, mi, res).swap(nw);
            ++stamp;
            for (int i : nw) live[i] = stamp;
            for (int i : nw) {
                vector<int> new_edge;
                for (int j : curG[i])
                    if (live[j] == stamp)
                        new_edge.pb(j);
                new_edge.swap(curG[i]);
            }
        }
    }
}