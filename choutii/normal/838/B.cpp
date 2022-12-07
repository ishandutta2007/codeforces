#include <bits/stdc++.h>

#define to first
#define v second
using namespace std;
typedef long long LL;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int inp() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}
const int MaxN = 201234;

int n, q; 
vector<pair<int, int> > e[MaxN];
int ret[MaxN], dfn[MaxN], in[MaxN], out[MaxN], dn; 
LL dep[MaxN], seg[MaxN << 2], tag[MaxN << 2];

void build(int p, int l, int r) {
	if(l == r) {
		int o = dfn[r];
		seg[p] = ret[o] + dep[o]; 
		return;
	}
	build(p << 1, l, l + r >> 1);
	build(p << 1 | 1, (l + r >> 1) + 1, r);
	seg[p] = min(seg[p << 1], seg[p << 1 | 1]);
}
void pushdown(int p) {
	if(!tag[p]) return;
	
	tag[p << 1] += tag[p];
	seg[p << 1] += tag[p]; 
	tag[p << 1 | 1] += tag[p];
	seg[p << 1 | 1] += tag[p];
	tag[p] = 0; 
}
LL query(int p, int l, int r, int a, int b) {
	if(a > r || b < l) return 1e12;
	if(a <= l && r <= b) return seg[p];
	
	pushdown(p);
	
	return min(query(p << 1, l, l + r >> 1, a, b), query(p << 1 | 1, (l + r >> 1) + 1, r, a, b));
} 

void modify(int p, int l, int r, int o, LL d){
	if(l == r) {
		seg[p] += d;
		return;
	}
	
	pushdown(p);
	
	if(o <= l + r >> 1) 
		modify(p << 1, l, l + r >> 1, o, d);
	else	
		modify(p << 1 | 1, (l + r >> 1) + 1, r, o, d);
	
	seg[p] = min(seg[p << 1], seg[p << 1 | 1]);
}

void range(int p, int l, int r, int a, int b, LL d) {
	if(a > r || b < l) return;
	
	if(a <= l && r <= b) {
		tag[p] += d;
		seg[p] += d;
		return;
	} 
	
	pushdown(p);
	
	range(p << 1, l, l + r >> 1, a, b, d);
	range(p << 1 | 1, (l + r >> 1) + 1, r, a, b, d);
	seg[p] = min(seg[p << 1], seg[p << 1 | 1]);
}

LL gdep(int o) {
	int u = in[o];
	return query(1, 1, n, u, u) -ret[o]; 
}

void dfs(int x, int fa = 0){
	dfn[++dn] = x;
	in[x] = dn;
	for(auto i : e[x]) {
		if(i.to == fa) continue;
		dep[i.to] = dep[x] + i.v;
		dfs(i.to, x);
	} 
	out[x] = dn;
}

int l[MaxN + MaxN], r[MaxN], x[MaxN];

int main() {
	int i;
	n = inp(); q = inp(); 
	
	for(i = 1; i < n; i++) {
		int u = inp(), v = inp(), w = inp();
		e[u].push_back(make_pair(v, w));
		l[i] = u, r[i] = v, x[i] = w;
	}
	
	for(i = 1; i < n; i++) {
		int u = inp(), v = inp(), w = inp();
		ret[u] = w;
		l[i + n - 1] = u;
	}
	
	dfs(1, 0);
	build(1, 1, n);
	
	for(i = 1; i <= q; i++) {
		int op = inp(), u = inp(), v = inp();
		if(op == 2) {
			if(in[u] <= in[v] && out[v] <= out[u]) {
				printf("%lld\n", gdep(v) - gdep(u));
			}else{
				LL s = query(1, 1, n, in[u], out[u]);
				printf("%lld\n", gdep(v) + s - gdep(u));
			}
		} else {
			if(n <= u && u <= (n - 1) * 2) {
				modify(1, 1, n, in[l[u]], v - ret[l[u]]);
				ret[l[u]] = v;
			}else {
				range(1, 1, n, in[r[u]], out[r[u]], v - x[u]);
				x[u] = v;
			}
		}
	}
	return 0;
}