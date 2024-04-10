#include <bits/stdc++.h>
using namespace std;

string s;

int a[4][4], cr[4], cc[4];
void erase() {
	memset(cr, 0, sizeof cr), memset(cc, 0, sizeof cc);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) cr[i] += a[i][j], cc[j] += a[i][j];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) if (cr[i] == 4 || cc[j] == 4) a[i][j] = 0;
}
int main() {
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '1') {
			for (int x = 0; x < 2; x++)
				for (int y = 0; y < 3; y++) if (a[x][y] + a[x][y + 1] == 0) {
					cout << x + 1 << ' ' << y + 1 << endl;
					a[x][y] = a[x][y + 1] = 1;
					goto lp;
				}
			lp: 
			erase();
		} else {
			for (int x = 2; x < 3; x++)
				for (int y = 0; y < 4; y++) if (a[x][y] + a[x + 1][y] == 0) {
					cout << x + 1 << ' ' << y + 1 << endl;
					a[x][y] = a[x + 1][y] = 1;
					goto lp1;
				}
			lp1: 
			erase();
		}
	}
	return 0;
}