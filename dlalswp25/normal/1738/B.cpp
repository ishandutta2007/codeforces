#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, K;
ll S[101010];
ll A[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		for(int i = N - K + 1; i <= N; i++) scanf("%lld", &S[i]);
		if(K == 1) { puts("Yes"); continue; }
		for(int i = N; i > N - K + 1; i--) {
			A[i] = S[i] - S[i - 1];
		}
		if(S[N - K + 1] > (N - K + 1) * A[N - K + 2]) { puts("No"); continue; }
		bool ok = true;
		for(int i = N - K + 2; i < N; i++) if(A[i] > A[i + 1]) ok = false;
		if(!ok) puts("No");
		else puts("Yes");
	}
	return 0;
}