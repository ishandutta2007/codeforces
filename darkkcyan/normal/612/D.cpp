#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fff(i, f, t) for (i = f; i < t; ++i)
#define ff(i, n) fff(i, 0, n)

struct point {
	int coordinate;
	bool isStartOfLine;
};

bool cmpPoint (point a, point b) {
	if (a.coordinate == b.coordinate) {
		return a.isStartOfLine > b.isStartOfLine;
	}
	return a.coordinate < b.coordinate;
}

int main (void) {
	ios_base::sync_with_stdio(false);

	int i, m;
	vector <point> points;

	unsigned int n, k;
	cin >> n >> k;

	points.resize(2 * n);

	m = 0;
	ff (i, n) {
		cin >> points[m].coordinate >> points[m + 1].coordinate;
		points[m].isStartOfLine = true;
		points[m + 1].isStartOfLine = false;
		m += 2;
	}

	sort(points.begin(), points.end(), cmpPoint);

	vector <int> result;
	int numberOfLineOverlap = 0;

	ff (i, 2 * n) {
		if (points[i].isStartOfLine) {
			++numberOfLineOverlap;
			if (numberOfLineOverlap == k) {
				if (!result.empty() && result.back() == points[i].coordinate) {
					result.pop_back();
				} else {
					result.push_back(points[i].coordinate);
				}
			}
		} else {
			--numberOfLineOverlap;
			if (numberOfLineOverlap == k - 1) {
				result.push_back(points[i].coordinate);
			}
		}
	}

	cout << result.size() / 2 << '\n';

	for (i = 0; i < result.size(); i += 2) {
		cout << result[i] << ' ' << result[i + 1] << '\n';
	}

	return 0;
}