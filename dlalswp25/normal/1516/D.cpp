#include <bits/stdc++.h>

using namespace std;

const int MX = 100000;

vector<int> primes;

int N, Q;
int A[101010];
int st[20][101010];
int sieve[101010];
int cnt[101010];
vector<int> F[101010];

vector<int> factorize(int x) {
	vector<int> ret;
	while(x > 1) {
		ret.push_back(sieve[x]);
		x /= sieve[x];
	}
	return ret;
}

int main() {
	for(int i = 2; i <= MX; i++) {
		if(!sieve[i]) { sieve[i] = i; primes.push_back(i); }
		for(int j : primes) {
			if(j * i > MX) break;
			sieve[j * i] = j;
			if(i % j == 0) break;
		}
	}

	scanf("%d%d", &N, &Q);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

	int r = 1;
	for(int i = 1; i <= N; i++) {
		while(r <= N) {
			F[r] = factorize(A[r]);
			bool ok = true;
			for(int j : F[r]) {
				if(cnt[j]) ok = false;
			}
			if(!ok) break;
			for(int j : F[r]) cnt[j]++;
			r++;
		}
		st[0][i] = r;
		for(int j : F[i]) cnt[j]--;
	}
	for(int i = 0; i <= 19; i++) st[i][N + 1] = N + 1;

	for(int i = 1; i <= 19; i++) for(int j = 1; j <= N; j++) st[i][j] = st[i - 1][st[i - 1][j]];
	while(Q--) {
		int l, r; scanf("%d%d", &l, &r);
		int ans = 0;
		for(int i = 19; i >= 0; i--) {
			if(st[i][l] > r) continue;
			ans += 1 << i;
			l = st[i][l];
		}
		printf("%d\n", ans + 1);
	}

	return 0;
}