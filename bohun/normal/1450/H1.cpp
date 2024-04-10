#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()

using ll = long long;
using namespace std;

const int N = 2e5 + 50;
const int P = 998244353;

ll pw(ll a, ll b) {
	ll c = 1;
	for (; b; b >>= 1, a = a * a % P)
		if (b & 1) c = c * a % P;
	return c;
}

ll fac[N], rev[N], ans;
int n, q, b0, b1, f0, f1;
char s[N];	

ll C(int a, int b) {
	return fac[a] * rev[a - b] % P * rev[b] % P;
}

int main() {
	fac[0] = rev[0] = 1;
	rep(i, 1, N - 1) {
		fac[i] = fac[i - 1] * i % P;
		rev[i] = pw(fac[i], P - 2);
	}
	scanf("%d%d%s", &n, &q, s + 1);
	rep(i, 1, n) {
		if (s[i] == '?') 
			(i & 1 ? f1++ : f0++);
		if (s[i] == 'b')
			(i & 1 ? b1++ : b0++);
	}
	rep(s, 0, f0 + f1) {
		if ((s + f1) % 2 != (b0 + b1) % 2) continue;
		ans = (ans + abs(b0 - b1 - f1 + s) * C(f0 + f1, s)) % P;
	}
	printf("%lld\n", ans * pw(pw(2, f0 + f1), P - 2) % P);
	return 0;
}