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

const int max_n = 311, inf = 1011111111;
const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

int n, a[max_n], ans, f[max_n][max_n];
char dp[33][max_n][max_n][8];
queue<pair<int, pair<int, int> > > q;

void proc(int x, int y, int napr, int i) {
    for (int j = 0; j < a[i]; ++j) {
        x += dx[napr];
        y += dy[napr];
        f[x][y] = 1;
    }
    dp[i][x][y][napr] = 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int x = 155, y = 155;
    while (a[0]--) {
        x += dx[0];
        y += dy[0];
        f[x][y] = 1;
    }
    dp[0][x][y][0] = 1;
    //cout << sizeof(dp) << endl;
    for (int i = 0; i + 1 < n; ++i) {
        for (int x = 0; x < max_n; ++x) {
            for (int y = 0; y < max_n; ++y) {
                for (int q = 0; q < 8; ++q) {
                    if (dp[i][x][y][q]) {
                        int a1 = (q - 1 + 8) % 8;
                        int a2 = (q + 1) % 8;
                        proc(x, y, a1, i + 1);
                        proc(x, y, a2, i + 1);
                    }
                }
            }
        }
    }
    for (int i = 0; i < max_n; ++i) {
        for (int j = 0; j < max_n; ++j) {
            ans += f[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}