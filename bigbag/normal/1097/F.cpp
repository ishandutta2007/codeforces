#include <bits/stdc++.h>

using namespace std;

const int max_n = 100011, max_x = 7077, inf = 1000111222;
const int magic = 64;

int n, q, z[max_x];
bitset<max_x> b[max_n], c[magic];

void write() {
    cout << endl;
    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i < 13; ++i) {
            cout << b[j][i];
        }
        cout << endl;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 1; i < max_x; ++i) {
        z[i] = (i == 1) - z[i];
        for (int j = 2 * i; j < max_x; j += i) {
            z[j] += z[i];
        }
    }
    for (int x = 1; x < magic; ++x) {
        for (int i = 1; i * x < max_x; ++i) {
            if (z[i] != 0) {
                c[x][i * x] = 1;
            }
        }
    }
    while (q--) {
        int tp;
        scanf("%d", &tp);
        if (tp == 1) {
            int num, x;
            scanf("%d%d", &num, &x);
            b[num].reset();
            for (int i = 1; i * i <= x; ++i) {
                if (x % i == 0) {
                    b[num][i] = 1;
                    if (i * i != x) {
                        b[num][x / i] = 1;
                    }
                }
            }
            /*if (x < magic) {
                b[num] = init[x];
            } else {
                b[num].reset();
                for (int i = x; i < max_x; i += x) {
                    b[num][i] = 1;
                }
            }*/
        } else if (tp == 2) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            b[x] = b[y] ^ b[z];
        } else if (tp == 3) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            b[x] = b[y] & b[z];
        } else {
            int num, x;
            scanf("%d%d", &num, &x);
            if (x < magic) {
                int ans = (b[num] & c[x]).count();
                printf("%d", ans & 1);
            } else {
                int ans = 0;
                for (int i = 1; i * x < max_x; ++i) {
                    if (z[i]) {
                        ans ^= b[num][i * x];
                    }
                }
                printf("%d", ans);
            }
        }
    }
    printf("\n");
    return 0;
}