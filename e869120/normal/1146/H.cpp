#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Point { int shogen; long long px, py; };

int shogen1(Point a1) {
	if (a1.px > 0 && a1.py == 0) return 1;
	if (a1.px == 0 && a1.py > 0) return 2;
	if (a1.px < 0 && a1.py == 0) return 3;
	if (a1.px == 0 && a1.py < 0) return 4;

	if (a1.px >= 0 && a1.py >= 0) return 1;
	if (a1.px <= 0 && a1.py >= 0) return 2;
	if (a1.px <= 0 && a1.py <= 0) return 3;
	return 4;
}

bool operator<(const Point &a1, const Point &a2) {
	int Z1 = a1.shogen, Z2 = a2.shogen;
	if (Z1 < Z2) return true;
	if (Z1 > Z2) return false;
	if (a1.px * a2.py > a1.py * a2.px) return true;
	return false;
}

Point operator+(const Point &a1, const Point &a2) {
	return Point{ 0, a1.px + a2.px, a1.py + a2.py };
}

Point operator-(const Point &a1, const Point &a2) {
	return Point{ 0, a1.px - a2.px, a1.py - a2.py };
}

int N; Point G[309]; vector<Point>H[309];

long long find_four() {
	long long V = 5LL * N * (N - 1LL) * (N - 2LL) * (N - 3LL) * (N - 4LL) / 120LL;
	for (int i = 0; i < N; i++) {
		vector<Point>E;
		for (int j = 0; j < N; j++) { if (i != j) { E.push_back(G[j] - G[i]); E[E.size() - 1].shogen = shogen1(E[E.size() - 1]); } }
		sort(E.begin(), E.end());
		for (int j = 0; j < N - 1; j++) { E.push_back(E[j]); E[E.size() - 1].shogen += 4; }

		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			Point Z1 = G[j] - G[i], Z2 = G[i] - G[j]; Z1.shogen = shogen1(Z1); Z2.shogen = shogen1(Z2); if (Z1.shogen > Z2.shogen) Z2.shogen += 4;
			int pos1 = lower_bound(E.begin(), E.end(), Z1) - E.begin(); pos1++;
			int pos2 = lower_bound(E.begin(), E.end(), Z2) - E.begin();
			long long K = pos2 - pos1;
			V -= K * (K - 1LL) * (K - 2LL) / 6LL;
		}
	}
	return V;
}

long long dot(Point a1, Point a2) {
	return a1.px * a2.py - a1.py * a2.px;
}

long long find_three() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) { if (i != j) { H[i].push_back(G[j] - G[i]); H[i][H[i].size() - 1].shogen = shogen1(H[i][H[i].size() - 1]); } }
		sort(H[i].begin(), H[i].end()); for (int k = 0; k < N - 1; k++) { H[i].push_back(H[i][k]); H[i][H[i].size() - 1].shogen += 4; }
	}

	long long V = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			vector<Point>EI = H[i], EJ = H[j];

			for (int k = 0; k < N; k++) {
				if (i == k || j == k) continue;
				long long L = dot(G[j] - G[i], G[k] - G[i]); if (L < 0) continue;

				Point Z1 = G[i] - G[j]; Z1.shogen = shogen1(Z1);
				Point Z2 = G[i] - G[k]; Z2.shogen = shogen1(Z2); if (Z1.shogen > Z2.shogen) Z2.shogen += 4;
				int pos1 = lower_bound(EI.begin(), EI.end(), Z1) - EI.begin();
				int pos2 = lower_bound(EI.begin(), EI.end(), Z2) - EI.begin();

				Point Z3 = G[j] - G[k]; Z3.shogen = shogen1(Z3);
				Point Z4 = G[j] - G[i]; Z4.shogen = shogen1(Z4); if (Z3.shogen > Z4.shogen) Z4.shogen += 4;
				int pos3 = lower_bound(EJ.begin(), EJ.end(), Z3) - EJ.begin();
				int pos4 = lower_bound(EJ.begin(), EJ.end(), Z4) - EJ.begin();

				long long K1 = pos2 - pos1;
				long long K2 = pos4 - pos3;
				V += K1 * K2;
			}
		}
	}
	return V;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) { cin >> G[i].px >> G[i].py; G[i].shogen = shogen1(G[i]); }
	long long E1 = N * (N - 1LL) * (N - 2LL) * (N - 3LL) * (N - 4LL) / 120LL;
	long long E2 = find_four();
	long long E3 = find_three();
	cout << E1 - E2 + E3 << endl;
	return 0;
}