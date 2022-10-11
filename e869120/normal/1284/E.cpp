#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

struct Point {
	long long shogen, px, py;
};

bool operator<(const Point& a1, const Point& a2) {
	if (a1.shogen < a2.shogen) return true;
	if (a1.shogen > a2.shogen) return false;
	if (a1.py * a2.px < a1.px * a2.py) return true;
	return false;
}

int getshogen(long long vx, long long vy) {
	if (vy == 0 && vx > 0) return 0;
	if (vy == 0 && vx < 0) return 2;
	if (vx == 0 && vy > 0) return 1;
	if (vx == 0 && vy < 0) return 3;
	if (vx > 0 && vy > 0) return 0;
	if (vx < 0 && vy > 0) return 1;
	if (vx < 0 && vy < 0) return 2;
	if (vx > 0 && vy < 0) return 3;
	return -1;
}

long long N, X[1 << 18], Y[1 << 18];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];

	// 
	long long Answer = 0;

	for (int i = 1; i <= N; i++) {
		vector<Point> vec;
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			long long sx = X[j] - X[i], sy = Y[j] - Y[i];
			vec.push_back(Point{ getshogen(sx,sy),sx,sy });
		}
		sort(vec.begin(), vec.end());

		long long ret = (N - 4LL) * (N - 1LL) * (N - 2LL) * (N - 3LL) / 24LL;
		for (int j = 0; j < vec.size(); j++) {
			Point anti = vec[j];
			anti.px *= -1LL; anti.py *= -1LL; anti.shogen = getshogen(anti.px, anti.py);
			int pos1 = lower_bound(vec.begin(), vec.end(), anti) - vec.begin();
			long long r = pos1 - j; if (r <= 0) r += (N - 1);
			ret -= (r - 3LL) * (r - 1LL) * (r - 2LL) / 6LL;
		}
		Answer += ret;
	}
	cout << Answer << endl;
	return 0;
}