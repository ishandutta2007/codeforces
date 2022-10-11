#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long I[1000009]; vector<int>vec[10];

long long calc(long long V) {
	string S = to_string(V);

	long long r = 1;
	for (int i = 0; i < S.size(); i++) { if (S[i] != '0') r *= (S[i] - '0'); }
	return r;
}

void init() {
	for (int i = 0; i < 10; i++) I[i] = i;
	for (int i = 10; i <= 1000000; i++) {
		I[i] = I[calc(i)];
	}
	for (int i = 0; i <= 1000000; i++) vec[I[i]].push_back(i);
}

int main() {
	init();
	long long Q, L, R, K; scanf("%lld", &Q);
	for (int i = 1; i <= Q; i++) {
		scanf("%lld%lld%lld", &L, &R, &K);
		int pos1 = lower_bound(vec[K].begin(), vec[K].end(), L) - vec[K].begin();
		int pos2 = lower_bound(vec[K].begin(), vec[K].end(), R + 1LL) - vec[K].begin();
		printf("%d\n", pos2 - pos1);
	}
	return 0;
}