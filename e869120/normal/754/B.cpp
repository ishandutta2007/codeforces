#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int x[4][4];
int dx[8] = { 0,1,1,1,0,-1,-1,-1 }, dy[8] = { 1,1,0,-1,-1,-1,0,1 };
bool solve() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (x[i][j] != 1)continue;
			for (int k = 0; k < 8; k++) {
				vector<pair<int, int>>vec;
				vec.push_back(make_pair(i + dx[k], j + dy[k]));
				vec.push_back(make_pair(i + dx[k] * 2, j + dy[k] * 2));
				if (vec[0].first < 0 || vec[0].first >= 4 || vec[0].second < 0 || vec[0].second >= 4)continue;
				if (vec[1].first < 0 || vec[1].first >= 4 || vec[1].second < 0 || vec[1].second >= 4)continue;
				if (x[vec[0].first][vec[0].second] != 1)continue;
				if (x[vec[1].first][vec[1].second] != 1)continue;
				return true;
			}
		}
	}
	return false;
}
int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			char c; cin >> c;
			if (c == '.')x[i][j] = 0;
			if (c == 'x')x[i][j] = 1;
			if (c == 'o')x[i][j] = 2;
		}
	}
	bool flag = false;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (x[i][j] != 0)continue;
			x[i][j] = 1;
			if (solve() == true)flag = true;
			x[i][j] = 0;
		}
	}
	if (flag == true)cout << "YES" << endl;
	if (flag == false)cout << "NO" << endl;
	return 0;
}