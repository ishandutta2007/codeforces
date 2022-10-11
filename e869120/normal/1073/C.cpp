#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

string S;
int cx[1 << 18], cy[1 << 18], ex, ey, n;

bool solve(int l, int r) {
	int dx = cx[l] + (cx[n] - cx[r + 1]);
	int dy = cy[l] + (cy[n] - cy[r + 1]);
	if (abs(ex - dx) + abs(ey - dy) <= (r - l + 1)) return true;
	return false;
}

int main() {
	cin >> n >> S >> ex >> ey;
	for (int i = 0; i < S.size(); i++) {
		cx[i + 1] = cx[i]; cy[i + 1] = cy[i];
		if (S[i] == 'L') cx[i + 1]--;
		if (S[i] == 'R') cx[i + 1]++;
		if (S[i] == 'U') cy[i + 1]++;
		if (S[i] == 'D') cy[i + 1]--;
	}
	if ((ex + ey + 1000000) % 2 != (cx[n] + cy[n] + 1000000) % 2) {
		cout << "-1" << endl;
		return 0;
	}
	if (ex == cx[n] && ey == cy[n]) {
		cout << "0" << endl;
		return 0;
	}
	int ans = (1 << 30);
	for (int i = 0; i < S.size(); i++) {
		int cl = i, cr = (int)S.size(), cm, minx = (1 << 30);
		for (int j = 0; j < 22; j++) {
			cm = (cl + cr) / 2;
			bool T = solve(i, cm);
			if (T == true) { minx = min(minx, cm); cr = cm; }
			else { cl = cm; }
		}
		ans = min(ans, minx - i + 1);
	}
	if (ans >= (1 << 29)) cout << "-1" << endl;
	else cout << ans << endl;
	return 0;
}