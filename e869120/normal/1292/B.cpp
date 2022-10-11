#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long X0, XA, XB;
long long Y0, YA, YB;
long long SX, SY, T;
vector<pair<long long, long long>> vec;

long long movement(long long vx, long long vy, long long wx, long long wy) {
	return abs(vx - wx) + abs(vy - wy);
}

int main() {
	cin >> X0 >> Y0 >> XA >> YA >> XB >> YB;
	cin >> SX >> SY >> T;

	long long cx = X0, cy = Y0;
	while (cx < (1LL << 55) && cy < (1LL << 55)) {
		vec.push_back(make_pair(cx, cy));
		cx = cx * XA + XB;
		cy = cy * YA + YB;
	}

	long long maxn = 0;
	for (int i = 0; i < vec.size(); i++) {
		for (int j = i; j < vec.size(); j++) {
			long long s1 = movement(SX, SY, vec[i].first, vec[i].second);
			long long s2 = movement(SX, SY, vec[j].first, vec[j].second);
			long long s3 = movement(vec[i].first, vec[i].second, vec[j].first, vec[j].second);
			long long r = min(s1, s2) + s3;
			if (r <= T) maxn = max(maxn, 1LL * (j - i + 1));
		}
	}

	cout << maxn << endl;
	return 0;
}