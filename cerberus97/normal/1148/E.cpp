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

const int N = 3e5 + 10;

struct ans_t {
	int i, j, d;
};

vector<ans_t> moves;
pii s[N];
int t[N];

int main() {
	fast_cin();
	int n; cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i].first;
		sum += s[i].first;
		s[i].second = i;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> t[i];
		sum -= t[i];
	}
	sort(s + 1, s + 1 + n);
	sort(t + 1, t + 1 + n);
	if (sum or s[1].first > t[1] or s[n].first < t[n]) {
		cout << "NO\n";
		return 0;
	}
	int p = 2;
	for (int l = 1; l <= n;) {
		if (s[l].first == t[l]) {
			++l;
			continue;
		} else if (s[l].first > t[l]) {
			cout << "NO\n";
			return 0;
		}
		while (p <= n and s[p].first <= t[p]) {
			++p;
		}
		int d = min(t[l] - s[l].first, s[p].first - t[p]);
		moves.pb({s[l].second, s[p].second, d});
		s[l].first += d;
		s[p].first -= d;
	}


	// int p = 1;
	// while (p + 1 <= n and s[p + 1].first <= t[p + 1]) {
	// 	++p;
	// }
	// int l = p, r = p + 1;
	// while (true) {
	// 	while (l >= 1 and s[l].first == t[l]) {
	// 		--l;
	// 	}
	// 	while (r <= n and s[r].first == t[r]) {
	// 		++r;
	// 	}
	// 	if (l < 1 or r > n) {
	// 		break;
	// 	}
	// 	int d = min(t[l] - s[l].first, s[r].first - t[r]);
	// 	moves.pb({s[l].second, s[r].second, d});
	// 	s[l].first += d;
	// 	s[r].first -= d;
	// }
	cout << "YES\n" << moves.size() << '\n';
	for (auto &i : moves) {
		cout << i.i << ' ' << i.j << ' ' << i.d << '\n';
	}
}