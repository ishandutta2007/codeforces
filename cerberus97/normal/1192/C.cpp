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

const int W = 62, L = 20;
const ll mod = 998244353;

ll ctr[L][W][W], g[W][W][W];
map<char, int> seen[L];
int nxt_id[L];

ll solve(ll f[W][W], int w);
int get_id(int len, char c);

int main() {
	fast_cin();
	int n; cin >> n;
	set<string> words;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		int len = s.length();
		if (!words.count(s)) {
			++ctr[len][get_id(len, s[0])][get_id(len, s[len - 1])];
			words.insert(s);
		}
		reverse(s.begin(), s.end());
		if (!words.count(s)) {
			++ctr[len][get_id(len, s[0])][get_id(len, s[len - 1])];
			words.insert(s);
		}
	}
	ll ans = 0;
	for (int len = 3; len <= 10; ++len) {
		ans += solve(ctr[len], nxt_id[len]);
		ans %= mod;
	}
	cout << ans << endl;
}

ll solve(ll f[W][W], int w) {
	ll ans = 0;
	for (int i = 0; i < w; ++i) {
		for (int j = 0; j < w; ++j) {
			for (int k = 0; k < w; ++k) {
				g[i][j][k] = 0;
				for (int x = 0; x < w; ++x) {
					g[i][j][k] += f[i][x] * f[j][x] * f[k][x];
				}
				g[i][j][k] %= mod;
			}
		}
	}
	for (int a = 0; a < w; ++a) {
		for (int b = 0; b <= a; ++b) {
			for (int c = 0; c <= b; ++c) {
				for (int d = 0; d <= c; ++d) {
					ll temp = (g[a][b][c] * g[a][b][d]) % mod;
					temp *= (g[a][c][d] * g[b][c][d]) % mod;
					temp %= mod;
					if (a == d) {
					} else if (a == c or b == d) {
						temp *= 4;
					} else if (a == b and c == d) {
						temp *= 6;
					} else if (a == b or b == c or c == d) {
						temp *= 12;
					} else {
						temp *= 24;
					}
					ans += temp;
				}
				ans %= mod;
			}
		}
	}
	return ans;
}

int get_id(int len, char c) {
	if (!seen[len].count(c)) {
		seen[len][c] = nxt_id[len]++;
	}
	return seen[len][c];
}