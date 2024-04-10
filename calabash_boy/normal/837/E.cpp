#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
	LL x, y;
	cin >> x >> y;
	LL g = __gcd(x, y);
	x /= g, y /= g;
	vector<LL> a;
	for (LL i = 2; i * i <= x; ++ i) {
		while (x % i == 0) {
			x /= i;
			a.push_back(i);
		}
	}
	if (x > 1) a.push_back(x);
	LL ans = 0;
	while (y) {
		LL g = y;
		for (LL i : a) {
			g = min(g, y % i);
		}
		ans += g;
		y -= g;
		vector<LL> b;
		for (LL i : a) {
			if (y % i == 0) {
				y /= i;
			}
			else {
				b.push_back(i);
			}
		}
		a.swap(b);
	}
	cout << ans << endl;
}