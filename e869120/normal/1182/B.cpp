#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int H, W;
char c[509][509];

int main() {
	cin >> H >> W;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) cin >> c[i][j];
	}

	int cx = -1, cy = -1;
	for (int i = 2; i <= H - 1; i++) {
		for (int j = 2; j <= W - 1; j++) {
			if (c[i + 1][j] == '*' && c[i][j + 1] == '*' && c[i][j - 1] == '*' && c[i - 1][j] == '*' && c[i][j] == '*') {
				cx = i; cy = j;
			}
		}
	}

	if (cx == -1 && cy == -1) {
		cout << "NO" << endl;
		return 0;
	}

	int cl = (1 << 30), cr = -(1 << 30), dl = (1 << 30), dr = -(1 << 30);
	for (int i = 1; i <= W; i++) { if (c[cx][i] == '*') { cl = min(cl, i); cr = max(cr, i); } }
	for (int i = 1; i <= H; i++) { if (c[i][cy] == '*') { dl = min(dl, i); dr = max(dr, i); } }

	bool flag = true;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			char cp = '.';
			if (i == cx && cl <= j && j <= cr) cp = '*';
			if (j == cy && dl <= i && i <= dr) cp = '*';
			if (c[i][j] != cp) flag = false;
		}
	}

	if (cl == cy || cy == cr || dl == cx || cx == dr) flag = false;

	if (flag == true) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}