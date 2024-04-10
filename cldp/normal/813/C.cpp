#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200010;
const int INF = 1000000007;
const double PI = acos(-1.0);

vector<int> X[MAXN];
int up[MAXN], f[MAXN], down[MAXN];

int dfs(int a, int fa, int depth) {
    for (int i = 0; i < X[a].size(); ++i) {
        if (X[a][i] == fa) continue;
        down[a] = max(down[a], dfs(X[a][i], a, depth + 1));
        f[X[a][i]] = a;
    }
    up[a] = depth;
    return down[a] + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int N, S;
    cin >> N >> S;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        X[a].push_back(b);
        X[b].push_back(a);
    }
    dfs(1, -1, 0);

    int ans = 0;
    int b = S;
    for (int i = 0; i < N; ++i) {
        if (up[b] <= i) break;
        ans = max(ans, up[b] + down[b]);
        b = f[b];
    }
    cout << ans + ans << endl;

    return 0;
}