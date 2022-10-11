#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

char c[59][59]; int H, W;

int main() {
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) cin >> c[i][j];
	}
	for (int i = 0; i < H; i++) {
		for (int j = i + 1; j < H; j++) {
			int c1 = 0, c2 = 0, c3 = 0;
			for (int k = 0; k < W; k++) {
				if (c[i][k] == '#' && c[j][k] == '#') c3++;
				else if (c[i][k] == '.' && c[j][k] == '.') c1++;
				else c2++;
			}
			if (c3 >= 1 && c2 >= 1) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}