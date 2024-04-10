#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
 
using namespace std;	

const int T = 1 << 19;

struct nod {
	int best = 0, best2 = 0;
	int pref0 = 0, pref1 = 0, suf0 = 0, suf1 = 0;
	int pref01 = 0, pref10 = 0, suf01 = 0, suf10 = 0;
	int cnt0 = 0, cnt1 = 0;
};

void umax(int &a, int b) {
	a = max(a, b);
}

nod merge(nod a, nod b) {
	nod c;
	c.cnt0 = a.cnt0 + b.cnt0;
	c.cnt1 = a.cnt1 + b.cnt1;
	c.best = max({a.best, b.best, a.suf01 + b.pref1, a.suf0 + b.pref01});
	c.best2 = max({a.best2, b.best2, a.suf10 + b.pref0, a.suf1 + b.pref10});
	c.suf0 = (b.cnt1 == 0 ? b.suf0 + a.suf0 : b.suf0);
	c.suf1 = (b.cnt0 == 0 ? b.suf1 + a.suf1 : b.suf1);
	c.pref0 = (a.cnt1 == 0 ? a.pref0 + b.pref0 : a.pref0);
	c.pref1 = (a.cnt0 == 0 ? a.pref1 + b.pref1 : a.pref1);
	
	c.pref01 = (a.cnt1 == 0 ? a.cnt0 + b.pref01 : a.pref01);
	if (a.pref01 == a.cnt0 + a.cnt1)
		umax(c.pref01, a.pref01 + b.pref1);
	umax(c.pref01, max(c.pref0, c.pref1));
	
	c.pref10 = (a.cnt0 == 0 ? a.cnt1 + b.pref10 : a.pref10);
	if (a.pref10 == a.cnt0 + a.cnt1)
		umax(c.pref10, a.pref10 + b.pref0);
	umax(c.pref10, max(c.pref0, c.pref1));
	
	c.suf01 = (b.cnt0 == 0 ? b.cnt1 + a.suf01 : b.suf01);
	if (b.suf01 == b.cnt0 + b.cnt1)
		umax(c.suf01, b.suf01 + a.suf0);
	umax(c.suf01, max(c.suf0, c.suf1));
	
	c.suf10 = (b.cnt1 == 0 ? b.cnt0 + a.suf10 : b.suf10);
	if (b.suf10 == b.cnt0 + b.cnt1)
		umax(c.suf10, b.suf10 + a.suf1);
	umax(c.suf10, max(c.suf0, c.suf1));
	
	return c;
}
	
nod t[T + T];
bool tag[T + T];

int n, m;
char s[T];

void odwroc(int v) {
	swap(t[v].best, t[v].best2);
	swap(t[v].cnt0, t[v].cnt1);
	swap(t[v].pref01, t[v].pref10);
	swap(t[v].suf01, t[v].suf10);
	swap(t[v].pref0, t[v].pref1);
	swap(t[v].suf0, t[v].suf1);
}

void push(int v) {
	if (!tag[v]) return;
	for (auto u : {2 * v, 2 * v + 1}) {
		tag[u] ^= 1;
		odwroc(u);
	}
	tag[v] = 0;
}

void invert(int x, int y, int v = 1, int l = 0, int r = T - 1) {
	if (x <= l && r <= y) {
		tag[v] ^= 1;
		odwroc(v);
		return;
	}
	push(v);
	int m = (l + r) / 2;
	if (x <= m)
		invert(x, y, 2 * v, l, m);
	if (m < y)
		invert(x, y, 2 * v + 1, m + 1, r);
	t[v] = merge(t[2 * v], t[2 * v + 1]);
}	
	
nod query(int x, int y, int v = 1, int l = 0, int r = T - 1) {
	if (x <= l && r <= y) {
		/*printf ("%d %d\n", l, r);
		cat(t[v].best);
		cat(t[v].cnt0);
		cat(t[v].pref01);
		cat(t[v].suf01);
		cat(t[v].suf0);*/
		return t[v];
	}
	push(v);
	nod res;
	int m = (l + r) / 2;
	if (x <= m)
		res = merge(res, query(x, y, 2 * v, l, m));
	if (m < y)
		res = merge(res, query(x, y, 2 * v + 1, m + 1, r));
	return res;
}

int main() {
	scanf ("%d%d", &n, &m);
	scanf ("%s", s + 1);
	rep(i, 1, n) {
		int v = i + T;
		t[v].best = 1;
		if (s[i] == '>')
			t[v].pref0 = t[v].suf0 = t[v].pref01 = t[v].pref10 = t[v].suf01 = t[v].suf10 = t[v].cnt0 = t[v].best2 = 1;
		else
			t[v].pref1 = t[v].suf1 = t[v].pref01 = t[v].pref10 = t[v].suf01 = t[v].suf10 = t[v].cnt1 = t[v].best2 = 1;
	}
	per(i, 1, T - 1)
		t[i] = merge(t[2 * i], t[2 * i + 1]);
	while (m--) {
		int a, b;
		scanf ("%d%d", &a, &b);
		invert(a, b);
		printf ("%d\n", query(a, b).best);
	}
	
	return 0;
}