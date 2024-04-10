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

int n; double a[110];

double f(int l, int r) {
    double all = 1.0, ret = 0;
    for(int i = l; i <= r; ++i) all *= (1 - a[i]);
    for(int i = l; i <= r; ++i) ret += a[i] * all / (1 - a[i]);
    return ret;
}

int main() {
    ri(n); rep(i, n) scanf("%lf", &a[i]);
    sort(a, a+n);
    double ans = a[n-1];
    for(int i = 0; i < n; ++i)
        for(int j = i; j < n; ++j)
            ans = max(ans, f(i, j));
    printf("%.9f\n", ans);
    return 0;
}