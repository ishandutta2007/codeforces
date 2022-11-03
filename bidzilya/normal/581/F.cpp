#include <iostream>
#include <deque>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <map>
#include <cassert>
using namespace std;

const int kInf = 1e9;
const int kMaxN = 5e3;

int n, m;
vector<vector<int> > g;
vector<vector<int> > ng;
vector<vector<int> > dp[2];
vector<bool> is_leaf;
vector<int> amount_of_leafs;

int indp[kMaxN][kMaxN + 1];

void CalcLeafs(int v, int pr)
{
    amount_of_leafs[v] = 0;
    is_leaf[v] = true;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];
        if (u != pr) {
            is_leaf[v] = false;
            CalcLeafs(u, v);
            amount_of_leafs[v] += amount_of_leafs[u];
            ng[v].push_back(u);
        }
    }
    if (is_leaf[v]) {
        ++amount_of_leafs[v];
    }
}

void CalcDp(int v)
{
    if (is_leaf[v]) {
        dp[0][v][1] = 0;
        dp[1][v][0] = 0;
        return;
    }
    for (auto u: ng[v]) {
        CalcDp(u);
    }
    vector<int> sum_amount_of_leafs(ng[v].size());
    sum_amount_of_leafs[0] = amount_of_leafs[ng[v][0]];
    for (int i = 1; i < (int) ng[v].size(); ++i) {
        sum_amount_of_leafs[i] = sum_amount_of_leafs[i - 1] + 
            amount_of_leafs[ng[v][i]];
    }
    for (int cur = 0; cur < 2; ++cur) {
        for (int i = 0; i < (int) ng[v].size(); ++i) {
            for (int j = 0; j <= sum_amount_of_leafs[i]; ++j) {
                indp[i][j] = kInf;
            }
        }
        for (int t = 0; t <= amount_of_leafs[ng[v][0]]; ++t) {
            for (int nx = 0; nx < 2; ++nx) {
                indp[0][t] = min(indp[0][t], dp[nx][ng[v][0]][t] + (nx != cur));
            }
        }
        for (int i = 1; i < (int) ng[v].size(); ++i) {
            for (int nx = 0; nx < 2; ++nx) {
                for (int t = 0; t <= amount_of_leafs[ng[v][i]]; ++t) {
                    for (int pt = 0; pt <= sum_amount_of_leafs[i - 1]; ++pt) {
                        indp[i][t + pt] = min(indp[i][t + pt], dp[nx][ng[v][i]][t] + (nx != cur) + 
                                                               indp[i - 1][pt]); 
                    }
                }
            }
        }
        for (int t = 0; t <= amount_of_leafs[v]; ++t) {
            dp[cur][v][t] = min(dp[cur][v][t], indp[ng[v].size() - 1][t]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    if (n == 2) {
        cout << 1 << endl;
        return 0;
    }
    g.resize(n);
    for (int i = 0; i + 1 < n; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1;
        --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }   
    int root = -1;
    for (int i = 0; i < n; ++i) {
        if (g[i].size() > 1) {
            root = i;
            break;
        }
    }

    amount_of_leafs.resize(n);
    is_leaf.resize(n);
    ng.resize(n);
    CalcLeafs(root, -1);

    m = amount_of_leafs[root] / 2;
    dp[0].resize(n);
    dp[1].resize(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            dp[j][i].assign(amount_of_leafs[i] + 1, kInf);
        }
    }
    CalcDp(root);

    cout << min(dp[0][root][m], dp[1][root][m]) << endl;

    return 0;
}