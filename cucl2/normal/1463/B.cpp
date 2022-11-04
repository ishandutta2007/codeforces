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
int a[55];
int b[55];

void solve() {
	scanf("%d", &n);
	cont(i, n) scanf("%d", a + i);
	cont(i, n) {
		int mj = 0, xj = Inf;
		loop(j, 30) if(abs(a[i] - (1 << j)) < xj) {
			xj = abs(a[i] - (1 << j));
			mj = j;
		}
		b[i] = 1 << mj;
	}
	cont(i, n) printf("%d%c", b[i], " \n"[i == n]);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}