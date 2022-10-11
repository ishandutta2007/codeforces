#include <iostream>
#include <string>
using namespace std;

int x[100009], H, W; string S[100009];

int main() {
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		cin >> S[i];
		for (int j = 0; j < S[i].size(); j++) x[j] += (S[i][j] - '0');
	}
	for (int i = 0; i < H; i++) {
		int cnt = 0;
		for (int j = 0; j < W; j++) { if (x[j] - (S[i][j] - '0') == 0) cnt++; }
		if (cnt == 0) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}