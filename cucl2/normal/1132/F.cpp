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
char s[505];
int dp[505][505];

int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	cont(i, n) dp[i][i] = 1;
	circ(l, 2, n) cont(i, n - l + 1) {
		int j = i + l - 1;
		dp[i][j] = dp[i][j - 1] + 1;
		circ(k, i, j - 1) if(s[k] == s[j]) {
			dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j - 1]);
		}
	}
	printf("%d\n", dp[1][n]);
	return 0;
}
/**
 * 
 *   f(l, r)  s[l..r] 
 *   
 *    s[r]  f(l, r) = f(l, r - 1) + 1
 *    s[r]  f(l, r) = min[i in [l, r), s[i] = s[r]](f(l, i) + f(i + 1, r - 1))
 *   f(1, n)  O(n^3)
 */