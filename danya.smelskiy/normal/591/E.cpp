# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_set>
# include <unordered_map>
using namespace std;



int n, m;
bool used[1005][1005];
string s[1005];
vector<pair<int, int> > q[3];

void dfs(int x, int y, int z) {
    if (x < 1 || x > n || y < 1 || y > m || used[x][y] || s[x][y] - '1' != z) return;
    used[x][y] = true;
    q[z].push_back({x, y});
    dfs(x - 1, y, z);
    dfs(x + 1, y, z);
    dfs(x, y - 1, z);
    dfs(x, y + 1, z);
    return;
}

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dist[5][5];
int d[3][1005][1005];


inline void calc(int it) {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            used[i][j] = false, d[it][i][j] = 1e7;
    vector<pair<int, int> > qq;
    int x, y;
    for (int i = 0; i < q[it].size(); ++i) {
        x = q[it][i].first;
        y = q[it][i].second;
        used[x][y] = true;
        d[it][x][y] = 0;
        qq.push_back({x, y});
    }
    int xx, yy;
    for (int i = 0; i < (int)qq.size(); ++i) {
        x = qq[i].first;
        y = qq[i].second;
        for (int j = 0; j < 4; ++j) {
            xx = x + dx[j];
            yy = y + dy[j];
            if (xx < 1 || xx > n || yy < 1 || yy > m || used[xx][yy] || s[xx][yy] == '#') continue;
            used[xx][yy] = true;
            d[it][xx][yy] = d[it][x][y] + 1;
            qq.push_back({xx, yy});
        }
    }
    for (int i = 0; i < 3; ++i) {
        if (i == it) continue;
        dist[it][i] = 1e7;
        for (int j = 0; j < q[i].size(); ++j)
            dist[it][i] = min(dist[it][i], d[it][q[i][j].first][q[i][j].second]);
    }
    return;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        s[i] = "#" + s[i];
    }
    for (int it = 0; it < 3; ++it) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) if (s[i][j] - '1' == it) dfs(i, j, it);
        }
    }
    for (int i = 0; i < 3; ++i)
        calc(i);
    int ans = 1e9;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k) if (i != j && i != k && j != k) ans = min(ans, dist[i][j] + dist[i][k] - 2);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            ans = min(ans, d[0][i][j] + d[1][i][j] + d[2][i][j] - 2);
    if (ans <= 1e6) cout << ans << '\n';
    else cout << -1 << '\n';
}