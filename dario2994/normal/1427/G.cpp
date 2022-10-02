#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define SZ(x) ((int)((x).size()))

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
#endif


const int MAXN = 200 + 5;
int vals[MAXN][MAXN];
int available[MAXN][MAXN][4];
int dt[4] = {0, 1, 0, -1};
int N;

bool sources[MAXN][MAXN];
bool sinks[MAXN][MAXN];
bool visited[MAXN][MAXN];

void reset_visited() {
    for (int x = 0; x < N; x++) for (int y = 0; y < N; y++) visited[x][y] = false;
}

bool dfs(int x, int y, bool is_goal[MAXN][MAXN]) {
    visited[x][y] = true;
    if (is_goal[x][y]) return true;
    for (int t = 0; t < 4; t++) {
        if (!available[x][y][t]) continue;
        int x1 = x + dt[t];
        int y1 = y + dt[t^1];
        if (is_goal == sources and available[x1][y1][t^2]) continue;
        if (visited[x1][y1]) continue;
        if (dfs(x1, y1, is_goal)) {
            if (available[x1][y1][t^2]) available[x][y][t] = false;
            else available[x1][y1][t^2] = true;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    cin >> N;

    vector<pair<int,int>> tiles;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> vals[i][j];
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        if (vals[i][j] >= 1) {
            tiles.push_back({i, j});
            sinks[i][j] = true;
        }
    }
    
    for (int x = 0; x < N; x++) for (int y = 0; y < N; y++) {
        if (vals[x][y] == -1) continue;
        for (int t = 0; t < 4; t++) {
            int x1 = x + dt[t];
            int y1 = y + dt[t^1];
            if (x1 < 0 or x1 >= N or y1 < 0 or y1 >= N) continue;
            if (vals[x1][y1] == -1) continue;
            available[x][y][t] = true;
        }
    }
    sort(tiles.begin(), tiles.end(), [&](pair<int,int> A, pair<int,int> B) {
        return vals[A.first][A.second] < vals[B.first][B.second];
    });
    
    LL res = 0;
    int flow = 0;

    for (int it = 0; it < SZ(tiles)-1; it++) {
        int x = tiles[it].first, y = tiles[it].second;
        
        while (dfs(x, y, sources)) {
            reset_visited();
            flow--;
        }
        reset_visited();
        sinks[x][y] = false;
        sources[x][y] = true;
        for (auto pp: tiles) {
        // for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            int i = pp.first, j = pp.second;
            if (sources[i][j] and !visited[i][j]) {
                while (dfs(i, j, sinks)) {
                    reset_visited();
                    flow++;
                }
            }
        }
        // for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            // if (visited[i][j] and !vals[i][j]) vals[i][j] = vals[x][y];
        // }
        reset_visited();
        
        LL cost = vals[tiles[it+1].first][tiles[it+1].second]-vals[x][y];
        res += cost * flow;
    }
    // for (int i = 0; i < N; i++) {
        // for (int j = 0; j < N; j++) cout << vals[i][j] << " ";
        // cout << "\n";
    // }
    cout << res << endl;
    
}