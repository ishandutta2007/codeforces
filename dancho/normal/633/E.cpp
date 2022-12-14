#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

struct elem {
    long long mc, mv;
};

long long fun(elem e) {
    return min(100LL * e.mv, e.mc);
}

int n, k;
int v[1 << 20];
int c[1 << 20];
multiset<long long> ms;

int stop;
elem bel[1 << 20];
long long p[1 << 20];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c[i]);
    }
    
    stop = 0;
    for (int i = n - 1; i >= 0; --i) {
        long long mxv = v[i];
        while (stop && bel[stop].mc >= c[i]) {
            mxv = max(mxv, bel[stop].mv);
            multiset<long long>::iterator it = ms.find(fun(bel[stop]));
            ms.erase(it);
            --stop;
        }
        ++stop;
        bel[stop].mv = mxv;
        bel[stop].mc = c[i];
        ms.insert(fun(bel[stop]));
        p[i] = (*ms.rbegin());
    }

    sort(p, p + n);
    double ans = 0;
    double coef = (double) k / (double) (n - k + 1.);
    for (int i = 0; i <= n - k; ++i) {
        coef = coef * (n - i - k + 1.);
        coef = coef / (n - i);
        // printf("OO %d %lf\n", i, coef);
        ans = ans + p[i] * coef;
    }
    printf("%.20lf\n", ans);
    return 0;
}