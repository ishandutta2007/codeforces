#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int A[202020];

ll gcd(ll a, ll b) { while(b) { a %= b; swap(a, b); } return a; }

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + N + 1);
		ll S = 0;
		for(int i = 1; i <= N; i++) S += A[i];
		ll g = gcd(S, N);
		if(N / g > 2) { puts("0"); continue; }
		ll t = 2 * S / N;
		ll ans = 0;
		map<int, int> mp;
		for(int i = 1; i <= N; i++) {
			ans += mp[t - A[i]];
			mp[A[i]]++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}