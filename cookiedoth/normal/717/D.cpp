/************
*           *
*   HELLO   *
*           *
************/

#include <iostream>
#include <stdio.h>

using namespace std;

const int mx = 102;
const int e = 127;
const int dgt = 7;
const int logn = 31;
const int slot = 3;

int res[slot][logn];

void tr(int ms, int xx) {
    int r = 0;
    for (int i = 0; i<dgt; i++) res[ms][i] = 0;
    while (xx > 0) {
        res[ms][r] = xx%2;
        xx = xx/2;
        r++;
    }
}

int main()
{
    int n, x, a, b, c, pow2[logn], i, j, w;
    double d[e+1], me[logn][e+1], p[mx], f[e+1];
    cin >> n >> x;
    for (i = 0; i<=x; i++) {
        cin >> p[i];
    }
    pow2[0] = 1;
    for (i = 1; i<logn; i++) pow2[i] = pow2[i-1]*2;
    for (i = 0; i<=x; i++) {
        me[0][i] = p[i];
    }
    for (i = x+1; i<=e; i++) {
        me[0][i] = 0;
    }
    for (a = 1; a<logn; a++) {
        for (i = 0; i<=e; i++) me[a][i] = 0;
        for (i = 0; i<=e; i++) {
            for (j = 0; j<=e; j++) {
                tr(0, i);
                tr(1, j);
                w = 0;
                for (b = 0; b<dgt; b++) {
                    if ((res[0][b] + res[1][b]) == 1) w = w + pow2[b];
                }
                me[a][w] += (me[a-1][i] * me[a-1][j]);
            }
        }
    }
    tr(2, n);
    c = 0;
    while (res[2][c] == 0) c++;
    for (i = 0; i<=e; i++) {
        d[i] = me[c][i];
    }
    for (a = c+1; a<logn; a++) {
        for (i = 0; i<=e; i++) {
            f[i] = 0;
        }
        if (res[2][a] == 1) {
            for (i = 0; i<=e; i++) {
                for (j = 0; j<=e; j++) {
                    tr(0, i);
                    tr(1, j);
                    w = 0;
                    for (b = 0; b<dgt; b++) {
                        if ((res[0][b] + res[1][b]) == 1) w = w + pow2[b];
                    }
                    f[w] = f[w] + (me[a][i]*d[j]);
                }
            }
            for (i = 0; i<=e; i++) {
                d[i] = f[i];
                f[i] = 0;
            }
        }
    }
    printf("%f", 1 - d[0]);
    return 0;
}