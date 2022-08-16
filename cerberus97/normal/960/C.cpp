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
	ll x, d;
	cin >> x >> d;
	vector<int> a;
	while (x) {
		ll sum = 0, p = 0;
		while (sum + (1 << p) <= x) {
			sum += (1 << p);
			++p;
		}
		x -= sum;
		a.pb(p);
	}
	vector<ll> ans;
	ll num = 1;
	for (auto &p : a) {
		for (int j = 0; j < p; ++j) {
			ans.pb(num);
		}
		num += d + 5;
	}
	cout << ans.size() << endl;
	for (auto &i : ans) {
		cout << i << ' ';
	}
}