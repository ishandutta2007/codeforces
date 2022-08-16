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

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e6 + 10;

bool isPrime[N];
vector<pii> ranges;

void sieve(int n);

int main() {
	sieve(N);
	int x2; cin >> x2;
	int temp = x2;
	int sq = sqrt(x2);
	for (int i = 2; i <= sq; ++i) {
		if (temp % i == 0) {
			while (temp % i == 0) {
				temp /= i;
			}
			int j = x2 / i;
			ranges.pb({i * (j - 1) + 1, x2});
			// cout << i * (j - 1) + 1 << ' ' << x2 << endl;
		}
	}
	if (temp > 1) {
		int j = x2 / temp;
		ranges.pb({temp * (j - 1) + 1, x2});
	}
	// for (auto &j : ranges) {
	// 	cout << j.first << ' ' << j.second << endl;
	// }
	int best = x2;
	for (int i = 2; i <= best; ++i) {
		if (isPrime[i]) {
			for (auto &j : ranges) {
				int l = j.first;
				int r = j.second;
				int x = i * ((l + i - 1) / i);
				// cout << i << ' ' << x << endl;
				if (x <= r) {
					if (x - i + 1 >= 3 and x - i + 1 > i) {
						best = min(best, x - i + 1);
					}
					if (l >= 3 and l > i) {
						best = min(best, x - i + 1);
					}
				}
				// cout << best << endl;
			}
		}
	}
	cout << best;
}

void sieve(int n) {
	for (int i = 2; i < n; ++i) {
		isPrime[i] = true;
	}
	for (ll i = 2; i < n; ++i) {
		if (isPrime[i]) {
			for (ll j = i * i; j < n; j += i) {
				isPrime[j] = false;
			}
		}
	}
}