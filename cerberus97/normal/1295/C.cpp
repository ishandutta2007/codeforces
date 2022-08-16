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
	int tc; cin >> tc;
	while (tc--) {
		string s, t;
		cin >> s >> t;
		int n = s.length();
		vector<vector<int>> nxt(n + 1, vector<int>(A, n));
		for (int i = n - 1; i >= 0; --i) {
			for (int c = 0; c < A; ++c) {
				nxt[i][c] = nxt[i + 1][c];
			}
			nxt[i][s[i] - 'a'] = i;
		}
		int ans = 1, p = 0;
		for (auto& c : t) {
			if (nxt[p][c - 'a'] == n) {
				if (nxt[0][c - 'a'] == n) {
					ans = -1;
					break;
				}
				++ans;
				p = nxt[0][c - 'a'] + 1;
			} else {
				p = nxt[p][c - 'a'] + 1;
			}
		}
		cout << ans << '\n';
	}
}