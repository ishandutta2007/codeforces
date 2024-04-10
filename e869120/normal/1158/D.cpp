#include <iostream>
#include <string>
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

char hantei(Point a1, Point a2) {
	// a1 -> a2
	if (a1.px * a2.py < a1.py * a2.px) return 'R';
	return 'L';
}

char hantei2(Point a1, Point a2, Point a3) {
	return hantei(Point{ a2.px - a1.px, a2.py - a1.py }, Point{ a3.px - a2.px, a3.py - a2.py });
}

long long N, X[2009], Y[2009], maxn = -(1LL << 60), start; string S;
vector<int>vec; bool used[2009];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) { cin >> X[i] >> Y[i]; if (maxn < X[i]) { maxn = X[i]; start = i; } }
	cin >> S;

	vec.push_back(start); used[start] = true;
	for (int i = 0; i < N - 1; i++) {
		vector<pair<Point, int>> E;
		for (int j = 0; j < N; j++) {
			if (used[j] == false) E.push_back(make_pair(Point{ X[j] - X[start], Y[j] - Y[start] }, j));
		}
		sort(E.begin(), E.end());

		int V = 0;
		for (int j = 0; j < E.size(); j++) {
			int v1 = E[j].second;
			int v2 = E[(j + 1) % E.size()].second;
			if (hantei2(Point{ X[v1], Y[v1] }, Point{ X[start], Y[start] }, Point{ X[v2], Y[v2] }) == 'L') V = (j + 1) % E.size();
		}
		if (S[i] == 'L') {
			start = E[V].second;
			vec.push_back(start); used[start] = true;
		}
		else {
			start = E[(V + E.size() - 1) % E.size()].second;
			vec.push_back(start); used[start] = true;
		}
	}

	Point A1 = Point{ X[vec[vec.size() - 3]], Y[vec[vec.size() - 3]] };
	Point A2 = Point{ X[vec[vec.size() - 2]], Y[vec[vec.size() - 2]] };
	Point A3 = Point{ X[vec[vec.size() - 1]], Y[vec[vec.size() - 1]] };

	if (hantei2(A1, A2, A3) != S[S.size() - 1]) swap(vec[vec.size() - 2], vec[vec.size() - 1]);

	for (int i = 0; i < vec.size(); i++) { if (i) cout << " "; cout << vec[i] + 1; } cout << endl;
	return 0;
}