#include <iostream>
#include <map>
#include <ctime>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long Rand() {
	long long s = 0, t = 1;
	for (int i = 0; i < 8; i++) {
		s += 1LL * (rand() % 256) * t;
		t *= 256LL;
	}
	return s;
}

long long N;
long long AL[1 << 18], AR[1 << 18];
long long BL[1 << 18], BR[1 << 18];
long long C[1 << 18];
long long SL[1 << 20], SR[1 << 20];
long long TL[1 << 20], TR[1 << 20];

vector<long long> vec;

int main() {
	srand((unsigned)time(NULL));
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%lld%lld%lld%lld", &AL[i], &AR[i], &BL[i], &BR[i]);
		vec.push_back(AL[i]);
		vec.push_back(AR[i]);
		vec.push_back(BL[i]);
		vec.push_back(BR[i]);
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for (int i = 1; i <= N; i++) {
		AL[i] = lower_bound(vec.begin(), vec.end(), AL[i]) - vec.begin(); AL[i]++;
		AR[i] = lower_bound(vec.begin(), vec.end(), AR[i]) - vec.begin(); AR[i]++;
		BL[i] = lower_bound(vec.begin(), vec.end(), BL[i]) - vec.begin(); BL[i]++;
		BR[i] = lower_bound(vec.begin(), vec.end(), BR[i]) - vec.begin(); BR[i]++;
		C[i] = Rand();
	}
	for (int i = 1; i <= N; i++) SL[AL[i]] += C[i];
	for (int i = 1; i <= N; i++) SR[AR[i]] += C[i];
	for (int i = 1; i <= N; i++) TL[BL[i]] += C[i];
	for (int i = 1; i <= N; i++) TR[BR[i]] += C[i];
	for (int i = 1; i <= vec.size() + 1; i++) SL[i] += SL[i - 1];
	for (int i = 1; i <= vec.size() + 1; i++) SR[i] += SR[i - 1];
	for (int i = 1; i <= vec.size() + 1; i++) TL[i] += TL[i - 1];
	for (int i = 1; i <= vec.size() + 1; i++) TR[i] += TR[i - 1];

	for (int i = 1; i <= N; i++) {
		long long v1 = SR[AL[i] - 1] + (SL[vec.size() + 1] - SL[AR[i]]);
		long long v2 = TR[BL[i] - 1] + (TL[vec.size() + 1] - TL[BR[i]]);
		if (v1 != v2) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}