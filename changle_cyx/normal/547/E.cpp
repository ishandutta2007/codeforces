#include <bits/stdc++.h>

using namespace std; 

template <class T> void read(T &x) {
	static char ch; 
	while (!isdigit(ch = getchar())); 
	x = ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
}

template <class T> inline void putint(T x) {
	static char buf[25], *tail = buf; 
	if (!x) putchar('0'); 
	else {
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

const int sigma = 26; 
const int MaxN = 200000 + 5; 

namespace ACAM {
	struct node {
		int trans[sigma], fail; 
	}tr[MaxN]; 

	int nT = 1; 
	vector<int> adj[MaxN]; 
	
	vector<int> insert(char *s) { //return all prenode
		vector<int> pre; 
		int x = 1; 
		for (int i = 1, len = strlen(s + 1), c; i <= len; ++i) {
			if (!tr[x].trans[c = s[i] - 'a']) tr[x].trans[c] = ++nT; 
			pre.push_back(x = tr[x].trans[c]); 
		}
		return pre; 
	}

	void buildFail() {
		static int que[MaxN], qr; 
		for (int i = 0; i < sigma; ++i) tr[0].trans[i] = 1; 
		
		que[qr = 1] = 1; 
		for (int i = 1; i <= qr; ++i) {
			int x = que[i]; 

			if (x != 1) adj[tr[x].fail].push_back(x); 
			for (int c = 0, y, z; c < sigma; ++c) {
				y = tr[x].fail, z = tr[x].trans[c]; 
				while (!tr[y].trans[c]) y = tr[y].fail; 
				if (y = tr[y].trans[c], z) tr[que[++qr] = z].fail = y; 
				else tr[x].trans[c] = y; 
			}
		}
	}

	int dfsClock, dfn[MaxN], sze[MaxN]; 
	void dfsInit(int u = 1) {
		dfn[u] = ++dfsClock, sze[u] = 1; 
		for (int v : adj[u]) dfsInit(v), sze[u] += sze[v]; 
	}
}

namespace bit {
	int n, a[MaxN]; 
	inline void modify(int x) {
		for (; x <= n; x += x & -x) ++a[x]; 
	}
	inline int query(int l, int r) {
		--l; 
		int res = 0; 
		for (; l; l ^= l & -l) res -= a[l]; 
		for (; r; r ^= r & -r) res += a[r]; 
		return res; 
	}
}

const int MaxQ = 5e5 + 5; 

struct request {
	int opt, x, pos; 
}; 

vector<request> req[MaxQ]; 
int ans[MaxQ]; 

int n, Q; 
vector<int> prenode[MaxN]; 

int main() {
#ifdef orzczk
	freopen("a.in", "r", stdin); 
#endif
//
	scanf("%d%d", &n, &Q); 
	
	for (int i = 1; i <= n; ++i) {
		static char s[MaxN]; 
		scanf("%s", s + 1); 
		prenode[i] = ACAM::insert(s); 
	}
	
	ACAM::buildFail(); 
	ACAM::dfsInit(); 

	for (int q = 1; q <= Q; ++q) {
		int l, r, k; 
		read(l), read(r), read(k); 	
		req[l - 1].push_back({-1, prenode[k].back(), q}); 
		req[r - 0].push_back({+1, prenode[k].back(), q}); 
	}

	bit::n = ACAM::nT; 
	for (int i = 1; i <= n; ++i) {
		for (int x : prenode[i]) bit::modify(ACAM::dfn[x]); 
		for (auto p : req[i]) ans[p.pos] += p.opt * bit::query(ACAM::dfn[p.x], ACAM::dfn[p.x] + ACAM::sze[p.x] - 1); 
	}

	for (int q = 1; q <= Q; ++q) putint(ans[q]), putchar('\n'); 
	
	return 0; 
}