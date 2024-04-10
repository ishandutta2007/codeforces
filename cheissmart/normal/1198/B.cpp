#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7, N = 200005;

int a[N], t[N*4], tag[N*4], n;

void push(int v) {
	t[v*2] = max(t[v*2], tag[v]);
	tag[v*2] = max(tag[v*2], tag[v]);
	t[v*2+1] = max(t[v*2+1], tag[v]);
	tag[v*2+1] = max(tag[v*2+1], tag[v]);
    tag[v] = 0;
}

void upd(int l, int r, int x, int v = 1, int tl = 1, int tr = n) {
	if(l > r) return;
	if(l == tl && r == tr) {
		t[v] = max(t[v], x);
		tag[v] = max(tag[v], x);
		if(x == 0) t[v] = tag[v] = 0;
		return;
	}
	push(v);
	int tm = (tl + tr) / 2;
	upd(l, min(r, tm), x, v*2, tl, tm);
	upd(max(tm+1, l), r, x, v*2+1, tm+1, tr);
	t[v] = max(t[v*2], t[v*2+1]);
}

int qry(int l, int r, int v = 1, int tl = 1, int tr = n) {
	if(l > r) return -INF;
	if(l == tl && r == tr)
		return t[v];
	push(v);
	int tm = (tl + tr) / 2;
	return max(qry(l, min(tm, r), v*2, tl, tm),
			   qry(max(tm+1, l), r, v*2+1, tm+1, tr));
}


int32_t main()
{
	IO_OP;
	
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	int q;
	cin >> q;
	while(q--) {
		int op;
		cin >> op;
		if(op == 1) {
			int p,x;
			cin >> p >> x;
			upd(p, p, 0);
			a[p] = x;
		} else {
			int x;
			cin >> x;
			upd(1, n, x);
		}
	}
	for(int i=1;i<=n;i++)
		cout << max(qry(i,i),a[i]) << " ";
}