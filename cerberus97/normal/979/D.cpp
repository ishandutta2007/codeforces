/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, K = 78, B = 17, inf = 1e6;

struct Node {
	int val, ch[2];
} node[2 * K * (1 << B) + 10];

bool exists[N];
int trie_root[K], nxt_id = 1;

void insert_trie(int root, int u);
int search_trie(int root, int x, int s);
int alloc_node();

int main() {
	fast_cin();
	for (int i = 1; i < K; ++i) {
		trie_root[i] = alloc_node();
	}
	int q; cin >> q;
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int u; cin >> u;
			if (exists[u]) {
				continue;
			}
			exists[u] = true;
			for (int i = 1; i < K; ++i) {
				if (u % i == 0) {
					insert_trie(trie_root[i], u);
				}
			}
		} else {
			int x, k, s;
			cin >> x >> k >> s;
			if (x % k) {
				cout << -1 << '\n';
			} else if (k >= K) {
				int best = -1, v = -1, mx = s - x;
				for (int i = k; i <= mx; i += k) {
					if (exists[i] and (i ^ x) > best) {
						best = i ^ x;
						v = i;
					}
				}
				cout << v << '\n';
			} else {
				cout << search_trie(trie_root[k], x, s - x) << '\n';
			}
		}
	}
}

void insert_trie(int root, int u) {
	// node[root].val = min(node[root].val, u);
	for (int b = B - 1; b >= 0; --b) {
		bool cur = (u & (1 << b));
		if (!node[root].ch[cur]) {
			node[root].ch[cur] = alloc_node();
		}
		root = node[root].ch[cur];
		node[root].val = min(node[root].val, u);
	}
}

int search_trie(int root, int x, int s) {
	int v = 0;
	for (int b = B - 1; b >= 0; --b) {
		bool cur = !(x & (1 << b));
		if (!node[root].ch[cur] or node[node[root].ch[cur]].val > s) {
			cur = !cur;
			if (!node[root].ch[cur] or node[node[root].ch[cur]].val > s) {
				return -1;
			}
		}
		root = node[root].ch[cur];
		v |= (cur << b);
	}
	return v;
}

int alloc_node() {
	int id = nxt_id++;
	node[id].val = inf;
	node[id].ch[0] = 0;
	node[id].ch[1] = 0;
	return id;
}