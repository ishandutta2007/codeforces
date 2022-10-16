#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1e5 + 7, M = 1e9 + 7;

int a[N], f[N], inv[N], fi[N];
map<int, int> cnt;

int C(int n, int k) {
	return (ll) f[n] * fi[k] % M * fi[n - k] % M;
}

signed main()
{
	IO_OP;

	f[0] = 1;
	for(int i = 1; i < N; i++) f[i] = (ll) f[i - 1] * i % M;
	inv[1] = 1;
	for(int i = 2; i < N; i++) inv[i] = M - (ll) M / i * inv[M % i] % M;
	fi[0] = 1;
	for(int i = 1; i < N; i++) fi[i] = (ll) fi[i - 1] * inv[i] % M;

	int n;
	cin >> n;
	ll sum = 0;
	for(int i = 0; i < n; i++) cin >> a[i], cnt[a[i]]++, sum += a[i];
	if(sum % n) return cout << 0 << '\n', 0;
	sum /= n;
	int pos = 0, neg = 0, zero = 0, ans = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] > sum) pos++;
		else if(a[i] < sum) neg++;
		else zero++;
	}
	if(pos == 0 && neg == 0) ans = 1;
	else if(pos >= 2 && neg >= 2) ans = 2;
	else if(pos == 1) {
		ans = neg + 1;
	} else {
		assert(neg == 1);
		ans = pos + 1;
	}

	ans = (ll) ans * C(n, zero) % M;
	ans = (ll) ans * f[pos] % M;
	ans = (ll) ans * f[neg] % M;
	for(pi p:cnt) if(p.F != sum) ans = (ll) ans * fi[p.S] % M;
	cout << ans << '\n';
}