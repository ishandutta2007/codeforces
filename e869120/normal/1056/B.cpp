#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

long long C[1009], N, M, ans = 0;

int main() {
	cin >> N >> M;
	long long V = N / M;
	for (int i = 1; i <= M; i++) C[(1LL * i * i) % M] += V;
	for (int i = V * M + 1; i <= N; i++) C[(1LL * i * i) % M] += 1;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) { if ((i + j) % M == 0) ans += C[i] * C[j]; }
	}
	cout << ans << endl;
	return 0;
}