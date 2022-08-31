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

const int N = 1e5 + 10, mod = 998244353;

int add(int a, int b) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
	return a;
}

int mul(ll a, int b) {
	return (a * b) % mod;
}

int get_ans(int n, int a, int b);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (auto& i : a) {
			cin >> i;
		}
		int mx = -1, mx_cnt = 0;
		for (auto& i : a) {
			if (i > mx) {
				mx = i;
				mx_cnt = 1;
			} else if (i == mx) {
				++mx_cnt;
			}
		}
		int ans = -1;
		if (mx_cnt > 1) {
			ans = get_ans(n, 1, 1);
		} else {
			int cnt = count(a.begin(), a.end(), mx - 1);
			ans = get_ans(n, cnt, cnt + 1);
		}
		cout << ans << '\n';
	}
}

int get_ans(int n, int a, int b) {
	int ans = 1;
	for (int i = 1; i <= n; ++i) {
		if (i != b) {
			ans = mul(ans, i);
		}
	}
	return mul(ans, a);
}