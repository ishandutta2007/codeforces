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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int M = 1e9 + 7, N = 3e5 + 5;

int p[N], pos[N], x[N], pw[N], pwi[N];
V<pi> vec;
pi b[N];

struct node {
	int cnt, lsum, rsum, e;
	node() {
		cnt = lsum = rsum = e = 0;
	}
	node(int x) {
		cnt = 1, lsum = rsum = x, e = 0;
	}
} t[N * 8];

node add(node l, node r) {
	node t;
	t.cnt = l.cnt + r.cnt;
	t.lsum = (l.lsum + pw[l.cnt] * r.lsum % M) % M;
	t.rsum = (r.rsum + pw[r.cnt] * l.rsum % M) % M;
	t.e = l.e + r.e + l.lsum * r.rsum % M * pwi[t.cnt] % M;
	t.e %= M;
	return t;
}

void upd(int pos, int op, int v=1, int tl = 0, int tr = vec.size()) {
	if(tr - tl == 1) {
		if(op == 1) t[v] = node(vec[tl].F);
		else t[v] = node();
		return;
	}
	int tm = (tl + tr) / 2;
	if(pos < tm) upd(pos, op, v*2, tl, tm);
	else upd(pos, op, v*2+1, tm, tr);
	t[v] = add(t[v*2], t[v*2+1]);
}

node qry() {
	return t[1];
}

signed main()
{
	IO_OP;
	
	pw[0] = 1;
	for(int i=1;i<N;i++)
		pw[i] = pw[i-1] * 2 % M;
	pwi[0] = 1;
	for(int i=1;i<N;i++)
		pwi[i] = pwi[i-1] * 500000004 % M;

	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> p[i];
		vec.EB(p[i], i);
		b[i] = {p[i], i};
	}
	int q;
	cin >> q;
	for(int i=0;i<q;i++) {
		cin >> pos[i] >> x[i];
		pos[i]--;
		vec.EB(x[i], -(i + 1));
	}
	sort(ALL(vec));
	for(int i=0;i<n;i++) {
		int pos = lower_bound(ALL(vec), b[i]) - vec.begin();
		upd(pos, 1);
	}
	cout << qry().e << endl;
	for(int i=0;i<q;i++) {
		int old_pos = lower_bound(ALL(vec), b[pos[i]]) - vec.begin();
		upd(old_pos, 0);
		b[pos[i]] = {x[i], -(i + 1)};
		int new_pos = lower_bound(ALL(vec), b[pos[i]]) - vec.begin();
		upd(new_pos, 1);
		cout << qry().e % M << endl;
	}
	
}