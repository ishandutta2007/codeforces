#include <bits/stdc++.h>

using namespace std;

typedef long long LL;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> S(K);
    vector<vector<int>> G(N);
    for(int& s : S) {
        cin >> s;
        --s;
    }
    while(M--) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    auto bfs = [&](int v0) {
        vector<int> Q = {v0};
        int i = 0;
        vector<int> dist(N, -1);
        dist[v0] = 0;
        while(i < int(Q.size())) {
            int v = Q[i];
            ++i;
            for(int u : G[v]) {
                if(dist[u] < 0) {
                    dist[u] = dist[v] + 1;
                    Q.push_back(u);
                }
            }
        }
        return dist;
    };
    auto d0 = bfs(0), dn = bfs(N - 1);
    sort(S.begin(), S.end(), [&](int i, int j) { return d0[i] > d0[j]; });
    int maxdn = dn[S[0]];
    int ans = 0;
    for(int i = 1; i < K; ++i) {
        ans = max(ans, d0[S[i]] + 1 + maxdn);
        maxdn = max(maxdn, dn[S[i]]);
    }
    cout << min(ans, d0[N - 1]) << "\n";
    
    return 0;
}