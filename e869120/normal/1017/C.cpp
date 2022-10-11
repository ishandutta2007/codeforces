#include <iostream>
#include <algorithm>
using namespace std;

int N, p[100009];

int main() {
	cin >> N;
	for (int i = 0; i <= N + 5; i++) {
		int z = (i / 2) * ((i + 1) / 2);
		if (z >= N) {
			int cx = N, s = (i / 2), cnt = 0;
			while (true) {
				for (int i = max(1, cx - s + 1); i <= cx; i++) { p[i] = cnt + 1; cnt++; }
				cx -= s; if (cx <= 0) break;
			}
			for (int j = 1; j <= N; j++) { if (j >= 2) cout << " "; cout << p[j]; } cout << endl;
			break;
		}
	}
	return 0;
}