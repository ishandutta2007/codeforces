#include <iostream>
using namespace std;

int N, M, C, a[100009];

int res(int p1, int p2, int p3) {
	int s = 0;
	if (p1 > p2) s += (p2 - p1);
	if (p2 > p3) s += (p3 - p2);
	return s;
}

void solve(int s) {
	int G; cin >> G;
	if (G <= C / 2) {
		for (int i = 1; i <= N; i++) {
			if (a[i] == 0 || a[i] > G) {
				cout << i << endl;
				a[i] = G;
				break;
			}
		}
	}
	else {
		for (int i = N; i >= 1; i--) {
			if (a[i] == 0 || a[i] < G) {
				cout << i << endl;
				a[i] = G;
				break;
			}
		}
	}
}

bool check() {
	//for (int i = 1; i <= N; i++) { if (i >= 2) cout << " "; cout << a[i]; } cout << endl;
	for (int i = 1; i <= N - 1; i++) {
		if (a[i] > a[i + 1] || a[i] == 0 || a[i + 1] == 0) return false;
	}
	return true;
}

int main() {
	cin >> N >> M >> C;
	for (int i = 1; i <= M; i++) {
		solve(i);
		if (check() == true) break;
	}
	return 0;
}