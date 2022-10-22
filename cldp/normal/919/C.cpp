#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 2010;
const int INF = 1000000007;
const double PI = acos(-1.0);

string x[MAXN];
int f[MAXN][MAXN], g[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i) cin >> x[i];
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (x[i][j] == '*') continue;
            f[i + 1][j + 1] = f[i + 1][j] + 1;
            g[i + 1][j + 1] = g[i][j + 1] + 1;
            if (f[i + 1][j + 1] >= K) ++ans;
            if (g[i + 1][j + 1] >= K && K > 1) ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}