#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll A[101010];
vector<ll> V;

int main() {
	int N, M, K; scanf("%d%d%d", &N, &M, &K);
	for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	ll S = A[N] - A[1] + 1;
	for(int i = 1; i < N; i++) {
		V.push_back(A[i + 1] - A[i] - 1);
	}
	sort(V.begin(), V.end());
	reverse(V.begin(), V.end());
	for(int i = 1; i < K; i++) {
		S -= V[i - 1];
	}
	printf("%lld\n", S);
	return 0;
}