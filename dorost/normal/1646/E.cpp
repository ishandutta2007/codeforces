/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012, M = 1012 * 1012;
bool p[M];
vector <pair <int, int>> divs[M];

int tav(int x, int n) {
	if (n == 0)
		return 1;
	int ans = tav(x, n / 2);
	ans = ans * ans;
	if (n % 2) {
		ans *= x;
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i < M; i++)
		p[i] = true;
	p[1] = false;
	for (int i = 2; i < M; i++) {
		if (!p[i])
			continue;
		divs[i].push_back(make_pair(i, 1));
		for (int j = i * 2; j < M; j += i) {
			p[j] = false;
			int x = j, c = 0;
			while (x % i == 0)
				x /= i, c++;
			divs[j].push_back(make_pair(i, c));
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			ans++;
			continue;
		}
		int x = 0;
		for (auto [a, b] : divs[i]) {
			x = __gcd(x, b);
		}
		if (x == 1) {
			ans += m;
			continue;
		}
		int sum = m;
		int nsk = (1 << (x - 1));
		for (int msk = 1; msk < nsk; msk++) {
			int mask = msk;
			int lcm = x;
			int z = 1;
			for (int j = 1; j < x; j++) {
				if (mask % 2) {
					z *= -1;
					lcm = lcm * j / __gcd(lcm, j);
				}
				mask /= 2;
			}
			lcm /= x;
			int mn;
			mn = m / lcm;
			mask = msk;
			for (int j = 1; j < x; j++) {
				if (mask % 2) {
					mn = min(mn, m / (lcm * x / j));
				}
				mask /= 2;
			}
			sum += mn * z;
		}
		ans += (sum);
	}
	cout << ans;
}