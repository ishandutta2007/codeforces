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

const int N = 1e3 + 10, M = N * N;

bool prime[M];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 2; i < M; ++i) {
		prime[i] = true;
	}
	for (int i = 2; i < M; ++i) {
		if (!prime[i]) {
			continue;
		}
		for (int j = 2 * i; j < M; j += i) {
			prime[j] = false;
		}
	}
	for (int m = n; ; ++m) {
		if (prime[m]) {
			cout << m << '\n';
			for (int i = 1; i <= n; ++i) {
				cout << i << ' ' << (i % n) + 1 << '\n';
			}
			m -= n;
			int l = 1, r = n / 2 + 1;
			while (m--) {
				cout << l << ' ' << r << '\n';
				l = (l % n) + 1;
				r = (r % n) + 1;
			}
			break;
		}
	}
}