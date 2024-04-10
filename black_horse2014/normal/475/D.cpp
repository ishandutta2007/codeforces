#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;

typedef long long LL;

#define MX 100005
#define bit(x) (1 << (x))
int b[MX];
int n, a[MX];
int x[MX][18];
map<int, LL> M;

void init() {
    int i, k;
    
    k = 0;
    for (i = 1; i < MX; i++) {
        if (i == bit(k + 1)) k++;
        b[i] = k;
    }
}

void build() {
    int i, j;
    
    for (i = 0; i < n; i++) x[i][0] = a[i];
    for (j = 1; j < 18; j++) {
        for (i = 0; i < n; i++) {
            x[i][j] = x[i][j - 1];
            if (i + bit(j - 1) < n) x[i][j] = __gcd(x[i][j - 1], x[i + bit(j - 1)][j - 1]);
        }
    }
}

int gcd(int st, int en) {
    int j = b[en - st];
    return __gcd(x[st][j], x[en - bit(j)][j]);
}

main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
    
    int q, i, j, st, en, md, g;
    
    init();
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    build();
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j = st) {
            g = gcd(i, j + 1);
            st = (gcd(i, n) == g) ? n : j + 1;
            en = n;
            while (en - st > 1) {
                md = (st + en) / 2;
                if (gcd(i, md) == g) st = md;
                else en = md;
            }
            M[g] += st - j;
        }
    }
    for (scanf("%d", &q); q--; ) {
        scanf("%d", &g);
        printf("%I64d\n", M[g]);
    }
}