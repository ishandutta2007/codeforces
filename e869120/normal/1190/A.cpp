#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

long long N, M, K, P[100009], cnt = 1, ans = 1;

int main() {
	scanf("%lld%lld%lld", &N, &M, &K);
	for (int i = 1; i <= M; i++) scanf("%lld", &P[i]);
	
	long long pres = (P[1] - cnt) / K;
	for (int i = 2; i <= M; i++) {
		if (pres == (P[i] - cnt) / K) {
			// 
		}
		else {
			ans++; cnt = i;
			pres = (P[i] - cnt) / K;
		}
	}
	printf("%lld\n", ans);
	return 0;
}