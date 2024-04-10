#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200100;
const int INF = 1000000007;

int N, K;
long long ans = 0;
vector<int> X[MAXN];
long long f[MAXN][5], s[MAXN], cnt[5];

void dp(int a, int fa) {
    s[a] = f[a][0] = 1;
    for (int i = 0; i < X[a].size(); ++i) {
        if (X[a][i] == fa) continue;
        dp(X[a][i], a);
        ans += s[X[a][i]] * (N - s[X[a][i]]);
        s[a] += s[X[a][i]];
        for (int j = 0; j < K; ++j) {
            for (int k = 0; k < K; ++k) {
                cnt[(j + k + 1) % K] += f[a][j] * f[X[a][i]][k];
            }
        }
        for (int j = 0; j < K; ++j) f[a][(j + 1) % K] += f[X[a][i]][j];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int a, b;
    cin >> N >> K;
    for (int i = 0; i < N - 1; ++i) {
        cin >> a >> b;
        X[a].push_back(b);
        X[b].push_back(a);
    }
    dp(1, -1);
    for (int i = 1; i < K; ++i) ans += cnt[i] * (K - i);
    cout << ans / K << endl;
    return 0;
}