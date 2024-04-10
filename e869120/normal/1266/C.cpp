#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

void solve(int H, int W) {
	if (H == 1 && W == 1) {
		cout << "0" << endl;
	}
	else if (H == 1 || W == 1) {
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				if (j >= 2) printf(" ");
				printf("%d", i + j);
			}
			printf("\n");
		}
	}
	else {
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				if (j >= 2) printf(" ");
				printf("%d", i * (H + j));
			}
			printf("\n");
		}
	}
}

int main() {
	int H, W; cin >> H >> W;
	solve(H, W);
	return 0;
}