/************
*           *
*   HELLO   *
*           *
************/

#include <bits/stdc++.h>

using namespace std;

const int mx = 3000000;
int n, u, v, cl[mx], used[mx];
vector<int> g[mx];

void dfs(int v, int forb) {
    used[v] = 1;
    int clr = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        if (used[g[v][i]] == 0) {
            while ((clr == forb) || (clr == cl[v]))
                clr++;
            cl[g[v][i]] = clr;
            clr++;
            dfs(g[v][i], cl[v]);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < (n - 1); ++i) {
        cin >> u >> v;
        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
        used[i] = 0;
    }
    cl[0] = 1;
    dfs(0, -1);
    int mxxx = 0;
    for (int i = 0; i < n; ++i) {
        mxxx = max(mxxx, cl[i]);
    }
    cout << mxxx << '\n';
    for (int i = 0; i < n; ++i) {
        cout << cl[i] << " ";
    }
    cout << endl;
    return 0;
}