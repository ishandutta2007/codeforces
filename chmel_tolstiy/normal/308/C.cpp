#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int nn = 1 << 20;

int n, m;

int a[nn];
int b[31][nn];
int c[31];

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a, a + n);
    for (int i = 0; i < m; ++i) {
        int y; scanf("%d", &y);
        b[y][c[y]++] = 1;
    }

    int res = 0;

    for (int x = 0; x < 30; ++x) {
        int h = 0;
        for (int i = 0; i < n; ++i) h += (a[i] & (1<<x)) > 0;
        int d = c[x];
        while (h > 0 && d > 0) {
            --d; --h;
            res += b[x][d];
        }
        if (d & 1) {
            b[x+1][c[x+1]++] = b[x][0];
        }
        for (int i = d % 2; i < d; i += 2) {
            b[x+1][c[x+1]++] = b[x][i] + b[x][i+1];
        }
    }
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}