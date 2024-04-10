#include <bits/stdc++.h>

using namespace std;

set<int> avail;
vector<int> G[500005];
int n;

int DFS(int node) {
    G[node].push_back(-1);
    G[node].push_back(n);

    sort(G[node].begin(), G[node].end());
    avail.erase(node);
    int ret = 1;

    for (int i = 1; i < (int)G[node].size(); ++i) {
        while (true) {
            auto it = avail.upper_bound(G[node][i - 1]);
            if (it != avail.end() && *it < G[node][i]) {
                ret += DFS(*it);            
            } else break;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }
    for (int i = 0; i < n; ++i)
        avail.insert(i);

    vector<int> szs;
    for (int i = 0; i < n; ++i) {
        if (avail.count(i))
            szs.push_back(DFS(i));
    }
    sort(szs.begin(), szs.end());
    cout << szs.size() << endl;
    for (auto x : szs) cout << x << " "; cout << endl;
    

    return 0;
}