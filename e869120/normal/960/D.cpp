#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

long long Q, J[100009];

long long lev(long long U) {
	long long C = 0;
	while (U >= 2) { C++; U /= 2; }
	return C;
}

int main() {
	cin >> Q;
	for (int i = 1; i <= Q; i++) {
		int v; scanf("%d", &v);
		if (v == 1) {
			long long k, p; scanf("%lld%lld", &k, &p);
			k = lev(k);
			if (k < 60) {
				J[k] -= p; J[k] %= (1LL << k);
				J[k] += (1LL << k); J[k] %= (1LL << k);
			}
		}
		if (v == 2) {
			long long k, p; scanf("%lld%lld", &k, &p);
			k = lev(k); p %= (1LL << k);
			for (int j = k; j < 60; j++) {
				J[j] -= p; J[j] %= (1LL << j);
				J[j] += (1LL << j); J[j] %= (1LL << j);
				p *= 2;
			}
		}
		if (v == 3) {
			long long I; scanf("%lld", &I);
			long long dep = lev(I);
			long long pos = (I - J[dep]) % (1LL << dep); vector<long long>E;

			while (dep >= 0) {
				long long S = (pos + J[dep]) % (1LL << dep);
				E.push_back(S + (1LL << dep));
				pos /= 2; dep--;
			}
			for (int j = 0; j < E.size(); j++) {
				if (j) printf(" "); printf("%lld", E[j]);
			}
			printf("\n");
		}
	}
	return 0;
}