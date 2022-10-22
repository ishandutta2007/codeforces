#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 101;
const int MAXK = 22;
const long long INF = 1000000007;

int N, K;
vector<int> X[MAXN];
long long f[MAXN][MAXK][MAXK];

int dfs(int a, int fa) {
    long long g[MAXK][MAXK];
    f[a][0][K] = f[a][1][0] = 1;
    for (int t = 0; t < X[a].size(); ++t) {
        if (X[a][t] == fa) continue;
        int b = X[a][t];
        dfs(b, a);
        memset(g, 0, sizeof(g));
        for (int i = 0; i <= K; ++i)
         for (int j = 0; j <= K; ++j)
          for (int k = 0; k <= K; ++k) 
           for (int l = 0; l <= K; ++l) {
               int p = max(l >= i ? 0 : i, j >= k ? 0 : k + 1);
               int q = max(j, l - 1);
               g[p][q] = (g[p][q] + f[a][i][j] * f[b][k][l]) % INF; 
           }

        for (int i = 0; i <= K + 1; ++i)
         for (int j = 0; j <= K + 1; ++j) f[a][i][j] = g[i][j];
    }
    return 0;
}

int main() {
    cin >> N >> K;
    for (int i = 1; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        X[a].push_back(b);
        X[b].push_back(a);
    }
    dfs(1, -1);
    int ans = 0;
    for (int i = 0; i <= K; ++i) ans = (ans + f[1][0][i]) % INF;
    cout << ans << endl;
    return 0;
}