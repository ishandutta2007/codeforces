#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

vector<vector<int>> solve(int H, int W) {
	bool flag = false;
	if (H > W) {
		flag = true;
		swap(H, W);
	}
	if (H == 1 && W == 1) {
		return vector<vector<int>>{vector<int>{0}};
	}
	if (H <= 2 && W <= 3) {
		return vector<vector<int>>{};
	}
	if (H == 3 && W == 3) {
		vector<vector<int>>ret;
		vector<int> A1 = { 0, 4, 8 };
		vector<int> A2 = { 5, 6, 1 };
		vector<int> A3 = { 3, 2, 7 };
		ret.push_back(A1);
		ret.push_back(A2);
		ret.push_back(A3);
		return ret;
	}

	vector<vector<pair<int, int>>>ans;
	for (int i = 0; i < H; i++) {
		vector<pair<int, int>>R;
		if (i % 2 == 0) {
			for (int j = W - 1; j >= 0; j--) { if (j % 2 == 0) R.push_back(make_pair(i, j)); }
			for (int j = W - 1; j >= 0; j--) { if (j % 2 == 1) R.push_back(make_pair(i, j)); }
		}
		if (i % 2 == 1) {
			if (W % 2 == 1) {
				for (int j = W - 1; j >= 0; j--) { if (j % 2 == 1) R.push_back(make_pair(i, j)); }
				for (int j = W - 1; j >= 0; j--) { if (j % 2 == 0) R.push_back(make_pair(i, j)); }
			}
			else {
				for (int j = 0; j < W; j++) { if (j % 2 == 1) R.push_back(make_pair(i, j)); }
				for (int j = 0; j < W; j++) { if (j % 2 == 0) R.push_back(make_pair(i, j)); }
			}
		}
		ans.push_back(R);
	}

	vector<vector<int>> FinalAns;

	if (flag == false) {
		for (int i = 0; i < H; i++) {
			vector<int>A;
			for (int j = 0; j < W; j++) A.push_back(ans[i][j].first * W + ans[i][j].second);
			FinalAns.push_back(A);
		}
	}
	if (flag == true) {
		for (int i = 0; i < W; i++) {
			vector<int>A;
			for (int j = 0; j < H; j++) A.push_back(ans[j][i].second * H + ans[j][i].first);
			FinalAns.push_back(A);
		}
	}
	return FinalAns;
}

int main() {
	int H, W; cin >> H >> W;
	vector<vector<int>> E = solve(H, W);
	if (E.size() == 0) {
		cout << "NO" << endl;
	}
	else {
		printf("YES\n");
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) { if (j) printf(" "); printf("%d", E[i][j] + 1); }
			printf("\n");
		}
	}
	return 0;
}