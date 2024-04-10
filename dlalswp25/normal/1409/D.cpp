#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

char A[20];
ll N;
int S;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", A); scanf("%d", &S);
		int d = strlen(A);
		ll N = 0;
		for(int i = 0; i < d; i++) N = (N * 10) + A[i] - '0';

		int sum = 0;
		for(int i = 0; i < d; i++) sum += A[i] - '0';
		if(sum <= S) { puts("0"); continue; }

		sum = 0;
		int idx;
		for(int i = 0; i < d; i++) {
			sum += A[i] - '0';
			if(sum >= S) { idx = i; break; }
		}

		int j;
		for(j = idx - 1; j >= 0; j--) {
			if(A[j] == '9') A[j] = '0';
			else { A[j]++; break; }
		}
		for(int i = idx; i < d; i++) A[i] = '0';

		ll M = 0;
		if(j < 0) M = 1;
		for(int i = 0; i < d; i++) M = M * 10 + A[i] - '0';
		printf("%lld\n", M - N);
	}
	return 0;
}