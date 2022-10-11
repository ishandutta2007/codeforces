#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

vector<int> V1[1029], V2[1029];
int H, W, C1[509][509], C2[509][509];

int main() {
	scanf("%d%d", &H, &W);
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			scanf("%d", &C1[i][j]);
			V1[i + j].push_back(C1[i][j]);
		}
	}
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			scanf("%d", &C2[i][j]);
			V2[i + j].push_back(C2[i][j]);
		}
	}
	for (int i = 2; i <= H + W; i++) {
		sort(V1[i].begin(), V1[i].end());
		sort(V2[i].begin(), V2[i].end());
		if (V1[i] != V2[i]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}