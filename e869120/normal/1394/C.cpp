#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int N;
int X[1 << 19], Y[1 << 19];
int minx = (1 << 30), miny = (1 << 30), maxx = -(1 << 30), maxy = -(1 << 30), mins = (1 << 30), maxs = -(1 << 30);
string S[1 << 19];

pair<int, int> solve(int border) {
	int xl = max(0, maxx - border), xr = minx + border;
	int yl = max(0, maxy - border), yr = miny + border;
	int sl = maxs - border, sr = mins + border;
	sl = max(sl, yl - xr);
	sr = min(sr, yr - xl);
	if (xl > xr || yl > yr || sl > sr) return make_pair(-1, -1);

	for (int i = sl; i <= sr; i++) {
		int vx = 0, vy = 0;
		if (i < yr - xr) {
			vx = xr;
			vy = vx + i;
		}
		else {
			vy = yr;
			vx = vy - i;
		}
		if (make_pair(vx, vy) == make_pair(0, 0)) continue;
		return make_pair(vx, vy);
	}
	return make_pair(-1, -1);
}

int main() {
	// 
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> S[i];
		for (int j = 0; j < S[i].size(); j++) {
			if (S[i][j] == 'B') X[i] += 1;
			if (S[i][j] == 'N') Y[i] += 1;
		}
	}

	// 
	for (int i = 1; i <= N; i++) {
		minx = min(minx, X[i]); maxx = max(maxx, X[i]);
		miny = min(miny, Y[i]); maxy = max(maxy, Y[i]);
		mins = min(mins, Y[i] - X[i]);
		maxs = max(maxs, Y[i] - X[i]);
	}

	// 
	int cl = 0, cr = (1 << 20), cm, minx = (1 << 20);
	pair<int, int> minid = make_pair(-1, -1);
	for (int i = 0; i < 30; i++) {
		cm = (cl + cr) / 2;
		pair<int, int> ret = solve(cm);
		if (ret == make_pair(-1, -1)) { cl = cm; }
		else { cr = cm; if (minx > cm) { minx = cm; minid = ret; } }
	}

	// 
	cout << minx << endl;
	for (int i = 0; i < minid.first; i++) cout << "B";
	for (int i = 0; i < minid.second; i++) cout << "N";
	cout << endl;
	return 0;
}