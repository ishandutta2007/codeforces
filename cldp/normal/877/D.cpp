#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);

string P[MAXN];
int f[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i) cin >> P[i];

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    --x1; --y1; --x2; --y2;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) f[i][j] = INF;
    }
    
    f[x1][y1] = 0;
    queue<pair<int, int> > Q;
    Q.push(make_pair(x1, y1));
    while (!Q.empty()) {
        int a = Q.front().first;
        int b = Q.front().second;
        Q.pop();
        for (int i = 1; i <= K; ++i) {
            if (a - i < 0 || P[a - i][b] == '#' || f[a - i][b] <= f[a][b]) break;
            if (f[a - i][b] != INF && f[a - i][b] > f[a][b] + 1) return 1;
            if (f[a - i][b] == INF) Q.push(make_pair(a - i, b));
            f[a - i][b] = f[a][b] + 1;
        }
        for (int i = 1; i <= K; ++i) {
            if (a + i >= N || P[a + i][b] == '#' || f[a + i][b] <= f[a][b]) break;
            if (f[a + i][b] != INF && f[a + i][b] > f[a][b] + 1) return 1;
            if (f[a + i][b] == INF) Q.push(make_pair(a + i, b));
            f[a + i][b] = f[a][b] + 1;
        }

        for (int i = 1; i <= K; ++i) {
            if (b - i < 0 || P[a][b - i] == '#' || f[a][b - i] <= f[a][b]) break;
            if (f[a][b - i] != INF && f[a][b - i] > f[a][b] + 1) return 1;
            if (f[a][b - i] == INF) Q.push(make_pair(a, b - i));
            f[a][b - i] = f[a][b] + 1;
        }
        for (int i = 1; i <= K; ++i) {
            if (b + i >= M || P[a][b + i] == '#' || f[a][b + i] <= f[a][b]) break;
            if (f[a][b + i] != INF && f[a][b + i] > f[a][b] + 1) return 1;
            if (f[a][b + i] == INF) Q.push(make_pair(a, b + i));
            f[a][b + i] = f[a][b] + 1;
        }
    }

    if (f[x2][y2] == INF) f[x2][y2] = -1;
    cout << f[x2][y2] << endl;

    return 0;
}