#include <iostream>
#include <algorithm>
using namespace std;

int M, N, p[100009];

int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		cout << M << endl;
		int r; cin >> r;
		if (r == 0) { return 0; }
		if (r == 1) { p[i] = -1; }
		else { p[i] = 1; }
	}
	int ret = 0, cnt = 0;
	for (int i = 29; i >= 0; i--) {
		int z = ret + (1 << i);
		cout << min(M, max(1, z)) << endl;
		int r; cin >> r; r *= p[cnt%N]; cnt++;
		if (r == 0) { return 0; }
		if (r == 1) ret += (1 << i);
	}
	return 0;
}