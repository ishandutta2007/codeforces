#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

int H, W, A[1009][1009];

int main() {
	scanf("%d%d", &H, &W);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			int t; scanf("%d", &t);
			A[i][j] ^= t;
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			int t; scanf("%d", &t);
			A[i][j] ^= t;
		}
	}
	for (int i = 0; i < H; i++) {
		int sum = 0;
		for (int j = 0; j < W; j++) {
			if (A[i][j] == 1) sum++;
		}
		if (sum % 2 == 1) { cout << "No" << endl; return 0; }
	}
	for (int i = 0; i < W; i++) {
		int sum = 0;
		for (int j = 0; j < H; j++) {
			if (A[j][i] == 1) sum++;
		}
		if (sum % 2 == 1) { cout << "No" << endl; return 0; }
	}
	cout << "Yes" << endl;
	return 0;
}