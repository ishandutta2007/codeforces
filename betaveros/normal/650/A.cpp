#include <iostream>
#include <map>
#include <utility>
using namespace std;

map<int, int> xmap;
map<int, int> ymap;
map<pair<int, int>, int> pointmap;

/*
struct Point {
	int x;
	int y;
	bool operator<(const Point & other) const {
		if (x != other.x) return x < other.x;
		return y < other.y;
	}
}
*/

int n;
int main() {
	cin >> n;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		ans += xmap[x];
		ans += ymap[y];
		ans -= pointmap[{x, y}];

		xmap[x]++;
		ymap[y]++;
		pointmap[{x, y}]++;
	}
	cout << ans << "\n";
}