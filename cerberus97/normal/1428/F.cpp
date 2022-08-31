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
	string s; cin >> s;
	s = " " + s + "0";
	vector<pii> stk;
	ll ans = 0, sum = 0;
	for (int i = n; i >= 1; --i) {
		if (s[i] == '1') {
			int sz = stk.size();
			if (s[i + 1] == '1') {
				++stk[sz - 1].first;
				--stk[sz - 1].second;
				sum += (n - i + 1);
			} else {
				stk.pb({1, i});
				++sz;
				sum += (n - i + 1);
			}
			while (sz >= 2) {
				if (stk[sz - 2].first < stk[sz - 1].first) {
					stk[sz - 2] = stk[sz - 1];
					stk.pop_back();
					--sz;
				} else {
					sum -= n - (stk[sz - 2].second + stk[sz - 1].first - 1) + 1;
					break;
				}
			}
		}
		ans += sum;
	}
	cout << ans << '\n';
}