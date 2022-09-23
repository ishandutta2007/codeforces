#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, Q;
int A[101010];
ll L[101010];
ll R[101010];

int main() {
	scanf("%d%d", &N, &Q);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 1; i < N; i++) L[i] = L[i - 1] + max(0, A[i] - A[i + 1]);
	for(int i = N; i > 1; i--) R[i] = R[i + 1] + max(0, A[i] - A[i - 1]);
	while(Q--) {
		int l, r; scanf("%d%d", &l, &r);
		if(l < r) printf("%lld\n", L[r - 1] - L[l - 1]);
		else printf("%lld\n", R[r + 1] - R[l + 1]);
	}
	return 0;
}