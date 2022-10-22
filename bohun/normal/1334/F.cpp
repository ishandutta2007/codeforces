#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define sz(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
 
using namespace std;

const int pod = (1 << 19);
const ll INF = 1e18;

struct nod {
	int l, r;
	ll min = 0, max = 0, sum = 0, lazy = 0;
};

nod operator+(nod l, nod r) {
	nod ans;
	ans.l = l.l;
	ans.r = r.r;
	ans.min = min(l.min, r.min);
	ans.max = max(l.max, r.max);
	ans.sum = l.sum + r.sum;
	return ans;
}

struct tree {
	nod t[2 * pod];
	
	tree() {
		rep(i, pod, 2 * pod - 1) t[i].l = t[i].r = i - pod;
		per(i, 1, pod - 1) t[i] = t[2 * i]  + t[2 * i + 1];
	}
	
	void akt(int v, ll z) {
		t[v].lazy += z;
		t[v].sum += z;
		t[v].min += z;
		t[v].max += z;
	}
	
	void push(int v) {
		if (t[v].lazy) {
			for (int u : {2 * v, 2 * v + 1}) 
				akt(u, t[v].lazy);
			t[v].lazy = 0;
		}
	}
	
	void add(int x, int y, ll z, int v = 1) {
		if (x <= t[v].l && t[v].r <= y) {
			akt(v, z);
			return;
		}
		push(v);
		int m = (t[v].l + t[v].r) / 2;
		if (x <= m) add(x, y, z, 2 * v);
		if (m < y) add(x, y, z, 2 * v + 1);
		t[v] = t[2 * v] + t[2 * v + 1];
	}
	
	nod query(int x, int y, int v = 1) {
		if (x <= t[v].l && t[v].r <= y) return t[v];
		push(v);
		int m = (t[v].l + t[v].r) / 2;
		nod ans;
		if (x <= m) ans = ans + query(x, y, 2 * v);
		if (m < y) ans = ans + query(x, y, 2 * v + 1);
		return ans;
	} 	
};	

const int nax = 5e5 + 100;
 
int n, m;
int a[nax]; 
int p[nax];
int b[nax];

bitset<nax> ok;
tree ja = tree();
 
int main() {
	scanf ("%d", &n);
	rep(i, 1, n) scanf ("%d", a + i);
	rep(i, 1, n) scanf ("%d", p + i);
	scanf ("%d", &m);
	rep(i, 1, m) 
		scanf ("%d", b + i);
	rep(i, 1, m) {
		ja.add(i, i, 1e18);
	}
	ok[0] = 1;
	rep(i, 1, n) {
		int pos = lower_bound(b + 1, b + m + 1, a[i]) - b - 1;
		int q;
		if (pos + 1 <= m && b[pos + 1] == a[i]) {
			q = pos + 2;
			int a = pos + 1;
			ll cost = min(ja.query(a - 1, a - 1).sum, ja.query(a, a).sum + min(p[i], 0));
			ok[a] = (ok[a] | ok[a - 1]);
			ja.add(a, a, -ja.query(a, a).sum);
			assert(ja.query(a, a).sum == 0);
			ja.add(a, a, cost);
		}
		else q = pos + 1;
		if (p[i] < 0 && q <= m) ja.add(q, m, p[i]);
		ja.add(0, pos, p[i]);
	}
			
	if (ok[m]) printf ("YES\n%lld\n", ja.query(m, m).sum);
	else printf ("NO\n");
			
	
	
	
	
    return 0;
}