#include <iostream>
#include <set>

using namespace std;

int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, a % b);
}

int main() {

	int n, x0, y0;
	cin >> n >> x0 >> y0;

	set<pair<int, int> > coords;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		x -= x0;
		y -= y0;

		if (y < 0) {
			y = -y;
			x = -x;
		}

		int g = gcd(x, y);
		x /= g;
		y /= g;
		coords.insert(make_pair(x, y));
	}
	cout << coords.size() << "\n";

}