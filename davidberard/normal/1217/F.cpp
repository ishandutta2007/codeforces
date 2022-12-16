#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int N = 200200;
const int RT = 450;

struct hist {
    int ind, val, ind2, sz;
    hist() {}
    hist(int a, int b, int c, int d) : ind(a), val(b), ind2(c), sz(d) {}
};

struct UF {
    int par[N];
    int sz[N];
    bool frozen = false;
    vector<hist> history;
    UF() {
        memset(par, -1, sizeof par);
        memset(sz, 1, sizeof sz);
    }
    void set_frozen(bool status) {
        frozen = status;
    }
    int FIND(int a) {
        if (par[a] == -1) return a;
        if (frozen) {
            return FIND(par[a]);
        }
        return par[a] = FIND(par[a]);
    }
    void UNION(int a, int b) {
        int fa = FIND(a);
        int fb = FIND(b);
        if (sz[fa] < sz[fb]) {
            swap(fa, fb);
        }
        if (fa != fb) {
            if (frozen) {
                history.emplace_back(fb, par[fb], fa, sz[fa]);
            }
            par[fb] = fa;
            sz[fa] += sz[fb];
        }
    }
    void revert() {
        for (int i=history.size()-1; i>=0; --i) {
            hist &h = history[i];
            sz[h.ind2] = h.sz;
            par[h.ind] = h.val;
        }
        history.clear();
    }
};

struct edge {
    int u, v;
    edge() {}
    edge(int a, int b) {
        u = min(a, b);
        v = max(a, b);
    }
    bool operator== (const edge& o) const {
        return u==o.u && v==o.v;
    }
};

namespace std {
template<>
struct hash<edge>
{
    std::size_t operator()(const edge& k) const {
        return 31*hash<int>()(k.u)+hash<int>()(k.v);
    }
};
}

unordered_set<edge> edges;


unordered_set<edge> potential;
unordered_set<edge> toggle;

struct query {
    int t, x, y;
};
query queries[N];

int n, m;

int inc(int x) {
    return (x == n ? 1 : x+1);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        cin >> queries[i].t >> queries[i].x >> queries[i].y;
    }
    int last = 0;
    for (int i=0; i<m; i+=RT) {
        //cerr <<" !!!! " << i  << endl;
        // Mark potential edges
        potential.clear();
        toggle.clear();
        for (int j=i; j<i+RT && j<m; ++j) {
            if (queries[j].t == 1) {
                potential.insert(edge(queries[j].x, queries[j].y));
                potential.insert(edge(inc(queries[j].x), inc(queries[j].y)));
            }
        }

        // Build union find & adjacency list
        UF uf;
        for (auto& e : edges) {
            if (!potential.count(e)) {
                uf.UNION(e.u, e.v);
                //cerr << "  UNIONED : " << e.u << " " << e.v << endl;
            }
        }
        for (auto& e : potential) {
            if (e.u != e.v && edges.count(e)) {
                //cerr << "  MARKED : " << e.u << " " << e.v << endl;
                toggle.insert(e);
                edges.erase(e);
            }
        }

        for (int j=i; j<i+RT && j<m; ++j) {
            uf.set_frozen(true);
            int uu = (queries[j].x+last-1)%n+1;
            int vv = (queries[j].y+last-1)%n+1;
            if (queries[j].t == 1) {
                uf.revert();
                edge e(uu, vv);
                if (toggle.count(e)) {
                    //cerr << "   T UNMARKED " << e.u << " " << e.v << endl;
                    toggle.erase(e);
                } else {
                    //cerr << "   T   MARKED " << e.u << " " << e.v << endl;
                    toggle.insert(e);
                }
            }
            if (queries[j].t == 2) {
                for (auto& e : toggle) {
                    //cerr << "     PREP WITH " << e.u << " " << e.v << endl;
                    uf.UNION(e.u, e.v);
                }
                last = uf.FIND(uu) == uf.FIND(vv);
                cout << last;
            }
        }

        for (auto& e : toggle) {
            if (edges.count(e)) {
                edges.erase(e);
            } else {
                edges.insert(e);
            }
        }
        
    }
    cout << endl;
    return 0;
}