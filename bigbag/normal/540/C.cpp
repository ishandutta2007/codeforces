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

const int max_n = 555, inf = 1111111111;

int n, m, sx, sy, fx, fy, used[max_n][max_n];
string s[max_n];

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

bool is_in(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

void dfs(int x, int y) {
    used[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
        int a = x + dx[i], b = y + dy[i];
        if (is_in(a, b) && used[a][b] == 0) {
            if (s[a][b] == '.' || (a == fx && b == fy)) {
                dfs(a, b);
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    cin >> sx >> sy >> fx >> fy;
    --sx;
    --sy;
    --fx;
    --fy;
    dfs(sx, sy);
    if (used[fx][fy] == 1) {
        int cnt = 0, f = 0;
        for (int i = 0; i < 4; ++i) {
            int x = fx + dx[i];
            int y = fy + dy[i];
            if (is_in(x, y) && s[x][y] == '.') {
                ++cnt;
            }
            if (x == sx && y == sy) {
                f = 1;
            }
        }
        if (sx == fx && sy == fy) {
            if (cnt > 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
            return 0;
            //+
        }
        if (s[fx][fy] == 'X') {
            cout << "YES" << endl;
            return 0;
            //+
        }
        if (f == 1 && cnt > 0) {
            cout << "YES" << endl;
        } else if (cnt > 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        cout << "NO" << endl;
    }
    return 0;
}