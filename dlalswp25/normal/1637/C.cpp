#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int A[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		if(N == 3 && A[2] % 2 == 1) { puts("-1"); continue; }
		bool ok = false;
		for(int i = 2; i < N; i++) if(A[i] > 1) ok = true;
		if(!ok) { puts("-1"); continue; }
		ll sum = 0;
		for(int i = 2; i < N; i++) sum += A[i];
		for(int i = 2; i < N; i++) sum += (A[i] & 1);
		printf("%lld\n", sum / 2);
	}
	return 0;
}