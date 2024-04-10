#include <bits/stdc++.h>

using namespace std;

int n, k, m;
vector<int> a;
vector<vector<int> > gr;
void read() {
    cin >> n >> m >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i], --a[i];

    gr.resize(n);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
}

map<int, int> cnt;
vector<bool> vis;
void dfs(int u) {
    cnt[a[u]]++;
    vis[u] = true;
    for (int i = 0; i < (int) gr[u].size(); ++i) {
        int v = gr[u][i];
        if (!vis[v]) dfs(v);
    }
}

bool cmpss(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}

int addsec(int a, const pair<int, int>& b) {
    return a + b.second;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("file.inp", "r", stdin);
    freopen("file.out", "w", stdout);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    read();
    vis.resize(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        cnt.clear();
        dfs(i);
        ans += accumulate(cnt.begin(), cnt.end(), 0, addsec) - max_element(cnt.begin(), cnt.end(), cmpss)->second;
    }
    cout << ans;

    return 0;
}