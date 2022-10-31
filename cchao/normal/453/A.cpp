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

int m, n;
double sb[100010];
void mul(double *a, double *b) {
    sb[0] = 0;
    for(int i = 1; i <= m; ++i) sb[i] = sb[i-1] + b[i];
    double sum = 0;
    for(int i = m; i >= 1; --i) {
        sum += a[i];
        a[i] = a[i] * sb[i] + (1 - sum) * b[i];
    }
}

double d[100010] = {}, b[100010] = {};

int main() {
    rii(m, n);
    for(int i = 1; i <= m; ++i) b[i] = 1.0 / m;
    while(n) {
        if(n&1) mul(d, b);
        mul(b, b);
        n >>= 1;
    }
    double ans = 0;
    for(int i = 1; i <= m; ++i)
        ans += i * d[i];
    printf("%.9f\n", ans);

    return 0;
}