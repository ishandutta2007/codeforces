#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, X, A[100009];

int main() {
	scanf("%lld%lld", &N, &X);
	for (int i = 0; i < N; i++) scanf("%lld", &A[i]);
	sort(A, A + N);

	if (N == 1) {
		cout << "0" << endl;
		return 0;
	}
	if (N == 2) {
		cout << min(abs(X - A[0]), abs(X - A[1])) << endl;
		return 0;
	}

	long long E1 = abs(A[0] - A[N - 2]) + min(abs(A[0] - X), abs(A[N - 2] - X));
	long long E2 = abs(A[1] - A[N - 1]) + min(abs(A[1] - X), abs(A[N - 1] - X));
	cout << min(E1, E2) << endl;
	return 0;
}