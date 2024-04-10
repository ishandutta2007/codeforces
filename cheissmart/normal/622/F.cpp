#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, M = 1e9 + 7, N = 1e6 + 7;

int qpow(int a, int b) {
	if(b == 0) return 1;
	int t = qpow(a, b / 2);
	t = t * t % M;
	if(b & 1) return t * a % M;
	else return t;
}

int y[N], fact[N], p[N], s[N];
int n, k;

int inv(int a) {
	if(a == 1) return 1;
	return M - M / a * inv(M % a) % M;
}

int f() { // returns P(n)
	int ans = 0;
	p[0] = 1, s[k + 3] = 1;
	for(int i = 1; i <= k + 2; i++) {
		p[i] = (M + n - i) % M * p[i - 1] % M;
	}
	for(int i = k + 2; i >= 1; i--) {
		s[i] = (M + n - i) % M * s[i + 1] % M;
	}
	for(int i = 1; i <= k + 2; i++) {
		int l = i - 1;
		int r = k + 2 - i;
		int div = fact[l] * fact[r] % M;
		if(r & 1) div = (M - div) % M;
		int num = p[i - 1] * s[i + 1] % M;
		ans += y[i] * num % M * inv(div) % M;
	}
	return ans % M;
}

signed main()
{
	IO_OP;
	
	fact[0] = 1;
	for(int i = 1; i < N; i++) fact[i] = i * fact[i-1] % M;

	cin >> n >> k;
	for(int i = 1; i <= k + 2; i++) {
		y[i] = (y[i-1] + qpow(i, k)) % M;
	}
	cout << f() << endl;

}