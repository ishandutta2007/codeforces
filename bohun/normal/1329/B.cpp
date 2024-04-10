#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
#define pc(x) __builtin_popcount(x)

using namespace std;

int t;
int d, MOD;
int pot[100];
int x[100];

void solve() {
	scanf ("%d%d", &d, &MOD);
	pot[0] = 1;
	rep(i, 1, 50) pot[i] = (LL) pot[i - 1] * 2 % MOD;
	int sz = -1;
	rep(i, 0, 31) {
		if ((1LL << i) > d) {
			sz = i - 1;
			break;
		}
	}
	rep(i, 0, sz) {
		if (i < sz) x[i] = pot[i];
		else x[i] = (d - pot[sz] + MOD + 1) % MOD;
	}
	int ans = 1;
	rep(i, 0, sz) {
		ans = (LL) ans * (x[i] + 1) % MOD;
	}
	printf ("%d\n", (ans - 1 + MOD) % MOD);
	
}
	

int main() {
	scanf ("%d", &t);
	while (t--) solve();
	
    return 0;
}