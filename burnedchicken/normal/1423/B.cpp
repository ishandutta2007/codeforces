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
const int maxn = 10010<<1, inf = 1e9;
int ma[maxn], vis[maxn], T, lst[maxn];
int n, m;
vector< tuple<int,int,int> > alle;
vector<pair<int,int>> edge[maxn];
void expand(int x, int y) {
	while (x) {
		int ny = ma[x];
		ma[x] = y, ma[y] = x;
		y = ny, x = lst[y];
	}
}
bool bfs(int s, int mx) {
	queue<int> q;
	++T;
	q.push(s);
	
	vis[s] = T, lst[s] = 0;
	while (q.size()) {
		int x = q.front();
		DE(x);
		q.pop();
		for (auto [cost, u] : edge[x]) {
			DE(x, u);
			if (cost > mx) break;
			if (!ma[u])
				return expand(x, u), true;
			else if (exchange(vis[u], T) != T)
				q.push(ma[u]), lst[u] = x;
		}
	}
	return false;
}
bool valid(int mx) {
	int cnt = 0;
	for (int i =1 ;i <= n+n;++i)
		ma[i] = 0;

	for (int i = 1;i <= n;++i)
		if (!ma[i] && bfs(i, mx))
			++cnt;
	DE(mx, cnt);
	return cnt == n;
}
void solve() {
	int l = 1, r = inf, m;
	while (l < r) {
		m = l + r >> 1;
		if (valid(m))
			r = m;
		else l = m+1;
	}
	if (!valid(l))
		cout << -1 << '\n';
	else
		cout << l << '\n';
}
signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	alle.resize(m);
	for (auto &[w, a, b] : alle) {
		cin >> a >> b >> w;
		edge[a].pb(w, b + n);
	}
	sort(ALL(alle));
	for (int i = 1;i <= n;++i)
		sort(ALL(edge[i]));
	solve();
}