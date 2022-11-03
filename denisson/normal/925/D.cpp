#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

using lint = long long;
template <typename A, typename B> auto min(A a, B b) { return a < b ? a : b; };
template <typename A, typename B> auto max(A a, B b) { return a < b ? b : a; };
template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

#define STRESS 0

vector<int> g[333333];
int d[333333];
int p[333333];
int lp[333333];
int ld[333333];

int deg[333333];

bool used[333333];
vector<int> vs;

void dfs(int v) {
    used[v] = true;
    vs.push_back(v);
    for (int i : g[v]) {
        if (!used[i]) {
            dfs(i);
        }
    }
}

void solve(istream& cin, ostream& cout) {
    int n, m;
    cin >> n >> m;
    rep(i, 0, m) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        if (x > y) {
            swap(x, y);
        }

        g[x].push_back(y);
        g[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }

    queue<int> q;
    q.push(0);
    rep(i, 0, 333333) {
        d[i] = 1e9;
    }
    memset(p, -1, sizeof(p));
    d[0] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i : g[v]) {
            if (d[i] > d[v] + 1) {
                d[i] = d[v] + 1;
                q.push(i);
                p[i] = v;
            }
        }
    }

    int ans1 = d[n - 1];
    int t = -1;
    rep(i, 0, n - 1) {
        if (d[i] == 2) {
            t = i;
            break;
        }
    }
    int o1, o2, o3;
    o1 = o2 = o3 = -1;
    int ans2 = 1e9;
    if (t != -1) {
        ans2 = 4;
    } else {
        used[0] = 1;
        used[n - 1] = 1;
        int z = -1;
        rep(i, 0, n) {
            if (d[i] != 1) {
                continue;
            }
            if (!used[i]) {
                vs.clear();
                dfs(i);
                int x = vs.size();
                for (int v : vs) {
                    if (deg[v] < x) {
                        z = v;
                        break;
                    }
                }
                if (z != -1) {
                    break;
                }
            }
        }
        if (z != -1) {
            memset(lp, -1, sizeof(lp));
            rep(i, 0, 333333) {
                ld[i] = 1e9;
            }
            assert(z != 0);
            ld[0] = 0;
            ld[z] = 0;
            ld[n - 1] = 0;
            q.push(z);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int i : g[v]) {
                    if (ld[i] > ld[v] + 1) {
                        ld[i] = ld[v] + 1;
                        q.push(i);
                        lp[i] = v;
                    }
                }
            }

            int lt = -1;
            rep(i, 0, n) {
                if (ld[i] == 2) {
                    lt = i;
                    break;
                }
            }
            if (lt != -1) {
                o3 = lt;
                o2 = lp[lt];
                o1 = lp[o2];
                assert(o1 == z);
            }
        }
    }

    int ans3 = 1e9;
    if (o1 != -1) {
        ans3 = 5;
    }

    if (ans1 != 1e9 && ans1 <= ans2 && ans1 <= ans3) {
        vector<int> tp;
        int x = n - 1;
        while (x != -1) {
            tp.push_back(x);
            x = p[x];
        }
        cout << tp.size() - 1 << "\n";
        reverse(tp.begin(), tp.end());
        for (int i : tp) {
            cout << i + 1 << " ";
        }
        return;
    }

    if (ans2 != 1e9 && ans2 <= ans3) {
        vector<int> tp;
        tp.push_back(n - 1);
        tp.push_back(0);
        int x = t;
        while (x != -1) {
            tp.push_back(x);
            x = p[x];
        }
        assert(tp.size() == 5);
        cout << tp.size() - 1 << "\n";
        reverse(tp.begin(), tp.end());
        for (int i : tp) {
            cout << i + 1 << " ";
        }
        return;
    }

    if (ans3 != 1e9) {
        vector<int> tp = {0, o1, o2, o3, o1, n - 1};
        cout << tp.size() - 1 << "\n";
        for (int i : tp) {
            cout << i + 1 << " ";
        }
        return;
    }

    cout << -1;
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
    for (int ti = 0; ti < 100; ti++) {
        stress::gen();
        stress::stupid();
        ifstream in("input.txt");
        ofstream out("output.txt");
        solve(in, out);
        out.flush();
        stress::check();
    }
    cout << "ok" << endl;
#endif
    return 0;
}