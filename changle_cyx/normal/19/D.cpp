#include <bits/stdc++.h>

using namespace std; 

typedef pair<int, int> pii; 

template <class T>
inline void read(T &x) {
	static char ch; 
	while (!isdigit(ch = getchar())); 
	x = ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
}

const int INF = 0x3f3f3f3f; 
const int MaxN = 200000 + 5; 

struct table {
	int np, p[MaxN]; 
	inline void push(int x) {
		p[++np] = x; 
	}
	inline void init() {
		sort(p + 1, p + np + 1); 
		np = unique(p + 1, p + np + 1) - p - 1; 
	}
	inline int find(int x) {
		return lower_bound(p + 1, p + np + 1, x) - p; 
	}
}ta, tb; 

namespace segt {
	#define lcc x << 1, l, mid
	#define rcc x << 1 | 1, mid + 1, r
	const int MaxS = MaxN << 2; 

	int n, seg[MaxS]; 

	void upt(int x) {
		seg[x] = max(seg[x << 1], seg[x << 1 | 1]); 
	}

	void modify(int p, int d, int x = 1, int l = 1, int r = n) {
		if (l == r) return (void)(seg[x] = d); 
		int mid = (l + r) >> 1; 
		p <= mid ? modify(p, d, lcc) : modify(p, d, rcc), upt(x); 
	}

	int query(int lowx, int lowy, int x = 1, int l = 1, int r = n) {
		if (l == r) return seg[x] < lowy ? l + 1 : l; 
		if (lowx <= l && seg[x] < lowy) return r + 1; 
		
		int mid = (l + r) >> 1; 

		if (lowx > mid) return query(lowx, lowy, rcc); 
		else {
			int pl = query(lowx, lowy, lcc); 
			return pl == mid + 1 ? query(lowx, lowy, rcc) : pl; 
		}
	}
}

struct oper {
	int op, x, y; 
}; 

int n; 
vector<oper> req; 
set<int> sy[MaxN]; 

int main() {
	read(n); 
	for (int i = 1, x, y, ch; i <= n; ++i) {
		while (!isalpha(ch = getchar())); 
		read(x), read(y); 
		if (ch == 'f') ++x, ++y; 

		ta.push(x), tb.push(y); 
		req.push_back({ch == 'a' ? 0 : (ch == 'r' ? 1 : 2), x, y}); 
	}
	ta.init(), tb.init(); 

	segt::n = ta.np; 
	for (int i = 0; i < n; ++i) {
		int x = ta.find(req[i].x), y = tb.find(req[i].y); 

		if (req[i].op == 0) {
			if (sy[x].empty() || y > *prev(sy[x].end())) segt::modify(x, y); 
			sy[x].insert(y); 
		} else if (req[i].op == 1) {
			bool opt = y == *prev(sy[x].end()); 
			sy[x].erase(y); 
			if (opt) segt::modify(x, sy[x].empty() ? 0 : *prev(sy[x].end())); 
		} else {
			int px = segt::query(x, y); 
			auto it = sy[px].lower_bound(y); 

			if (it == sy[px].end()) puts("-1"); 
			else printf("%d %d\n", ta.p[px], tb.p[*it]); 
		}
	}

	return 0; 
}