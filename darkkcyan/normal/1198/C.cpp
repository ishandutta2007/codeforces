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

#define maxn 501010
int n, m;
vector<int> gr[maxn];
map<pair<int, int>, int> edges;
set<int> left_nodes;

template<class T>
pair<T, T> ordered(pair<T, T> x) {
    if (x.xx > x.yy) swap(x.xx, x.yy);
    return x;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    rep1(testcase, ntest) {
        cin >> n >> m;
        rep1(i, 3 * n) gr[i].clear();
        edges.clear();

        rep1(i, m) {
            int u, v; cin >> u >> v;
            gr[u].push_back(v);
            gr[v].push_back(u);
            edges[ordered(make_pair(u, v))] = i;
        }

        left_nodes.clear();
        rep1(i, 3 * n) left_nodes.insert(i);

        vector<int> picked_edges;

        while (len(edges)) {
            picked_edges.push_back(edges.begin()->yy);
            auto cur_edge = edges.begin()->xx;
            edges.erase(edges.begin());
            for (auto u: {cur_edge.xx, cur_edge.yy}) {
                for (auto v: gr[u]) {
                    edges.erase(ordered(make_pair(u, v)));
                }
                left_nodes.erase(u);
            }
        }

        // clog << len(left_nodes) << ' ' << len(picked_edges) << endl;
        if (len(left_nodes) >= n) {
            cout << "IndSet\n";
            for (auto i: left_nodes) {
                cout << i << ' ';
                if (--n == 0) break;
            }
        } else {
            cout << "Matching\n";
            for (auto i: picked_edges) {
                cout << i << ' ';
                if (--n == 0) break;
            }
        }
        cout << '\n';
    }

    return 0;
}