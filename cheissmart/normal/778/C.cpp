#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 3e5 + 7;

int nxt[N][26], ans[N], sz[N];
V<pair<int*, int>> his;

void set_val(int& a, int b) {
	his.EB(&a, a);
	a = b;
}

void backto(int sz) {
	assert((int) his.size() >= sz);
	while((int) his.size() > sz) {
		auto p = his.back();
		*p.F = p.S;
		his.pop_back();
	}
}

int unite(int a, int b) { // unite a into b
	int res = 1;
	for(int c = 0; c < 26; c++) {
		if(nxt[a][c] == 0) continue;
		if(nxt[b][c] == 0) {
			set_val(nxt[b][c], nxt[a][c]);
		} else {
			res += unite(nxt[a][c], nxt[b][c]);
		}
	}
	return res;
}

void dfs(int u, int d = 0) {
	sz[u] = 1;
	int mx = -1, mxc = -1;
	vi ch;
	for(int c = 0; c < 26; c++) {
		if(nxt[u][c] == 0) continue;
		int v = nxt[u][c];
		ch.PB(v);
		dfs(v, d + 1);
		sz[u] += sz[v];
		if(sz[v] > mx) {
			mx = sz[v];
			mxc = v;
		}
	}
	if(ch.empty()) return;
	int tt = his.size();
	ans[d]++;
	for(int v:ch) if(v != mxc)
		ans[d] += unite(v, mxc);
	backto(tt);
}

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		int u, v, c;
		char cc;
		cin >> u >> v >> cc;
		c = cc - 'a';
		nxt[u][c] = v;
	}
	dfs(1);
	int mn = n, p = -1;
	for(int i = 0; i < n; i++) {
		if(n - ans[i] < mn) {
			mn = n - ans[i];
			p = i + 1;
		}
	}
	cout << mn << endl;
	cout << p << endl;

}