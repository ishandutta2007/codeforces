#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;
const long double  PI =3.141592653589793238463;

#define fff(i, a, b) for (i = a; i != b; ++i)
#define ff(i, n) fff(i, 0, n)

bool cmpPairAngle (pair<long double, int> a, pair<long double, int> b) {
	return a.first < b.first;
}

int main (void) {
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	pair <long double, int> arr[n];

	int i, k, m;

	ff (i, n) {
		int x, y;
		cin >> x >> y;
		arr[i] = make_pair(atan2(y, x), i + 1);
		if (arr[i].first < 0) arr[i].first += 2 * PI;
	}

	sort(arr, &arr[n], cmpPairAngle);

	long double minAngle = 2 * PI;
	int minTempInd = -1;

	ff (i, n) {
		long double angle = arr[i].first - arr[(i - 1 + n) % n].first;
		if (angle < 0) angle += 2 * PI;
		// cout << arr[i].first << ' ' << arr[i].second << ' ' << angle << '\n';
		if (angle < minAngle) {
			minAngle = angle;
			minTempInd = i;
			// cout << "new min\n";
		}
	}

	cout << arr[minTempInd].second << ' ' << arr[(minTempInd - 1 + n) % n].second;

	return 0;
}