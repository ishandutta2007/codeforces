#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, X;
int A[101010];
ll S[101010];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &X);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + N + 1);
		reverse(A + 1, A + N + 1);
		for(int i = 1; i <= N; i++) S[i] = S[i - 1] + A[i];

		int l = 1, r = N;
		while(l <= r) {
			int m = l + r >> 1;
			if(S[m] >= (ll)X * m) l = m + 1;
			else r = m - 1;
		}
		printf("%d\n", r);
	}
	return 0;
}