#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

long long P, K, A[2009], B[2009];

int main() {
	cin >> P >> K;
	for (int i = 0; i <= 2000; i++) {
		P *= -1LL;
		long long Q = (P + K - 1LL) / K;
		if (P < 0) { Q = -P / K; Q *= -1; }
		B[i] = Q;
		A[i] = (Q * K - P);
		P = B[i];
	}
	int id = -1;
	for (int i = 2000; i >= 0; i--) {
		if (A[i] >= 1) { id = i; break; }
	}
	cout << id + 1 << endl;
	for (int i = 0; i <= id; i++) {
		if (i) cout << " ";
		cout << A[i];
	}
	cout << endl;
	return 0;
}