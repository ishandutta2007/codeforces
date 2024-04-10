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

const int max_n = 111, inf = 1111111111;

int n, m, used[max_n][max_n];
string s[max_n];

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

bool is_in(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

void dfs(int x, int y, int px, int py) {
    used[x][y] = 1;
    //cout << x << " " << y << endl;
    for (int i = 0; i < 4; ++i) {
        int a = x + dx[i], b = y + dy[i];
        if (is_in(a, b) && s[x][y] == s[a][b]) {
            if (used[a][b] == 0) {
                dfs(a, b, x, y);
            } else if (used[a][b] == 1) {
                //cout << x << " " << y << " -> " << a << " " << b << endl;
                if (a == px && b == py) continue;
                cout << "Yes" << endl;
                exit(0);
            }
        }
    }
    used[x][y] = 2;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (used[i][j] == 0) {
                dfs(i, j, -1, -1);
            }
        }
    }
    cout << "No" << endl;
    return 0;
}