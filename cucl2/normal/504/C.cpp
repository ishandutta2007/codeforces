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

int n;
int a[1 << 17];
int cnt[1 << 17];

int main() {
    scanf("%d", &n);
    cont(i, n) scanf("%d", a + i);
    int ps = -1;
    cont(i, n) if(a[i] != a[n + 1 - i]) {
        ps = i - 1; break;
    }
    if(!~ps) return printf("%lld\n", n * (n + 1ll) / 2), 0;
    int L = ps + 1, R = n - ps;
    int ls, rs;
    auto check = [&](int mid) {
        loop(i, mid) ++cnt[a[L + i]];
        bool can = 1;
        int ji = 0, ou = 0;
        for(int l = L, r = R; l <= r; ++l, --r) {
            if(l < L + mid && r < L + mid) {
                if(l == r) ++ji;
                else ++ou;
            } else if(l < L + mid) {
                if(!cnt[a[r]]) can = 0;
                --cnt[a[r]];
            } else if(a[l] != a[r]) can = 0;
        }
        cont(i, n) {
            if(cnt[i] % 2 == 1) {
                if(!ji) can = 0;
                --ji;
            }
            ou -= cnt[i] / 2;
            if(ou < 0) can = 0;
            cnt[i] = 0;
        }
        return can;
    };
    int l = -1, r = R - L + 2;
    while(r - l > 1) {
        int m = (l + r) >> 1;
        if(check(m)) r = m;
        else l = m;
    }
    ls = r;
    auto check2 = [&](int mid) {
        loop(i, mid) ++cnt[a[R - i]];
        bool can = 1;
        int ji = 0, ou = 0;
        for(int l = L, r = R; l <= r; ++l, --r) {
            if(l > R - mid && r > R - mid) {
                if(l == r) ++ji;
                else ++ou;
            } else if(r > R - mid) {
                if(!cnt[a[l]]) can = 0;
                --cnt[a[l]];
            } else if(a[l] != a[r]) can = 0;
        }
        cont(i, n) {
            if(cnt[i] % 2 == 1) {
                if(!ji) can = 0;
                --ji;
            }
            ou -= cnt[i] / 2;
            if(ou < 0) can = 0;
            cnt[i] = 0;
        }
        return can;
    };
    l = -1, r = R - L + 1;
    while(r - l > 1) {
        int m = (l + r) >> 1;
        if(check2(m)) r = m;
        else l = m;
    }
    rs = r;
    printf("%lld\n", 1ll * (ps + 1) * (ps + 2 * (R - L + 1) + 1 - ls - rs));
    return 0;
}