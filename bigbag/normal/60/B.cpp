#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 11, inf = 111111111;
const int dx[] = {0, 0, 0, 0, -1, 1};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {1, -1, 0, 0, 0, 0};

int ans, k, n, m, x, y, used[max_n][max_n][max_n];
string s[max_n][max_n];

bool is_in(int a, int x, int y) {
    return a >= 0 && x >= 0 && y >= 0 && a < k && x < n && y < m;
}

void dfs(int a, int x, int y) {
    ++ans;
    used[a][x][y] = 1;
    for (int i = 0; i < 6; ++i) {
        int aa = a + dx[i], xx = x + dy[i], yy = y + dz[i];
        if (is_in(aa, xx, yy) && used[aa][xx][yy] == 0 && s[aa][xx][yy] == '.') {
            dfs(aa, xx, yy);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> k >> n >> m;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> s[i][j];
        }
    }
    cin >> x >> y;
    ans = 0;
    dfs(0, x - 1, y - 1);
    cout << ans << endl;
    return 0;
}