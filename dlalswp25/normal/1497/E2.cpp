#include <bits/stdc++.h>

using namespace std;

const int MX = 10000000;

int N, K;
int sieve[10101010];
vector<int> primes;

int V[202020];
int R[202020];
int cur[10101010];
int D[202020][25];

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

		for(int i = 1; i <= N; i++) { cur[V[i]] = 0; R[i] = N + 1; }
		for(int i = N; i >= 1; i--) {
			if(cur[V[i]]) {
				R[i] = cur[V[i]];
			}
			cur[V[i]] = i;
		}

		set<int> S;
		for(int i = 1; i <= N; i++) for(int j = 0; j <= K; j++) D[i][j] = 1010101010;
		for(int i = 0; i <= K; i++) D[N + 1][i] = 0;
		S.insert(N + 1);
		for(int i = N; i >= 1; i--) {
			if(R[i] <= N) S.insert(R[i]);
			if(S.size() > K + 2) S.erase(--S.end());
			for(int j = 0; j <= K; j++) {
				auto it = S.begin();
				for(int k = j; k >= 0; k--) {
					int t = *it;
					if(t > N) { D[i][j] = 1; break; }
					D[i][j] = min(D[i][j], D[t][k] + 1);
					it++;
				}
			}
		}
		printf("%d\n", D[1][K]);
	}
	return 0;
}