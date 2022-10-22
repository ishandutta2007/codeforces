#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using pil = pair<int,ll>;
using ld = long double;
using ui = unsigned int;
using ull = unsigned long long;
using ui128 = __uint128_t;
#define all(x) (x).begin(),(x).end()
#define mp make_pair
const int MN = 8e4, MOD = 777777777;
bool good[4][4];
int dp[MN][4][4]; //dp[len][start][end]
int a[MN],seg[MN << 1], n, cntbad;
set<int> nonzero;
void update (int i, int v) {
	for (seg[i += n - 1] = v; i>1; i>>=1) {
		seg[i>>1] = (ll)seg[i] * seg[i^1] % MOD;
	}
}
int query () {
	int ret = 1;
	for (int l = n, r = n<<1;l<r;l>>=1,r>>=1) {
		if (l&1) ret = (ll)ret * seg[l++] % MOD;
		if (r&1) ret = (ll)ret * seg[--r] % MOD;
	}
	return ret;
}
int fix (int i, int v) {
	cntbad -= !good[a[i-1]][a[i]] + !good[a[i]][a[i+1]];
	if (a[i]) {
		nonzero.erase(i); auto it = nonzero.upper_bound(i);
		int nxt = *it, lst = *prev(it);
		if (lst + 1 < i) update(lst+1,1);
		if (i + 1 < nxt) update(i+1,1);
	} else {
		int lst = *--nonzero.upper_bound(i);
		update(lst+1,1);
	}
	a[i] = v;
	if (a[i]) {
		auto it = nonzero.upper_bound(i);
		int nxt = *it, lst = *prev(it);
		if (lst + 1 < i) {
			int can = 0;
			for (int j = 1; j <= 3; j++) for (int k = 1; k <= 3; k++) if (good[a[lst]][j] && good[k][a[i]]) {can += dp[i-lst-1][j][k]; if (can >= MOD) can -= MOD;}
			update(lst+1,can);
		}
		if (i + 1 < nxt) {
			int can = 0;
			for (int j = 1; j <= 3; j++) for (int k = 1; k <= 3; k++) if (good[a[i]][j] && good[k][a[nxt]]) {can += dp[nxt-i-1][j][k]; if (can >= MOD) can -= MOD;}
			update(i+1,can);
		}
		nonzero.insert(i);
	} else {
		auto it = nonzero.upper_bound(i);
		int lst = *prev(it), nxt = *it, can = 0;
		for (int j = 1; j <= 3; j++) for (int k = 1; k <= 3; k++) if (good[a[lst]][j] && good[k][a[nxt]]) {can += dp[nxt - lst - 1][j][k]; if (can >= MOD) can -= MOD;}
		update(lst+1,can);
	}
	cntbad += !good[a[i-1]][a[i]] + !good[a[i]][a[i+1]];
	return cntbad ? 0 : query();
}
int main () { 
	int q;
	scanf ("%d %d",&n,&q); nonzero.insert(0); nonzero.insert(n+1);
	for (int i = 1; i <= 3; i++) for (int j = 1; j <= 3; j++) {int a; scanf ("%d",&a); good[i][j] = a;}
	good[0][0] = good[0][1] = good[0][2] = good[0][3] = good[1][0] = good[2][0] = good[3][0] = 1;
	for (int start = 1; start <= 3; start++) {
		dp[1][start][start] = 1;
		for (int len = 2; len <= n; len++) {
			for (int lst = 1; lst <= 3; lst++) 
				for (int cur = 1; cur <= 3; cur++) 
					if (good[lst][cur]) {
						dp[len][start][cur] += dp[len-1][start][lst]; 
						if (dp[len][start][cur] >= MOD) dp[len][start][cur] -= MOD;
					}
		}
	}
	for (int i = 1; i < (n << 1); i++) seg[i] = 1;
	int sum = 0;
	for (int i = 1; i <= 3; i++) for (int j = 1; j <= 3; j++) {sum += dp[n][i][j]; if (sum >= MOD) sum -= MOD;}
	update(1,sum);
	while (q--) {
		int x,v;
		scanf ("%d %d",&x,&v);
		printf ("%d\n",fix(x,v));
	}
    return 0;
}