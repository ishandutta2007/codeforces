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

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

struct nd{
	nd *l, *r;
	int sm;
	nd(int val = 0) {
		l = r = nullptr;
		sm = val;
	}
	nd(nd* _l, nd* _r) {
		l = _l, r = _r;
		sm = 0;
		if(l) sm += l -> sm;
		if(r) sm += r -> sm;
	}
};

int qry(nd* t, int l, int r, int tl = 1, int tr = INF) {
	if(l > r) return 0;
	if(l == tl && r == tr) return t -> sm;
	int ret = 0;
	int tm = (tl + tr) / 2;
	if(t -> l) ret += qry(t -> l, l, min(r, tm), tl, tm);
	if(t -> r) ret += qry(t -> r, max(l, tm+1), r, tm+1, tr);
	return ret;
}

nd* upd(nd* t, int pos, int add, int tl = 1, int tr = INF) {
	if(!t) t = new nd();
	if(tl == tr) return new nd(t -> sm + add);
	int tm = (tl + tr) / 2;
	if(pos <= tm) return new nd(upd(t -> l, pos, add, tl, tm), t -> r);
	else return new nd(t -> l, upd(t -> r, pos, add, tm+1, tr));
}

map<string, int> m;
int cnt;

int to_int(string s) {
	if(m.count(s)) return m[s];
	else return m[s] = ++cnt;
}

nd* tver[100005], *mver[100005];

signed main()
{
	IO_OP;
	
	int q;
	cin >> q;
	tver[0] = new nd(), mver[0] = new nd();
	for(int i=1, x;i<=q;i++) {
		tver[i] = tver[i-1], mver[i] = mver[i-1];
		string op, s;
		cin >> op;
		if(op[0] == 's') { // set
			cin >> s >> x;
			int id = to_int(s);
			int o = qry(mver[i-1], id, id);
			tver[i] = upd(tver[i-1], x, 1);
			if(o) tver[i] = upd(tver[i], o, -1);
			mver[i] = upd(mver[i-1], id, x - o);
		} else if(op[0] == 'r') { // remove
			cin >> s;
			int id = to_int(s);
			int o = qry(mver[i-1], id, id);
			if(o) tver[i] = upd(tver[i-1], o, -1);
			if(o) mver[i] = upd(mver[i-1], id, -o);
		} else if(op[0] == 'q') { // query
			cin >> s;
			int id = to_int(s);
			int o = qry(mver[i], id, id);
			if(o <= 1) {
				cout << o-1 << endl;
				continue;
			}
			cout << qry(tver[i], 1, o-1) << endl;
		} else { // undo
			int x;
			cin >> x;
			tver[i] = tver[i-1-x], mver[i] = mver[i-1-x];
		}
	}
		
}