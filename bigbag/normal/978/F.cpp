#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, k, x[max_n], ans[max_n];
pair<int, int> a[max_n];
vector<int> g[max_n];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        a[i] = {x[i], i};
    }
    sort(a, a + n);
    while (k--) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int pos = 0;
    for (int i = 0; i < n; ++i) {
        while (a[pos].first < a[i].first) {
            ++pos;
        }
        int v = a[i].second;
        ans[v] = pos;
        for (int to : g[v]) {
            ans[v] -= (x[v] > x[to]);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}