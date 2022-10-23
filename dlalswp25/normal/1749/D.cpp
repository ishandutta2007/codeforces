#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;
const int MX = 200000;

int sieve[202020];
vector<int> primes;

ll gcd(ll a, ll b) { while(b) { a %= b; swap(a, b); } return a; }

int main() {
	for(int i = 2; i <= MX; i++) {
		if(!sieve[i]) { sieve[i] = i; primes.push_back(i); }
		for(int j : primes) {
			if(i * j > MX) break;
			sieve[i * j] = j;
			if(i % j == 0) break;
		}
	}

	int N; ll M;
	scanf("%d%lld", &N, &M);
	ll x = 1;
	ll ans = 0;
	for(int i = 1; i <= N; i++) {
		x = x * (M % MOD) % MOD;
		ans = (ans + x) % MOD;
	}
	ll t = 1;
	for(int i = 1; i <= N; i++) {
		if(sieve[i] == i) t *= i;
		if(t > M) break;
		if(i == 1) x = M % MOD;
		else x = x * (M / t % MOD) % MOD;
		ans = (ans + MOD - x) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}