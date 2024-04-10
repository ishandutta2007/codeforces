#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; cin >> T;
	while (T--) {
		int x; cin >> x;
		int flg = 0;
		for (int i = 3; i <= 360; i++) {
			for (int j = 1; j <= i-2; j++) {
				if (x * i == j * 180) {
					flg = 1;
					break;
				}
			}
			if (flg) {
				cout << i << endl;
				break;
			}
		}
	}
}