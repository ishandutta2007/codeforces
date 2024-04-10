#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 1e6 + 10;
const int MOD = 998244353;	

void add(ll &a, ll b) {
	a += b;
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
}	

ll pt(ll a, ll b) {
	if (!b) return 1;
	if (b & 1) return 1LL * a * pt(a, b - 1) % MOD;
	return pt(1LL * a * a % MOD, b / 2);
}		

ll n;
int fac[N], rev[N];

ll fq(ll a, ll b) {
	return 1LL * fac[a] * rev[b] % MOD * rev[a - b] % MOD;
}

int main() {
	fac[0] = rev[0] = 1;
	rep(i, 1, N - 1) {
		fac[i] = 1LL * fac[i - 1] * i % MOD;
		rev[i] = pt(fac[i], MOD - 2);
	}
	scanf ("%lld", &n);
	ll ans = 0;
	rep(i, 0, n) {
		if (i == 0) 
			add(ans, pt(pt(3, n) - 3, n));
		else {
			int c = (ll) fq(n, i) * ((pt(3, i) - 3) * pt(3, n * n - n * i) % MOD + 3 * pt((pt(3, n - i) - 1), n)) % MOD;
			if (i % 2 == 1)
				add(ans, -c);
			else
				add(ans, c);
		}
	}
	printf ("%lld\n", (pt(3, n * n) - ans + MOD) % MOD);
			
	return 0;
}