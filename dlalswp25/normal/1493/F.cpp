#include <bits/stdc++.h>

using namespace std;

const int MX = 1000;

int N, M;
int qans;
int sieve[1010];
vector<int> primes;

void query(int h, int w, int x1, int y1, int x2, int y2) {
	printf("? %d %d %d %d %d %d\n", h, w, x1, y1, x2, y2);
	fflush(stdout);
	scanf("%d", &qans);
}

int main() {
	for(int i = 2; i <= MX; i++) {
		if(!sieve[i]) { sieve[i] = i; primes.push_back(i); }
		for(int j : primes) {
			if(i * j > MX) break;
			sieve[i * j] = j;
			if(i % j == 0) break;
		}
	}

	scanf("%d%d", &N, &M);
	int n = 1, m = 1;

	int tmp = M;
	for(int i = 2; i <= M; i++) {
		if(tmp < i) break;
		if(sieve[i] != i) continue;
		if(tmp % i) continue;
		if(i == 2) {
			query(N, tmp / 2, 1, 1, 1, tmp / 2 + 1);
			if(qans) {
				n *= 2;
				tmp /= 2;
				i--;
			}
		}
		else {
			int t = tmp / i;
			query(N, t * (i / 2), 1, 1, 1, t * (i / 2) + 1);
			if(!qans) continue;
			query(N, t * (i / 2), 1, 1, 1, tmp - t * (i / 2) + 1);
			if(qans) {
				n *= i;
				tmp /= i;
				i--;
			}
		}
	}

	tmp = N;
	for(int i = 2; i <= N; i++) {
		if(tmp < i) break;
		if(sieve[i] != i) continue;
		if(tmp % i) continue;
		if(i == 2) {
			query(tmp / 2, M, 1, 1, tmp / 2 + 1, 1);
			if(qans) {
				m *= 2;
				tmp /= 2;
				i--;
			}
		}
		else {
			int t = tmp / i;
			query(t * (i / 2), M, 1, 1, t * (i / 2) + 1, 1);
			if(!qans) continue;
			query(t * (i / 2), M, 1, 1, tmp - t * (i / 2) + 1, 1);
			if(qans) {
				m *= i;
				tmp /= i;
				i--;
			}
		}
	}

	int a = 0, b = 0;
	for(int i = 1; i <= n; i++) if(n % i == 0) a++;
	for(int i = 1; i <= m; i++) if(m % i == 0) b++;

	printf("! %d\n", a * b);
	fflush(stdout);
	return 0;
}