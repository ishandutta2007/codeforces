#include <map>
#include <set>
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

const int max_n = 2002, inf = 111111111;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m, k, mm[max_n][max_n];

bool is_in(int x, int y) {
    return x > 0 && y > 0 && x <= n && y <= m;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    queue <pair<int, int> > q;
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        mm[x][y] = 1;
        q.push(make_pair(x, y));
    }
    int cnt = 1;
    while (!q.empty()) {
        if (cnt == n * m) {
            break;
        }
        pair<int, int> v = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int x = v.first + dx[i], y = v.second + dy[i];
            if (is_in(x, y) && mm[x][y] == 0) {
                ++cnt;
                mm[x][y] = mm[v.first][v.second] + 1;
                q.push(make_pair(x, y));
            }
        }
    }
    int max1 = -1, x, y;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (mm[i][j] > max1) {
                max1 = mm[i][j];
                x = i;
                y = j;
            }
        }
    }
    cout << x << ' ' << y << endl;
    return 0;
}