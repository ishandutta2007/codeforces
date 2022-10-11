#include<iostream>
using namespace std;
int a[100][100], H, W; long long ret = 0;
int main() {
	cin >> H >> W;
	for (int i = 0; i < H; i++) { for (int j = 0; j < W; j++)cin >> a[i][j]; }
	for (int i = 0; i < H; i++) {
		int c = 0;
		for (int j = 0; j < W; j++)c += a[i][j];
		ret += (1LL << c) + (1LL << (W - c)); ret -= 2;
	}
	for (int i = 0; i < W; i++) {
		int c = 0;
		for (int j = 0; j < H; j++)c += a[j][i];
		ret += (1LL << c) + (1LL << (H - c)); ret -= 2;
	}
	ret -= H*W;
	cout << ret << endl;
	return 0;
}