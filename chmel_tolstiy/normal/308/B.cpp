#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

const int nn = 1 << 20;

int n, r, c, l, w;
char s[nn * 10];
int p[nn];
int a[nn][20];
int b[nn][20];

void solve() {
    gets(s); sscanf(s, "%d %d %d", &n, &r, &c);
    gets(s); l = (int)strlen(s);

    p[w++] = 0;
    for (int i = 0; i < l; ++i)
        if (s[i] == ' ') p[w++] = i + 1;

    p[w] = l + 1;
    //cerr << s << endl;
    //cerr << n << ' ' << c << ' ' << l << endl;
    //for (int i = 0; i <= n; ++i) cerr << p[i] << ' '; cerr << endl;
    
    for (int j = 0; j < 20; ++j) {
        b[n][j] = n;
        a[n][j] = 0;
    }

    for (int i = n - 1; i >= 0; --i) {
        int pos = upper_bound(p, p + n + 1, p[i] + c + 1) - p - 1;
        //cerr << i << ' ' << pos << ' ' << pos - i << ' ' << p[pos] - p[i] << endl;
        a[i][0] = pos - i;
        b[i][0] = pos;
        for (int j = 1; j < 20; ++j) {
            if (b[i][j-1] != i) {
                b[i][j] = b[b[i][j-1]][j-1] == b[i][j-1] ? i : b[b[i][j-1]][j-1];
                a[i][j] = a[i][j-1] + a[b[i][j-1]][j-1];
            } else {
                b[i][j] = b[i][j-1];
                a[i][j] = a[i][j-1];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        //for (int j = 0; j < 4; ++j) printf("%2d,%2d        ", a[i][j], b[i][j]); puts("");
    }

    int best = 0;
    int words = 0;
    for (int i = 0; i < n; ++i) {
        int cur_w = i;
        int cur_c = 0;
        for (int k = 0; k < 20; ++k) if (r & (1 << k)) {
            cur_c += a[cur_w][k];
            if (b[cur_w][k] == cur_w) {
                break;
            } else {
                cur_w = b[cur_w][k];
            }
        }

        if (words < cur_c) {
            words = cur_c;
            best = i;
        }
    }
    //cerr << best << ' ' << words << endl;
    //cerr << a[best][0] << endl;
    
    while (words) {
        s[p[best + a[best][0]] - 1] = 0;
        puts(s + p[best]);
        words -= a[best][0];
        best += a[best][0];
    }
}

int main() {
    solve();
    return 0;
}