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
 
using namespace std;
 
#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
 
const int N = 2e5 + 10;

int prv[N];
 
int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int n = s.length();
		s = " " + s;
		int ans = 0;
		prv[0] = 0;
		for (int i = 1; i <= n; ++i) {
			if (s[i] == '1') {
				prv[i] = i;
			} else {
				prv[i] = prv[i - 1];
			}
		}
		for (int r = 1; r <= n; ++r) {
			ll p2 = 1, val = 0;
			for (int l = r; l >= 1; --l) {
				val += p2 * (s[l] - '0');
				p2 *= 2;
				if (p2 > n) {
					if (val < r - l + 1) {
					} else if (prv[l - 1] < l - (val - (r - l + 1))) {
						++ans;
					}
					break;
				} else if (val == r - l + 1) {
					++ans;
				}
			}
		}
		cout << ans << '\n';
	}	
}