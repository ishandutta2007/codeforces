#include <cstdio>

#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

#ifdef ONLINE_JUDGE
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;


int q, n, ans = 0;
vector<vector<int> > g;
int us[100], d[100];

int calc(int v) {
    us[v] = 1;
    int cans = 0;
    for (int i = 0; i < g[v].size(); ++i) {
        int u = g[v][i];
        if (!us[u]) {
            cans = max(cans, calc(u));
            d[v] = max(d[v], d[u] + 1);
        }
    }
    cans = max(cans, d[v]);
    for (int i = 0; i < g[v].size(); ++i)
        for (int j = i + 1; j < g[v].size(); ++j) {
            int v1 = g[v][i];
            int v2 = g[v][j];
            cans = max(cans, d[v1] + d[v2] + 2);
        }
    return cans;
}

int main() {
    for (cin >> q; q; --q) {
        cin >> n;
        g.clear();
        g.resize(n);
        for (int i = 0; i < n - 1; ++i) {
            int v1, v2;
            cin >> v1 >> v2;
            --v1; --v2;
            g[v1].push_back(v2);
            g[v2].push_back(v1);
        }
        for (int i = 0; i < n; ++i) {
            us[i] = 0;
            d[i] = 0;
        }
        ans += calc(0);
    }
    cout << ans << endl;
    return 0;
}