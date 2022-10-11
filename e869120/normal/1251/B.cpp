#include <iostream>
#include <string>
using namespace std;

int T;
int N; string S[1 << 18];

int solve() {
	int c1 = 0, c2 = 0;
	int v = 0;
	for (int i = 1; i <= N; i++) {
		if (S[i].size() % 2 == 1) v++;
		for (int j = 0; j < S[i].size(); j++) { if (S[i][j] == '0') c1++; else c2++; }
	}
	if (v >= 1) return N;
	if (c1 % 2 == 0 && c2 % 2 == 0) return N;
	return N - 1;
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> S[i];
		cout << solve() << endl;
	}
	return 0;
}