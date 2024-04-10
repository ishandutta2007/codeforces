#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

long long N, A[200009], sum;

int main() {
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for (int i = 0; i <= N; i++) {
		long long cl = A[i], cr = A[i + 1], K = abs(cr - cl);
		sum += K * (N + 1 - K);
	}
	cout << sum / 2 << endl;
	return 0;
}