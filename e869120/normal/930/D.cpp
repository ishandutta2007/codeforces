#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

class BIT {
public:
	vector<int> bit; int size_ = 0;

	void init(int sz) {
		size_ = sz + 2;
		bit.resize(size_ + 2, 0);
	}
	void add(int pos, int x) {
		pos++;
		while (pos <= size_) {
			bit[pos] += x;
			pos += (pos&-pos);
		}
	}
	int sum(int pos) {
		int s = 0; pos++;
		while (pos >= 1) {
			s += bit[pos];
			pos -= (pos&-pos);
		}
		return s;
	}
};

const int MAX_N = 100000;
int xl[MAX_N * 2 + 1], xr[MAX_N * 2 + 1], yl[MAX_N * 2 + 1], yr[MAX_N * 2 + 1];
vector<int> F[MAX_N * 2 + 1][2];

long long solve(vector<pair<int, int>> vec, int mask) {
	for (int i = 0; i <= MAX_N * 2; i++) { F[i][0].clear(); F[i][1].clear(); xl[i] = (1 << 30); xr[i] = -(1 << 30); yl[i] = (1 << 30); yr[i] = -(1 << 30); }
	for (int i = 0; i < vec.size(); i++) {
		xl[vec[i].first] = min(xl[vec[i].first], vec[i].second);
		xr[vec[i].first] = max(xr[vec[i].first], vec[i].second);
		yl[vec[i].second] = min(yl[vec[i].second], vec[i].first);
		yr[vec[i].second] = max(yr[vec[i].second], vec[i].first);
	}
	for (int i = 1; i <= MAX_N * 2; i++) xl[i] = min(xl[i], xl[i - 1] + 1);
	for (int i = 1; i <= MAX_N * 2; i++) xr[i] = max(xr[i], xr[i - 1] - 1);
	for (int i = 1; i <= MAX_N * 2; i++) yl[i] = min(yl[i], yl[i - 1] + 1);
	for (int i = 1; i <= MAX_N * 2; i++) yr[i] = max(yr[i], yr[i - 1] - 1);
	for (int i = MAX_N * 2 - 1; i >= 0; i--) xl[i] = min(xl[i], xl[i + 1] + 1);
	for (int i = MAX_N * 2 - 1; i >= 0; i--) xr[i] = max(xr[i], xr[i + 1] - 1);
	for (int i = MAX_N * 2 - 1; i >= 0; i--) yl[i] = min(yl[i], yl[i + 1] + 1);
	for (int i = MAX_N * 2 - 1; i >= 0; i--) yr[i] = max(yr[i], yr[i + 1] - 1);

	for (int i = 0; i <= MAX_N * 2; i++) {
		if (yl[i] + 1 <= yr[i] - 1) { F[yl[i] + 1][0].push_back(i); F[yr[i] - 1][1].push_back(i); }
	}

	BIT ZA; ZA.init(MAX_N * 2 + 1);
	BIT ZB; ZB.init(MAX_N * 2 + 1);
	long long res = 0;
	for (int i = 0; i <= MAX_N * 2; i++) {
		for (int j = 0; j < F[i][0].size(); j++) {
			if (F[i][0][j] % 2 == 0) ZA.add(F[i][0][j], 1);
			if (F[i][0][j] % 2 == 1) ZB.add(F[i][0][j], 1);
		}
		if (xl[i] + 1 <= xr[i] - 1) {
			if (i % 2 == mask) res += ZA.sum(xr[i] - 1) - ZA.sum(xl[i]);
			if (i % 2 != mask) res += ZB.sum(xr[i] - 1) - ZB.sum(xl[i]);
		}
		for (int j = 0; j < F[i][1].size(); j++) {
			if (F[i][1][j] % 2 == 0) ZA.add(F[i][1][j], -1);
			if (F[i][1][j] % 2 == 1) ZB.add(F[i][1][j], -1);
		}
	}
	return res;
}

int main() {
	int N; vector<pair<int, int>> vec1, vec2;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int px, py; scanf("%d%d", &px, &py);
		px += MAX_N; py += MAX_N;
		if ((px + py) % 2 == 0) vec1.push_back(make_pair(px, py));
		if ((px + py) % 2 == 1) vec2.push_back(make_pair(px, py));
	}

	long long I1 = solve(vec1, 1);
	long long I2 = solve(vec2, 0);
	cout << I1 + I2 << endl;
	return 0;
}