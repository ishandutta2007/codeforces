#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define sz(a) (int)a.size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define y1 y228
#define y2 y229
#define rank rank228
#define left left228
#define right right228
using ll = long long;
using ld = long double;

using namespace std;

template<class T1, class T2> int chkmax(T1 &a, const T2 &b) {
    if (b > a) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T1, class T2> int chkmin(T1 &a, const T2 &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream &out = cerr) {
    while (begin != end) {
        out << (*begin) << " ";
        begin++;
    }
    out << endl;
}

template<class T> void output(const T &x, ostream &out = cerr) {
    output(x.begin(), x.end(), out);
}

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector<vector<int> > g, children;
vector<int> deg, cmp, p;
int n, m, cmp_cnt;

void yes(vector<int> v) {
    cout << "Yes\n";
    cout << v.size() << "\n";
    for (auto x : v) {
        cout << x + 1 << " ";
    }
    cout << "\n";
}

void no() {
    cout << "No\n";
}

void antiyes(vector<int> v) {
    vector<int> needed_remove(n, 1);
    for (auto x : v) {
        needed_remove[x] = 0;
    }
    vector<int> to_remove;
    for (int i = 0; i < n; ++i) {
        if (needed_remove[i]) {
            to_remove.push_back(i);
        }
    }
    yes(to_remove);
}

int timer, big_cycle;
vector<int> tin, h;
pair<int, int> cycle;

int tree_search(int v, int pv) {
    if (v != pv) {
        h[v] = h[pv] + 1;
    }
    tin[v] = timer++;
    cmp[v] = cmp_cnt;
    p[v] = pv;
    for (auto v1 : g[v]) {
        //cerr << v << " -> " << v1 << " " << pv << endl;
        if (deg[v1] != 2) continue;
        if (v1 == pv) continue;
        //cerr << "not skip " << pv << endl;
        if (cmp[v1] == -1 && tree_search(v1, v)) {
            return 1;
        } else {
            if (tin[v1] < tin[v]) {
                chkmin(cycle, make_pair(h[v] - h[v1], v));
            }
        }
    }
    return 0;
}

const int INF = 1e9;
vector<int> used;

void hang_trees(int v, int pv) {
    used[v] = 1;
    p[v] = pv;
    //cout << pv << ' ' << v << endl;
    children[pv].push_back(v);
    for (auto v1 : g[v]) {
        if (v1 != pv && !used[v1]) {
            hang_trees(v1, v);
        }
    }
}

void one_path(int one) {
    vector<int> par(n, -1), d(n, INF);
    queue<int> q;
    q.push(one);
    d[one] = 0;
    int t = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v != one && deg[v] == 1) {
            t = v;
            break;
        }
        for (auto v1 : g[v]) {
            if (d[v1] == INF) {
                q.push(v1);
                d[v1] = d[v] + 1;
                par[v1] = v;
            }
        }
    }
    assert(t != -1);
    if (d[t] == n - 1) {
        no();
    }
    else {
        vector<int> path;
        while (true) {
            path.push_back(t);
            if (t == one) {
                break;
            }
            t = par[t];
        }
        antiyes(path);
    }
}

const int mx = 5e5 + 228;
bool dp[mx][2][3][3][2];
bool prefdp[mx][2][3][3][2];
vector<int> gp[mx][2][3][3][2];


void fill_dp() {
    for (int i = 0; i < n; ++i) {
        for (int c1 = 0; c1 < 2; ++c1) {
            for (int c2 = 0; c2 < 3; ++c2) {
                for (int c3 = 0; c3 < 3; ++c3) {
                    for (int f = 0; f < 2; f++) {
                        dp[i][c1][c2][c3][f] = 0;
                        prefdp[i][c1][c2][c3][f] = 0;
                        gp[i][c1][c2][c3][f].clear();
                    }
                }
            }
        }
    }
}

vector<int> conn1;

int root;

void calc_dp(int v) {
    for (auto v1 : children[v]) {
        calc_dp(v1);
    }
    for (int t = 0; t < 2; t++) {
        dp[v][t][0][(conn1[v] ? 1 - t: 0)][(t == 0 ? 1: 0)] = true;
        for (auto h: children[v]) {
            for (int t1 = 0; t1 < 2; t1++) {
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        for (int k = 0; k < 2; k++) {
                            if (dp[h][t1][i][j][k]) {
                                if (t1 == 1 && (i + 1 - t) % 3 != 0) {
                                    continue;
                                }
                                for (int g = 0; g < 3; g++) {
                                    for (int g1 = 0; g1 < 3; g1++) {
                                        for (int k1 = 0; k1 < 2; k1++) {
                                            if (dp[v][t][g][g1][k1]) {
                                                int ng = (g + 1 - t1) % 3;
                                                int ng1 = (g1 + j) % 3;
                                                prefdp[h][t][ng][ng1][k | k1] = true;
                                                gp[h][t][ng][ng1][k | k1] = {g, g1, k1, t1, i, j, k};
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            for (int g = 0; g < 3; g++) {
                for (int g1 = 0; g1 < 3; g1++) {
                    for (int k = 0; k < 2; k++) {
                        dp[v][t][g][g1][k] = prefdp[h][t][g][g1][k];
                    }
                }
            }
        }
    }
}


vector<int> st;

void restore_dp(int v, int t, int i, int j, int t2) {
    if (t == 0) {
        //cout << v + 1 << endl;
        st.pb(v);
    }
    if (children[v].empty()) {
        return;
    }
    reverse(all(children[v]));
    for (auto x: children[v]) {
        auto k = gp[x][t][i][j][t2];
        i = k[0];
        j = k[1];
        t2 = k[2];
        restore_dp(x, k[3], k[4], k[5], k[6]);
    }
}

void solve() {
    cin >> n >> m;
    g.resize(n);
    children.resize(n);
    tin.assign(n, -1);
    h.assign(n, 0);
    timer = 0;
    big_cycle = 0;
    for (int i = 0; i < n; ++i) {
        g[i].clear();
        children[i].clear();
    }
    deg.assign(n, 0);
    cmp.assign(n, -1);
    p.assign(n, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u] = (deg[u] + 1) % 3;
        deg[v] = (deg[v] + 1) % 3;
    }

    //cerr << "deg" << endl;
    //output(all(deg));

    if (n == 1) {
        no();
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (deg[i] == 0) {
            vector<int> v;
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    v.push_back(j);
                }
            }
            yes(v);
            return;
        }
    }

    cycle = {n, -1};

    cmp_cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 2 && cmp[i] == -1) {
            tree_search(i, i);
            cmp_cnt++;
        }
    }
    
    if (cycle.first == n - 1) {
    	no();
    	return;
    }

    if (cycle.first < n - 1) {
    	vector<int> path;
    	int v = cycle.second;
    	path.push_back(v);
    	for (int i = 0; i < cycle.first; ++i) {
    		v = p[v];
    		path.push_back(v);
    	}
    	antiyes(path);
    	return;
    }

    vector<int> ones;
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 1) {
            ones.push_back(i);
        }
    }

    assert(!ones.empty());

    if (ones.size() > 1) {
        one_path(ones[0]);
        return;
    }

    root = ones[0];

    conn1.assign(n, 0);
    used.assign(n, 0);
    used[root] = 1;
    for (auto v : g[root]) {
        conn1[v] = 1;
        if (used[v] == 0) {
            hang_trees(v, root);
        }
    }
    fill_dp();

    calc_dp(root);
    for (int t1 = 0; t1 < 3; t1++) {
        if (dp[root][1][t1][0][1]) {
            st.clear();
            restore_dp(root, 1, t1, 0, 1);
            yes(st);
            return;
        }
    }
    no();
}

int main() {
    fast_io();

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }
}