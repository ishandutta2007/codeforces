#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

long long N, Q, A[1 << 18], S;

int main() {
	cin >> N >> Q;
	for (int i = 0; i < (1 << N); i++) { scanf("%lld", &A[i]); S += A[i]; }
	printf("%.12Lf\n", 1.0L * S / (1.0 * (1 << N)));

	for (int i = 1; i <= Q; i++) {
		long long t1, t2; scanf("%lld%lld", &t1, &t2);
		S -= A[t1]; A[t1] = t2; S += A[t1];
		printf("%.12Lf\n", 1.0L * S / (1.0 * (1 << N)));
	}
	return 0;
}