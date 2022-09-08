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

const int max_n = 555, max_len = 111111, inf = 1111111111;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, m, x, y, a[max_n][max_n], ans[max_len];
string s;

int get_tp(char c) {
    if (c == 'U') {
        return 0;
    }
    if (c == 'D') {
        return 1;
    }
    if (c == 'L') {
        return 2;
    }
    return 3;
}

bool is_in(int x, int y) {
    return 0 <= x && 0 <= y && x < n && y < m;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> x >> y >> s;
    int res = 0;
    --x;
    --y;
    for (int i = 0; i <= s.length(); ++i) {
        if (a[x][y] == 0) {
            a[x][y] = 1;
            ans[i] = 1;
            ++res;
        }
        if (i < s.length()) {
            int tp = get_tp(s[i]);
            int nx = x + dx[tp], ny = y + dy[tp];
            if (is_in(nx, ny)) {
                x = nx;
                y = ny;
            }
        }
    }
    ans[s.length()] += n * m - res;
    for (int i = 0; i <= s.length(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}