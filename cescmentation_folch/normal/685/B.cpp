#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

const int N = 300010;

vi G[N];
vi H[N];
int h[N];
int Z[N];
int M[N];
int tt = 0;

int dfs(int x, int p) {
    Z[x] = 1;
    M[x] = 0;
    for (int i = 0; i < G[x].size(); ++i) {
        int y = G[x][i];
        if (y == p) continue;
        Z[x] += dfs(y, x);
        M[x] = max(M[x], Z[y]);
    }
    int m = (Z[x])/2;
    h[x] = -1;
    for (int i = 0; i < G[x].size(); ++i) {
        int y = G[x][i];
        if (y == p) continue;
        if (Z[y] > m) {
            h[x] = h[y];
            H[h[x]].push_back(x);
        }
    }
    if (h[x] == -1) {
        ++tt;
        h[x] = tt;
        H[tt].push_back(x);
    }
    return Z[x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        G[x].push_back(i);
        G[i].push_back(x);
    }
    dfs(1, -1);
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        int m = (Z[x])/2;
        int r = h[x];
        int a = 0;
        int b = H[r].size();
        while (a + 1 < b) {
            int c = (a + b)/2;
            if (M[H[r][c]] <= m) a = c;
            else b = c;
        }
        cout << H[r][a] << endl;
    }
}