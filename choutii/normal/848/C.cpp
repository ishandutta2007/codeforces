#include <bits/stdc++.h>

#define fir first
#define sec second
using namespace std;
typedef long long LL;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int inp() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 101234;
const int MaxNode = 16000000;
int n, q, a[MaxN], b[MaxN];

LL query() {
	
}

LL seg[MaxNode]; int lc[MaxNode], rc[MaxNode], pn, rot[MaxN];

void insert(int &p, int l, int r, int t, int x) {
	if(!p) p = ++pn;
	seg[p] += x; 
	if(l == r) return;
	if(t <= l + r >> 1)
		insert(lc[p], l, l + r >> 1, t, x);
	else 
		insert(rc[p], (l + r >> 1) + 1, r, t, x);
}

LL query(int p, int l, int r, int x) {
	if(!p) return 0;
	if(l == r) return seg[p];
	if(x <= l + r >> 1)
		return query(lc[p], l, l + r >> 1, x);
	else 
		return query(rc[p], (l + r >> 1) + 1, r, x) + seg[lc[p]];
}

void insert(int i, int p, int v) {
	for(; i <= n; i += i & -i)
		insert(rot[i], 0, n, p, v);
}

LL query(int i, int v) {
	LL ans = 0;
	for(; i; i -= i & -i) 
		ans += query(rot[i], 0, n, v);
	return ans;
}

set <int> s[MaxN];
typedef set<int> :: iterator setI;
void del(int p) {
	int x = a[p];
	setI y = s[x].find(p);
	setI l = y, r = y; ++r;
	if(l != s[x].begin()) {
		--l; 
		insert(*l, *y, *l - *y);
		if(r != s[x].end())
			insert(*l, *r, *r - *l);
	}
	if(r != s[x].end())
		insert(*y, *r, *y - *r);
	s[x].erase(p);
}

void add(int p) {
	int x = a[p];
	s[x].insert(p);
	setI y = s[x].find(p);
	setI l = y, r = y; ++r;
	if(l != s[x].begin()) {
		--l; 
		insert(*l, *y, *y - *l);
		if(r != s[x].end())
			insert(*l, *r, *l - *r);
	}
	if(r != s[x].end())
		insert(*y, *r, *r - *y);
}

void modify(int p, int x) {
	if(a[p] != x) {
		del(p);
		a[p] = x;
		add(p);
	}
}

int main() {
	int i;
	n = inp(); q = inp();
	for(i = 1; i <= n; i++) a[i] = inp(), add(i);
	while(q--) {
		int o, x, y;
		o = inp(); x = inp(); y = inp();
		if(o == 2) 
			printf("%I64d\n", query(y, y) - query(x - 1, y) - query(y, x - 1) + query(x - 1, x - 1));
		else 
			modify(x, y);
	}
	return 0;
}