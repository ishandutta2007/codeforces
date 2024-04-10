/* by Natsu Kinmoe */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); ++i)
#define cont(i, n)          for(int i = 1; i <= (n); ++i)
#define circ(i, a, b)       for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

int a, b, c, d;

ll calc(int mid) {
    ll urs = 1ll * a * mid;
    ll tms = min(c / d, mid - 1);
    ll his = tms * d * (tms + 1) / 2 * b + (mid - tms - 1) * b * c;
    return urs - his;
}

void solve() {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int l = 0, r = 2000000;
    while(r - l > 5) {
        int m1 = l + (r - l) / 3, m2 = l + (r - l) * 2 / 3;
        if(calc(m1) < calc(m2)) l = m1;
        else r = m2;
    }
    if(r == 2000000) return void(puts("-1"));
    ll ans = 0;
    circ(i, l, r) ans = max(ans, calc(i));
    printf("%lld\n", ans);
}

int main() {
    int T; scanf("%d", &T);
    while(T--) solve();
    return 0;
}