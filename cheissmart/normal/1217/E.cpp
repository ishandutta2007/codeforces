#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define endl '\n'
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e12 + 7, N = 2e5 + 7;

int a[N], n, m;
struct node{
	int ans, mn[11];
	node(int x = 0) {
		ans = INF;
		string s = to_string(x); reverse(ALL(s));
		for(int i=0;i<11;i++)
			if(i < (int)s.size() && s[i] != '0')
				mn[i] = x;
			else
				mn[i] = INF;
	}
	node operator+(const node t) const {
		node res;
		res.ans = min(ans, t.ans);
		for(int i=0;i<11;i++) {
			res.ans = min(res.ans, mn[i] + t.mn[i]);
			res.mn[i] = min(mn[i], t.mn[i]);
		}
		return res;
	}
} t[4*N];


void bld(int v = 1, int tl = 1, int tr = n) {
	if(tl == tr) {
		t[v] = node(a[tl]);
		return;
	}
	int tm = (tl + tr) / 2;
	bld(v*2, tl, tm);
	bld(v*2+1, tm+1, tr);
	t[v] = t[v*2] + t[v*2+1];
}

void upd(int pos, int x, int v = 1, int tl = 1, int tr = n) {
	if(tl == tr) {
		t[v] = node(x);
		return;
	}
	int tm = (tl + tr) / 2;
	if(pos <= tm) upd(pos, x, v*2, tl, tm);
	else upd(pos, x, v*2+1, tm+1, tr);
	t[v] = t[v*2] + t[v*2+1];
}

node qry(int l, int r, int v = 1, int tl = 1, int tr = n) {
	if(l > r) return node();
	if(l == tl && r == tr) return t[v];
	int tm = (tl + tr) / 2;
	return qry(l, min(tm, r), v*2, tl, tm) + qry(max(tm+1, l), r, v*2+1, tm+1, tr);
}

int32_t main()
{
	IO_OP;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	bld();
	while(m--) {
		int op;
		cin >> op;
		if(op == 1) {
			int i, x;
			cin >> i >> x;
			upd(i, x);
		} else {
			int l, r;
			cin >> l >> r;
			int ans = qry(l, r).ans;
			if(ans == INF) ans = -1;
			cout << ans << endl;
		}
	}
	
}