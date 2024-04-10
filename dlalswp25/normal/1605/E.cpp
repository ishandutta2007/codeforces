#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, Q;
int A[1010101];
int B[1010101];
int mu[1010101];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= N; i++) scanf("%d", &B[i]);

	if(N == 1) {
		scanf("%d", &Q);
		while(Q--) {
			int x; scanf("%d", &x);
			printf("%d\n", abs(A[1] - x));
		}
		return 0;
	}

	mu[1] = 1;
	for(int i = 1; i <= N; i++) {
		for(int j = i + i; j <= N; j += i) mu[j] -= mu[i];
	}

	ll ans = 0;
	vector<int> v;
	for(int i = 2; i <= N; i++) {
		if(!mu[i]) ans += abs(B[i] - A[i]);
		else v.push_back(mu[i] * (B[i] - A[i]));
		for(int j = i + i; j <= N; j += i) A[j] += (B[i] - A[i]);
	}

	sort(v.begin(), v.end());
	vector<ll> S(v.size());
	int M = v.size();
	S[0] = v[0];
	for(int i = 1; i < M; i++) {
		S[i] = S[i - 1] + v[i];
	}

	scanf("%d", &Q);
	while(Q--) {
		int x; scanf("%d", &x);
		ll extra = abs(A[1] - x);
		x = A[1] - x;
		int t = lower_bound(v.begin(), v.end(), x) - v.begin();
		if(t) {
			extra += (ll)t * x - S[t - 1];
			extra += S.back() - S[t - 1] - (ll)(M - t) * x;
		}
		else extra += (ll)S.back() - (ll)M * x;
		printf("%lld\n", ans + extra);
	}

	return 0;
}