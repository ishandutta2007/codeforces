#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int H, W, A[1009][1009]; vector<int>X[1009], Y[1009];

int main() {
	scanf("%d%d", &H, &W);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) scanf("%d", &A[i][j]);
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			X[i].push_back(A[i][j]);
			Y[j].push_back(A[i][j]);
		}
	}
	for (int i = 0; i < H; i++) { sort(X[i].begin(), X[i].end()); X[i].erase(unique(X[i].begin(), X[i].end()), X[i].end()); }
	for (int i = 0; i < W; i++) { sort(Y[i].begin(), Y[i].end()); Y[i].erase(unique(Y[i].begin(), Y[i].end()), Y[i].end()); }
	
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (j) printf(" ");
			int c1 = 0, c2 = lower_bound(X[i].begin(), X[i].end(), A[i][j]) - X[i].begin(), c3 = X[i].size() - 1;
			int d1 = 0, d2 = lower_bound(Y[j].begin(), Y[j].end(), A[i][j]) - Y[j].begin(), d3 = Y[j].size() - 1;
			int G = d2 - c2;
			d1 -= G; d2 -= G; d3 -= G;

			int ret = max(c3, d3) - min(c1, d1) + 1;
			printf("%d", ret);
		}
		printf("\n");
	}
	return 0;
}