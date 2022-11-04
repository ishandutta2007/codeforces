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

int n, k;
int a[1 << 17], b[1 << 17];
ll sm[1 << 17];

int main() {
	scanf("%d%d", &n, &k);
	cont(i, n) scanf("%d", a + i), sm[i] = sm[i - 1] + a[i];
	cont(i, n) scanf("%d", b + i);
	if(k >= 2) {
		int mn = sm[n];
		cont(i, n - 1) mn = min(mn, b[i]);
		printf("%lld\n", max<ll>(sm[n] - mn, a[n] - b[n]));
	} else if(!k) {
		ll mx = 0;
		cont(i, n) mx = max(mx, sm[n] - sm[i - 1] - b[i]);
		printf("%lld\n", mx);
	} else {
		int mn = Inf, mn2 = Inf;
		cont(i, n) {
			if(b[i] < mn) mn2 = mn, mn = b[i];
			else if(b[i] < mn2) mn2 = b[i];
		}
		ll mx = max(0ll, sm[n] - mn - mn2);
		mn = Inf;
		cont(i, n - 1) {
			if(b[i] < mn) mn = b[i];
		}
		mx = max(mx, sm[n - 1] - mn);
		range(i, n, 2, -1) {
			mx = max(mx, sm[n] - sm[i - 1] - b[i]);
			mx = max(mx, sm[n] - sm[i] + sm[i - 1] - b[1]);
		}
		printf("%lld\n", mx);
	}
	return 0;
}

/**
 * 14:00-14:30, 30min
 * 14:30-14:50, 20min
 * 
 *   k >= 2 
 *   k == 0 
 *   k == 1 
 *   
 *    n n 
 *    1
 *    1 1
 */