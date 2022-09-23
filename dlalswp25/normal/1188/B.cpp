#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<ll, int> mp;
int N;
ll p, k;
ll A[303030];
ll B[303030];

int main() {
	scanf("%d", &N);
	scanf("%lld%lld", &p, &k);
	for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for(int i = 1; i <= N; i++) {
		ll t = A[i] * A[i] % p * A[i] % p * A[i] % p;
		t = (t + p * p - k * A[i]) % p;
		B[i] = t; 
	}
	ll ans = 0;
	for(int i = 1; i <= N; i++) {
		ans += mp[B[i]];
		mp[B[i]]++;
	}
	printf("%lld\n", ans);
	return 0;
}