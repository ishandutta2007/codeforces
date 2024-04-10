#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int H, W, A1[309], A2[309], B1[309], B2[309], P1[309], P2[309], NextA[309], NextB[309]; string S1[309][309], S2[309][309], S3[309][309];
vector<tuple<int, int, int, int>>tup;

int sz = 0, Debug = 1;

void simulate() {
	if (Debug == 1) return;

	for (int i = sz; i < tup.size(); i++) {
		int ex = get<0>(tup[i]), ey = get<1>(tup[i]), fx = get<2>(tup[i]), fy = get<3>(tup[i]);
		string V = ""; V += S3[ex][ey][(int)S3[ex][ey].size() - 1];
		V += S3[fx][fy];
		S3[fx][fy] = V;
		S3[ex][ey] = S3[ex][ey].substr(0, (int)S3[ex][ey].size() - 1);
	}
	sz = tup.size();
}

int main() {
	cin >> H >> W;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) { cin >> S1[i][j]; S3[i][j] = S1[i][j]; }
	}
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) cin >> S2[i][j];
	}
	for (int i = 1; i <= H; i++) { if (i == H) NextA[i] = 1; else NextA[i] = i + 1; }
	for (int i = 1; i <= W; i++) { if (i == W) NextB[i] = 1; else NextB[i] = i + 1; }

	// Step 1. 
	for (int i = 1; i <= H; i++) {
		for (int j = 2; j <= W - 1; j++) {
			for (int k = S1[i][j].size() - 1; k >= 0; k--) {
				if (S1[i][j][k] == '0') { A1[i]++; tup.push_back(make_tuple(i, j, i, 1)); }
				if (S1[i][j][k] == '1') { A2[i]++; tup.push_back(make_tuple(i, j, i, W)); }
			}
		}
		for (int k = S1[i][1].size() - 1; k >= 0; k--) {
			if (S1[i][1][k] == '0') { A1[NextA[i]]++; tup.push_back(make_tuple(i, 1, NextA[i], 1)); }
			if (S1[i][1][k] == '1') { A2[i]++; tup.push_back(make_tuple(i, 1, i, W)); }
		}
		for (int k = S1[i][W].size() - 1; k >= 0; k--) {
			if (S1[i][W][k] == '0') { A1[i]++; tup.push_back(make_tuple(i, W, i, 1)); }
			if (S1[i][W][k] == '1') { A2[NextA[i]]++; tup.push_back(make_tuple(i, W, NextA[i], W)); }
		}
	}

	simulate();

	// Step 1-2.
	for (int i = 1; i <= H; i++) { P1[i] = A1[i]; P2[i] = A2[i]; }
	for (int i = 1; i <= H; i++) {
		for (int j = 2; j <= W - 1; j++) {
			for (int k = S2[i][j].size() - 1; k >= 0; k--) {
				if (S2[i][j][k] == '0') P1[i]--;
				if (S2[i][j][k] == '1') P2[i]--;
			}
		}
	}

	while (true) {
		pair<int, int>minx = make_pair(1 << 30, -1), maxn = make_pair(-(1 << 30), -1);
		for (int i = 1; i <= H; i++) {
			minx = min(minx, make_pair(P1[i], i));
			maxn = max(maxn, make_pair(P1[i], i));
		}
		if (minx.first >= 0) break;
		tup.push_back(make_tuple(maxn.second, 1, minx.second, 1));
		P1[maxn.second]--; P1[minx.second]++; A1[maxn.second]--; A1[minx.second]++;
	}

	while (true) {
		pair<int, int>minx = make_pair(1 << 30, -1), maxn = make_pair(-(1 << 30), -1);
		for (int i = 1; i <= H; i++) {
			minx = min(minx, make_pair(P2[i], i));
			maxn = max(maxn, make_pair(P2[i], i));
		}
		if (minx.first >= 0) break;
		tup.push_back(make_tuple(maxn.second, W, minx.second, W));
		P2[maxn.second]--; P2[minx.second]++; A2[maxn.second]--; A2[minx.second]++;
	}

	simulate();

	// Step 2.
	for (int i = 1; i <= H; i++) {
		for (int j = 2; j <= W - 1; j++) {
			for (int k = S2[i][j].size() - 1; k >= 0; k--) {
				if (S2[i][j][k] == '0') { A1[i]--; tup.push_back(make_tuple(i, 1, i, j)); }
				if (S2[i][j][k] == '1') { A2[i]--; tup.push_back(make_tuple(i, W, i, j)); }
			}
		}
	}

	simulate();

	// Step 3.
	for (int i = 1; i <= H; i++) {
		int T = i - 1; if (i == 1) T = H;
		for (int j = 0; j < S2[i][1].size(); j++) { if (S2[i][1][j] == '0') B1[T]++; else B2[i]++; }
		for (int j = 0; j < S2[i][W].size(); j++) { if (S2[i][W][j] == '0') B1[i]++; else B2[T]++; }
	}
	vector<int>VA1, VA2, VB1, VB2;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= A1[i]; j++) VA1.push_back(i); // 0
		for (int j = 1; j <= A2[i]; j++) VB1.push_back(i); // 1
		for (int j = 1; j <= B1[i]; j++) VA2.push_back(i); // 0
		for (int j = 1; j <= B2[i]; j++) VB2.push_back(i); // 1
	}
	for (int i = 0; i < VA1.size(); i++) { if (VA1[i] != VA2[i]) tup.push_back(make_tuple(VA1[i], 1, VA2[i], 1)); }
	for (int i = 0; i < VB1.size(); i++) { if (VB1[i] != VB2[i]) tup.push_back(make_tuple(VB1[i], W, VB2[i], W)); }

	simulate();

	// Step 4.
	for (int i = 1; i <= H; i++) {
		int T = i - 1; if (i == 1) T = H;
		for (int j = S2[i][1].size() - 1; j >= 0; j--) {
			if (S2[i][1][j] == '0') tup.push_back(make_tuple(T, 1, i, 1));
			if (S2[i][1][j] == '1') tup.push_back(make_tuple(i, W, i, 1));
		}
		for (int j = S2[i][W].size() - 1; j >= 0; j--) {
			if (S2[i][W][j] == '0') tup.push_back(make_tuple(i, 1, i, W));
			if (S2[i][W][j] == '1') tup.push_back(make_tuple(T, W, i, W));
		}
	}

	simulate();

	cout << tup.size() << "\n";
	for (int i = 0; i < tup.size(); i++) cout << get<0>(tup[i]) << " " << get<1>(tup[i]) << " " << get<2>(tup[i]) << " " << get<3>(tup[i]) << "\n";
	return 0;
}