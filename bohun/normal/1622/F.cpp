#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define cat(x) cerr << #x << " = " << x << '\n';
using ll = long long;
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	vector<int> prime(n + 1, 0);
	for (int i = 2; i <= n; i++) {
		if (!prime[i]) {
			for (int j = i; j <= n; j += i)
				prime[j] = i;
		}
	}

	mt19937_64 rng(233);
	vector<long long> h(n + 1);
	for (int i = 2; i <= n; i++)
		if (prime[i] == i)
			h[i] = rng();

	long long P = 0;
	vector<long long> p(n + 1);
	for (int i = 1; i <= n; i++) {
		p[i] = p[i - 1];
		int x = i;
		while (x > 1) {
			p[i] ^= h[prime[x]];
			x /= prime[x];
		}
		P ^= p[i];
	}

	auto print = [&](vector<int> erased) {
		cout << n - erased.size() << '\n';
		for (int i = 1; i <= n; i++)
			if (!count(erased.begin(), erased.end(), i))
				cout << i << ' ';
		cout << '\n';
		exit(0);
	};

	if (P == 0) print({});

	for (int i = 1; i <= n; i++)
		if (p[i] == P)
			print({i});

	map<long long, int> mp;
	for (int i = 1; i <= n; i++) {
		if (mp.count(P ^ p[i]))
			print({i, mp[P ^ p[i]]});
		mp[p[i]] = i;
	}

	assert(n % 2 == 1);
	print({2, (n - 1) / 2, n});

	return 0;
}