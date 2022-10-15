#include <iostream>
#include <cassert>

using namespace std;

typedef long long ll;
const int M = (int)1e9 + 7;

int add(int a, int b) {
	a += b;
	if (a >= M) return a - M;
	if (a < 0) return a + M;
	return a;
}

int mul(int a, int b) {
	return a * (ll)b % M;
}

int pw(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1) r = mul(r, a);
		a = mul(a, a);
		b /= 2;
	}
	return r;
}

int dv(int a, int b) {
	return mul(a, pw(b, M - 2));
}

void addup(int& a, int b) {
	a = add(a, b);
}

void mulup(int& a, int b) {
	a = mul(a, b);
}

const int N = (int)2e6 + 7;
int fact[N];
int ifact[N];

int comb(int n, int k) {
	assert(0 <= k && k <= n && n < N);
	return mul(fact[n], mul(ifact[k], ifact[n - k]));
}

int cntways(int cnt, int sum) {
	assert(1 <= cnt && cnt <= sum && sum < N);
	/// fix the partial sums
	return comb(sum - 1, cnt - 1);
}

int cailey(int n, int k) {
	if (n == k) {
		return 1;
	}
	assert(0 <= k && k < n);
	return mul(k, pw(n, n - k - 1));
}

int solve(int n, int m) {
	int sol = 0;
	for (int edges = 1; edges <= min(n - 1, m); edges++) {
		int ways = 1;
		mulup(ways, cntways(edges, m));
		mulup(ways, cailey(n, edges + 1));
		mulup(ways, fact[edges - 1]);
		mulup(ways, comb(n - 2, edges - 1));
		mulup(ways, pw(m, n - 1 - edges));

		addup(sol, ways);
	}
	return sol;
}

int main() {


	fact[0] = 1;
	for (int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
	ifact[N - 1] = dv(1, fact[N - 1]);
	for (int i = N - 2; i >= 0; i--) ifact[i] = mul(ifact[i + 1], i + 1);


	int n, m, a, b;
	cin >> n >> m >> a >> b;
	int sol = solve(n, m);
	cout << sol << "\n";
}