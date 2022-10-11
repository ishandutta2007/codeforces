#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

long long norm(long long a, long long b) {
	return a*a + b*b;
}
long double args(long long a, long long b) {
	if (b < 0) { a *= -1; b *= -1; }
	if (a == 0 && b == 0) return 0;
	long double F = 1.0L*a / sqrtl(1.0L*(a*a + b*b));
	long double G = acos(F);
	return G*180.0L / 3.14159265358979323L;
}

struct State { long double rad; long long ex, ey; vector<pair<int, int>>A; };
bool operator<(const State &a1, const State &a2) {
	if (a1.rad < a2.rad) return true;
	return false;
}

long long n, x[100009], y[100009], c[100009], B = 1000000000000LL;
vector<State>T;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		T.push_back(State{ args(x[i], y[i]), x[i], y[i], vector<pair<int,int>>{make_pair(i,1)} });
	}
	
	while (true) {
		sort(T.begin(), T.end());
		vector<State>U;
		for (int i = 0; i < (int)T.size() - 1; i += 2) {
			long long ax = T[i].ex, ay = T[i].ey;
			long long bx = T[i + 1].ex, by = T[i + 1].ey;
			if (norm(ax + bx, ay + by) <= B) {
				State G;
				for (int j = 0; j < T[i].A.size(); j++) G.A.push_back(T[i].A[j]);
				for (int j = 0; j < T[i + 1].A.size(); j++) G.A.push_back(T[i + 1].A[j]);
				G.ex = ax + bx; G.ey = ay + by;
				G.rad = args(G.ex, G.ey);
				U.push_back(G);
			}
			else if (norm(ax - bx, ay - by) <= B) {
				State G;
				for (int j = 0; j < T[i].A.size(); j++) G.A.push_back(T[i].A[j]);
				for (int j = 0; j < T[i + 1].A.size(); j++) G.A.push_back(make_pair(T[i + 1].A[j].first, T[i + 1].A[j].second*-1));
				G.ex = ax - bx; G.ey = ay - by;
				G.rad = args(G.ex, G.ey);
				U.push_back(G);
			}
			else {
				U.push_back(T[i]);
				U.push_back(T[i + 1]);
			}
		}
		if (T.size() % 2 == 1) U.push_back(T[T.size() - 1]);
		if (T.size() == U.size()) break;
		T = U;
	}
	
	State FinalAnswer; FinalAnswer.ex = (1 << 30); FinalAnswer.ey = (1 << 30);

	for (int i = 0; i < (1 << T.size()); i++) {
		State G; G.ex = 0; G.ey = 0; G.A = vector<pair<int, int>>{};
		for (int j = 0; j < T.size(); j++) {
			if ((i / (1 << j)) % 2 == 0) {
				G.ex += T[j].ex; G.ey += T[j].ey;
				for (int k = 0; k < T[j].A.size(); k++) G.A.push_back(T[j].A[k]);
			}
			else {
				G.ex -= T[j].ex; G.ey -= T[j].ey;
				for (int k = 0; k < T[j].A.size(); k++) G.A.push_back(make_pair(T[j].A[k].first, T[j].A[k].second * -1));
			}
		}
		if (norm(FinalAnswer.ex, FinalAnswer.ey) > norm(G.ex, G.ey)) {
			FinalAnswer = G;
		}
	}
	for (int i = 0; i < FinalAnswer.A.size(); i++) c[FinalAnswer.A[i].first] = FinalAnswer.A[i].second;
	for (int i = 1; i <= n; i++) { if (i >= 2) cout << " "; cout << c[i]; } cout << endl;
	return 0;
}