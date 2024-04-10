#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
	
		
using namespace std;

const int pod = (1 << 17);
const int nax = 100111;

int n, m, X;
int a[nax];
int type, l, r;

struct node {
	ll ans = 0;
	vector <pair<int, int>> pref, suf; // wartosc, ile
	
	node () {
		ans = 0;
		pref.clear();
		suf.clear();
	}
} t[2 * pod];

node lacz(const node a, const node b) {
	node c = node();
	c.ans = a.ans + b.ans;
	int wsk = ss(b.pref) - 1;
	int sum = 0;
	if(ss(b.pref))
		sum = b.pref.back().se;
	for(int i = 0; i < ss(a.suf); ++i) {
		while(wsk > 0 && (a.suf[i].fi | b.pref[wsk - 1].fi) >= X) {
			wsk -= 1;
			sum += b.pref[wsk].se;
		}
		if(wsk >= 0 && (a.suf[i].fi | b.pref[wsk].fi) >= X)
			c.ans += (ll) a.suf[i].se * sum;
	}
	int val = -1;
	int ile = 0;
	for(auto it : a.pref) {
		if(val != -1 && (val | it.fi) != val) {
			c.pref.pb(mp(val, ile));
			ile = 0;
		}
		val = max(val, 0);
		val |= it.fi;
		ile += it.se;
	}
	for(auto it : b.pref) {
		if(val != -1 && (val | it.fi) != val) {
			c.pref.pb(mp(val, ile));
			ile = 0;
		}
		val |= it.fi;
		ile += it.se;
	}
	c.pref.pb(mp(val, ile));
	
	val = -1;
	ile = 0;
	
	for(auto it : b.suf) {
		if(val != -1 && (val | it.fi) != val) {
			c.suf.pb(mp(val, ile));
			ile = 0;
		}
		val = max(val, 0);
		val |= it.fi;
		ile += it.se;
	}
	for(auto it : a.suf) {
		if(val != -1 && (val | it.fi) != val) {
			c.suf.pb(mp(val, ile));
			ile = 0;
		}
		val |= it.fi;
		ile += it.se;
	}
	c.suf.pb(mp(val, ile));
	return c;
}
	

void mod(int x, int c) {
	x += pod;
	t[x].pref.clear();
	t[x].suf.clear();
	t[x].ans = (c >= X);
	t[x].pref.pb(mp(c, 1));
	t[x].suf.pb(mp(c, 1));
	x /= 2;
	while(x) {
		t[x] = lacz(t[2 * x], t[2 * x + 1]);
		x /= 2;
	}
}

node query(int x, int y, int u = 1, int l = 0, int r = pod - 1) {
	if(x <= l && r <= y)
		return t[u];
	int m = (l + r) / 2;
	node res = node();
	if(x <= m)
		res = query(x, y, 2 * u, l, m);
	if(m < y)
		res = lacz(res, query(x, y, 2 * u + 1, m + 1, r));
	return res;
}

int main() {
	scanf("%d %d %d", &n, &m, &X);
	FOR(i, 1, n)
		scanf("%d", a + i);
	FOR(i, 1, 2 * pod - 1) 
		t[i] = node();	
	FOR(i, 1, n)
		mod(i, a[i]);
		
	while(m--) {
		scanf("%d %d %d", &type, &l, &r);
		if(type == 1)
			mod(l, r);
		else {
			printf("%lld\n", query(l, r).ans);
		}
	}
	
	
	return 0;
}