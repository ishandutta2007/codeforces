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

const int N = 1e6 + 10, A = 5e3 + 10;

bool prime[A];
int sz[A], cnt[A], occur[A];
vector<pii> pfac[A];

int main() {
	fast_cin();
	fill(prime + 2, prime + A, true);
	for (int i = 2; i < A; ++i) {
		if (prime[i]) {
			for (int j = 2 * i; j < A; j += i) {
				prime[j] = false;
			}
		}
	}
	for (int i = 1; i < A; ++i) {
		for (int p = 2; p <= i; ++p) {
			if (!prime[p]) {
				continue;
			}
			pfac[i].pb({p, 0});
			int temp = p;
			while (temp <= i) {
				pfac[i].back().second += i / temp;
				temp *= p;
			}
			sz[i] += pfac[i].back().second;
		}
	}
	int n; cin >> n;
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		int k; cin >> k;
		++cnt[k];
		ans += sz[k];
	}
	for (int i = 2; i < A; ++i) {
		occur[pfac[i].back().first] += cnt[i];
	}
	while (true) {
		int mx_p = 0, mx_occ = 0;
		for (int i = 2; i < A; ++i) {
			if (occur[i] > mx_occ) {
				mx_occ = occur[i];
				mx_p = i;
			}
		}
		if (mx_occ <= n - mx_occ) {
			break;
		}
		ans -= mx_occ - (n - mx_occ);
		memset(occur, 0, sizeof(occur));
		for (int i = 2; i < A; ++i) {
			if (!cnt[i]) {
				continue;
			} else if (pfac[i].back().first != mx_p) {
				cnt[i] = 0;
			} else {
				--pfac[i].back().second;
				if (pfac[i].back().second == 0) {
					pfac[i].pop_back();
				}
				if (pfac[i].empty()) {
					cnt[i] = 0;
				} else {
					occur[pfac[i].back().first] += cnt[i];
				}
			}
		}
	}
	cout << ans << endl;
}