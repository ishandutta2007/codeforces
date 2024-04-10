#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10002;
const int INF = 1000000007;
const double PI = acos(-1.0);
const int MX[4] = {-1, 0, 1, 0};
const int MY[4] = {0, 1, 0, -1};

int N, M, K;
bool x[MAXN][MAXN];
bool z[MAXN][MAXN];
bool rx[MAXN], cx[MAXN];
queue<pair<int, int> > Q[2];


bool check(int a, int b) {
    if (a < 1 || a > N || b < 1 || b > M) return false;
    return true;
}

void bfs(int a, int b, queue<pair<int, int> > &Q) {
    queue<pair<int, int> > P;
    P.push(make_pair(a, b));
    while (!P.empty()) {
        a = P.front().first;
        b = P.front().second;
        z[a][b] = true;
        Q.push(P.front());
        P.pop();
        for (int i = 0; i < 4; ++i) {
            int c = a + MX[i];
            int d = b + MY[i];
            if (!check(c, d) || z[c][d] || !x[c][d]) continue;
            P.push(make_pair(c, d));
        }
    }
}

void spanra(int a, const int &cur) {
    if (rx[a]) return ;
    rx[a] = true;
    for (int j = 1; j <= M; ++j) {
        if (z[a][j]) continue;
        z[a][j] = true;
        if (x[a][j]) bfs(a, j, Q[1 - cur]);
        if (a > 1 && !z[a - 1][j] && x[a - 1][j]) bfs(a - 1, j, Q[1 - cur]);
        if (a < N && !z[a + 1][j] && x[a + 1][j]) bfs(a + 1, j, Q[1 - cur]);
    }
}

void spancb(int b, const int &cur) {
    if (cx[b]) return ;
    cx[b] = true;
    for (int i = 1; i <= N; ++i) {
        if (z[i][b]) continue;
        z[i][b] = true;
        if (x[i][b]) bfs(i, b, Q[1 - cur]);
        if (b > 1 && !z[i][b - 1] && x[i][b - 1]) bfs(i, b - 1, Q[1 - cur]);
        if (b < M && !z[i][b + 1] && x[i][b + 1]) bfs(i, b + 1, Q[1 - cur]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> K;
    for (int i = 0; i < K; ++i) {
        int a, b;
        cin >> a >> b;
        x[a][b] = true;
    }

    int cur = 0;
    bfs(1, 1, Q[cur]);
    int ans = 0;
    while (true) {
        if (z[N][M]) {
            cout << ans << endl;
            break;
        }
        if (Q[cur].empty()) {
            cout << -1 << endl;
            break;
        }
        ++ans;
        while (!Q[cur].empty()) {
            int a = Q[cur].front().first;
            int b = Q[cur].front().second;
          //  cout << a << " " << b << endl;
            Q[cur].pop();
            spanra(a, cur);
            if (a > 1) spanra(a - 1, cur);
            if (a < N) spanra(a + 1, cur);
            spancb(b, cur);
            if (b > 1) spancb(b - 1, cur);
            if (b < M) spancb(b + 1, cur);
        }
     //   cout << endl;
        cur = 1 - cur;
    }

    return 0;
}