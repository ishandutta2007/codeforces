#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, q, f[2][max_n];
int bad;

void proc(int y, int z) {
    int add = 0;
    add += f[0][y] & f[1][y];
    if (y) {
        add += f[0][y] & f[1][y - 1];
        add += f[0][y - 1] & f[1][y];
    }
    if (y + 1 < n) {
        add += f[0][y] & f[1][y + 1];
        add += f[0][y + 1] & f[1][y];
    }
    bad += add * z;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        --y;
        proc(y, -1);
        f[x][y] ^= 1;
        proc(y, 1);
        if (bad) {
            puts("No");
        } else {
            puts("Yes");
        }
    }
    return 0;
}