#include <iostream>

using namespace std;

typedef long long ll;

int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, a % b);
}

int amts[1000005][26];

int main() {
	ios::sync_with_stdio(0);

	ll n, m;
	string x, y;
	cin >> n >> m >> x >> y;
	int g = gcd(x.size(), y.size());
	for (unsigned int i = 0; i < x.size(); ++i)
		++amts[i % g][x[i] - 'a'];
	ll mis = 0;
	for (unsigned int i = 0; i < y.size(); ++i)
		mis += x.size() / g - amts[i % g][y[i] - 'a'];
	ll lcm = (x.size() / g) * ((ll) y.size());
	cout << ((x.size() * n) / lcm) * mis << "\n";

	return 0;
}