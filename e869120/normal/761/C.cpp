#include<iostream>
#include<algorithm>
using namespace std;
char c[50][50]; int H, W, d[50][50];
int main() {
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> c[i][j];
			if (c[i][j] >= '0' && c[i][j] <= '9')d[i][j] = 0;
			if (c[i][j] >= 'a' && c[i][j] <= 'z')d[i][j] = 1;
			if (c[i][j] == '#' || c[i][j] == '&' || c[i][j] == '*')d[i][j] = 2;
		}
	}
	int F[3] = { 0,0,0 }, I[3] = { 0,0,0 };
	for (int i = 0; i < H; i++) { F[d[i][0]] = 1; I[d[i][0]]++; }
	if (F[0] + F[1] + F[2] == 3) { cout << "0" << endl; return 0; }
	int minx = 999999999;
	for (int i = 0; i < H; i++) {
		int J[3] = { I[0],I[1],I[2] }; J[d[i][0]]--;
		for (int j = 0; j < W; j++) {
			J[d[i][j]]++;
			if (J[0] >= 1 && J[1] >= 1 && J[2] >= 1)minx = min(minx, min(j, W - j));
			J[d[i][j]]--;
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < H; j++) {
			if (i == j)continue;
			int J[3] = { I[0],I[1],I[2] }; J[d[i][0]]--; J[d[j][0]]--;
			for (int k = 0; k < W; k++) {
				for (int l = 0; l < W; l++) {
					J[d[i][k]]++; J[d[j][l]]++;
					if (J[0] >= 1 && J[1] >= 1 && J[2] >= 1)minx = min(minx, min(k, W - k) + min(l, W - l));
					J[d[i][k]]--; J[d[j][l]]--;
				}
			}
		}
	}
	cout << minx << endl;
	return 0;
}