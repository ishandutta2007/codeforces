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

struct node {
	ll val; int id;
	vector<node*> children;
	node(ll v) : val(v), id(0), children(0) {}
	node(ll v, int _id) : val(v), id(_id), children(0) {}
};

node* series_merge(node* n1, node* n2);
node* parallel_merge(node* n1, node* n2);
int dfs(node* u, vector<ll>& ans);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int r; cin >> r;
		char tmp; cin.get(tmp);
		string s;
		getline(cin, s);
		stack<node*> stk;
		int nid = 0;
		for (auto& c : s) {
			if (c == '(') {
				stk.push(new node(-1));
			} else if (c == 'S') {
				stk.push(new node(-2));
			} else if (c == 'P') {
				stk.push(new node(-3));
			} else if (c == '*') {
				stk.push(new node(1, nid++));
			} else if (c == ')') {
				node* cur = stk.top();
				stk.pop();
				while (stk.top()->val != -1) {
					if (stk.top()->val == -2) {
						stk.pop();
						cur = series_merge(cur, stk.top());
					} else {
						stk.pop();
						cur = parallel_merge(cur, stk.top());
					}
					stk.pop();
				}
				stk.pop();
				stk.push(cur);
			}
		}
		vector<ll> ans(nid, 0);
		ll k = dfs(stk.top(), ans);
		for (auto& i : ans) {
			i *= k * r;
		}
		cout << "REVOLTING ";
		for (auto& i : ans) {
			cout << i << ' ';
		}
		cout << '\n';
	}
}

node* series_merge(node* n1, node* n2) {
	return (n1->val < n2->val ? n1 : n2);
}

node* parallel_merge(node* n1, node* n2) {
	n1->children.pb(n2);
	n1->val += n2->val;
	return n1;
}

int dfs(node* u, vector<ll>& ans) {
	int sz = 1;
	ans[u->id] = 1;
	for (auto& v : u->children) {
		sz += dfs(v, ans);
	}
	return sz;
}