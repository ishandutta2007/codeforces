#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
 
const int maxn = 200001;
const int maxb = 201;
const int maxc = 1201;
 
struct vec {
	long long x, y;
	vec() {}
	vec(long long x, long long y) :x(x), y(y) {}
	vec operator -(const vec &v) const { return vec(x - v.x, y - v.y); }
	long long operator *(const vec &v) const { return x * v.y - y * v.x; }
	long double operator ^(const vec &v) const { return (long double)x * v.y - (long double)y * v.x; }
};
 
vector<int> adj[maxn];
int a[maxn], b[maxn];
int prv[maxn], cnt[maxn];
int rev[maxn];
int n, q;
 
void dfs(int u);
void init();
void modify(int l, int r, int d);
long long cal(int l, int r);
 
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 2; i <= n; i++) {
		int prt;
		scanf("%d", &prt);
		adj[prt].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
	}
	dfs(1);
	init();
	for (int i = 1; i <= q; i++) {
		int type;
		scanf("%d", &type);
		if (type == 1) {
			int v, x;
			scanf("%d%d", &v, &x);
			modify(prv[v], prv[v] + cnt[v] - 1, x);
		}
		else {
			int v;
			scanf("%d", &v);
			long long ans = cal(prv[v], prv[v] + cnt[v] - 1);
			printf("%lld\n", ans);
		}
	}
	return 0;
}
 
void dfs(int u) {
	static int t = 0;
	prv[u] = ++t;
	cnt[u] = 1;
	rev[t] = u;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		a[v] += a[u];
		b[v] += b[u];
		dfs(v);
		cnt[u] += cnt[v];
	}
}
 
int bel[maxn];
int st[maxc], en[maxc];
long long x[maxn], y[maxn];
long long k[maxc];
int id[maxn];
vec stku[maxc][maxb], stkd[maxc][maxb];
int topu[maxc], topd[maxc];
int posu[maxc], posd[maxc];
int bsz, bcnt;
 
bool cmp(int a, int b) {
	if (x[a] != x[b]) return x[a] < x[b];
	return y[a] < y[b];
}
 
void init() {
	bsz = max(1, (int)sqrt(n / 6));
	for (int i = 1; i <= n; i++) {
		bel[i] = i / bsz + 1;
		if (bel[i] != bel[i - 1]) {
			en[bcnt] = i - 1;
			st[++bcnt] = i;
		}
	}
	en[bcnt] = n;
	for (int i = 1; i <= n; i++) {
		x[i] = b[rev[i]];
		y[i] = a[rev[i]] * x[i];
	}
	for (int i = 1; i <= n; i++) id[i] = i;
	for (int b = 1; b <= bcnt; b++) {
		sort(id + st[b], id + en[b] + 1, cmp);
		for (int i = st[b]; i <= en[b]; i++) {
			vec v(x[id[i]], y[id[i]]);
			while (topu[b] >= 2 && (stku[b][topu[b]] - stku[b][topu[b] - 1] ^ v - stku[b][topu[b]]) >= 0) topu[b]--;
			stku[b][++topu[b]] = v;
			while (topd[b] >= 2 && (stkd[b][topd[b]] - stkd[b][topd[b] - 1] ^ v - stkd[b][topd[b]]) <= 0) topd[b]--;
			stkd[b][++topd[b]] = v;
		}
		posu[b] = 1;
		posd[b] = topd[b];
	}
}
 
void modify_macro(int b, int d) {
	k[b] += d;
}
 
void modify_micro(int b, int l, int r, int d) {
	for (int i = st[b]; i <= en[b]; i++) {
		y[i] += k[b] * x[i];
	}
	k[b] = 0;
	for (int i = l; i <= r; i++) {
		y[i] += d * x[i];
	}
	topu[b] = topd[b] = 0;
	for (int i = st[b]; i <= en[b]; i++) {
		vec v(x[id[i]], y[id[i]]);
		while (topu[b] >= 2 && (stku[b][topu[b]] - stku[b][topu[b] - 1] ^ v - stku[b][topu[b]]) >= 0) topu[b]--;
		stku[b][++topu[b]] = v;
		while (topd[b] >= 2 && (stkd[b][topd[b]] - stkd[b][topd[b] - 1] ^ v - stkd[b][topd[b]]) <= 0) topd[b]--;
		stkd[b][++topd[b]] = v;
	}
	posu[b] = 1;
	posd[b] = topd[b];
}
 
void modify(int l, int r, int d) {
	for (int b = 1; b <= bcnt; b++) {
		if (st[b] >= l && en[b] <= r) modify_macro(b, d);
		else if (max(l, st[b]) <= min(r, en[b])) modify_micro(b, max(l, st[b]), min(r, en[b]), d);
	}
}
 
long long cal_macro(int b) {
	vec v(1, -k[b]);
	while (posu[b] < topu[b] && v*stku[b][posu[b]] < v*stku[b][posu[b] + 1]) posu[b]++;
	while (posd[b] > 1 && v*stkd[b][posd[b]] > v*stkd[b][posd[b] - 1]) posd[b]--;
	return max(v*stku[b][posu[b]], -(v * stkd[b][posd[b]]));
}
 
long long cal_micro(int b, int l, int r) {
	long long ans = 0;
	for (int i = l; i <= r; i++) {
		ans = max(ans, max(k[b] * x[i] + y[i], -k[b] * x[i] - y[i]));
	}
	return ans;
}
 
long long cal(int l, int r) {
	long long ans = 0;
	for (int b = 1; b <= bcnt; b++) {
		if (st[b] >= l && en[b] <= r) ans = max(ans, cal_macro(b));
		else if (max(l, st[b]) <= min(r, en[b])) ans = max(ans, cal_micro(b, max(l, st[b]), min(r, en[b])));
	}
	return ans;
}