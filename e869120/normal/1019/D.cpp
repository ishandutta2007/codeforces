#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int Debug = 1;

struct Point {
	int shogen; long long px, py;
};

bool operator<(const Point &a1, const Point &a2) {
	if (a1.shogen < a2.shogen) return true;
	if (a1.shogen > a2.shogen) return false;
	if (a1.px * a2.py > a1.py * a2.px) return true;
	return false;
}

Point operator-(const Point &a1, const Point &a2) {
	return Point{ 0, a1.px - a2.px, a1.py - a2.py };
}

int getshogen(long long cx, long long cy) {
	if (cx > 0 && cy == 0) return 0;
	if (cx == 0 && cy > 0) return 1;
	if (cx < 0 && cy == 0) return 2;
	if (cx == 0 && cy < 0) return 3;
	if (cx > 0 && cy > 0) return 0;
	if (cx < 0 && cy > 0) return 1;
	if (cx < 0 && cy < 0) return 2;
	if (cx > 0 && cy < 0) return 3;
	return -1;
}

class LargeTriangle {
public:
	vector<tuple<Point, int, int>> G;
	vector<int> ind, a;

	bool check(int N, long long S, vector<long long>X, vector<long long>Y) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					if (i == j || j == k || k == i) continue;
					Point V1 = Point{ 0, X[i], Y[i] };
					Point V2 = Point{ 0, X[j], Y[j] };
					Point V3 = Point{ 0, X[k], Y[k] };
					Point VA = V2 - V1;
					Point VB = V3 - V2;
					if (VA.px * VB.py - VA.py * VB.px == 0) return false;
				}
				if (i != j) {
					if (X[i] == X[j] && Y[i] == Y[j]) return false;
				}
			}
		}
		return true;
	}

	long long menseki(vector<pair<long long, long long>> V) {
		Point G1 = Point{ 0, V[0].first, V[0].second };
		Point G2 = Point{ 0, V[1].first, V[1].second };
		Point G3 = Point{ 0, V[2].first, V[2].second };
		Point VA = G2 - G1;
		Point VB = G3 - G1;
		return abs(VA.px * VB.py - VA.py * VB.px);
	}

	bool solve_Jury(int N, long long S, vector<long long> X, vector<long long> Y) {
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				for (int k = j + 1; k < N; k++) {
					vector<pair<long long, long long>>R;
					R.push_back(make_pair(X[i], Y[i]));
					R.push_back(make_pair(X[j], Y[j]));
					R.push_back(make_pair(X[k], Y[k]));
					if (menseki(R) == 2LL * S) return true;
				}
			}
		}
		return false;
	}

	vector<pair<long long, long long>> solve(int N, long long S, vector<long long> X, vector<long long> Y) {
		vector<int> ind(N, 0);
		vector<int> a(N, 0);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				Point L1 = Point{ 0, X[j], Y[j] }, L2 = Point{ 0, X[i], Y[i] };
				Point V = L1 - L2;
				V.shogen = getshogen(V.px, V.py);

				if (V.shogen >= 2) continue;

				G.push_back(make_tuple(V, i, j));
			}
		}
		sort(G.begin(), G.end());

		vector<tuple<long long, long long, int>> D;
		for (int i = 0; i < N; i++) D.push_back(make_tuple(-Y[i], -X[i], i));
		sort(D.begin(), D.end());
		for (int i = 0; i < D.size(); i++) {
			ind[get<2>(D[i])] = i;
			a[i] = get<2>(D[i]);
		}

		for (int i = 0; i < G.size(); i++) {
			int cl = 0, cr = D.size(), cm;
			for (int j = 0; j < 24; j++) {
				cm = (cl + cr) / 2;
				long long val = get<0>(G[i]).px * (Y[a[cm]] - Y[get<1>(G[i])]) - get<0>(G[i]).py * (X[a[cm]] - X[get<1>(G[i])]);
				if (-val == 2LL * S) {
					vector<pair<long long, long long>> ans;
					int ind1 = get<1>(G[i]); ans.push_back(make_pair(X[ind1], Y[ind1]));
					int ind2 = get<2>(G[i]); ans.push_back(make_pair(X[ind2], Y[ind2]));
					int ind3 = a[cm]; ans.push_back(make_pair(X[ind3], Y[ind3]));
					return ans;
				}
				if (-val > 2LL * S) cr = cm;
				else cl = cm;
			}
			int v1 = get<1>(G[i]), v2 = get<2>(G[i]);
			swap(a[ind[v1]], a[ind[v2]]);
			swap(ind[v1], ind[v2]);
		}
		return vector<pair<long long, long long>> {};
	}
};

int main() {
	if (Debug == 1) {
		LargeTriangle G;
		long long n, s; vector<long long> x, y;
		cin >> n >> s; x.resize(n, 0); y.resize(n, 0);
		for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

		vector<pair<long long, long long>> J = G.solve(n, s, x, y);
		if (J.size() == 0) cout << "No" << endl;
		else {
			cout << "Yes" << endl;
			for (int i = 0; i < J.size(); i++) cout << J[i].first << " " << J[i].second << endl;
		}
	}
	else {
		for (int t = 1; t <= 100000; t++) {
			LargeTriangle Z;
			long long n = 8, s = rand() % 2000LL + 1LL; vector<long long>x, y;
			for (int i = 0; i < n; i++) { x.push_back((rand() % 101LL) - 50LL); y.push_back((rand() % 101LL) - 50LL); }

			bool I = Z.check(n, s, x, y);
			if (I == true) {
				vector<pair<long long, long long>> F = Z.solve(n, s, x, y);

				if (F.size() == 0) {
					bool J = Z.solve_Jury(n, s, x, y);
					if (J == true) {
						cout << "Wrong Answer on Test #" << t + 1 << endl;
						cout << endl;
					}
				}
				else {
					long long B = Z.menseki(F);
					if (B != 2LL * s) {
						cout << "Wrong Answer on Test #" << t + 1 << endl;
						cout << endl;
					}
				}
			}
		}
	}
	return 0;
}