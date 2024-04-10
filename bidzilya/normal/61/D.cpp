#include <cstdio>
#include <cstring>

#include <iostream>
#include <fstream>
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

const int max_n = 1e5 + 100;

int n;
vector<vector<int> > gv, gw;
ll ans_ret[max_n], ans_nret[max_n];

void calc(int v, int pr) {
    for (int i = 0; i < (int) gv[v].size(); ++i) {
        int u = gv[v][i];
        if (u != pr) {
            calc(u, v);
            ans_ret[v] += ans_ret[u];
            ans_ret[v] += 2 * gw[v][i];
        }
    }
    ans_nret[v] = ans_ret[v];
    for (int i = 0; i < (int) gv[v].size(); ++i) {
        int u = gv[v][i];
        if (u != pr) {
            ans_nret[v] = min(ans_nret[v], ans_ret[v] - gw[v][i] - ans_ret[u] + ans_nret[u]);
        }
    }
}

int main() {
    cin >> n;
    gv.resize(n);
    gw.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        --v1; --v2;
        gv[v1].push_back(v2);
        gv[v2].push_back(v1);
        gw[v1].push_back(w);
        gw[v2].push_back(w);
    }
    calc(0, 0);
    cout << ans_nret[0] << endl;
    return 0;
}