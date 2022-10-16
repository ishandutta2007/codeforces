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

const int INF = 1e9 + 7, N = 3e5 + 7;

int q[N], pos[N], n;
int t[N * 4], lazy[N * 4];

void push(int v) {
	if(lazy[v]) {
		t[v*2] += lazy[v], lazy[v*2] += lazy[v];
		t[v*2+1] += lazy[v], lazy[v*2+1] += lazy[v];
		lazy[v] = 0;
	}
}

void add(int l, int r, int val, int v = 1, int tl = 0, int tr = n) {
	if(l >= r) return;
	if(l == tl && r == tr) {
		t[v] += val;
		lazy[v] += val;
		return;
	}
	push(v);
	int tm = (tl + tr) / 2;
	add(l, min(tm, r), val, v * 2, tl, tm);
	add(max(tm, l), r, val, v * 2 + 1, tm, tr);
	t[v] = max(t[v*2], t[v*2+1]);
}

int qry(int l, int r, int v = 1, int tl  =0, int tr = n) {
	if(l >= r) return -INF;
	if(l == tl && r == tr) {
		return t[v];
	}
	push(v);
	int tm = (tl + tr) / 2;
	return max(qry(l, min(tm, r), v * 2, tl, tm), qry(max(tm, l), r, v * 2 + 1, tm, tr));
}

signed main()
{
	IO_OP;
	
	cin >> n;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		pos[t] = i;
	}
	for(int i=0;i<n;i++) cin >> q[i];
	int ans = n;
	add(0, pos[ans] + 1, 1);
	for(int i=0;i<n;i++) {
		while(t[1] <= 0) add(0, pos[--ans] + 1, 1);
		cout << ans << " ";
		add(0, q[i], -1);
	}
}