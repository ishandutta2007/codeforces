#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long Q, L, R; vector<long long>F;

long long square(long long B) {
	long long L = 0, R = 2000000000LL, M, maxn = 0;
	for (int i = 0; i <= 40; i++) {
		M = (L + R) / 2;
		if (M*M <= B) { maxn = max(maxn, M); L = M; }
		else { R = M; }
	}
	return maxn;
}

void init() {
	for (int i = 3; i <= 60; i += 2) {
		for (int j = 2; j <= 1000000; j++) {
			long long V = 1;
			for (int k = 0; k < i; k++) {
				if ((1LL << 60) / V < j) { V = (1LL << 60); break; }
				V *= j;
			}
			if (V != (1LL << 60)) {
				long long P = square(V);
				if (P*P != V) F.push_back(V);
			}
			if (V == (1LL << 60)) break;
		}
	}
	sort(F.begin(), F.end());
	F.erase(unique(F.begin(), F.end()), F.end());
}

int main() {
	cin >> Q; init();
	for (int i = 1; i <= Q; i++) {
		scanf("%lld%lld", &L, &R);
		long long pos1 = lower_bound(F.begin(), F.end(), L) - F.begin();
		long long pos2 = lower_bound(F.begin(), F.end(), R + 1) - F.begin();
		long long v = square(R) - square(L - 1);
		printf("%lld\n", (pos2 - pos1) + v);
	}
	return 0;
}