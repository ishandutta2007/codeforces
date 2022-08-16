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

const int N = 1e5 + 10, A = 26;

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n, k; string s;
		cin >> n >> k >> s;
		string ans = "";
		sort(s.begin(), s.end());
		ans = s[k - 1];
		if (s[0] == s[k - 1]) {
			if (n > k and s[k] == s[n - 1]) {
				int cnt = (n - 1) / k;
				ans += string(cnt, s[k]);
			} else {
				for (int i = k; i < n; ++i) {
					ans += s[i];
				}
			}
		}
		cout << ans << '\n';
	}
}