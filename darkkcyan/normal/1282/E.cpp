#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
// #define rand __rand
// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
// template<class T = int> T rand(T range = numeric_limits<T>::max()) {
    // return (T)(rng() % range);
// }

struct piece {
    int a, b, c;
    int id;
    piece() {}
    piece(int x, int y, int z, int i) : a(x), b(y), c(z), id(i) {}

    vector<int> ver(int rem = -1) const  {
        vector<int> ans;
        if (rem != a) ans.push_back(a);
        if (rem != b) ans.push_back(b);
        if (rem != c) ans.push_back(c);
        return ans;
    }

    int sum_ver() { return a + b + c; }
};

bool operator<(const piece& u, const piece& v) {
    return u.id < v.id;
}

#define maxn 101010
int n;
map<pair<int, int>, vector<piece>> adj;
set<int> p_gr[maxn], ver_gr[maxn];

pair<int, int> ordered(int u, int v) {
    if (u > v) swap(u, v);
    return {u, v};
}

struct cmp_deg {
    bool operator()(int u, int v) const {
        if (len(p_gr[u]) == len(p_gr[v])) return u < v;
        return len(p_gr[u]) < len(p_gr[v]);
    }
};

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        cin >> n;

        adj.clear();

        rep1(i, n - 2) {
            int x, y, z; cin >> x >> y >> z;
            adj[ordered(x, y)].emplace_back(x, y, z, i);
            adj[ordered(y, z)].emplace_back(x, y, z, i);
            adj[ordered(z, x)].emplace_back(x, y, z, i);
        }

        rep1(i, n) {
            p_gr[i].clear();
            ver_gr[i].clear();
        }

        for (auto [edge, pieces]: adj) {
            assert(len(pieces) <= 2);
            if (len(pieces) == 1) {
                ver_gr[edge.xx].insert(edge.yy);
                ver_gr[edge.yy].insert(edge.xx);
            }
            else {
                p_gr[pieces[0].id].insert(pieces[1].id);
                p_gr[pieces[1].id].insert(pieces[0].id);
            }
        }
        
        for (int u = 1; ;) {
            cout << u << ' ';
            int v = *ver_gr[u].begin();
            ver_gr[u].erase(v);
            ver_gr[v].erase(u);
            u = v;
            if (v == 1) break;
        }

        cout << '\n';

        set<int, cmp_deg> prio;
        rep1(i, n - 2) prio.insert(i);
        while (len(prio)) {
            int u = *prio.begin();
            prio.erase(prio.begin());
            cout << u << ' ';
            for (auto v: p_gr[u]) {
                prio.erase(v);
                p_gr[v].erase(u);
                prio.insert(v);
            }
            p_gr[u].clear();
        }
        cout << '\n';
        
    }

    return 0;
}