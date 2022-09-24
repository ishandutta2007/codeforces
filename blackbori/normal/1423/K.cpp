#include <bits/stdc++.h>

using namespace std;

int M = 1000000;
bool notprime[1010101];
int S[1010101];
int sq[1010101];

int main() {
	notprime[1] = true;
	for(int i = 2; i * i <= M; i++) {
		if(notprime[i]) continue;
		for(int j = i * i; j <= M; j += i) notprime[j] = true;
	}

	for(int i = 3; i <= M; i++) S[i] = S[i - 1] + (1 - notprime[i]);
	for(int i = 1; i <= 999; i++) {
		for(int j = i * i; j <= (i + 1) * (i + 1) - 1; j++) sq[j] = i;
	}
	sq[1000000] = 1000;

	int Q; scanf("%d", &Q);
	while(Q--) {
		int N; scanf("%d", &N);
		printf("%d\n", S[N] - S[sq[N]] + 1 + (N > 1 && N <= 3));
	}
	return 0;
}