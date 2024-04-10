#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	vector<pair<int, int>> p(3);
	vector<int> xx(3), yy(3);
	for (int i = 0; i < 3; i++) {
		cin >> xx[i] >> yy[i];
		p[i] = {xx[i], yy[i]};
	}
	sort(xx.begin(), xx.end());
	sort(yy.begin(), yy.end());

	stringstream ss; int cnt = 0;

	int X = xx[1], Y = yy[1];
	for (auto [x, y]: p) {
		if (x == X && y == Y) continue;
		if (x == X) {
			cnt++;
			ss << x << ' ' << y << ' ' << X << ' ' << Y << '\n';
			continue;
		}
		if (y == Y) {
			cnt++;
			ss << x << ' ' << y << ' ' << X << ' ' << Y << '\n';
			continue;
		}
		{
			cnt += 2;
			ss << x << ' ' << y << ' ' << X << ' ' << y << '\n';
			ss << X << ' ' << y << ' ' << X << ' ' << Y << '\n';
		}
	}

	cout << cnt << '\n' << ss.str();

	return 0;
}