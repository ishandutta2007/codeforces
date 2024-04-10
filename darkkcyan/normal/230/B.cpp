#include <bits/stdc++.h>
using namespace std;

bitset<1000010> p;
int main() {
	p[0] = p[1] = 1;
	for (long long  i = 2; i <= 1000000; ++i) {
		if (p[i]) continue;
		for (long long  f = i * i; f <= 1000000; f += i) {
			p[f] = 1;
		}
	}
	int n; cin >> n;
	while (n--) {
		long long a; cin >> a;
		long long t = (long long ) sqrt(a);
		if (t * t != a) cout << "NO\n";
		else if (p[t]) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}