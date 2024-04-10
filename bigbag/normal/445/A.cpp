#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111, inf = 1111111111;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m;
string s[max_n];

bool is_in(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

void dfs(int x, int y, char c) {
    s[x][y] = c;
    for (int k = 0; k < 4; ++k) {
        int a = x + dx[k], b = y + dy[k];
        if (is_in(a, b) && s[a][b] == '.') {
            if (c == 'W') dfs(a, b, 'B');
            else dfs(a, b, 'W');
        }
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '.') {
                dfs(i, j, 'W');
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << s[i] << endl;
    }
    return 0;
}