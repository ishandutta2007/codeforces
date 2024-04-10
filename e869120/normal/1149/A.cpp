#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

int N, A[1 << 18], c1, c2;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) { scanf("%d", &A[i]); if (A[i] == 1) c1++; if (A[i] == 2) c2++; }

	if (c1 == 0 || c2 == 0) {
		for (int i = 0; i < N; i++) { if (i) cout << " "; cout << A[i]; } cout << endl;
	}
	else {
		cout << "2 1";
		for (int i = 1; i <= c2 - 1; i++) cout << " 2";
		for (int i = 1; i <= c1 - 1; i++) cout << " 1";
		cout << endl;
	}
	return 0;
}