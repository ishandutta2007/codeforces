#include <bits/stdc++.h>
using namespace std;

bool DoKuhn(int v, vector<int>& mt, vector<bool>& used,
            const vector<vector<int> >& g)
{
    if (used[v]) {
        return false;
    }
    used[v] = true;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];
        if (mt[u] == -1 || DoKuhn(mt[u], mt, used, g)) {
            mt[u] = v;
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    vector<vector<int> > g(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (abs(a[i] - b[j]) <= 1) {
                g[i].push_back(j);
            }
        }
    }

    vector<int> mt(m, -1);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        vector<bool> used(n, false);
        if (DoKuhn(i, mt, used, g)) {
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}