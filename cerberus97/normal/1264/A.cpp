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

const int N = 4e5 + 10;

int p[N];

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> p[i];
		}
		vector<int> groups;
		p[n + 1] = -1;
		int cur = 0;
		for (int i = 1; i <= n; ++i) {
			++cur;
			if (p[i] != p[i + 1]) {
				groups.pb(cur);
				cur = 0;
			}
		}
		int mx = n / 2, sum = n;
		while (sum > mx) {
			sum -= groups.back();
			groups.pop_back();
		}
		int sz = groups.size();
		int g = groups[0], s = 0, b = 0;
		int i = 1;
		while (i < sz and s <= g) {
			s += groups[i++];
		}
		while (i < sz) {
			b += groups[i++];
		}
		if (g < s and g < b) {
			cout << g << ' ' << s << ' ' << b << '\n';
		} else {
			cout << 0 << ' ' << 0 << ' ' << 0 << '\n';
		}
	}
}