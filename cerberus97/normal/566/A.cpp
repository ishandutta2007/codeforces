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

const int N = 1e5 + 10, A = 26;

struct node {
	node *ch[A];
	vector<int> here[2];
	node() {
		for (int i = 0; i < A; ++i) {
			ch[i] = NULL;
		}
	}
};

int match[N];

void add0(node *root, string &s, int id);
void add1(node *root, string &s, int id);
ll solve(node *root, node *par = NULL, int depth = 0);

int main() {
	fast_cin();
	node *root = new node();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		string s; cin >> s;
		add0(root, s, i);
	}
	for (int i = 1; i <= n; ++i) {
		string s; cin >> s;
		add1(root, s, i);
	}
	cout << solve(root) << '\n';
	for (int i = 1; i <= n; ++i) {
		cout << i << ' ' << match[i] << '\n';
	}
}

void add0(node *root, string &s, int id) {
	for (auto &i : s) {
		if (!root->ch[i - 'a']) {
			root->ch[i - 'a'] = new node();
		}
		root = root->ch[i - 'a'];
		// ++root->ctr[type];
	}
	root->here[0].pb(id);
}

void add1(node *root, string &s, int id) {
	for (auto &i : s) {
		if (!root->ch[i - 'a']) {
			break;
			// root->ch[i - 'a'] = new node();
		}
		root = root->ch[i - 'a'];
		// ++root->ctr[type];
	}
	root->here[1].pb(id);
}

ll solve(node *root, node *par, int depth) {
	ll ans = 0;
	// int ans = min(root->ctr[0], root->ctr[1]);
	for (int i = 0; i < A; ++i) {
		if (root->ch[i]) {
			ans += solve(root->ch[i], root, depth + 1);
		}
	}
	while (!root->here[0].empty() and !root->here[1].empty()) {
		match[root->here[0].back()] = root->here[1].back();
		root->here[0].pop_back();
		root->here[1].pop_back();
		ans += depth;
	}
	for (int j = 0; j < 2; ++j) {
		for (auto &i : root->here[j]) {
			par->here[j].pb(i);
		}
	}
	return ans;
}