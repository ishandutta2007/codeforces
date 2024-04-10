#include <bits/stdc++.h>
#define int long long

using namespace std;

#define TASKNAME ""

struct DSU {
    int n;
    vector <int> p, r;
    vector <int> lt, rt;
    DSU(int n) : n(n), p(n), r(n), lt(n), rt(n) {
        iota(p.begin(), p.end(), 0);
        iota(lt.begin(), lt.end(), 0);
        iota(rt.begin(), rt.end(), 0);
    }
    int get(int v) {
        if (p[v] == v) return v;
        return p[v] = get(p[v]);
    }
    bool uni(int v, int u) {
        v = get(v);
        u = get(u);
        if (v == u) return false;
        if (r[v] == r[u]) r[u]++;
        if (r[v] > r[u]) swap(v, u);
        p[v] = u;
        if (rt[v] == lt[u] - 1) {
            lt[u] = lt[v];
        } else if (rt[u] == lt[v] - 1) {
            rt[u] = rt[v];
        }
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    DSU dsu(n), nxt(n);
    for (int i = 0; i < q; i++) {
        int tp, v, u;
        cin >> tp >> v >> u;
        tp--, v--, u--;
        if (!tp) {
            dsu.uni(v, u);
        } else if (tp == 1) {
            int last = v;
            int now = nxt.rt[nxt.get(v)] + 1;
            while (now <= u) {
                nxt.uni(now, last);
                dsu.uni(now, last);
                last = now;
                now = nxt.rt[nxt.get(now)] + 1;
            }
        } else if (tp == 2) {
            if (dsu.get(v) == dsu.get(u)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}