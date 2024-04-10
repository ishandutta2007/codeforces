#include <bits/stdc++.h>
using namespace std;

bool DoKunh(int v, const vector<vector<int> >& g,
                    vector<bool>& used,
                    vector<int>& mt)
{
    if (used[v]) {
        return false;
    }
    used[v] = true;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];
        if (mt[u] == -1 || DoKunh(mt[u], g, used, mt)) {
            mt[u] = v;
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<int> > b(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        for (int j = 2; j * j <= a; ++j) {
            while (a % j == 0) {
                b[i].push_back(j);
                a /= j;
            }
        }
        if (a > 1) {
            b[i].push_back(a);
        }
    }
    vector<vector<int> > c(n);
    int n1 = 0;
    int n2 = 0;
    for (int i = 0; i < n; ++i) {
        c[i].resize(b[i].size());
        if ((i & 1) == 1) {
            for (int j = 0; j < (int) b[i].size(); ++j) {
                c[i][j] = n2;
                ++n2;
            }
        } else {
            for (int j = 0; j < (int) b[i].size(); ++j) {
                c[i][j] = n1;
                ++n1;
            }
        }
    }
    vector<vector<int> > g(n1);
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        if ((r & 1) == 0) {
            swap(l, r);
        }
        for (int j1 = 0; j1 < (int) b[l].size(); ++j1) {
            for (int j2 = 0; j2 < (int) b[r].size(); ++j2) {
                if (b[l][j1] == b[r][j2]) {
                    g[c[l][j1]].push_back(c[r][j2]);
                }
            }
        }
    }
    vector<int> mt(n2, -1);
    vector<bool> used(n1);
    int ans = 0;
    for (int i = 0; i < n1; ++i) {
        used.assign(n1, false);
        if (DoKunh(i, g, used, mt)) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}