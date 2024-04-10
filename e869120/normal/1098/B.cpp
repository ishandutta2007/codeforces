#include <iostream>
#include <string>
#include <vector>
using namespace std;

string S[300009], T[300009], U[300009], V[300009]; int H, W, minx = 1000000;

int compare(string V1, string V2) {
	int cnt = 0;
	for (int i = 0; i < V1.size(); i++) {
		if (V1[i] != V2[i]) cnt++;
	}
	return cnt;
}

void rotate() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) T[j] += S[i][j];
	}
	for (int i = 0; i < W; i++) S[i] = T[i];
	swap(H, W);
}

void solve(int flag, string V1, string V2) {
	int sum = 0;
	for (int i = 0; i < H; i += 2) {
		string P1; for (int j = 0; j < W; j++) P1 += V1[(j + 0) % 2];
		string P2; for (int j = 0; j < W; j++) P2 += V1[(j + 1) % 2];
		int L1 = compare(P1, S[i]);
		int L2 = compare(P2, S[i]);
		if (L1 < L2) { V[i] = P1; sum += L1; }
		else { V[i] = P2; sum += L2; }
	}
	for (int i = 1; i < H; i += 2) {
		string P1; for (int j = 0; j < W; j++) P1 += V2[(j + 0) % 2];
		string P2; for (int j = 0; j < W; j++) P2 += V2[(j + 1) % 2];
		int L1 = compare(P1, S[i]);
		int L2 = compare(P2, S[i]);
		if (L1 < L2) { V[i] = P1; sum += L1; }
		else { V[i] = P2; sum += L2; }
	}
	if (sum < minx) {
		minx = sum;
		if (flag == 0) {
			for (int i = 0; i < H; i++) U[i] = V[i];
		}
		else {
			for (int i = 0; i < 300000; i++) U[i] = "";
			for (int i = 0; i < H; i++) {
				for (int j = 0; j < W; j++) U[j] += V[i][j];
			}
		}
	}
}

int main() {
	cin >> H >> W;
	for (int i = 0; i < H; i++) cin >> S[i];

	for (int i = 0; i < 2; i++) {
		solve(i, "AC", "GT");
		solve(i, "AG", "CT");
		solve(i, "AT", "CG");
		solve(i, "CG", "AT");
		solve(i, "CT", "AG");
		solve(i, "GT", "AC");
		if (i == 0) rotate();
	}

	for (int i = 0; i < W; i++) cout << U[i] << endl;
	return 0;
}