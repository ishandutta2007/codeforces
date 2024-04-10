#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[300005], b[300005], d[300005], t[4*300005], n;
vi c[300005];

void bld(int v = 1, int tl = 0, int tr = n) {
	if(tr-tl == 1) {
		t[v] = a[tl];
		return;
	}
	int tm = (tl + tr) / 2;
	bld(v*2, tl, tm);
	bld(v*2+1, tm, tr);
	t[v] = min(t[v*2], t[v*2+1]);
}

int qry(int l, int r, int v=1, int tl = 0, int tr = n) {
	if(l >= r) return INF;
	if(tl == l && tr == r) return t[v];
	int tm = (tl + tr) / 2;
	return min(qry(l, min(tm, r), v*2, tl, tm), qry(max(l, tm), r, v*2+1, tm, tr));
}

void upd(int x, int val, int v=1, int tl = 0, int tr = n) {
	if(tr - tl == 1){
		t[v] = val;
		return;
	}
	int tm = (tl + tr) / 2;
	if(x < tm) upd(x, val, v*2, tl, tm);
	else upd(x, val, v*2+1, tm, tr);
	t[v] = min(t[v*2], t[v*2+1]);
}

bool solve() {
	cin >> n;
	for(int i=1;i<=n;i++)
		c[i].clear();
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=n-1;i>=0;i--)
		c[a[i]].PB(i);
	for(int i=0;i<n;i++)
		cin >> b[i];
	for(int i=0;i<n;i++) {
		if(c[b[i]].empty())
			return false;
		d[i] = c[b[i]].back();
		c[b[i]].pop_back();
	}
	bld();
	for(int i=0;i<n;i++) {
		if(qry(0, d[i]+1) < b[i])
			return false;
		upd(d[i], INF);
	}

	return true;
}

int main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		if(solve())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	
}