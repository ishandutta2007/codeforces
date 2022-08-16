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

pair<char, int> d[N];

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> d[i].first;
			d[i].first -= '0';
			d[i].second = i - 1;
		}
		sort(d + 1, d + 1 + n);
		int pref = 1;
		while (pref + 1 <= n and d[pref].second < d[pref + 1].second) {
			++pref;
		}
		int suff = n;
		while (suff - 1 >= 1 and d[suff].second > d[suff - 1].second) {
			--suff;
		}
		d[0].second = -1;
		d[n + 1].second = n + 1;
		bool ans = false;
		for (int md = 0; md <= 9; ++md) {
			int l = n + 1, r = 0;
			for (int i = 1; i <= n; ++i) {
				if (d[i].first == md) {
					r = i;
					l = min(l, i);
				}
			}
			if (l <= r and suff <= r + 1 and pref >= l - 1) {
				ans = true;
				for (int i = l; i <= r; ++i) {
					if (d[i].second < d[l - 1].second and d[i].second > d[r + 1].second) {
						ans = false;
						break;
					}
				}
			}
			if (ans) {
				ans = true;
				string s(n, '0');
				for (int i = 1; i <= n; ++i) {
					if (i < l) {
						s[d[i].second] = '1';
					} else if (i > r) {
						s[d[i].second] = '2';
					} else if (d[i].second >= d[l - 1].second) {
						s[d[i].second] = '1';
					} else {
						s[d[i].second] = '2';
					}
				}
				cout << s << '\n';
				break;
			}
		}
		if (!ans) {
			cout << "-\n";
		}
	}
}