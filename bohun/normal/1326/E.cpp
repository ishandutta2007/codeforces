#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 3e5 + 10101;
const int pod = (1 << 19);
const int INF = 1e9;

 
struct seg {
	int t[2 * pod];
	void init() {
		rep(i, 1, 2 * pod - 1) t[i] = 0;
	}
	void add(int x, int c) {
		x += pod;
		t[x] += c;
		for (x /= 2; x; x /= 2)
			t[x] = t[2 * x] + t[2 * x + 1];
	}
	int query(int l, int r) {
		int res = 0;
		r++;
		for (l += pod, r += pod; l < r; l /= 2, r /= 2) {
			if (l & 1) res += t[l++];
			if (r & 1) res += t[--r];
		}
		return res;
	}
} bombs, gao;


struct segtre {
	LL lazy[2 * pod];
	LL mini[2 * pod];
	
	void init() {
		for(int i = 1; i < 2 * pod; ++i) {
			mini[i] = lazy[i] = 0;
		}
	}
	
	inline void push(int u, int len) {
		if(!lazy[u])
			return;
		mini[2 * u] += lazy[u];
		mini[2 * u + 1] += lazy[u];
		lazy[2 * u] += lazy[u];
		lazy[2 * u + 1] += lazy[u];
		lazy[u] = 0;
	}
	
	void add(int x, int y, LL z, int u = 1, int l = 0, int r = pod - 1) {
		if(x <= l && r <= y) {
			mini[u] += z;
			lazy[u] += z;
			return;
		}
		push(u, r - l + 1);
		int m = (l + r) / 2;
		if(x <= m)
			add(x, y, z, 2 * u, l, m);
		if(m < y)
			add(x, y, z, 2 * u + 1, m + 1, r);
		mini[u] = min(mini[2 * u], mini[2 * u + 1]);
	}
	
	LL query(int x, int y, int u = 1, int l = 0, int r = pod - 1) {
		if(x <= l && r <= y)
			return mini[u];
		push(u, r - l + 1);
		int m = (l + r) / 2;
		LL res = INF;
		if(x <= m)
			res = min(res, query(x, y, 2 * u, l, m));
		if(m < y)
			res = min(res, query(x, y, 2 * u + 1, m + 1, r));
		return res;
	}
} ja;

int BOMB[N];
int Z[N];

struct xd {
	struct nod {
		int L, R, W;
	};
	nod t[2 * pod];
	
	void init() {
		rep(i, 1, 2 * pod - 1) {
			t[i] = {0, 0, 0};
		}
	}
	
	nod merge(nod a, nod b) {
		nod c;
		c.W = a.W + b.W;
		int d = min(a.L, b.R);
		c.W += d;
		c.L = a.L + b.L - d;
		c.R = a.R + b.R - d;
		return c;
	}
	
	void akt(int pos) {
		if (BOMB[pos] == 1) t[pod + pos].R = 1;
		if (Z[pos] == 1) t[pod + pos].L = 1;
		t[pod + pos].W = 0;
		if (Z[pos] == 1 && BOMB[pos] == 1) {
			t[pos + pod].L = t[pos + pod].R = 0;
			t[pos + pod].W = 1;
		}
		pos += pod;
		pos /= 2;
		while (pos) {
			t[pos] = merge(t[2 * pos], t[2 * pos + 1]);
			pos /= 2;
		}
	}
	
	nod query(int x, int y, int u = 1, int l = 0, int r = pod - 1) {
		if (x <= l && r <= y) {
			//printf ("--- %d %d %d %d %d\n", l, r, t[u].W, t[u].L, t[u].R);
			return t[u];
		}
		int m = (l + r) / 2;
		nod ans = {0, 0, 0};
		if (x <= m) ans = merge(ans, query(x, y, 2 * u, l, m));
		if (m < y) ans = merge(ans, query(x, y, 2 * u + 1, m + 1, r));
		return ans;
	}
} on;
		
void addbomb(int x) {
	//printf ("ADD BOOMB %d\n", x);
	ja.add(x, x, -INF);
	ja.add(x, pod - 1, -1);
	BOMB[x] = 1;
	on.akt(x);
	bombs.add(x, 1);
}

void addsiebie(int x) {
	//printf ("ADD SSS %d\n", x);
	gao.add(x, 1);
	ja.add(x, pod - 1, 1);
	Z[x] = 1;
	on.akt(x);
}

bool dead(int x) {
	int k = on.query(1, x - 1).W;
	//cat(k);
	LL MINI = ja.query(x, pod - 1);
	int Left = bombs.query(1, x - 1);
	int Left1 = gao.query(1, x - 1);
	k = Left1 - k;
	//printf ("%d %lld %d %d %d\n", x, MINI, Left, Left1, k);
	if (MINI + k + Left - Left1 < 0) return true;
	return false;
}
		

int n;
int p[N], q[N], gdzie[N];

int main() {
	ja.init();
	ja.add(0, pod - 1, INF);
	bombs.init();
	gao.init();
	scanf ("%d", &n);
	rep(i, 1, n) {
		scanf ("%d", p + i);
		gdzie[p[i]] = i;
	}
	rep(i, 1, n) scanf ("%d", q + i);
	
	int ans = n;
	rep(i, 1, n) {
		if (i > 1)
		addbomb(q[i - 1]);
		while (ans > 0 && dead(gdzie[ans])) {
			addsiebie(gdzie[ans]);
			ans--;
		}
		printf ("%d ", ans);
	}
		
	
    return 0;
}