#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;
typedef long long LL;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define pb push_back
#define MX 1000005

#define X first
#define Y second
int m;
int x1, Y1, h1, h2, x2, y2, a1, a2;
int chk[MX][2], val[MX][2];

int main() {

    int i;
    scanf("%d", &m);
    scanf("%d%d%d%d", &h1, &a1, &x1, &Y1);
    scanf("%d%d%d%d", &h2, &a2, &x2, &y2);
    val[h1][0] = 0;
    int a = h1;
    int K1, K2, B1, B2;
    for (;;) {
        chk[a][0] = 1;
        int _a = (1LL * a * x1 + Y1) % m;
        if (chk[_a][0]) {
            K1 = -val[_a][0] + val[a][0] + 1;
            if (val[a1][0] == 0) {
                
                puts("-1");
                return 0;
            } else if (val[a1][0] < val[_a][0]) {
                K1 = -1;
            }
            B1 = val[a1][0];
            break;
        }
        val[_a][0] = val[a][0] + 1;
        a = _a;
    }

    a = h2;
    for (;;) {
        chk[a][1] = 1;
        int _a = (1LL * a * x2 + y2) % m;
        if (chk[_a][1]) {
            K2 = -val[_a][1] + val[a][1] + 1;
            if (val[a2][1] == 0) {
                
                puts("-1");
                return 0;
            } else if (val[a2][1] < val[_a][1]) {
                K2 = -1;
            }
            B2 = val[a2][1];
            break;
        }
        val[_a][1] = val[a][1] + 1;
        a = _a;
    }
    if (K1 == -1 &&  K2 == -1) {
        if (B1 == B2) {
            printf("%d\n", B1);
        } else {
            puts("-1");
        }
    } else if (K1 == -1) {
        if (B1 >= B2 && (B1 - B2) % K2 == 0) {
            printf("%d\n", B1);
        } else {
            puts("-1");
        }
    } else if (K2 == -1) {
        if (B2 >= B1 && (B2 - B1) % K1 == 0) {
            printf("%d\n", B2);
        } else {
            puts("-1");
        }
    } else {
        LL res = 1000000000000000LL;
        for (i = 0; i <= m; i++) {
            LL tmp = 1LL * i * K1 + B1;
            if (tmp >= B2 && (tmp - B2) % K2 == 0) res = min(res, tmp);
        }
        for (i = 0; i <= m; i++) {
            LL tmp = 1LL * i * K2 + B2;
            if (tmp >= B1 && (tmp - B1) % K1 == 0) res = min(res, tmp);
        }
        if (res == 1000000000000000LL) puts("-1");
        else cout << res << endl;
    }
    return 0;
}