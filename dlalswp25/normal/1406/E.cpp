#include <bits/stdc++.h>

using namespace std;

int N;
int lft;
bool chk[101010];
bool notprime[101010];
vector<int> primes;

int A(int x) {
	printf("A %d\n", x); fflush(stdout);
	int ret; scanf("%d", &ret);
	return ret;	
}

int B(int x) {
	printf("B %d\n", x); fflush(stdout);
	int ret; scanf("%d", &ret);
	return ret;
}

void ers(int x) {
	for(int i = x; i <= N; i += x) {
		if(!chk[i]) lft--;
		chk[i] = true;
	}
}

int main() {
	scanf("%d", &N);
	if(N == 1) {
		printf("C 1\n");
		fflush(stdout);
		return 0;
	}
	lft = N;

	notprime[1] = true;
	for(int i = 2; i * i <= N; i++) {
		if(notprime[i]) continue;
		for(int j = i * i; j <= N; j += i) notprime[j] = true;
	}

	primes.push_back(1);
	for(int i = 1; i <= N; i++) if(!notprime[i]) primes.push_back(i);

	int pn = primes.size();
	pn--;
	int q;

	while(1) {
		if(pn == 1) {
			B(2);
			if(A(2)) q = 2;
			else {
				puts("C 1");
				fflush(stdout);
				return 0;
			}
			break;
		}
		for(int i = pn; i > pn / 2; i--) {
			B(primes[i]);
			ers(primes[i]);
		}
		int x = A(1);
		if(x != lft) {
			for(int i = pn; i > pn / 2; i--) {
				int t = A(primes[i]);
				if(t) { q = primes[i]; break; }
			}
			break;
		}
		pn = pn / 2;
	}

	B(q);
	for(int i = 2; i * i <= N && i <= q; i++) {
		if(notprime[i]) continue;
		while(1) {
			if(q * i > N || !A(q * i)) break;
			q *= i;
		}
	}
	printf("C %d\n", q); fflush(stdout);

	return 0;
}