#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 59;

struct State {
	char c[MAX_N][MAX_N];
};

int H, W;

vector<pair<int, int>> solve(State S) {
	vector<pair<int, int>>D;
	for (int t = 1; t <= 100000; t++) {
		bool flag = false;
		if (H % 2 == 0) {
			for (int i = 1; i <= H; i++) {
				for (int j = 1; j <= W; j++) {
					if (i % 2 == 1 && S.c[i][j] != 'U') flag = true;
					if (i % 2 == 0 && S.c[i][j] != 'D') flag = true;
				}
			}
		}
		else {
			for (int i = 1; i <= H; i++) {
				for (int j = 1; j <= W; j++) {
					if (j % 2 == 1 && S.c[i][j] != 'L') flag = true;
					if (j % 2 == 0 && S.c[i][j] != 'R') flag = true;
				}
			}
		}
		if (flag == false) return D;

		for (int i = 1; i <= H - 1; i++) {
			for (int j = 1; j <= W - 1; j++) {
				if (t % 2 == 1) {
					if (S.c[i][j] == 'U' && S.c[i][j + 1] == 'U' && S.c[i + 1][j] == 'D' && S.c[i + 1][j + 1] == 'D') {
						S.c[i + 0][j + 0] = 'L';
						S.c[i + 0][j + 1] = 'R';
						S.c[i + 1][j + 0] = 'L';
						S.c[i + 1][j + 1] = 'R';
						D.push_back(make_pair(i, j));
					}
				}
				if (t % 2 == 0) {
					if (S.c[i][j] == 'L' && S.c[i][j + 1] == 'R' && S.c[i + 1][j] == 'L' && S.c[i + 1][j + 1] == 'R') {
						S.c[i + 0][j + 0] = 'U';
						S.c[i + 0][j + 1] = 'U';
						S.c[i + 1][j + 0] = 'D';
						S.c[i + 1][j + 1] = 'D';
						D.push_back(make_pair(i, j));
					}
				}
			}
		}
	}
	return D;
}

int main() {
	cin >> H >> W; State T, U;
	for (int i = 1; i <= H; i++) { for (int j = 1; j <= W; j++) cin >> T.c[i][j]; }
	vector<pair<int, int>> D1 = solve(T);
	for (int i = 1; i <= H; i++) { for (int j = 1; j <= W; j++) cin >> U.c[i][j]; }
	vector<pair<int, int>> D2 = solve(U);
	vector<pair<int, int>> D3 = D1;
	for (int i = D2.size() - 1; i >= 0; i--) D3.push_back(D2[i]);

	cout << D3.size() << endl;
	for (int i = 0; i < D3.size(); i++) cout << D3[i].first << " " << D3[i].second << endl;
	return 0;
}