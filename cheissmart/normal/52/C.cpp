#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e18 + 7, N = 200005;

int a[N], t[N*8], tag[N*8], n, m;

void push(int v) {
    t[v] += tag[v];
// 	t[v*2] += tag[v];
    tag[v*2] += tag[v];
    // t[v*2+1] += tag[v];
    tag[v*2+1] += tag[v];
    tag[v] = 0;
}

void bld(int v = 1, int tl = 1, int tr = n) {
	if(tl == tr) {
		t[v] = a[tl];
		return;
	}
	int tm = (tl + tr) / 2;
	bld(v*2, tl, tm);
	bld(v*2+1, tm+1, tr);
	t[v] = min(t[v*2], t[v*2+1]);
}

void upd(int l, int r, int x, int v = 1, int tl = 1, int tr = n) {
	push(v);
	if(l > r) return;
	if(l == tl && r == tr) {
        tag[v] += x;
        push(v);
		return;
	}
	int tm = (tl + tr) / 2;
	upd(l, min(r, tm), x, v*2, tl, tm);
	upd(max(tm+1, l), r, x, v*2+1, tm+1, tr);
	t[v] = min(t[v*2], t[v*2+1]);
}

int qry(int l, int r, int v = 1, int tl = 1, int tr = n) {
	push(v);
	if(l > r) return INF;
	if(l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return min(qry(l, min(tm, r), v*2, tl, tm),
			   qry(max(tm+1, l), r, v*2+1, tm+1, tr));
}

int32_t main()
{
	IO_OP;
//	freopen("out.txt", "w", stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	bld();
	
	cin >> m;
	cin.ignore();
	while(m--) {
		string buf;
		getline(cin, buf);
		stringstream ss(buf);
		int l, r, x;
		ss >> l >> r;
		l++, r++;
		if(ss >> x) { // update
			if(l > r) {
				upd(l, n, x);
				upd(1, r, x);
			} else {
				upd(l, r, x);
			}
		} else { // query
			if(l > r) {
				cout << min(qry(l, n),  qry(1, r)) << endl;
			} else {
				cout << qry(l, r) << endl;
			}
		}
	}
}