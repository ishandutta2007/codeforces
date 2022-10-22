#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <unordered_map>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(tint a = 0; a<(int) (n); ++a)
#define forsn(a, s, n) for(tint a = (s); a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long tint;
typedef vector<tint> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vvi> vvvi;
typedef vector<pair<tint,tint>> vp;
typedef vector<vp> vvp;
typedef tree<pair<tint, tint>,null_type,less<pair<tint, tint>>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

pair<tint, tint> dfs(tint act, tint p, vvi& tree, vi& h) {
	tint e = 0, mch = 0;
	if(p != -1) {
		if(tree[act].empty()) {
			return {h[act], h[act]};
		}
		for(auto j: tree[act]) if(j != p) {
			auto sans = dfs(j, act, tree, h);
			e += sans.first;
			mch = max(mch, sans.second);
		}
		e += max(0LL, h[act]-mch);
		mch = max(mch, h[act]);
		return {e, mch};
	} else {
		if(tree[act].size() == 1) {
			auto sans = dfs(tree[act][0], act, tree, h);
			return {sans.first + 2*h[act] - sans.second, h[act]};
		} else {
			int a = 0, b = 0;
			for(auto j: tree[act]) {
				auto sans = dfs(j, act, tree, h);
				e += sans.first;
				if(sans.second > a) {
					swap(a, b);
					a = sans.second;
				} else {
					if(sans.second > b) {
						b = sans.second;
					}
				}
			}
			return {e + 2*h[act] - a - b, h[act]};
		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
	
	forn(tc, T) {
		tint n;
		cin >> n;
		vi h(n);
		tint root = 0;
		forn(i, n) {
			cin >> h[i];
			if(h[i] > h[root]) root = i;
		}
		
		vvi tree(n);
		forn(i, n-1) {
			tint a, b;
			cin >> a >> b;
			a--; b--;
			tree[a].push_back(b);
			tree[b].push_back(a);
		}
		auto ans = dfs(root, -1, tree, h);
		cout << ans.first << endl;
	}
}