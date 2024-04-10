#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111, inf = 111111111;

int n, m, a[max_n], b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        ans += w;
        a[u] += w;
        b[v] += w;
    }
    for (int i = 1; i <= n; ++i) {
        //cout << b[i] << ' ' << a[i] << endl;
        ans -= min(a[i], b[i]);
    }
    cout << ans << endl;
    return 0;
}