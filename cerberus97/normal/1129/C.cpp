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

const int N = 3010, C = 50, mod = 1e9 + 7;

struct node {
	node *ch[2];
	node() {
		ch[0] = ch[1] = NULL;
	}
};

ll dp[N][N];
string s = "";

inline bool valid(int l, int r);
int trie_find(node *root, string s);
void trie_insert(node *root, string s);

int main() {
	fast_cin();
	int m; cin >> m;
	ll ans = 0;
	node *root = new node();
	for (int i = 1; i < N; ++i) {
		dp[i][i - 1] = 1;
	}
	for (int n = 1; n <= m; ++n) {
		char c; cin >> c;
		// c -= '0';
		s += c;
		for (int i = n; i >= 1; --i) {
			for (int j = n; j >= n - 3 and j >= 1; --j) {
				if (valid(j, n)) {
					dp[i][n] += dp[i][j - 1];
				}
			}
			dp[i][n] %= mod;
		}
		string t = s;
		reverse(t.begin(), t.end());
		int len = trie_find(root, t);
		for (int i = 1; i <= n - len; ++i) {
			ans += dp[i][n];
			ans %= mod;
		}
		cout << ans << '\n';
		trie_insert(root, t);
	}
}

inline bool valid(int l, int r) {
	--l; --r;
	string test = s.substr(l, r - l + 1);
	if (test == "0011" or test == "0101" or test == "1110" or test == "1111") {
		return false;
	}
	return true;
}

int trie_find(node *root, string t) {
	int ans = 0;
	for (auto &i : t) {
		if (root->ch[i - '0'] == NULL) {
			return ans;
		}
		root = root->ch[i - '0'];
		++ans;
	}
	return ans;
}

void trie_insert(node *root, string t) {
	for (auto &i : t) {
		if (root->ch[i - '0'] == NULL) {
			root->ch[i - '0'] = new node();
		}
		root = root->ch[i - '0'];
	}
}