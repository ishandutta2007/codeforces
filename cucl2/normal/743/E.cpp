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
int dp[1005][265];
int a[1005];
int qzh[1005][9], pos[1005][9];

bool inline check(int l) {
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	loop(i, n) loop(j, 256) {
		if(!dp[i][j]) continue;
		dp[i + 1][j] = 1;
		loop(k, 8) if(!((j >> k) & 1)) {
			if(!pos[qzh[i][k] + l][k]) continue;
			dp[pos[qzh[i][k] + l][k]][j | (1 << k)] = 1;
		}
	}
	return dp[n][255];
}

void inline chmax(int &a, int b) {a = max(a, b);}

int inline getans(int l) {
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	loop(i, n) loop(j, 256) {
		if(!~dp[i][j]) continue;
		chmax(dp[i + 1][j], dp[i][j]);
		loop(k, 8) {
			if(!l) chmax(dp[i][j | (1 << k)], dp[i][j]);
			if(!((j >> k) & 1)) {
				if(l && pos[qzh[i][k] + l][k]) chmax(dp[pos[qzh[i][k] + l][k]][j | (1 << k)], dp[i][j]);
				if(pos[qzh[i][k] + l + 1][k]) chmax(dp[pos[qzh[i][k] + l + 1][k]][j | (1 << k)], dp[i][j] + 1);
			}
		}
	}
	return dp[n][255];
}

int main() {
	scanf("%d", &n);
	cont(i, n) scanf("%d", a + i), --a[i];
	cont(i, n) {
		loop(j, 8) qzh[i][j] = qzh[i - 1][j] + (a[i] == j);
		pos[qzh[i][a[i]]][a[i]] = i;
	}
	int l = 0, r = n + 1;
	while(r - l > 1) {
		int m = (l + r) >> 1;
		if(check(m)) l = m;
		else r = m;
	}
	printf("%d\n", getans(l) + (l << 3));
	return 0;
}

/**
 * 15:00-15:15, 15min
 * 15:15-15:30, 15min
 * 
 *   l
 *    f(i, j)  i j
 *    l  j 
 *    f(*, {1..8})  1 l 
 *   dp l  l + 1  dp  l + 1 
 */