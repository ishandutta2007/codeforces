#include <bits/stdc++.h>

using namespace std;

const int max_n = 505, inf = 1000111222;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, m;
char s[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '.') {
                s[i][j] = 'D';
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < 4; ++k) {
                int x = i + dx[k], y = j + dy[k];
                if (0 <= x && x < n && 0 <= y && y < m && s[i][j] == 'S' && s[x][y] == 'W') {
                    puts("No");
                    return 0;
                }
            }
        }
    }
    puts("Yes");
    for (int i = 0; i < n; ++i) {
        puts(s[i]);
    }
    return 0;
}