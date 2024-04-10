#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, K, S, H[250009], cnt[250009], minx = (1LL << 30);

int main() {
	scanf("%lld%lld", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &H[i]); cnt[H[i]]++;
		minx = min(minx, H[i]);
	}
	for (int i = 250000; i >= 1; i--) cnt[i - 1] += cnt[i];

	long long cnts = 0;
	for (int i = 250000; i > minx; i--) {
		cnts += cnt[i];
		if (cnts + cnt[i - 1] > K || i == minx + 1) { if (cnts >= 1) S++; cnts = 0; }
	}
	cout << S << endl;
	return 0;
}