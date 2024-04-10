#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int> > a[200000];
vector<int> ans[200000];

void dfs(int v, int p, int r) {
    int cnt = 0;
    for (int i = 0; i < a[v].size(); i++) {
        if (a[v][i].first != p) {
            if (cnt == r) {
                cnt++;
            }
            ans[cnt].push_back(a[v][i].second);
            dfs(a[v][i].first, v, cnt);
            cnt++;
        }
    }
}

int main() {
    iostream::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--; u--;
        a[v].push_back({u, i});
        a[u].push_back({v, i});
    }
    int mx = 0;
    int mxi = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].size() > mx) {
            mx = (int) a[i].size();
            mxi = i;
        }
    }
    cout << mx << "\n";
    dfs(mxi, -1, -1);
    for (int i = 0; i < mx; i++) {
        cout << ans[i].size() << " ";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] + 1 << " ";
        }
        cout << "\n";
    }
}