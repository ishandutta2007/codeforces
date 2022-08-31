/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 3e8 + 10, S = sqrt(N) + 5;

int n;
uint a, b, c, d, ans;
bitset<S> not_prime;

void seg_sieve();
inline void solve(int p);
inline uint f(uint x);

int main() {
	cin >> n >> a >> b >> c >> d;
	seg_sieve();
	cout << ans << endl;
}

void seg_sieve() {
	vector<int> primes;
	int sq = sqrt(n) + 5;
	not_prime[1] = 1;
	not_prime[2] = 0;
	// cout << sq << endl;
	for (int i = 2; i < sq; ++i) {
		if (!not_prime[i]) {
			solve(i);
			primes.pb(i);
			for (int j = i * i; j < sq; j += i) {
				not_prime[j] = 1;
			}
		}
	}
	int l = sq, r = min(n, l + sq);
	while (l <= r) {
		not_prime = 0;
		for (auto &i : primes) {
			int x = (l + i - 1) / i;
			for (int j = i * x; j <= r; j += i) {
				not_prime[j - l] = 1;
			}
		}
		for (int i = l; i <= r; ++i) {
			if (!not_prime[i - l]) {
				solve(i);
			}
		}
		l = r + 1;
		r = min(n, l + sq);
	}
}

inline void solve(int p) {
	// cout << p << endl;
	uint e = 0;
	ll check = p;
	while (check <= n) {
		e += n / check;
		check *= p;
	}
	ans += e * f(p);
}

inline uint f(uint x) {
	return d + x * (c + x * (b + x * a));
}