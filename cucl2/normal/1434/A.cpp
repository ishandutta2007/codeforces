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

int a[6];
int n;
const int maxn = 1 << 17;
int b[maxn];

struct segt {
    int dt[maxn << 1];
    void inline init() {memset(dt, Inf, sizeof(dt));}
    void inline add(int a, int x) {
        a += maxn; dt[a] = x;
        while(a >>= 1) dt[a] = min(dt[a << 1], dt[a << 1 | 1]);
    }
} seg;

int main() {
    seg.init();
    loop(i, 6) scanf("%d", a + i);
    scanf("%d", &n);
    cont(i, n) scanf("%d", b + i);
    cont(i, n) seg.add(i, -1);
    sort(a, a + 6); sort(b + 1, b + n + 1);
    vector<pair<int, pair<int, int> > > ms;
    cont(i, n) loop(j, 6) ms.pub(mak(b[i] - a[j], mak(i, j)));
    sort(all(ms));
    int ans = Inf;
    loop(i, SZ(ms)) {
        int val = ms[i].first;
        int ni = ms[i].second.first, nj = ms[i].second.second;
        seg.add(ni, val);
        if(seg.dt[1] == -1) continue;
        ans = min(ans, val - seg.dt[1]);
    }
    printf("%d\n", ans);
    return 0;
}