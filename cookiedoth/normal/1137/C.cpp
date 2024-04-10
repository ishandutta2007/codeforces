#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <string>
#include <cstring>
#include <functional>
#include <numeric>
#include <random>
#include <cassert>
#include <cmath>
#include <ctime>
#include <queue>
#include <deque>

#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

template<class iterator> void output(iterator begin, iterator end, ostream &out = cerr) {
    while (begin != end) {
        out << (*begin) << " ";
        begin++;
    }
    out << endl;
}

template<class T> void output(T &x, ostream& out = cerr) {
    output(x.begin(), x.end(), out);
}

template<class T> int chkmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T> int chkmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return 1;
    }
    return 0;
}

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const int mx = 1e5 + 228;
const int D = 50;
const int MX = mx * D;
int n, m, d;
char opened[mx][D], used1[mx][D];
int c1[mx][D], value[MX], cmp_cnt, dp[MX];
vector<int> g[mx], rev_g[mx];
vector<int> g1[MX];
vector<int> topsort1;

void build_topsort1(int v) {
    used1[v / d][v % d] = 1;
    for (auto v1 : g[v / d]) {
        if (used1[v1][(v % d + 1) % d] == 0) {
            build_topsort1(v1 * d + (v % d + 1) % d);
        }
    }
    topsort1.push_back(v);
}

void cmp_dfs1(int v, int cur_d) {
    c1[v][cur_d] = cmp_cnt;
    for (auto v1 : rev_g[v]) {
        if (c1[v1][(cur_d - 1 + d) % d] == -1) {
            cmp_dfs1(v1, (cur_d - 1 + d) % d);
        }
    }
}

void build_cmp1() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            c1[i][j] = -1;
        }
    }

    topsort1.reserve(MX);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            if (used1[i][j] == 0) {
                build_topsort1(i * d + j);
            }
        }
    }
    /*cerr << "topsort" << endl;
    for (auto pp : topsort1) {
        cerr << pp.first << " " << pp.second << endl;
    }*/
    reverse(all(topsort1));
    for (auto pp : topsort1) {
        if (c1[pp / d][pp % d] == -1) {
            cmp_dfs1(pp / d, pp % d);
            cmp_cnt++;
            //assert(cmp_cnt <= 1e7);
        }
    }

    topsort1.clear();
    topsort1.shrink_to_fit();

    for (int i = 0; i < n; ++i) {
        for (auto v : g[i]) {
            for (int j = 0; j < d; ++j) {
                int cmp1 = c1[i][j];
                int cmp2 = c1[v][(j + 1) % d];
                if (cmp1 != cmp2) {
                    dp[cmp1]++;
                }
            }
        }
    }
    for (int i = 0; i < cmp_cnt; ++i) {
        g1[i].reserve(dp[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (auto v : g[i]) {
            for (int j = 0; j < d; ++j) {
                int cmp1 = c1[i][j];
                int cmp2 = c1[v][(j + 1) % d];
                if (cmp1 != cmp2) {
                    g1[cmp1].push_back(cmp2);
                }
            }
        }
    }
}

void dp_dfs(int v) {
    for (auto v1 : g1[v]) {
        if (dp[v1] == -1) {
            dp_dfs(v1);
        }
        chkmax(dp[v], dp[v1]);
    }
    if (dp[v] == -1) {
        dp[v] = value[v];
    }
    else {
        dp[v] += value[v];
    }
}

int main() {
    fast_io();
    cin >> n >> m >> d;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        //cerr << "uv " << u << " " << v << endl;
        g[u].push_back(v);
        rev_g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            char c;
            cin >> c;
            opened[i][j] = c - '0';
        }
    }
    build_cmp1();
    /*cerr << "c1" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            cerr << c1[i][j] << " ";
        }
        cerr << endl;
    }*/

    for (int i = 0; i < cmp_cnt; ++i) {
        dp[i] = -1;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            if (opened[i][j] && dp[c1[i][j]] != i) {
                value[c1[i][j]]++;
                dp[c1[i][j]] = i;
            }
        }
    }

    for (int i = 0; i < cmp_cnt; ++i) {
        dp[i] = -1;
    }

    int c0 = c1[0][0];
    dp_dfs(c0);
    cout << dp[c0] << endl;
}