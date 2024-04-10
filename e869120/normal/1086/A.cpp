#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

int x[3], y[3]; tuple<int, int, int>tup = make_tuple((1 << 30), -1, -1);

int main() {
	cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			int c = abs(x[0] - i) + abs(x[1] - i) + abs(x[2] - i) + abs(y[0] - j) + abs(y[1] - j) + abs(y[2] - j);
			tup = min(tup, make_tuple(c, i, j));
		}
	}
	
	int sx = get<1>(tup), sy = get<2>(tup);

	vector<pair<int, int>>vec;
	for (int i = 0; i < 3; i++) {
		int cx = sx, cy = sy;
		while (cx < x[i]) { cx++; vec.push_back(make_pair(cx, cy)); }
		while (cx > x[i]) { cx--; vec.push_back(make_pair(cx, cy)); }
		while (cy < y[i]) { cy++; vec.push_back(make_pair(cx, cy)); }
		while (cy > y[i]) { cy--; vec.push_back(make_pair(cx, cy)); }
	}
	vec.push_back(make_pair(sx, sy));
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	cout << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++) cout << vec[i].first << " " << vec[i].second << endl;
	return 0;
}