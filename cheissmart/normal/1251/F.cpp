#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 3e5 + 5, M = 998244353, G = 3, K = 5;

int fact[2 * N], inverse[2 * N], fact_inverse[2 * N];
int n, k, q, a[N], b[K], qq[N];
int p1[N*2], p2[N*2];
ll ans[N];

int qpow(int a, int b) {
	if(b == 0) return 1;
	ll t = qpow(a, b / 2);
	t = t * t % M;
	if(b & 1) return t * a % M;
	else return t;
}

int inv(int a) {
	return qpow(a, M - 2);
}

int C(int n, int k) {
	return (ll) fact[n] * fact_inverse[k] % M * fact_inverse[n - k] % M;
}

int pos[N*2];

void NTT(int *a, int k, int inverse = false) {
	for(int i = 1; i < (1 << k); i++) pos[i] = ((i & 1) << (k - 1)) | (pos[i >> 1] >> 1);
	for(int i = 0; i < (1 << k); i++) if(pos[i] < i) swap(a[pos[i]], a[i]);
	for(int len = 2; len <= (1 << k); len *= 2) {
		int omega = qpow(G, M / len);
		if(inverse) omega = inv(omega);
		for(int i = 0; i < (1 << k); i += len) {
			int cur = 1;
			for(int j = i; j < i + len / 2; j++) {
				int l = a[j], r = a[j + len / 2];
				a[j] = (l + (ll)cur * r) % M;
				a[j + len / 2] = (l - (ll) cur * r % M + M) % M;
				cur = (ll) cur * omega % M;
			}
		}
	}
}

void multiply(int *p1, int *p2) { // p1 = p1 * p2
	int k = __lg(n) + 1;
	NTT(p1, k);
	NTT(p2, k);
	for(int i = 0; i < (1 << k); i++)
		p1[i] = (ll) p1[i] * p2[i] % M;
	NTT(p1, k, true);
	for(int i = 0; i < (1 << k); i++)
		p1[i] = (ll) p1[i] * inv(1 << k) % M;
}

void solve(int b) {
	memset(p1, 0, sizeof p1);
	memset(p2, 0, sizeof p2);
	vi v;
	for(int i = 0; i < n; i++)
		if(a[i] < b) v.PB(a[i]);
	int once = 0, twice = 0;
	for(int i = 0; i < v.size();) {
		int j = i;
		while(i < v.size() && v[i] == v[j]) i++;
		if(i - j == 1) once++;
		else twice++;
	}
	for(int i = 0; i <= once; i++) {
		p1[i] = (ll) C(once, i) * qpow(2, i) % M;
	}
	for(int i = 0; i <= twice * 2; i++) {
		p2[i] = C(2 * twice, i);
	}
	multiply(p1, p2);
	for(int i = 0; i < q; i++) {
		int take = qq[i] / 2 - b - 1;
		if(take >= 0 && take <= n) ans[i] += p1[take];
	}
}


signed main()
{
	IO_OP;
	
	fact[0] = 1;
	for(int i = 1; i < 2 * N; i++) fact[i] = (ll) fact[i-1] * i % M;
	inverse[1] = 1;
	for(int i = 2; i < 2 * N; i++) inverse[i] = M - (ll) M / i * inverse[M % i] % M;
	fact_inverse[0] = 1;
	for(int i = 1; i < 2 * N; i++) fact_inverse[i] = (ll) fact_inverse[i - 1] * inverse[i] % M;
 
	cin >> n >> k;
	for(int i = 0; i < n ; i++) cin >> a[i];
	sort(a, a+n);
	for(int i = 0; i < k; i++) cin >> b[i];
	cin >> q;
	for(int i = 0; i < q; i++) cin >> qq[i];
	for(int i = 0; i < k; i++) solve(b[i]);
	for(int i = 0; i < q; i++) cout << ans[i] % M << endl;
	
}