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

double ksmii(double a, int b) {
	if(!b) return 1;
	double x = ksmii(a, b >> 1);
	x *= x; if(b & 1) x *= a;
	return x;
}

int n, T;
double dp[5005][5005];
int p[5005], t[5005];

int main() {
	scanf("%d%d", &n, &T);
	cont(i, n) scanf("%d%d", p + i, t + i);
	dp[0][0] = 1;
	double ans = 0;
	cont(i, n) {
		double P = p[i] / 100.;
		double pr = 0, pm = ksmii(1 - P, t[i] - 1) * P, pp = ksmii(1 - P, t[i] - 1);
		cont(j, T) {
			pr *= 1 - P;
			pr += P * dp[i - 1][j - 1];
			if(j >= t[i]) {
				pr -= dp[i - 1][j - t[i]] * pm;
				dp[i][j] = pr + dp[i - 1][j - t[i]] * pp;
			} else {
				dp[i][j] = pr;
			}
		}
		cont(j, T) ans += dp[i][j];
	}
	printf("%.10lf\n", ans);
	return 0;
}

/**
 * 
 *   f(i, j)  j  i 
 *    0
 *    t  (1 - p)^(t - 1) * p
 *    f(i, j)  t - 1  t 
 *   f  O(nT)
 */