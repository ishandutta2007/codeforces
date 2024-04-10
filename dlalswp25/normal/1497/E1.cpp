#include <bits/stdc++.h>

using namespace std;

const int MX = 10000000;

int N, K;
int sieve[10101010];
vector<int> primes;

int V[202020];

int main() {
	for(int i = 2; i <= MX; i++) {
		if(!sieve[i]) { sieve[i] = i; primes.push_back(i); }
		for(int j : primes) {
			if(i * j > MX) break;
			sieve[i * j] = j;
			if(i % j == 0) break;
		}
	}

	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			V[i] = 1;
			while(a > 1) {
				int t = sieve[a];
				if(V[i] % t == 0) V[i] /= t;
				else V[i] *= t;
				a /= t;
			}
		}

		int ans = 0;
		set<int> S;
		for(int i = 1; i <= N; i++) {
			if(S.find(V[i]) != S.end()) {
				ans++; S.clear();
			}
			S.insert(V[i]);
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}