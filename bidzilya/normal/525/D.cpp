#include <bits/stdc++.h>
using namespace std;

const int kMaxN = 2e3;

char s[kMaxN][kMaxN + 1];
int a[kMaxN][kMaxN + 1];
int used[kMaxN][kMaxN + 1];
int n, m;

bool GoodPos(int i, int j)
{
    return i >= 0 && i + 1 < n && j >= 0 && j + 1 < m;
}

int GetSum(int i, int j)
{
    return (s[i][j] == '*') + (s[i][j + 1] == '*') +
           (s[i + 1][j] == '*') + (s[i + 1][j + 1] == '*');
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
    }

    queue<pair<int, int> > q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (GoodPos(i, j)) {
                a[i][j] = GetSum(i, j);
                if (a[i][j] == 1) {
                    q.push(make_pair(i, j));
                    used[i][j] = 1;
                }
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i <= 1; ++i) {
            for (int j = 0; j <= 1; ++j) {
                s[i + x][j + y] = '.';
            }
        }

        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                int nx = dx + x;
                int ny = dy + y;

                if (GoodPos(nx, ny) && !used[nx][ny] && GetSum(nx, ny) == 1) {
                    q.push(make_pair(nx, ny));
                    used[nx][ny] = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%s\n", s[i]);
    }


    return 0;
}