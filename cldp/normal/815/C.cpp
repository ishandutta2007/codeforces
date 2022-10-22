#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 5010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int f[MAXN][MAXN][2];
vector<int> X[MAXN];
int A[MAXN], B[MAXN], S[MAXN];


void dp(int a) {
    S[a] = 1;
    for (int i = 0; i < MAXN; ++i) f[a][i][0] = f[a][i][1] = INF;

    f[a][0][0] = 0;
    f[a][1][0] = A[a];
    f[a][1][1] = B[a];
    for (int i = 0; i < X[a].size(); ++i) {
        int b = X[a][i];
        dp(b);
        for (int j = S[a]; j >= 0; --j) {
            for (int k = S[b]; k >= 0; --k) {
                f[a][j + k][1] = min(f[a][j + k][1], f[a][j][1] + min(f[b][k][1], f[b][k][0]));
                f[a][j + k][0] = min(f[a][j + k][0], f[a][j][0] + f[b][k][0]);
            }
        }
        S[a] += S[X[a][i]];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;
    cin >> A[1] >> B[1];
    B[1] = A[1] - B[1];
    for (int i = 2; i <= N; ++i) {
        int C;
        cin >> A[i] >> B[i] >> C;
        B[i] = A[i] - B[i];
        X[C].push_back(i);
    }

    dp(1);
    int ans = 0;
    for (int i = 1; i <= S[1]; ++i) {
        if (f[1][i][0] <= Q || f[1][i][1] <= Q) ans = i;
    }
    cout << ans << endl;

    return 0;
}