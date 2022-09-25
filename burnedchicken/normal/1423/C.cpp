#include<bits/stdc++.h>
#define pb emplace_back
#define ALL(i) begin(i), end(i)
using namespace std;
using ll = long long;
#ifdef KEV
#define DE(args...) cerr << "[" << #args << "] = ", kout(args)
void kout() {cerr << endl;}
template<class T1, class ...T2>
void kout (T1 v, T2 ...e) { cerr << v << ' ', kout(e...); }
void debug(auto L, auto R) { while (L != R) cerr << *L << " \n"[next(L)==R], ++L; }
#else
#define DE(...) 0
void debug(...) {}
#endif
const int maxn = 10010;
int n, sz[maxn], k;
bool ban[maxn];
vector<int> edge[maxn];
vector<pair<int,int>> res;
int getsz(int now, int lst = -1) {
	sz[now] = 1;
	for (int u : edge[now]) if (u != lst && !ban[u])
		sz[now] += getsz(u, now);
	return sz[now];
}
int getcen(int now, int allsz, int lst = -1) {
	for (int u : edge[now]) if (u != lst && !ban[u])
		if (sz[u] * 2 > allsz)
			return getcen(u, allsz, now);
	return now;
}
void con(int now, int tp, int lst = -1) {
	static int d;
	if (ban[now]) return;
	++d;
	if (d > 1)
		res.pb(now, tp);
	for (int u : edge[now]) if (u != lst)
		con(u, tp, now);
	--d;
}
void spcon(int now, int tp, int lst = -1) {
	static int d;
	if (ban[now]) return;
	++d;
	if (d > 2)
		res.pb(now, tp);
	for (int u : edge[now]) if (u != lst)
		spcon(u, tp, now);
	--d;
}
void solve(int sd = 1) {
	static int d;
	if (getsz(sd) - 1 <= k) return;
	++d;
	int cen = getcen(sd, sz[sd]);
	getsz(cen);
	ban[cen] = true;
	int p = 0;
	for (int u : edge[cen]) if (!ban[u]) {
		if (sz[u] > sz[p]) p = u;
	}
	for (int u : edge[cen]) 
		if (u == p)
			spcon(u, cen);
		else
			con(u, cen);
	int csz = sz[sd];
	for (int u : edge[cen]) if (!ban[u])
		solve(u);
	--d;
}
signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	for (int i = 1, a, b;i < n;++i) {
		cin >> a >> b;
		edge[a].pb(b);
		edge[b].pb(a);
	}
	solve();
	DE(res.size(), n);
	assert(res.size() <= n * 10);
#ifdef KEV
	return 0;
#endif
	cout << res.size() << '\n';
	for (auto [a, b] : res)
		cout << a << ' ' << b << '\n';
}