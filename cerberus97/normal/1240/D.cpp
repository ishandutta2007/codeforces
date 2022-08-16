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

const int N = 3e5 + 10;

struct node {
	int cnt;
	node* par;
	map<int, node*> ch;
	node() : cnt(0), par(NULL) {}
};

int a[N];

ll solve(node* cur);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		node* root = new node();
		root->cnt = 1;
		node* cur = root;
		stack<int> stk;
		stk.push(-1);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			if (stk.top() == a[i]) {
				cur = cur->par;
				stk.pop();
			} else {
				if (!cur->ch[a[i]]) {
					cur->ch[a[i]] = new node();
					cur->ch[a[i]]->par = cur;
				}
				cur = cur->ch[a[i]];
				stk.push(a[i]);
			}
			++cur->cnt;
		}
		cout << solve(root) << '\n';
	}
}

ll solve(node* cur) {
	ll ans = (ll(cur->cnt) * (cur->cnt - 1)) / 2;
	for (auto &p : cur->ch) {
		ans += solve(p.second);
	}
	return ans;
}