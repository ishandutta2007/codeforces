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

int N;
ll t[5005], x[5005];
bool f[5005][5005];
ll g[5005];

int main() {
	scanf("%d", &N);
	cont(i, N) scanf("%lld%lld", t + i, x + i);
	memset(g, Inf, sizeof(g));
	g[0] = 0;
	loop(i, N) {
		// For g[i]
		if(g[i] <= t[i]) {
			g[i + 1] = min(g[i + 1], max(g[i] + abs(x[i + 1] - x[i]), t[i]));
			circ(j, i + 2, N) {
				if(max(g[i] + abs(x[j] - x[i]), t[i]) + abs(x[i + 1] - x[j]) <= t[i + 1]) {
					f[i + 1][j] = 1;
				}
			}
		}
		// For f[i][j]
		circ(j, i + 2, N) if(f[i][j] && abs(x[i + 1] - x[i]) + t[i] <= t[i + 1]) f[i + 1][j] = 1;
		// i == j - 1
		int j = i + 1;
		if(f[i][j]) {
			if(abs(x[j + 1] - x[i]) + t[i] <= t[j + 1]) g[j + 1] = min(g[j + 1], max(abs(x[j + 1] - x[i]) + t[i], t[j]));
			circ(k, j + 2, N) {
				if(max(t[i] + abs(x[k] - x[i]), t[j]) + abs(x[j + 1] - x[k]) <= t[j + 1]) {
					f[j + 1][k] = 1;
				}
			}
		}
	}
	if(g[N] <= t[N] || f[N - 1][N]) puts("YES");
	else puts("NO");
	return 0;
}

/**
 * 
 *   f(i, j)  i  j 
 *    g(i)  i - 1  i 
 *   f(i, j)
 *    i < j - 1 i + 1  i + 1 
 *    i == j - 1
 *     j + 1  g(j + 1) 
 *     k  j + 1  f(j + 1, k)  1
 *   g(i)
 *    i 
 *     i + 1  i  i + 1  g(i + 1)
 *     i  j  i + 1 f(i + 1, j)
 */