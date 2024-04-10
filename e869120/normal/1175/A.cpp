#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

int main() {
	long long Q, N, K;
	scanf("%lld", &Q);

	for (int i = 1; i <= Q; i++) {
		scanf("%lld%lld", &N, &K); long long cnt = 0;
		while (true) {
			cnt += (N%K);
			N -= (N%K); if (N == 0) break;
			N /= K; cnt++;
		}
		printf("%lld\n", cnt);
	}
	return 0;
}