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

const int max_n = 111, inf = 1011111111;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

int ans, n, m, sx, sy, p[4];
string s[max_n], t;

bool is_in(int x, int y) {
    return 0 <= x && 0 <= y && x < n && y < m;
}

bool check() {
    int x = sx;
    int y = sy;
    for (int i = 0; i < t.length(); ++i) {
        int num = p[t[i] - '0'];
        x += dx[num];
        y += dy[num];
        if (!is_in(x, y)) {
            return false;
        }
        if (s[x][y] == '#') {
            return false;
        }
        if (s[x][y] == 'E') {
            return true;
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
    }
    cin >> t;
    p[0] = 0;
    p[1] = 1;
    p[2] = 2;
    p[3] = 3;
    do {
        if (check()) {
            ++ans;
        }
    } while (next_permutation(p, p + 4));
    cout << ans << endl;
    return 0;
}