#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define fst first
#define snd second
#define mp make_pair

#define rep(i, n) for(int i = 0; i < n; ++i)

#define ri(x) scanf("%d", &x)
#define rii(x,y) scanf("%d%d", &x, &y)
#define riii(x,y,z) scanf("%d%d%d", &x, &y, &z)
#define ria(a, n) rep(_, n) scanf("%d", &a[_])

#define pi(x) printf("%d\n", x)
#define pia(a, n) rep(_, n) printf("%d%c", a[_], _==n-1?'\n': ' ')

#define Ttimes int T; scanf("%d", &T); while(T--)

double d[1010][1010]={{}};
int main() {
    int n, m; rii(n, m);
    double ans = 0;
    d[0][0] = 1;

    rep(i, n+1) rep(j, n+1) {
        if(d[i][j] < 1e-9) continue;
        int la = m - i;
        int lb = n * m - m - j;
        //printf("at %d %d la lb %d %d\n", i, j, la, lb);
        if(la) d[i+1][j] += d[i][j] * la / (la + lb);
        if(lb) d[i][j+1] += d[i][j] * lb / (la + lb);
    }


    for(int i = 1; i <= n; ++i) {
        ans += (1. * i * i / n / n) * d[i][n-i];
    }

    printf("%.9f\n", ans * n);
    return 0;
}