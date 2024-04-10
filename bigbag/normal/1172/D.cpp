#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

int n, r[max_n], c[max_n];
int cnt, ansx[max_n][2], ansy[max_n][2];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &r[i]);
        --r[i];
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c[i]);
        --c[i];
    }
    for (int i = 0; i < n; ++i) {
        int row, col;
        for (int j = i; j < n; ++j) {
            if (r[j] == i) {
                row = j;
            }
            if (c[j] == i) {
                col = j;
            }
        }
        if (row == i && col == i) {
            continue;
        }
        ansx[cnt][0] = row;
        ansy[cnt][0] = i;
        ansx[cnt][1] = i;
        ansy[cnt][1] = col;
        ++cnt;
        swap(r[i], r[row]);
        swap(c[i], c[col]);
    }
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; ++i) {
        printf("%d %d %d %d\n", 1 + ansx[i][0], 1 + ansy[i][0], 1 + ansx[i][1], 1 + ansy[i][1]);
    }
    return 0;
}