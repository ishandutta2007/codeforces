#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvpi G;
vi V;

bool pote;

void dfs(int x ,int c) {
    V[x] = c;
    for (int i = 0; i < (int)G[x].size(); ++i) {
        int y = G[x][i].first;
        int k = G[x][i].second;
        int c2 = c;
        if (k) c2 ^= 3;
        if (V[y] != 0) {
            if (V[y] != c2) pote = false;
        }
        else {
            dfs(y, c2);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vi F(n);
    vvi A(n);
    G = vvpi(m);
    V = vi(m, 0);
    
    for (int i = 0; i < n; ++i) cin >> F[i];
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int x;
            cin >> x;
            A[x - 1].push_back(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        int x = A[i][0];
        int y = A[i][1];
        int c = F[i]^1;
        G[x].push_back(pi(y, c));
        G[y].push_back(pi(x, c));
    }
    
    pote = true;
    for (int i = 0; i < m; ++i) {
        if (V[i] == 0) dfs(i, 1);
    }
    
    if (pote) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}