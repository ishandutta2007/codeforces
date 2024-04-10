#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
 
using ll = long long;
using ld = long double;
using namespace std;

const int N = 1 << 17;
const int B = 300;

int n, a[N], cnt[N], res[N];
vector <int> pos[N];

int d[N + N];
void add(int x, int delta) {
	x += N;
	while (x) {
		d[x] += delta;
		x /= 2;
	}
}

int qq(int v = 1, int siz = N) {
	while (v < N) {
		if (d[2 * v] != siz / 2)
			v = v + v;
		else
			v = v + v + 1;
		siz /= 2;
	}
	return v - N;
}	

struct gao {
	int l, r, id;
};
vector <gao> g;

void add(int x) {
	x = a[x];
	if (!cnt[x]) add(x, 1);
	cnt[x]++;
}

void del(int x) {
	x = a[x];
	if (cnt[x] == 1) add(x, -1);
	cnt[x]--;
} 

int main() {
	add(0, 1);
	scanf ("%d", &n);
	int ones = 0;
	rep(i, 1, n) {
		scanf ("%d", a + i);
		ones += a[i] == 1;
		pos[a[i]].pb(i);
	}
	if (ones == n) return !printf ("1\n");
	rep(i, 2, n + 2) {
		int last = 0;
		for (auto x : pos[i]) {
			if (last + 1 <= x)
				g.pb({last + 1, x, i});
			last = x;
		}
		if (last + 1 <= n)
			g.pb({last + 1, n, i});
	}	
	sort(all(g), [&](gao p, gao q) {
		if (p.l / B != q.l / B)
			return p.l / B < q.l / B;
		return p.r < q.r;
	});
	int L = 0, R = 0;
	for (auto it : g) {
		int l = it.l, r = it.r, id = it.id;
		while (R < r) add(++R);
		while (L < l) del(L++);
		while (R > r) del(R--);
		while (L > l) add(--L);
		//~ cout << l << " " << r << " " << qq() << " " << id << endl;
		if (res[id] == 0 && qq() >= id)
			res[id] = 1;
		//~ cat(res[3]);
	}
	int ans = 2;
	while (res[ans]) ans++;
	printf ("%d\n", ans);
	return 0;
}