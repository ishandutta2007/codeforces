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

const int A = 26;

int main() {
	fast_cin();
	string s; cin >> s;
	vector<ll> cnt(A, 0);
	vector<vector<ll>> p_cnt(A, vector<ll>(A, 0));
	for (auto& c : s) {
		c -= 'a';
		for (int i = 0; i < A; ++i) {
			p_cnt[i][c] += cnt[i];
		}
		++cnt[c];
	}
	ll ans = *max_element(cnt.begin(), cnt.end());
	for (auto& v : p_cnt) {
		ans = max(ans, *max_element(v.begin(), v.end()));
	}
	cout << ans << '\n';
}