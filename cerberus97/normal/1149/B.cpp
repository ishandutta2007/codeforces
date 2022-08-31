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

const int N = 1e5 + 10, L = 260, C = 30;

int dp[L][L][L];
int nxt[N][C], len[5];
string w[5];

void upd(int i, int j, int k, int n);

int main() {
	fast_cin();
	int n, q;
	string s;
	cin >> n >> q >> s;
	s = ' ' + s;
	for (int j = 0; j < C; ++j) {
		nxt[n][j] = nxt[n + 1][j] = n + 1;
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < C; ++j) {
			nxt[i][j] = nxt[i + 1][j];
		}
		nxt[i][s[i + 1] - 'a'] = i + 1;
	}
	for (int i = 0; i < L; ++i) {
		for (int j = 0; j < L; ++j) {
			for (int k = 0; k < L; ++k) {
				dp[i][j][k] = n + 1;
			}
		}
	}
	dp[0][0][0] = 0;
	w[1] = w[2] = w[3] = "a";
	while (q--) {
		char type, c; int t;
		cin >> type >> t;
		if (type == '+') {
			cin >> c;
			++len[t];
			w[t] += c;
			int l[5] = {0}, r[5];
			l[t] = len[t];
			for (int j = 1; j <= 3; ++j) {
				r[j] = len[j];
			}
			for (int i = l[1]; i <= r[1]; ++i) {
				for (int j = l[2]; j <= r[2]; ++j) {
					for (int k = l[3]; k <= r[3]; ++k) {
						upd(i, j, k, n);
					}
				}
			}
		} else {
			--len[t];
			w[t].pop_back();
		}
		if (dp[len[1]][len[2]][len[3]] == n + 1) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
}

void upd(int i, int j, int k, int n) {
	if (!i and !j and !k) {
		dp[i][j][k] = 0;
		return;
	}
	int &ans = dp[i][j][k];
	ans = n + 1;
	if (i) {
		ans = min(ans, nxt[dp[i - 1][j][k]][w[1][i] - 'a']);
	}
	if (j) {
		ans = min(ans, nxt[dp[i][j - 1][k]][w[2][j] - 'a']);
	}
	if (k) {
		ans = min(ans, nxt[dp[i][j][k - 1]][w[3][k] - 'a']);
	}
}