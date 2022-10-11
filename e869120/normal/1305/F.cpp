#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#pragma warning (disable: 4996)
using namespace std;

bool isprime[1 << 20];
vector<long long> primes;

void init() {
	for (int i = 2; i <= 1020000; i++) isprime[i] = true;
	for (int i = 2; i * i <= 1020000; i++) {
		for (int j = i * i; j <= 1020000; j += i) isprime[j] = false;
	}
	for (int i = 2; i <= 1020000; i++) {
		if (isprime[i] == true) primes.push_back(i);
	}
}

vector<long long> factor(long long x) {
	vector<long long> vec;
	for (int i = 0; i < primes.size(); i++) {
		if (primes[i] * primes[i] > x) break;
		if (x % primes[i] != 0) continue;
		vec.push_back(primes[i]);
		while (x % primes[i] == 0) x /= primes[i];
	}
	if (x >= 2) vec.push_back(x);
	return vec;
}

long long N, A[1 << 18];

long long Rand() {
	return (rand() % 32768) * 32768 + (rand() % 32768);
}

int main() {
	srand((unsigned)time(NULL));
	scanf("%lld", &N); init();
	for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);

	// fatality rate < 1/1073741824
	vector<long long> G;
	for (int t = 1; t <= 30; t++) {
		int K = Rand() % N + 1;
		for (long long j = A[K] - 2; j <= A[K] + 2; j++) {
			if (j <= 0LL) continue;
			vector<long long> G2 = factor(j);
			for (int k = 0; k < G2.size(); k++) G.push_back(G2[k]);
		}
	}
	sort(G.begin(), G.end());
	G.erase(unique(G.begin(), G.end()), G.end());

	long long minx = (1LL << 60);
	for (int i = 0; i < G.size(); i++) {
		long long cand = G[i], sum = 0;
		for (int j = 1; j <= N; j++) {
			if (A[j] < cand) {
				sum += (cand - A[j]);
			}
			else {
				long long rem = A[j] % cand;
				sum += min(rem, cand - rem);
			}
		}
		minx = min(minx, sum);
	}
	cout << minx << endl;
	return 0;
}