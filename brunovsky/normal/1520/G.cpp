#include <bits/stdc++.h>

using namespace std;

#define long int64_t
#define DV(a) (" [" #a "=" + to_string(a) + "]")

// *****

#define MAXN 2000
long inf = INT64_MAX / 4;
int N, M, W;
int A[MAXN][MAXN];
long from[MAXN][MAXN];
long to[MAXN][MAXN];
bool vis[MAXN][MAXN];

constexpr int dd[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dp(int fr, int fc, long mat[MAXN][MAXN]) {
    vector<array<int, 2>> bfs;
    int i = 0, S = 0;
    memset(vis, 0, sizeof(vis));
    vis[fr][fc] = true, mat[fr][fc] = 0;
    bfs.push_back({fr, fc}), S++;
    while (i < S) {
        auto [rs, cs] = bfs[i++];
        for (auto d : dd) {
            int r = rs + d[0], c = cs + d[1];
            if (0 <= r && r < N && 0 <= c && c < M && !vis[r][c] && A[r][c] >= 0) {
                vis[r][c] = true, mat[r][c] = mat[rs][cs] + W;
                bfs.push_back({r, c}), S++;
            }
        }
    }
}

auto solve() {
    cin >> N >> M >> W;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> A[r][c];
            from[r][c] = to[r][c] = inf;
        }
    }
    dp(0, 0, from);
    dp(N - 1, M - 1, to);
    assert(from[N - 1][M - 1] == to[0][0]);
    long min_teleport_from = inf, min_teleport_to = inf;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (A[r][c] > 0) {
                min_teleport_from = min(min_teleport_from, from[r][c] + A[r][c]);
                min_teleport_to = min(min_teleport_to, to[r][c] + A[r][c]);
            }
        }
    }
    long ans = min(to[0][0], min_teleport_from + min_teleport_to);
    return ans == inf ? -1 : ans;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}