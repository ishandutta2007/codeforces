#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define LL long long
#define LD long double
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define boost cin.tie(0), ios_base::sync_with_stdio(0);


using namespace std;		

const int nax = 2e5 + 111;

const int pod = (1 << 18);

struct segtre {
	LL lazy[2 * pod];
	LL sum[2 * pod];
	
	void init() {
		for(int i = 1; i < 2 * pod; ++i) {
			sum[i] = lazy[i] = 0;
		}
	}
	
	inline void push(int u, int len) {
		if(!lazy[u])
			return;
		sum[2 * u] += lazy[u];
		sum[2 * u + 1] += lazy[u];
		lazy[2 * u] += lazy[u];
		lazy[2 * u + 1] += lazy[u];
		lazy[u] = 0;
	}
	
	void add(int x, int y, LL z, int u = 1, int l = 0, int r = pod - 1) {
		if(x <= l && r <= y) {
			sum[u] += z;
			lazy[u] += z;
			return;
		}
		push(u, r - l + 1);
		int m = (l + r) / 2;
		if(x <= m)
			add(x, y, z, 2 * u, l, m);
		if(m < y)
			add(x, y, z, 2 * u + 1, m + 1, r);
		sum[u] = min(sum[2 * u], sum[2 * u + 1]);
	}
	
	LL query(int x, int y, int u = 1, int l = 0, int r = pod - 1) {
		if(x <= l && r <= y)
			return sum[u];
		push(u, r - l + 1);
		int m = (l + r) / 2;
		LL res = 1e18;
		if(x <= m)
			res = query(x, y, 2 * u, l, m);
		if(m < y)
			res = min(res, query(x, y, 2 * u + 1, m + 1, r));
		return res;
	}
} ja;

int n;
int p[nax];
int cost[nax];	
int a[nax];

LL ans = 1e18;
LL pref[nax];



int main() {	
	scanf ("%d", &n);
	FOR(i, 1, n) scanf ("%d", p + i);
	FOR(i, 1, n) {
		scanf ("%d", a + i); 
		cost[p[i]] = a[i];
	}
	FOR(i, 1, n) {
		pref[i] = pref[i - 1] + cost[i];
	}
	LL sum = 0;
	FOR(i, 1, n) ja.add(i, i, pref[i]);
	for (int i = 1; i < n; ++i) {
		sum += a[i];
		ja.add(p[i], n, -2 * a[i]);
		ans = min(ans, sum + ja.sum[1]);
	}
	printf ("%lld", ans);	
	
	return 0;
}