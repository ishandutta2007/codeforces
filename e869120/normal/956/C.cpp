#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, A[1 << 18], B[1 << 18]; long long s = 0;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) { scanf("%d", &A[i]); B[i] = A[i] + 1; }
	for (int i = 1; i <= N; i++) B[i] = max(B[i], B[i - 1]);
	for (int i = N - 1; i >= 1; i--) B[i] = max(B[i], B[i + 1] - 1);
	for (int i = 1; i <= N; i++) s += 1LL * (B[i] - A[i] - 1LL);
	cout << s << endl;
	return 0;
}