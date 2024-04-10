#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int C[100100];
vector<int> G[100100];
vector<int> GT[100100];
bool visited[100100];
vector<int> post_order;
vector<int> SCC;

void dfs1(int n) {
    visited[n] = true;
    for(int x : G[n]) {
        if(!visited[x]) {
            dfs1(x);
        }
    }
    post_order.push_back(n);
}

void dfs2(int n) {
    visited[n] = true;
    SCC.push_back(C[n]);
    for(int x : GT[n]) {
        if(!visited[x]) {
            dfs2(x);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    int N, M;
    cin >> N;
    for(int n = 0; n < N; ++n) {
        cin >> C[n];
    }
    cin >> M;
    while(M--) {
        int u, v;
        cin >> u >> v;
        G[u - 1].push_back(v - 1);
        GT[v - 1].push_back(u - 1);
    }
    for(int n = 0; n < N; ++n) {
        if(!visited[n]) {
            dfs1(n);
        }
    }
    memset(visited, 0, sizeof(visited));
    reverse(post_order.begin(), post_order.end());
    long long ans1 = 0, ans2 = 1;
    for(int n : post_order) {
        if(!visited[n]) {
            SCC.clear();
            dfs2(n);
            int m = *min_element(SCC.begin(), SCC.end());
            ans1 += m;
            ans2 = (ans2 * count(SCC.begin(), SCC.end(), m)) % MOD;
        }
    }
    cout << ans1 << ' ' << ans2 << '\n';
}