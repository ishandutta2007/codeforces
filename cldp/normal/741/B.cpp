#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000007;
const int MAXN = 2010;

int f[MAXN];
int w[MAXN], b[MAXN];

vector<int> X[MAXN];
bool z[MAXN];
vector<int> Y[MAXN];

int dfs(int a, int group) {
    z[a] = true;
    Y[group].push_back(a);
    for (int i = 0; i < X[a].size(); ++i) {
        if (!z[X[a][i]]) dfs(X[a][i], group);
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int N, M, W;
    cin >> N >> M >> W;
    for (int i = 1; i <= N; ++i) cin >> w[i];
    for (int i = 1; i <= N; ++i) cin >> b[i];
    for (int i = 1; i <= M; ++i) {
        int a, b;
        cin >> a >> b;
        X[a].push_back(b);
        X[b].push_back(a);
    }
    int T = 0;
    for (int i = 1; i <= N; ++i) {
        if (!z[i]) dfs(i, T); else continue;
        ++T;
    }
    
    memset(f, -1, sizeof(f));
    f[0] = 0;
    
    for (int i = 0; i < T; ++i) {
        int WW = 0, BB = 0;
        for (int k = 0; k < Y[i].size(); ++k) {
            WW += w[Y[i][k]];
            BB += b[Y[i][k]];
        }
        
        for (int j = W; j >= 0; --j) {
            if (f[j] == -1) continue;
            if (j + WW <= W) f[j + WW] = max(f[j + WW], f[j] + BB);
            for (int k = 0; k < Y[i].size(); ++k) {
                if (j + w[Y[i][k]] <= W) f[j + w[Y[i][k]]] = max(f[j + w[Y[i][k]]], f[j] + b[Y[i][k]]);
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i <= W; ++i) ans = max(ans, f[i]);
    cout << ans << endl;
    
    return 0;
}