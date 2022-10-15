#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, h_, m_; cin >> n >> h_ >> m_;
		int a_ = h_ * 60 + m_;
		int d = 1440;
		while (n--) {
			int h, m; cin >> h >> m;
			int a = h * 60 + m;
			d = min(d, (a - a_ + 1440) % 1440);
		}
		int h = d / 60, m = d % 60;
		cout << h << ' ' << m << '\n';
	}
	return 0;
}