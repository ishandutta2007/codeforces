#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, Q;
int A[1010101];
ll S[1010101];

int main() {
	scanf("%d%d", &N, &Q);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	sort(A + 1, A + N + 1); reverse(A + 1, A + N + 1);
	for(int i = 1; i <= N; i++) S[i] = S[i - 1] + A[i];
	while(Q--) {
		int x, y; scanf("%d%d", &x, &y);
		printf("%lld\n", S[x] - S[x - y]);
	}
	return 0;
}