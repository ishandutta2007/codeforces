#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MX = 20000000;

vector<int> primes;
int sieve[20202020];
ll ans;
int c, d, x;

void f(int g) {
	int y = (x / g + d);
	if(y % c) return;
	y /= c;
	int cnt = 0, last = 0;
	while(y > 1) {
		int t = sieve[y];
		if(last != t) { cnt++; last = t; }
		y /= t;
	}
	ans += (1 << cnt);
}

int main() {
	for(int i = 2; i <= MX; i++) {
		if(!sieve[i]) { sieve[i] = i; primes.push_back(i); }
		for(int j : primes) {
			if(i * j > MX) break;
			sieve[i * j] = j;
			if(i % j == 0) break;
		}
	}

	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d%d", &c, &d, &x);
		ans = 0;
		for(int i = 1; i * i <= x; i++) {
			if(x % i) continue;
			f(i);
			if(i != x / i) f(x / i);
		}
		printf("%lld\n", ans);
	}
	return 0;
}