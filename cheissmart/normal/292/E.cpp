#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

const int N = 1e5 + 87;

struct nd{
	int x, y;
	nd(){x=0, y=0;}
	nd(int _x, int _y) {
		x = _x, y = _y;
	} 
}t[N*4];

int a[N], b[N], n, m;
bool mkd[N*4];

void push(int v) {
	if(mkd[v]) {
		t[v*2] = t[v*2+1] = t[v];
		mkd[v*2] = mkd[v*2+1] = true;
		mkd[v] = 0;
	}
} 

void upd(int l, int r, int x, int y, int v=1, int tl=1, int tr=n) {
	if(l > r) return;
	if(l == tl && r == tr) {
		t[v] = nd(x, y);
		mkd[v] = true;
	} else {
		push(v);
		int tm = (tl + tr) / 2;
		upd(l,   min(r, tm), x, y, v*2,   tl,   tm);
		upd(max(l, tm+1), r, x, y, v*2+1, tm+1, tr);
	} 
}

int qry(int pos, int v=1, int tl=1, int tr=n) {
	if(tl == tr) {
		int x = t[v].x, y = t[v].y;
		if(mkd[v]) return a[pos-y+x];
		else return b[pos];
	}
	push(v);
	int tm = (tl + tr) / 2;
	if(pos <= tm)
		return qry(pos, v*2, tl, tm);
	else 
		return qry(pos, v*2+1, tm+1, tr);
}

int main()
{
	IO_OP;
	
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++)
		cin >> b[i];

	while(m--) {
		int t;
		cin >> t;
		if(t == 1) {
			int x, y, k;
			cin >> x >> y >> k;
			upd(y, y+k-1, x, y);
		} else {
			int x;
			cin >> x;
			cout << qry(x) << endl;		
		}
	}
}