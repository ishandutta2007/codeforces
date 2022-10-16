#include <bits/stdc++.h>
#define IO_OP ios::sync_with_stdio(0), cin.tie(0)
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define SZ(v) int((v).size())
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 5e5 + 7, C = 1e6 + 7;

bitset<C> yes;

int a[N];

pi t[C * 4];
int lz[C * 4];

pi add(pi a, pi b) {
	if(a.F != b.F) return min(a, b);
	else return {a.F, a.S + b.S};
}

void apply(int v, int x) {
	t[v].F += x;
	lz[v] += x;
}

void push(int v) {
	apply(v * 2, lz[v]);
	apply(v * 2 + 1, lz[v]);
	lz[v] = 0;
}

void build(int v = 1, int tl = 1, int tr = C) {
	if(tr - tl == 1) {
		if(yes[tl]) t[v] = {0, 1};
		else t[v] = {INF, 1};
		return;
	}
	int tm = (tl + tr) / 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm, tr);
	t[v] = add(t[v * 2], t[v * 2 + 1]);
}

void upd(int l, int r, int x, int v = 1, int tl = 1, int tr = C) {
	if(l <= tl && tr <= r) {
		apply(v, x);
		return;
	}
	push(v);
	int tm = (tl + tr) / 2;
	if(l < tm) upd(l, r, x, v * 2, tl, tm);
	if(r > tm) upd(l, r, x, v * 2 + 1, tm, tr);
	t[v] = add(t[v * 2], t[v * 2 + 1]);
}

void activate(int pos) {
	upd(pos, pos + 1, -INF);
}
void deactivate(int pos) {
	upd(pos, pos + 1, INF);
}
void go(int l, int r, int x) {
	if(l < r) upd(l, r, x);
}

signed main()
{
	IO_OP;
	
	build();
	
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		activate(a[i]);
	}
	
	
	for(int i = 0; i + 1 < n; i++)
		go(a[i], a[i + 1], 1);
		
	while(q--) {
		int pos, x;
		cin >> pos >> x, pos--;
		if(pos - 1 >= 0) go(a[pos - 1], a[pos], -1);
		if(pos + 1 < n) go(a[pos], a[pos + 1], -1);
		deactivate(a[pos]);
		a[pos] = x;
		activate(a[pos]);
		if(pos - 1 >= 0) go(a[pos - 1], a[pos], 1);
		if(pos + 1 < n) go(a[pos], a[pos + 1], 1);
		cout << t[1].S << '\n';
	}
	
}