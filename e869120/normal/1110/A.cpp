#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

int B, N, A[1 << 18], cnt, r;

int main() {
	scanf("%d%d", &B, &N);
	for (int i = N - 1; i >= 0; i--) scanf("%d", &A[i]);

	r = 1;
	for (int i = 0; i < N; i++) {
		cnt += r * A[i]; cnt %= 2; r *= B; r %= 2;
	}
	if (cnt == 0) cout << "even" << endl;
	else cout << "odd" << endl;
	return 0;
}