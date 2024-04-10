#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <string>
using namespace std;
#pragma warning (disable: 4996)

char c[2009][2009]; int N, K, dp[2009][2009], r[2009][2009], tp[2009][2009];

string solve(int cx, int cy) {
	if (cx + cy > 2 * N - 2) return "";
	if (cx >= N || cy >= N) return "~";

	string str = "";
	while (true) {
		str += c[cx][cy];
		if (tp[cx][cy] == 0) break;
		else if (tp[cx][cy] == 1) cx++;
		else if (tp[cx][cy] == 2) cy++;
	}
	return str;
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) scanf("%s", &c[i]);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int cost = 1; if (c[i][j] == 'a') cost = 0;
			int V1 = (1 << 30); if (i == 0 && j == 0) V1 = 0;
			if (i >= 1) V1 = min(V1, dp[i - 1][j]);
			if (j >= 1) V1 = min(V1, dp[i][j - 1]);
			dp[i][j] = V1 + cost;
		}
	}
	r[N - 1][N - 1] = 0;
	for (int i = 2 * N - 1; i >= 0; i--) {
		vector<pair<int, int>>J;
		for (int j = 0; j < N; j++) {
			int sx = j, sy = i - j; if (sy < 0 || sy >= N) continue;
			J.push_back(make_pair(sx, sy));
		}
		vector<tuple<char, int, int, int>> tup;
		for (int j = 0; j < J.size(); j++) {
			pair<char, int> I = make_pair('z', 1000000007);
			int px = J[j].first, py = J[j].second;

			if (px < N - 1 && I > make_pair(c[px][py], r[px + 1][py])) { I = min(I, make_pair(c[px][py], r[px + 1][py])); tp[px][py] = 1; }
			if (py < N - 1 && I > make_pair(c[px][py], r[px][py + 1])) { I = min(I, make_pair(c[px][py], r[px][py + 1])); tp[px][py] = 2; }

			tup.push_back(make_tuple(I.first, I.second, px, py));
		}
		sort(tup.begin(), tup.end());
		for (int j = 0; j < tup.size(); j++) r[get<2>(tup[j])][get<3>(tup[j])] = j;
	}

	vector<pair<int, int>>E; int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dp[i][j] > K) continue;
			if (ret < i + j) { ret = i + j; E.clear(); }
			if (ret == i + j) E.push_back(make_pair(i, j));
		}
	}

	if (K == 0) {
		cout << solve(0, 0) << endl;
		return 0;
	}

	string str = "~";
	for (int i = 0; i < E.size(); i++) {
		int sx = E[i].first, sy = E[i].second; string B = "";
		for (int j = 0; j <= sx + sy; j++) B += "a";

		string C1 = solve(sx + 1, sy);
		string C2 = solve(sx, sy + 1);
		B += min(C1, C2);
		str = min(str, B);
	}
	cout << str << endl;
	return 0;
}