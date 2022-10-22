#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pib = pair<int,bool>;
using ll = long long;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#ifdef fread_unlocked
#define fread fread_unlocked
#define fwrite fwrite_unlocked
#endif
#define mp make_pair
#define lc ind<<1
#define rc ind<<1|1
const int MN = 2e5+5, MOD = 1e9+7, BASE = 31, MASK = (1 << 10) - 1;
bool done[MN]; int go;
map<int,int> dp;
int solve (int mask) {
	if (dp.count(mask)) return dp[mask];
	int has = 0;
	for (int j = 1; j <= go; j++) if (mask>>j&1) {
		int togo = mask;
		for (int i = j; i <= go; i += j) togo &=~ (1 << i);
		has |= 1 << solve(togo);
	}
	for (int j = 0;;j++) if (has>>j&1^1) return dp[mask] = j;
}
int main () {
	int n, ret = 0;
	scanf ("%d",&n); int extra = n; dp[1073741822] = 12; dp[536870910] = 11; dp[268435454] = 6; dp[134217726] = 3;
	for (int i = 2; i * i <= n; i++) if (!done[i]) {
		int cur = 0; go = 0;
		for (ll j = i; j <= n; j *= i) {
			if (j < MN) done[j] = 1;
			cur ^= 1 << (++go); --extra;
		}
		ret ^= solve(cur);
	}
	ret ^= (extra&1);
	printf(ret ? "Vasya\n" : "Petya\n");
	return 0;
}