/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
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

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 10, A = 2e6 + 10, mod = 1e9 + 7;

int p[N], max_pwr[A], ctr[A], idx[A];
vector<int> primes;
bool not_prime[A];

void sieve();
ll pwr(ll x, ll e);

int main() {
	fast_cin();
	sieve();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
	}
	sort(p + 1, p + 1 + n);
	ll ans = 1;
	set<int> check;
	for (int i = n; i >= 1; --i) {
		if (!max_pwr[idx[p[i]]]) {
			max_pwr[idx[p[i]]] = 1;
			ctr[idx[p[i]]] = 1;
			ans = (ans * p[i]) % mod;
		} else {
			check.insert(p[i] - 1);
			int temp = p[i] - 1, sq = sqrt(temp);
			for (int j = 0; primes[j] <= sq; ++j) {
				int c = 0;
				while (temp % primes[j] == 0) {
					temp /= primes[j];
					++c;
				}
				if (c > max_pwr[j]) {
					ans = (ans * pwr(primes[j], c - max_pwr[j])) % mod;
					max_pwr[j] = c;
					ctr[j] = 1;
				} else if (c == max_pwr[j]) {
					++ctr[j];
				}
			}
			if (temp > 1) {
				if (1 > max_pwr[idx[temp]]) {
					ans = (ans * temp) % mod;
					max_pwr[idx[temp]] = 1;
					ctr[idx[temp]] = 1;
				} else if (1 == max_pwr[idx[temp]]) {
					++ctr[idx[temp]];
				}
			}
		}
	}
	for (auto &i : check) {
		int temp = i, sq = sqrt(temp);
		bool need = false;
		for (int j = 0; primes[j] <= sq; ++j) {
			int c = 0;
			while (temp % primes[j] == 0) {
				temp /= primes[j];
				++c;
			}
			if (c == max_pwr[j] and ctr[j] == 1) {
				need = true;
				break;
			}
		}
		if (temp > 1 and ctr[idx[temp]] == 1) {
			need = true;
		}
		if (!need) {
			ans = (ans + 1) % mod;
			break;
		}
	}
	cout << ans << endl;
}

void sieve() {
	for (int i = 2; i < A; ++i) {
		if (!not_prime[i]) {
			primes.pb(i);
			idx[i] = primes.size() - 1;
			for (int j = i; j < A; j += i) {
				not_prime[j] = true;
			}
		}
	}
}

ll pwr(ll x, ll e) {
	ll ans = 1;
	x %= mod;
	while (e) {
		if (e & 1) {
			ans = (ans * x) % mod;
		}
		x = (x * x) % mod;
		e /= 2;
	}
	return ans;
}