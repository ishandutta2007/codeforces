#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;

int mod;
int n;

ll pt(ll a, ll b) {
	if(b == 0) return 1;
	if(b & 1) return 1ll * a * pt(a, b - 1) % mod;
	return pt(1ll * a * a % mod, b / 2);
}

ll ans = 0;
ll fac[300005];

int main () {

	scanf("%d %d", &n, &mod);

	fac[0] = 1;
	for(int i = 1; i <= 300000; ++i)
		fac[i] = 1ll * fac[i - 1] * i % mod;

	for(int dl = 1; dl <= n; ++dl) {
		ans = (ans + 1ll * (n - dl + 1) * (n - dl + 1) % mod * fac[dl] % mod * fac[n - dl] % mod) % mod;
	}
	printf("%lld", ans);


	return 0;
}