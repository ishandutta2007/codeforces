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

const int N = 1e5 + 10;

struct st {
	ll l, r, t, p;
};

int main() {
	fast_cin();
	st s1, s2;
	cin >> s1.l >> s1.r >> s1.t;
	cin >> s2.l >> s2.r >> s2.t;
	s1.p = s1.r - s1.l + 1;
	s2.p = s2.r - s2.l + 1;
	if (s1.p < s2.p) {
		swap(s1, s2);
	}
	s2.l -= s1.l;
	s1.l = 0;
	ll g = __gcd(s1.t, s2.t);
	ll l = ((s2.l % s1.t) + s1.t) % s1.t;
	ll l_min = l - (l / g) * g;
	ll ans1 = min(s1.p - 1, l_min + s2.p - 1) - l_min + 1;
	ll l_max = l + ((s1.t - 1 - l) / g) * g;
	ll ans2 = min(s1.t + s1.p - 1, l_max + s2.p - 1) - s1.t + 1;
	cout << max(0ll, max(ans1, ans2));
}