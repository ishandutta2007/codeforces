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

int a[3];

void solve() {
	int mn = Inf, sm = 0;
	loop(i, 3) scanf("%d", a + i), mn = min(mn, a[i]), sm += a[i];
	if(sm % 3) {
		puts("no"); return;
	}
	sm -= 3 * mn;
	while(sm % 6) {
		sm += 3; --mn;
	}
	int rm = mn - sm / 6;
	if(rm < 0 || rm % 3) puts("no");
	else puts("yes");
}

int main() {
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}