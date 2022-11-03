#include <cstdio>
#include <cstring>
#include <cmath>

#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int max_int = (1LL << 31) - 1;

//#define LOCAL

#ifdef LOCAL
#include <fstream>
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

const int max_n = 2e2 + 10;

vector<vector<int> > g;
int ans = 0;
int lpath[max_n], depth[max_n];
int us[max_n];
int n;

void go1(int v1, int pr, int v2) {
    if (v1 == v2) {
        us[v2] = 1;
    } else {
        for (int i = 0; i < (int) g[v1].size(); ++i) {
            int u = g[v1][i];
            if (u == pr) continue;
            go1(u, v1, v2);
            if (us[u]) {
                us[v1] = 1;
            }
        }
    }
}

void go2(int v) {
    us[v] = 1;
    int m1 = 0, m2 = 0;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];
        if (us[u]) continue;
        go2(u);
        depth[v] = max(depth[v], depth[u] + 1);
        lpath[v] = max(lpath[v], lpath[u]);
        if (depth[u] + 1 >= m1) {
            m2 = m1;
            m1 = depth[u] + 1;
        } else if (depth[u] + 1 > m2) {
            m2 = depth[u] + 1;
        }
    }
    lpath[v] = max(lpath[v], depth[v]);
    if (m1 != 0 && m2 != 0)
        lpath[v] = max(lpath[v], m1 + m2);
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1; --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            for (int k = 0; k < n; ++k)
                us[k] = lpath[k] = depth[k] = 0;
            go1(i, i, j);
            int l1 = 0;
            for (int k = 0; k < n; ++k)
                l1 += us[k];
            --l1;
            for (int k = 0; k < n; ++k)
                if (!us[k]) {
                    go2(k);
                    ans = max(ans, l1 * lpath[k]);
                }
        }
    cout << ans << endl;
    return 0;
}