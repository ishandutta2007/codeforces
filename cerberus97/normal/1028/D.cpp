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

const int N = 4e5 + 10, inf = 1e9, mod = 1e9 + 7;

string s[N];
int p[N];

int main() {
	fast_cin();
	int n; cin >> n;
	ll ans = 1;
	int last_accept = 0, a1 = -inf, a2 = inf;
	set<int> have;
	have.insert(a1);
	have.insert(a2);
	for (int i = 1; i <= n; ++i) {
		cin >> s[i] >> p[i];
		if (s[i] == "ACCEPT") {
			if (p[i] < a1 or p[i] > a2) {
				cout << 0 << endl;
				return 0;
			} else if (p[i] > a1 and p[i] < a2) {
				ans = (ans * 2) % mod;
			}
			last_accept = i;
			have.erase(p[i]);
			auto it = have.lower_bound(p[i]);
			a2 = *it;
			--it;
			a1 = *it;
		} else {
			have.insert(p[i]);
		}
	}
	// cout << a1 << ' ' << a2 << endl;
	int k = 0;
	for (int i = n; i > last_accept; --i) {
		if (a1 < p[i] and p[i] < a2) {
			++k;
		}
	}
	ans = (ans * (k + 1)) % mod;
	cout << ans << endl;
}