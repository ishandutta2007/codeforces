#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

string S, T1, T2, P; int N;

string solve() {
	int ca = -1, cb = -1; string ret = "";

	while (true) {
		int va = -1, vb = -1;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				int t1 = ca + 1 + i, t2 = cb + 1 + j;
				if (t1 < 0 || t2 < 0 || t1 >= T1.size() || t2 >= T2.size()) continue;
				if (T1[t1] == T2[t2]) { va = t1; vb = t2; }
			}
		}
		if (va == -1 && vb == -1) break;

		if (ca == -1 && cb == -1) {
			if (va == 1) P = T1[0];
			else if (vb == 1) P = T2[0];
		}
		ca = va; cb = vb; ret += T1[ca];
	}
	return ret;
}

int main() {
	cin >> S; N = S.size();

	if (N == 2) {
		cout << S[0] << endl;
		return 0;
	}

	if (N % 2 == 1) {
		T1 = S.substr(0, N / 2);
		T2 = S.substr(N - (N / 2), N / 2);
		P = S.substr(N / 2, 1);
	}
	else {
		T1 = S.substr(0, N / 2);
		T2 = S.substr(N / 2, N / 2);
	}
	reverse(T1.begin(), T1.end());

	string A = solve();
	string A1 = A, A2 = A;
	reverse(A1.begin(), A1.end());

	cout << A1 << P << A2 << endl;
	return 0;
}