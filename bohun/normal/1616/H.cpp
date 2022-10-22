#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define cat(x) cerr << #x << " = " << x << '\n';
using ll = long long;
using namespace std;

const int P = 998244353;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (auto &x : a)
		cin >> x;
	sort(a.begin(), a.end());

	vector<int> power(n + 1);
	power[0] = 1;
	for (int i = 1; i <= n; i++)
		power[i] = 2 * power[i - 1] % P;

	auto run = [&](int bit, int l, int r) {
		while (l < r && !(a[l] >> bit & 1))
			l++;
		return l;
	};

	function<int(int, int, int, int, int)> solve = [&](int bit, int a, int b, int c, int d) -> int {
		int len1 = b - a;
		int len2 = d - c;
		if (a == b && c == d) 
			return 1;
		if (bit == -1) 
			return power[len1 + len2];

		int m1 = run(bit, a, b);
		int m2 = run(bit, c, d);

		if (x >> bit & 1) 
			return 1ll * solve(bit - 1, a, m1, m2, d) * solve(bit - 1, m1, b, c, m2) % P;
		else
			return (1ll * solve(bit - 1, a, m1, c, m2) + solve(bit - 1, m1, b, m2, d) + P - 1 + 
					+ 1ll * (power[m1 - a] - 1) * (power[b - m1] - 1)
					+ 1ll * (power[m2 - c] - 1) * (power[d - m2] - 1)) % P;
	};

	function<int(int, int, int)> go = [&](int bit, int l, int r) -> int {
		if (l == r)
			return 0;
		if (bit == -1)
			return power[r - l] - 1;

		int m = run(bit, l, r);

		if (x >> bit & 1)
			return (solve(bit - 1, l, m, m, r) + P - 1) % P;
		else
			return (go(bit - 1, l, m) + go(bit - 1, m, r)) % P;
	};

	cout << go(29, 0, n) << '\n';
	return 0;
}