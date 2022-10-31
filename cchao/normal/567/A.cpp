#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repe(i, a, b) for(int i = a; i <= b; ++i)
#define ri(a) scanf("%d", &a)
#define rii(a, b) scanf("%d%d", &a, &b)
#define riii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define rs(s) scanf("%s", s)
#define pi(n) printf("%d\n", n)
#define pia(a, n) rep(_, n) printf("%d%c", a[_], _ == n - 1 ? '\n' : ' ')
#define ria(a, n) rep(_, n) scanf("%d", &a[_])
#define Ttimes int T; ri(T); for(int ks = 1; ks <= T; ++ks)
#define IO(name) freopen(name".in", "r", stdin);freopen(name".out", "w", stdout)
#define PB push_back
#define MP make_pair
#define F first
#define S second

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int maxn = 100010;
const double eps = 1e-8;
pii a[maxn];
int aa[maxn], bb[maxn];
int main() {
    int n; ri(n);
    rep(i, n) {
        ri(a[i].F);
        a[i].S = i;
    }
    sort(a, a + n);
    rep(i, n) {
        int x = a[i].S;
        aa[x] = i ? a[i].F - a[0].F : a[1].F - a[0].F;
        bb[x] = i == n - 1 ? a[n - 1].F - a[n - 2].F : a[n - 1].F - a[i].F;
        if(aa[x] > bb[x])
            swap(aa[x], bb[x]);
        if(i) aa[x] = min(aa[x], a[i].F - a[i-1].F);
        if(i + 1 < n) aa[x] = min(aa[x], a[i+1].F - a[i].F);
    }
    rep(i, n) printf("%d %d\n", aa[i], bb[i]);


    return 0;
}