#include <bits/stdc++.h>
#define ll long long
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

const int N = 3e5 + 101;
const int MOD = 998244353;

ll pt(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b /= 2;
	}
	return res;
}

int n;
int a[N];
ll p[N];

ll r(int l, int r) {
	l = max(l, 1);
	return (p[r] - p[l - 1] + MOD) % MOD;
}

int main() {
	scanf ("%d", &n);
	rep(i, 1, n) 
		scanf ("%d", a + i);
	sort(a + 1, a + n + 1);
	rep(i, 1, n)
		p[i] = (a[i] + p[i - 1]) % MOD;
	rep(i, 1, n) {
		int s = n - i, g = 1;
		ll res = 0;
		while (s > 0) {
			res += r(s - i + 1, s) * g % MOD;
			res %= MOD;
			s -= i;
			g++;
		}
		printf ("%lld ", res * pt(n, MOD - 2) % MOD);
	}
	
	return 0;
}