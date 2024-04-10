#include <bits/stdc++.h>
using namespace std; 

template <class T>
inline void read(T &x) {
	static char ch; 
	static bool opt; 
	while (!isdigit(ch = getchar()) && ch != '-'); 
	x = (opt = ch == '-') ? 0 : ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
	if (opt) x = ~x + 1; 
}

template <class T>
inline void putint(T x) {
	static char buf[25], *tail = buf; 
	if (!x) putchar('0'); 
	else {
		if (x < 0) x = ~x + 1, putchar('0'); 
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

typedef pair<int, int> pii; 

struct ansNode {
	pii a, b, c;
	ansNode(){}
	ansNode(pii x, pii y, pii z):
		a(x), b(y), c(z) {}
	 
	inline void print() {
		putint(a.first), putchar(' ');  
		putint(a.second), putchar(' '); 
		putint(b.first), putchar(' '); 
		putint(b.second), putchar(' '); 
		putint(c.first), putchar(' '); 
		putint(c.second), putchar('\n'); 
	}
}; 

const int MaxN = 1e2 + 5; 

int n, m; 
int a[MaxN][MaxN]; 
vector<ansNode> ans; 

inline void modify(pii x, pii y, pii z) {
	ans.emplace_back(x, y, z); 
	a[x.first][x.second] ^= 1; 
	a[y.first][y.second] ^= 1; 
	a[z.first][z.second] ^= 1; 
}

inline void solve(pii p[4]) {
	int cnt = 0; 
	for (int i = 0; i < 4; ++i) {
		cnt += a[p[i].first][p[i].second]; 
	}
	
	vector<int> pos; 
	
	if (!cnt) {
		return; 
	} else if (cnt == 1) {
		for (int i = 0; i < 4; ++i) {
			if (a[p[i].first][p[i].second]) {
				pos.push_back(i); 
			}
		}
		for (int i = 0; i < 4; ++i) {
			if (!a[p[i].first][p[i].second]) {
				pos.push_back(i); 
			}
		}
	} else if (cnt == 2) {
		for (int i = 0; i < 4; ++i) {
			if (!a[p[i].first][p[i].second]) {
				pos.push_back(i); 
			}
		}
		for (int i = 0; i < 4; ++i) {
			if (a[p[i].first][p[i].second]) {
				pos.push_back(i); 
			}
		}
	} else {
		for (int i = 0; i < 4; ++i) {
			if (a[p[i].first][p[i].second]) {
				pos.push_back(i); 
			}
		}
	}
	
	modify(p[pos[0]], p[pos[1]], p[pos[2]]); 
	solve(p); 
}

void work() {
	ans.clear(); 
	
	read(n), read(m); 
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			scanf("%1d", &a[i][j]); 
		}
	
	for (int i = 1; i <= n - 2; ++i) {
		for (int j = 1; j < m; ++j)
			if (a[i][j]) {
				modify(pii(i, j), pii(i + 1, j), pii(i, j + 1)); 
			}
		if (a[i][m]) {
			modify(pii(i, m), pii(i + 1, m), pii(i + 1, m - 1)); 
		}
	}
	
	for (int j = 1; j <= m - 2; ++j) {
		pii ext1 = pii(n - 1, j + 1), ext2 = pii(n, j + 1); 
		
		if (a[n - 1][j] && a[n][j]) {
			modify(pii(n - 1, j), pii(n, j), ext1); 
		} else if (a[n - 1][j]) {
			modify(pii(n - 1, j), ext1, ext2); 
		} else if (a[n][j]) {
			modify(pii(n, j), ext1, ext2); 
		}
	}
	
	pii p[4]; 
	p[0] = pii(n, m); 
	p[1] = pii(n, m - 1); 
	p[2] = pii(n - 1, m); 
	p[3] = pii(n - 1, m - 1); 
	solve(p); 
	
	putint(ans.size()), putchar('\n'); 
	for (auto v : ans) v.print(); 
	
//	for (int i = 1; i <= n; ++i)
//		for (int  j = 1; j <= m; ++j)
//			assert(!a[i][j]); 
}

int main() {
#ifdef orzczk
	freopen("input.txt", "r", stdin); 
#endif

	int T; 
	read(T);
	while (T--) work(); 
	
	return 0; 
}