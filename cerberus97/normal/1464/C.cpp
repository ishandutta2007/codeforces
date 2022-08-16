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

const int N = 1e5 + 10;

void fail();

int main() {
	fast_cin();
	int n; ll T;
	cin >> n >> T;
	string s; cin >> s;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = (1ll << (s[i] - 'a'));
	}
	T += a[n - 2] - a[n - 1];
	a[n - 2] = 0; a[n - 1] = 0;
	ll X = accumulate(a.begin(), a.end(), 0ll);
	if (abs(X + T) % 2 or abs(T) > abs(X)) {
		fail();
	}
	ll sum = (X + T) / 2;
	sort(a.begin(), a.end(), greater<ll>());
	for (auto& i : a) {
		if (sum >= i) {
			sum -= i;
		}
	}
	if (sum == 0) {
		cout << "Yes\n";
	} else {
		fail();
	}
}

void fail() {
	cout << "No\n";
	exit(0);
}