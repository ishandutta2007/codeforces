#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int x[500][500], mx = 100000, my = 100000, nx = -1, ny = -1;
int main() {
	int H, W; cin >> H >> W;
	for (int i = 0; i < H; i++) {
		string S; cin >> S;
		for (int j = 0; j < W; j++) {
			if (S[j] == 'X') { x[i][j] = 1; mx = min(mx, i); my = min(my, j); nx = max(nx, i); ny = max(ny, j); }
		}
	}
	bool flag = true;
	for (int i = mx; i <= nx; i++) {
		for (int j = my; j <= ny; j++) {
			if (x[i][j] == 0)flag = false;
		}
	}
	if (flag == true)cout << "YES" << endl;
	if (flag == false)cout << "NO" << endl;
	return 0;
}