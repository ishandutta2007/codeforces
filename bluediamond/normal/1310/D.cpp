#include <bits/stdc++.h>

using namespace std;

mt19937 rng((long long) (new char));
const int K = 10 + 7;
const int N = 80 + 7;
const int INF = (int) 1e9;

int n, k, dist[N][N], col[N], ans = INF, best[K][N];

void make_step() {
    for (int i = 1; i <= n; i++)
        col[i] = rng() % 2;
    for (int t = 1; t <= k; t++)
        for (int i = 1; i <= n; i++)
            best[t][i] = INF;
    best[1][1] = 0;
    for (int t = 1; t < k; t++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (col[i] != col[j])
                    best[t + 1][j] = min(best[t + 1][j], best[t][i] + dist[i][j]);
    ans = min(ans, best[k][1]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> dist[i][j];
    k++;
    int steps = (int) 2e8 / (n * n * k);
    for (int i = 1; i <= steps; i++)
        make_step();
    cout << ans << "\n";
}