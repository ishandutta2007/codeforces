#include <bits/stdc++.h>

#define fir first
#define sec second
using namespace std;
typedef long long LL;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int read() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 201234;
vector<int> e[MaxN]; int n, q;
 
int l[MaxN], r[MaxN], dn, p[MaxN], t[MaxN];
void dfs(int x) {
	l[x] = ++dn; p[dn] = x;
	for(auto y : e[x]) 
	 	dfs(y);
	r[x] = dn;
}

int seg[MaxN << 2], tag[MaxN << 2];
void build(int p, int l, int r) {
	if(l == r) seg[p] = t[:: p[r]];
	else {
		build(p << 1, l, l + r >> 1);
		build(p << 1 | 1, (l + r>> 1) + 1, r);
		seg[p] = seg[p << 1] + seg[p << 1 | 1];
	}
}

void push_down(int p, int l, int r) {
	if(l == r) return;
	if(tag[p]) {
		tag[p] = 0;
		tag[p << 1] ^= 1; tag[p << 1 | 1] ^= 1;
		seg[p << 1] = ((l + r >> 1) - l + 1) - seg[p << 1];
		seg[p << 1 | 1] = (r - (l + r >> 1)) - seg[p << 1 | 1];
	}
	
}
void modify(int p, int l, int r, int a, int b) {
	if(r < a || b < l) return;
	if(a <= l && r <= b) {
		tag[p] ^= 1; 
		seg[p] = (r - l + 1) - seg[p];
		return;
	}
	push_down(p, l, r);
	modify(p << 1, l, l + r >> 1, a, b);
	modify(p << 1 | 1, (l + r >> 1) + 1, r, a, b);
	seg[p] = seg[p << 1] + seg[p << 1 | 1]; 
}

int query(int p, int l, int r, int a, int b) {
	if(b < l || a > r) return 0;
	if(a <= l && r <= b) return seg[p];
	push_down(p, l, r);
	return query(p << 1, l, l + r >> 1, a, b) +  query(p << 1 | 1, (l + r >> 1) + 1, r, a, b);
}

int main() {
	int i;
	n = read();
	for(i = 2; i <= n; i++) {
		int p = read(); 
		e[p].push_back(i);
	}
	for(i = 1; i <= n; i++) t[i] = read();
	dfs(1);
	build(1, 1, n);
	q = read();
	while(q--) {
		char op[10];
		scanf("%s", op);
		int x = read();
		if(op[0] == 'p')
			modify(1, 1, n, l[x], r[x]);
		else
			printf("%d\n", query(1, 1, n, l[x], r[x]));
	}
	return 0;
}