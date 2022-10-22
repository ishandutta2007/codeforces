#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 700005;
struct fenwick {
	ll f[N];
	void add(int i, int d) {
		for (; i < N; i += i & -i)
			f[i] += d;
	}
	ll query(int i) {
		ll res = 0;
		for (; i > 0; i -= i & -i)
			res += f[i];
		return res;
	}
	ll range(int l, int r) {
		return query(r) - query(l - 1);
	}
} A, B;

int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	ll sum = 0, res = 0;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;

		res += x * i + sum;

		for (int j = 0; j <= 300000; j += x)
			res -= j * A.range(j, j + x - 1);

		res -= B.query(x);

		for (int j = x; j <= 300000; j += x)
			B.add(j, x);

		A.add(x, 1);
		sum += x;
		cout << res << " ";
	}
	return 0;
}