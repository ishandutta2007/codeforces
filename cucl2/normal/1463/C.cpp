/* by Hyperhydrochloric Acid */
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
int t[1 << 17], x[1 << 17];

void solve() {
	scanf("%d", &n);
	cont(i, n) scanf("%d%d", t + i, x + i);
	int pos = 0, dst = 0, ans = 0;
	cont(i, n) {
		if(pos == dst) {
			dst = x[i];
		}
		int to = pos;
		if(i == n) {
			to = dst;
		} else {
			if(pos > dst) to = max(dst, pos - (t[i + 1] - t[i]));
			else to = min(dst, pos + (t[i + 1] - t[i]));
		}
		if(min(pos, to) <= x[i] && x[i] <= max(pos, to)) ++ans;
		pos = to;
	}
	printf("%d\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}