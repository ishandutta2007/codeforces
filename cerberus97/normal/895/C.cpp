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
#include <bitset>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, P = 80, mod = 1e9 + 7;

int arr[N];
bitset<N> a[P];
ll p2[N];
bool prime[P];

int rref(int n, int m);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	p2[0] = 1;
	for (int i = 1; i < N; ++i) {
		p2[i] = (2 * p2[i - 1]) % mod;
	}
	for (int i = 2; i < P; ++i) {
		prime[i] = true;
	}
	vector<int> primes;
	for (int i = 2; i < P; ++i) {
		if (prime[i]) {
			primes.pb(i);
			for (int j = 2 * i; j < P; j += i) {
				prime[j] = false;
			}
		}
	}
	int m = primes.size();
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			int ctr = 0;
			while (arr[j] % primes[i] == 0) {
				arr[j] /= primes[i];
				++ctr;
			}
			a[i][j] = (ctr & 1);
			// cout << a[i][j] << ' ';
		}
		// cout << endl;
	}
	int fvar = rref(m, n);
	cout << (p2[fvar] + mod - 1) % mod << endl;
}

int rref(int n, int m) {
	int sr = 0, pivots = 0;
	for (int j = 0; j < m; ++j) {
		for (int i = sr; i < n; ++i) {
			if (a[i][j]) {
				swap(a[i], a[sr]);
				break;
			}
		}
		if (!a[sr][j]) {
			continue;
		}
		++pivots;
		for (int i = sr + 1; i < n; ++i) {
			if (a[i][j]) {
				a[i] ^= a[sr];
			}
		}
		++sr;
	}
	return m - pivots;
}