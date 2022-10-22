#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);

double x[MAXN], y[MAXN], r[MAXN];
vector<int> X[MAXN];
double f[MAXN][3];
bool z[MAXN][3];

double dist(int a, int b) {
    return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
}

double dp(int a, int b) {
    if (z[a][b]) return f[a][b];
    z[a][b] = true;
    f[a][b] = 0;
    if (X[a].size() == 0) return f[a][b];

    if (b == 2) {
        for (int i = 0; i < X[a].size(); ++i) {
            int t = X[a][i];
            f[a][b] += dp(t, 1) - r[t] * r[t];
        }
    } 
    if (b == 0) {
        for (int i = 0; i < X[a].size(); ++i) {
            int t = X[a][i];
            f[a][b] += dp(t, 1) + r[t] * r[t];
        }
    } 
    if (b == 1) {
        for (int i = 0; i < X[a].size(); ++i) {
            int t = X[a][i];
            f[a][b] += max(dp(t, 2) + r[t] * r[t], dp(t, 0) - r[t] * r[t]);
        }
    }

    return f[a][b];
}


int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> x[i] >> y[i] >> r[i];
    r[0] = 1e8;
    for (int i = 1; i <= N; ++i) {
        int k = 0;
        for (int j = 1; j <= N; ++j) {
            if (i == j) continue;
            if (dist(i, j) + r[i] <= r[j] + 1e-2) {
                if (r[j] < r[k]) k = j;
            }
        }
        X[k].push_back(i);
    }

    cout << fixed << setprecision(10) << dp(0, 0) * PI << endl;

    return 0;
}