#include <iostream>
#include <vector>

using namespace std;

int k;
vector<vector<int> > tr;
vector<vector<long long> > dst;
vector<long long> sumd;
vector<bool> used;

void dfs(int v) {
    used[v] = true;
    sumd[v] = 0;
    for (int i = 0; i < tr[v].size(); ++i) {
        if (!used[tr[v][i]]) {
            ++dst[v][1 % k];
            ++sumd[v];
            dfs(tr[v][i]);
            sumd[v] += sumd[tr[v][i]];
            sumd[v] += dst[tr[v][i]][0];
            for (int j = 0; j < k; ++j) {
                dst[v][(j + 1) % k] += dst[tr[v][i]][j];
            }
        }
    }
}

void dfs1(int v, const vector<long long>& dp, long long sm) {
    used[v] = true;
    sumd[v] += sm;
    sumd[v] += dp[0];
    if (v != 0) {
        sumd[v] += 1;
        dst[v][1 % k] += 1;
    }
    vector<long long> curd = dst[v];
    for (int j = 0; j < k; ++j) {
        curd[(j + 1) % k] += dp[j];
    }
    for (int i = 0; i < tr[v].size(); ++i) {
        if (!used[tr[v][i]]) {
            vector<long long> buf = curd;
            for (int j = 0; j < k; ++j) {
                buf[(j + 1) % k] -= dst[tr[v][i]][j];
            }
            --buf[1 % k];
            dfs1(tr[v][i], buf, sumd[v] - sumd[tr[v][i]] - dst[tr[v][i]][0] - 1);
        }
    }
}

int main() {
    int n;
    cin >> n >> k;
    tr.resize(n);
    used.assign(n, false);
    sumd.assign(n, 0);
    dst.resize(n, vector<long long>(k, 0));
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tr[a].push_back(b);
        tr[b].push_back(a);
    }
    dfs(0);
    used.assign(n, false);
    dfs1(0, vector<long long> (k, 0), 0);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += sumd[i];
    }
    cout << ans / 2 << endl;
}