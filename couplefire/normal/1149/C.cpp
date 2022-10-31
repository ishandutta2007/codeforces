#include <bits/stdc++.h>
using namespace std;
 
const int MN = 222 * 1000;
 
struct good {
	int uR, uL;
	int dR, dL;
	int udR, udL, udA;
	int sum, ans;
} seg[MN * 4];
 
int sz;
string s;
 
good set_it(char ch) {
	good nw;
	int b = (ch == ')');
	nw.uR = nw.uL = b;
	nw.dR = nw.dL = !b;
	nw.udR = nw.udL = nw.udA = nw.ans = 1;
	nw.sum = (b? 1: -1);
	return nw;
}
 
good merge(good a, good b) {
	good m;
	m.uL = max(a.uL, b.uL + a.sum);
	m.uR = max(b.uR, a.uR + b.sum);
	m.dL = max(a.dL, b.dL - a.sum);
	m.dR = max(b.dR, a.dR - b.sum);
	m.udL = max({a.udL, a.udA + b.dL, a.sum + b.udL});
	m.udR = max({b.udR, b.udA + a.uR, -b.sum + a.udR});
	m.udA = max(a.udA - b.sum, a.sum + b.udA);
	m.sum = a.sum + b.sum;
	m.ans = max({a.ans, b.ans, a.uR + b.udL, a.udR + b.dL});
	return m;
}
 
void chng(int p, char c, int s = 0, int e = sz, int v = 1) {
//	cerr << p << ' ' << c << ' ' << s << ' ' << e << ' ' << v << endl;
	if (e - s == 1) {
		seg[v] = set_it(c);
		return;
	}
	int mid = (s + e) >> 1;
	if (p < mid)
		chng(p, c, s, mid, v * 2);
	else
		chng(p, c, mid, e, v * 2 + 1);
	seg[v] = merge(seg[v * 2], seg[v * 2 + 1]);
}
 
void build(int s = 0, int e = sz, int v = 1) {
//	if (s | e | v)
//		cerr << s << ' ' << e << ' ' << v << endl;
	if (e - s == 1) {
		seg[v] = set_it(::s[s]);
		return;
	}
	int mid = (s + e) / 2;
	build(s, mid, v * 2);
	build(mid, e, v * 2 + 1);
	seg[v] = merge(seg[v * 2], seg[v * 2 + 1]);
}
 
int main() {
	int n, q;
	cin >> n >> q;
	sz = 2 * n - 2;
	cin >> s;
	build();
	cout << seg[1].ans << endl;
//	cerr << s << endl;
	while (q--) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		chng(u, s[v]);
//		cerr << u << ' ' << s[v] << endl;
		chng(v, s[u]);
//		cerr << v << ' ' << s[u] << endl;
		swap(s[v], s[u]);
//		cerr << s << endl;
		cout << seg[1].ans << endl;
	}
}