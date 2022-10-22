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

const int nax = 100005, inf = 1e9, mod = 1e9 + 7;

int n, q, a, b, c;
int val[nax];

vector <int> v[nax];
struct zap {
	int u, v, ile, id;
	bool operator < (const zap y) const {
		return ile < y.ile;
	}
};

vector <zap> prime[10000005];

vector <pair<int, int>> node[10000005];

int sito[10000005];
unordered_map <int, int> mapa;

int pre = 1, post = 1;
int in[nax], out[nax], leave[nax], h[nax], lca[nax][18], V[nax];

void dfs(int node, int par = 0) {
	in[node] = pre++;
	//cout << "Pre " << node << " " << pre - 1 << endl;
	leave[node] = post - 1;
	for(auto it: v[node]) {
		if(it != par) {
			h[it] = h[node] + 1;
			lca[it][0] = node;
			dfs(it, node);
		}
	}
	out[node] = post++;
	//cout  << "Post " << node << " " << post - 1 << endl;
}

struct fen {
	int d[2 * nax];
	void init() {
		for(int i = 0; i <= nax; ++i)
			d[i] = 0;
	}
	void add(int pos, int val) {
		for(int i = pos; i <= nax; i += i & -i)
			d[i] += val;
	}
	int daj(int x) {
		int res = 0;
		for(int i = x; i; i -= i & -i)
			res += d[i];
		return res;
	}
	int seg(int l, int r) {
		return daj(r) - daj(l - 1);
	}
};

fen Post, Pre;

int ans[nax];

int Lca(int x, int y) {
	if(h[y] > h[x])
		swap(x, y);
	for(int i = 17; 0 <= i; --i)
		if(h[x] - (1 << i) >= h[y])
			x = lca[x][i];
	if(x == y)
		return x;
	for(int i = 17; 0 <= i; --i)
		if(lca[x][i] != lca[y][i]) {
			x = lca[x][i];
			y = lca[y][i];
		}
	return lca[x][0];
}


int pt(int a, int b) {
	int res = 1;
	while(b) {
		if(b & 1)
			res = (ll) res * a % mod;
		a = (ll) a * a % mod;
		b /= 2;
	}
	return res;
}

int FUN(int x) {
	return Pre.daj(in[x]) + Post.daj(leave[x]);
}
	

int main() {
	
	Post.init();
	Pre.init();
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int N = 1e7;
	
	for(int i = 2; i <= N; ++i) {
		if(!sito[i]) 
			for(int j = i; j <= N; j += i)
				sito[j] = i;
	}
	
	cin >> n;
	for(int i = 1; i < n; ++i) {
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	for(int i = 1; i <= n; ++i) {
		cin >> val[i];
		V[i] = val[i];
		mapa.clear();
		while(val[i] != 1) {
			mapa[sito[val[i]]]++;
			val[i] /= sito[val[i]];
			
		}
		
		for(auto it: mapa) {
			node[it.fi].pb(mp(it.se, i));
		}
	}
	
	dfs(1);
	
	for(int j = 1; j <= 17; ++j)
		for(int i = 1; i <= n; ++i)
			lca[i][j] = lca[lca[i][j - 1]][j - 1];
	
	cin >> q;
	for(int i = 1; i <= q; ++i) {
		ans[i] = 1;
		cin >> a >> b >> c;
		mapa.clear();
		int d = c;
		while(d > 1) {
			mapa[sito[d]]++;
			d /= sito[d];
		}
		for(auto it: mapa) {
			zap x;
			x.u = a;
			x.v = b;
			x.id = i;
			x.ile = it.se;
			prime[it.fi].pb(x);
		}
	}
	
	for(int i = 2; i <= N; ++i) {
		if(ss(node[i]) == 0 || ss(prime[i]) == 0)
			continue;
		int wsk = 0;
		sort(node[i].begin(), node[i].end());
		sort(prime[i].begin(), prime[i].end());
		
		int maks = max(node[i].back().fi, prime[i].back().ile);
		
		for(int j = 1; j <= maks; ++j) {
			for(auto it: node[i]) {
				if(it.fi >= j) {
					Pre.add(in[it.se], 1);
					Post.add(out[it.se], -1);
				//	cout << "ADD" << it.fi << " " << i << " " << j << endl; 
				}
			}
			while(wsk < ss(prime[i]) && prime[i][wsk].ile == j) {
				int Sum = 0;
				int C = Lca(prime[i][wsk].u, prime[i][wsk].v);
				int CC = C;
				C = lca[C][0];
				Sum = FUN(prime[i][wsk].u) + FUN(prime[i][wsk].v) - 2 * FUN(C) - Pre.seg(in[CC], in[CC]);
				ans[prime[i][wsk].id] = (ll) ans[prime[i][wsk].id] * pt(i, Sum) % mod;
				wsk++;
			}
		}
		for(auto it: node[i]) {
			Pre.add(in[it.se], -it.fi);
			Post.add(out[it.se], it.fi);
		}
		
	}
	
	for(int i = 1; i <= q; ++i) {
		cout << ans[i] << endl;
	}
		
			
			
		
	
	
	
		
	
				
	
	
	
	
	
	
	
	
	
	
				
	
	
	return 0;
}