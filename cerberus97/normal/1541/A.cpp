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
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int nxt = 0, bak_n = n;
		vector<int> ans;
		while (n) {
			if (n == 3) {
				ans.pb(nxt + 1);
				ans.pb(nxt + 2);
				ans.pb(nxt);
				nxt += 3;
				n -= 3;
			} else {
				ans.pb(nxt + 1);
				ans.pb(nxt);
				nxt += 2;
				n -= 2;
			}
		}		
		for (auto& i : ans) {
			cout << (i % bak_n) + 1 << ' ';
		}
		cout << '\n';
	}
}