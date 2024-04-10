#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Point {
	long long px, py;
};

int shogen(Point V1) {
	if (V1.px == 0) {
		if (V1.py >= 0) return 1;
		return 3;
	}
	if (V1.py == 0) {
		if (V1.px >= 0) return 0;
		return 2;
	}
	if (V1.px > 0 && V1.py > 0) return 0;
	if (V1.px < 0 && V1.py > 0) return 1;
	if (V1.px < 0 && V1.py < 0) return 2;
	return 3;
}

bool operator<(const Point &a1, const Point &a2) {
	int c1 = shogen(a1), c2 = shogen(a2);
	if (c1 < c2) return true;
	if (c1 > c2) return false;

	// (3, 7) < (2, 5)
	if (a1.py * a2.px < a1.px * a2.py) return true;
	return false;
}

long long N, X[2009], Y[2009], sum;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];

	for (int i = 0; i < N; i++) {
		vector<Point>vec;
		for (int j = 0; j < N; j++) { if (i == j) continue; vec.push_back(Point{ X[j] - X[i], Y[j] - Y[i] }); }
		sort(vec.begin(), vec.end());
		
		for (int j = 0; j < vec.size(); j++) {
			int pos1 = lower_bound(vec.begin(), vec.end(), Point{ -1LL * vec[j].px, -1LL * vec[j].py }) - vec.begin();
			long long A1 = pos1 - (j + 1); if (A1 < 0) A1 += vec.size();
			long long A2 = 1LL * vec.size() - 1LL - A1;

			sum += (A1 * (A1 - 1LL) / 2LL) * (A2 * (A2 - 1LL) / 2LL);
		}
	}
	cout << sum / 2LL << endl;
	return 0;
}