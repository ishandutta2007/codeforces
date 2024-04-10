#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
#pragma warning (disable: 4996)

int N, K, A[100009];
int Debug = 1;

string ask(int p1, int p2) {
	if (p2 == N + 1) return "TAK";

	if (Debug == 1) {
		cout << "1 " << p1 << " " << p2 << endl;
		string str; cin >> str;
		return str;
	}
	if (Debug == 2) {
		int v1 = (1 << 30); for (int i = 0; i < K; i++) v1 = min(v1, abs(A[i] - p1));
		int v2 = (1 << 30); for (int i = 0; i < K; i++) v2 = min(v2, abs(A[i] - p2));
		if (v1 > v2) return "NIE";
		return "TAK";
	}
}

int solve(int pl, int pr) {
	if (pl >= pr) return -1;

	int cl = pl, cr = pr, cm, ret1 = (1 << 30); bool flag = true;
	for (int i = 0; i < 18; i++) {
		cm = (cl + cr) / 2;
		string V = ask(cm, cm + 1);
		if (V == "TAK") { cr = cm; ret1 = min(ret1, cm); }
		else { cl = cm; flag = false; }
	}

	if (ret1 == (1 << 30) || flag == true) {
		if (pl == 1 && pr == N + 1) return ret1;
		if (pr == N + 1) {
			string W1 = ask(pl - 1, pl);
			string W2 = ask(pl, pl - 1);
			if (W1 == W2) return pl;
			return -1;
		}
		return 1;
	}
	return ret1;
}

pair<int, int> solve() {
	int Z1 = solve(1, N + 1);
	int Z2 = solve(Z1 + 1, N + 1); if (Z2 >= 1) return make_pair(Z1, Z2);
	int Z3 = solve(1, Z1); if (Z3 >= 1) return make_pair(Z1, Z3);
	return make_pair(-1, -1);
}

int main() {
	if (Debug == 1) {
		cin >> N >> K;
		pair<int, int> Z = solve();
		cout << "2 " << Z.first << " " << Z.second << endl;
	}
	if (Debug == 2) {
		cin >> N >> K; for (int i = 0; i < K; i++) cin >> A[i];
		pair<int, int> Z = solve();
		cout << "2 " << Z.first << " " << Z.second << endl;
	}
	return 0;
}