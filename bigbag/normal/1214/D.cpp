#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111;
const int dx[] = {1, 0};
const int dy[] = {0, 1};

char s[max_n];
int n, m, cnt[2 * max_n];
vector<vector<char>> a, used, dp1, dp2;

bool is_in(int x, int y) {
    return 0 <= x && 0 <= y && x < n && y < m;
}

bool bfs() {
    used.resize(n, vector<char> (m, 0));
    queue<pair<int, int>> q;
    q.push({0, 0});
    used[0][0] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 2; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (is_in(nx, ny) && !used[nx][ny] && a[nx][ny] == '.') {
                used[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    return used[n - 1][m - 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    a.resize(n, vector<char> (m));
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        for (int j = 0; j < m; ++j) {
            a[i][j] = s[j];
        }
    }
    if (!bfs()) {
        puts("0");
        return 0;
    }
    dp1.resize(n, vector<char> (m, 0));
    dp2.resize(n, vector<char> (m, 0));
    dp1[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dp1[i][j]) {
                for (int k = 0; k < 2; ++k) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (is_in(nx, ny) && a[nx][ny] == '.') {
                        dp1[nx][ny] = 1;
                    }
                }
            }
        }
    }
    dp2[n - 1][m - 1] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (dp2[i][j]) {
                for (int k = 0; k < 2; ++k) {
                    int nx = i - dx[k], ny = j - dy[k];
                    if (is_in(nx, ny) && a[nx][ny] == '.') {
                        dp2[nx][ny] = 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dp1[i][j] && dp2[i][j]) {
                ++cnt[i + j];
            }
        }
    }
    for (int i = 1; i < n + m - 2; ++i) {
        if (cnt[i] <= 1) {
            puts("1");
            return 0;
        }
    }
    puts("2");
    return 0;
}