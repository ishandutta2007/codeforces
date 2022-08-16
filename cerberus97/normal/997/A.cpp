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

const int N = 1e5 + 10;

int main() {
	int n; ll x, y;
	cin >> n >> x >> y;
	string s; cin >> s;
	s += "1";
	ll k = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0' and s[i + 1] == '1') {
			++k;
		}
	}
	ll best = k * y;
	for (ll a = 1; a <= k; ++a) {
		best = min(best, a * y + (k - a) * x);
	}
	cout << best;
}