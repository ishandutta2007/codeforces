#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define FORd(i, n) for(int i = n; 1 <= i; --i)

using namespace std;
using namespace __gnu_pbds;

// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> siema;

const int nax = 500005, pod = (1 << 19);

int n;
int a, b;
int q;

int fre = 0, in[nax], out[nax];

vector <int> v[nax];
		
	
void dfs(int node, int par) {
	in[node] = fre++;
	for(auto it: v[node]) {
		if(it == par)
			continue;
		dfs(it, node);
	}
	out[node] = fre - 1;
}

struct drzewo {
	int t[pod * 2];
	int lazy[pod * 2];
	void init() {
		for(int i = 1; i < 2 * pod; ++i) {
			t[i] = lazy[i] = 0;
		}
	}
	void push(int node) {
		if(lazy[node] == 0)
			return;
		t[2 * node] = max(t[2 * node], t[node]);
		t[2 * node + 1] = max(t[2 * node + 1], t[node]);
		lazy[2 * node] = max(lazy[2 * node], lazy[node]);
		lazy[2 * node + 1] = max(lazy[2 * node + 1], lazy[node]);
		lazy[node] = 0;
	}
	
	void add(int x, int y, int val, int node = 1, int le = 0, int pr = pod - 1) {
		if(pr <= y && x <= le) {
			lazy[node] = val;
			t[node] = val;
			return ;
		}
		push(node);
		int mid = (le + pr) / 2;
		if(x <= mid)
			add(x, y, val, 2 * node, le, mid);
		if(mid < y)
			add(x, y, val, 2 * node + 1, mid + 1, pr);
		t[node] = max(t[2 * node], t[2 * node + 1]);
	}
	int daj(int x, int y, int node = 1, int le = 0, int pr = pod - 1) {
		if(pr <= y && x <= le) {
			return t[node];
		}
		push(node);
		int mid = (le + pr) / 2;
		int best = 0;
		if(x <= mid)
			best = daj(x, y, 2 * node, le, mid);
		if(mid < y)
			best = max(best, daj(x, y, 2 * node + 1, mid + 1, pr));
		return best;
	}
};

drzewo A, B;
			

int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	for(int i = 1; i < n; ++i) {
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1, 0);
	A.init();
	B.init();
	
	int q;
	cin >> q;
	for(int i = 1; i <= q; ++i) {
		int type;
		cin >> type >> a;
		if(type == 1) {
			A.add(in[a], out[a], i);
		}
		if(type == 2) {
			B.add(in[a], in[a], i);
		}
		if(type == 3) {
			int C = A.daj(in[a], in[a]);
			int D = B.daj(in[a], out[a]);
			if(C > D) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
	}
			
	
	
	
				
	
	
    return 0;
}