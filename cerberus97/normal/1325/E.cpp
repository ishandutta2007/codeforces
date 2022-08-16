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
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, A = 1e6 + 10, S = sqrt(A) + 10, inf = 1e9 + 42;

vector<int> g[A];

int shortest_cycle(int s);

int main() {
	fast_cin();
	vector<bool> is_prime(A, true);
	vector<int> pfactor(A, 1);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i < A; ++i) {
		if (is_prime[i]) {
			pfactor[i] = i;
			for (ll j = ll(i) * i; j < A; j += i) {
				if (is_prime[j]) {
					is_prime[j] = false;
					pfactor[j] = i;
				}
			}
		}
	}
	int ans = inf;
	int n; cin >> n;
	vector<bool> seen(A, false);
	for (int i = 1; i <= n; ++i) {
		int a; cin >> a;
		int num = 1;
		vector<int> factors;
		while (a > 1) {
			int p = pfactor[a];
			a /= p;
			if (!factors.empty() and factors.back() == p) {
				factors.pop_back();
				num /= p;
			} else {
				factors.pb(p);
				num *= p;
			}
		}
		if (factors.size() == 1) {
			factors.pb(1);
		}
		if (num == 1) {
			ans = 1;
			break;
		} else if (seen[num]) {
			ans = 2;
		} else {
			g[factors[0]].pb(factors[1]);
			g[factors[1]].pb(factors[0]);
		}
		seen[num] = true;
	}
	for (int u = 2; u < S; ++u) {
		ans = min(ans, shortest_cycle(u));
	}
	if (ans >= inf) {
		cout << -1 << '\n';
	} else {
		cout << ans << '\n';
	}
}

int shortest_cycle(int s) {
	if (g[s].empty()) {
		return inf;
	}
	vector<bool> seen(A, false);
	vector<int> dist(A, inf);
	queue<int> q;
	q.push(s);
	seen[s] = true;
	dist[s] = 0;
	int ans = inf;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto& v : g[u]) {
			if (dist[u] + 1 < dist[v]) {
				dist[v] = dist[u] + 1;
				q.push(v);
			} else if (dist[v] >= dist[u]) {
				ans = min(ans, 1 + dist[u] + dist[v]);
			}
		}
	}
	return ans;
}