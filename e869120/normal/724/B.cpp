#include <iostream>
#include <vector>
#include <map>
using namespace std;

int H, W, P[29][29]; map<vector<int>, int>Map;

void init() {
	vector<int>B; for (int i = 0; i < W; i++) B.push_back(i + 1);
	Map[B] = 1;

	for (int i = 0; i < W; i++) {
		for (int j = i + 1; j < W; j++) {
			swap(B[i], B[j]);
			Map[B] = 1;
			swap(B[i], B[j]);
		}
	}
}

bool solve() {
	bool flag = true;
	for (int i = 0; i < H; i++) {
		vector<int>A; for (int j = 0; j < W; j++) { A.push_back(P[i][j]); }
		if (Map[A] == 0) flag = false;
	}
	return flag;
}

int main() {
	cin >> H >> W;
	init();
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) cin >> P[i][j];
	}

	bool I1 = solve();

	for (int i = 0; i < W; i++) {
		for (int j = i + 1; j < W; j++) {
			for (int k = 0; k < H; k++) swap(P[k][i], P[k][j]);
			bool J = solve();
			if (J == true) I1 = true;
			for (int k = 0; k < H; k++) swap(P[k][i], P[k][j]);
		}
	}
	if (I1 == true) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}