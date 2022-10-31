#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define fst first
#define snd second
#define mp make_pair

#define rep(i, n) for(register int i = 0; i < n; ++i)

#define ri(x) scanf("%d", &x)
#define rii(x,y) scanf("%d%d", &x, &y)
#define riii(x,y,z) scanf("%d%d%d", &x, &y, &z)
#define ria(a, n) rep(_, n) scanf("%d", &a[_])

#define pi(x) printf("%d\n", x)
#define pia(a, n) rep(_, n) printf("%d%c", a[_], _==n-1?'\n': ' ')

#define Ttimes int T; scanf("%d", &T); while(T--)

const int np = 16;
const int full = (1<<np);
int primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};

int d[110][full]={{}}, p[110][full], a[110];
bool v[110][full];

int main() {

    int s[70];
    for(register int i = 1; i < 70; ++i) {
        s[i] = 0;
        for(register int j = 0; j < np; ++j)
            if(i % primes[j] == 0)
                s[i] |= (1<<j);
    }

    int n; ri(n); ria(a, n);

    rep(i, n) rep(b, full) {
        register int e = a[i] + a[i];
        for(register int j = 1; j <= e; ++j) {
            if((s[j]&b)==0) {
                int cost = abs(j - a[i]) + d[i][b], bs = s[j] | b, ii = i + 1;
                if(!v[ii][bs] || cost < d[ii][bs]) {
                    v[ii][bs] = true;
                    d[ii][bs] = cost;
                    p[ii][bs] = j;
                }
            }
        }
    }

    int mi = d[n][0], pos = 0;
    for(register int i = 1; i < full; ++i)
        if(v[n][i] && d[n][i] < mi) {
            mi = d[n][i];
            pos = i;
        }

    int ans[110];
    for(register int i = n; i >= 1; --i) {
        int fa = p[i][pos];
        ans[i] = fa;
        pos ^= s[fa];
    }
    for(int i = 1; i <= n; ++i) printf("%d ", ans[i]);
    puts("");

    return 0;
}