#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
 
inline int gcd(int a, int b) {
    return a ? gcd(b % a, a) : b;
}
 
int nd[100100];
vector<int> p[6];
 
int f(int *a) {
    int g[8];
    g[1] = nd[a[0]];
    g[2] = nd[a[1]];
    g[4] = nd[a[2]];
    g[3] = nd[gcd(a[0], a[1])];
    g[5] = nd[gcd(a[0], a[2])];
    g[6] = nd[gcd(a[1], a[2])];
    g[7] = nd[gcd(a[0], gcd(a[1], a[2]))];
    int ans1 = 0, ans2 = 0;
    int x[3];
    forn (mask, 1 << 6) {
        if (mask == 0) {
            continue;
        }
        x[0] = x[1] = x[2] = 0;
        int cnt = 0;
        forn (i, 6) {
            if (mask & (1 << i)) {
                ++cnt;
                forn (j, 3) {
                    x[j] |= 1 << p[i][j];
                }
            }
        }
        if (cnt & 1) {
            ans1 += g[x[0]] * g[x[1]] * g[x[2]];
            ans2 += g[x[0] | x[1]] * g[x[2]];
        } else {
            ans1 -= g[x[0]] * g[x[1]] * g[x[2]];
            ans2 -= g[x[0] | x[1]] * g[x[2]];
        }
    }
    return (ans1 + ans2 * 3 + g[7] * 2) / 6;
}
 
int main() {
    int pcnt = 0;
    forn (i, 3) {
        forn (j, 3) {
            if (i == j) {
                continue;
            }
            p[pcnt++] = {i, j, 3 - i - j};
        }
    }
    for (int i = 1; i < 100100; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            if (i % j) {
                continue;
            }
            ++nd[i];
            if (j * j < i) {
                ++nd[i];
            }
        }
    }
    int T = 100000;
    scanf("%d", &T);
    forn (q, T) {
        int a[3];
        scanf("%d%d%d", &a[0], &a[1], &a[2]);
        printf("%d\n", f(a));
    }
    return 0;
}