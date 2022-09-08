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

const int max_n = 101111, max_m = 12, bsize = 400, inf = 1111111111;

struct block {
    pair<int, int> a[bsize][max_m];
};

int n, m, q, l[bsize], r[bsize], dx[222], dy[222], num[max_n];
char s[max_n][max_m];
block b[bsize];
pair<int, int> p(2, 2);

bool is_in(int num, int x, int y) {
    return 0 <= x && x <= r[num] - l[num] && 0 <= y && y < m;
}

void get(int num, int x, int y, int px, int py) {
    if (b[num].a[x][y] != p) {
        return;
    }
    int nx = x + dx[s[l[num] + x][y]];
    int ny = y + dy[s[l[num] + x][y]];
    if (!is_in(num, nx, ny)) {
        b[num].a[x][y] = make_pair(nx, ny);
        return;
    }
    if (b[num].a[nx][ny] != p) {
        b[num].a[x][y] = b[num].a[nx][ny];
        return;
    }
    if (nx == px && ny == py) {
        b[num].a[x][y] = make_pair(inf, inf);
        return;
    }
    get(num, nx, ny, x, y);
    b[num].a[x][y] = b[num].a[nx][ny];
}

void update(int num) {
    for (int i = l[num]; i <= r[num]; ++i) {
        for (int j = 0; j < m; ++j) {
            b[num].a[i - l[num]][j] = p;
        }
    }
    for (int i = l[num]; i <= r[num]; ++i) {
        for (int j = 0; j < m; ++j) {
            get(num, i - l[num], j, -3, -3);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    dx['<'] = 0;
    dy['<'] = -1;
    dx['>'] = 0;
    dy['>'] = 1;
    dx['^'] = -1;
    dy['^'] = 0;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < bsize; ++i) {
        l[i] = i * bsize;
        r[i] = min(n - 1, (i + 1) * bsize - 1);
        for (int j = l[i]; j <= r[i] && j < max_n; ++j) {
            num[j] = i;
        }
        update(i);
    }
    while (q--) {
        char c1[2], c2[2];
        int x, y;
        scanf("%s%d%d", c1, &x, &y);
        --x;
        --y;
        if (c1[0] == 'A') {
            int num_b = num[x];
            x -= l[num_b];
            while (true) {
                if (num_b < 0) {
                    printf("%d %d\n", x + 1, y + 1);
                    break;
                }
                int nx = b[num_b].a[x][y].first;
                int ny = b[num_b].a[x][y].second;
                if (nx == inf && ny == inf) {
                    printf("-1 -1\n");
                    break;
                }
                if (ny < 0 || ny >= m) {
                    printf("%d %d\n", l[num_b] + nx + 1, ny + 1);
                    break;
                }
                --num_b;
                if (num_b < 0) x = -1;
                else x = r[num_b] - l[num_b];
                y = ny;
            }
        } else {
            scanf("%s", c2);
            s[x][y] = c2[0];
            update(num[x]);
        }
    }
    return 0;
}