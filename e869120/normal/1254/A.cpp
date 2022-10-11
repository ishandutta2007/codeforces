#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

int T, H, W, K;
char c[109][109], ans[109][109];
vector<char> I;

void init() {
	for (char i = 'a'; i <= 'z'; i++) I.push_back(i);
	for (char i = 'A'; i <= 'Z'; i++) I.push_back(i);
	for (char i = '0'; i <= '9'; i++) I.push_back(i);
}

void solve() {
	vector<pair<int, int>> vec[109];
	int cnts = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (c[i][j] != 'R') continue;
			vec[cnts % K].push_back(make_pair(i, j));
			cnts++;
		}
	}

	int rem = 0, ret = 0;
	for (int i = 0; i < H; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < W; j++) {
				ans[i][j] = I[ret];
				if (c[i][j] == 'R') { rem++; }
				if (rem == vec[ret].size() && ret < K - 1) { rem = 0; ret++; }
			}
		}
		if (i % 2 == 1) {
			for (int j = W - 1; j >= 0; j--) {
				ans[i][j] = I[ret];
				if (c[i][j] == 'R') { rem++; }
				if (rem == vec[ret].size() && ret < K - 1) { rem = 0; ret++; }
			}
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) cout << ans[i][j];
		cout << endl;
	}
}

int main() {
	cin >> T; init();
	for (int i = 1; i <= T; i++) {
		cin >> H >> W >> K;
		for (int j = 0; j < H; j++) {
			for (int k = 0; k < W; k++) cin >> c[j][k];
		}
		solve();
	}
	return 0;
}