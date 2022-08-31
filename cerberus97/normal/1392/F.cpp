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

int main() {
	fast_cin();
	int n; cin >> n;
	vector<ll> h(n);
	for (auto& i : h) {
		cin >> i;
	}
	ll len = 0, ht = 0, cnt = 0;
	for (auto& i : h) {
		++len;
		cnt += (i - ht);
		ll mx = len * (len - 1) / 2;
		ll rem = (cnt - mx) / len;
		cnt -= rem * len;
		ht += rem;
	}
	vector<ll> ans(n, 0);
	for (ll i = 1; ; ++i) {
		if (cnt >= i) {
			cnt -= i;
			++ans[n - i];
		} else {
			++ans[n - i];
			--ans[n - i + cnt];
			break;
		}
	}
	ll cur = 0;
	for (auto& i : ans) {
		cur += i;
		i = cur + ht;
		cout << i << ' ';
	}
	cout << endl;
}