#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 4e5 + 7;

int p[N], cnt[N], vis[N];
vi G[N];

int find(int u) {
	return p[u] == u ? u : p[u] = find(p[u]);
}

void unite(int x, int y) {
	int rx = find(x), ry = find(y);
	if(rx == ry) return;
	cnt[ry] += cnt[rx];
	p[rx] = ry;
}

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	V<array<int, 3>> a;
	for(int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		a.PB({x, y, i});
		a.PB({y, x, -i});
	}
	sort(ALL(a));
	for(int i = 2; i <= 2 * n + 1; i++) p[i] = i;
	for(int i = 1; i <= n; i++) cnt[i * 2] = 1;
	set<array<int, 3>> stk;
	for(int i = 0; i < n * 2; i++) {
		int u = abs(a[i][2]) * 2, v = u + 1;
		if(a[i][2] < 0) swap(u, v);
		int y = a[i][1];
		for(auto tt:stk) {
			if(tt[0] > y) break;
			unite(tt[1], v);
			unite(tt[2], u);
			if(find(u) == find(v)) {
				cout << -1 << '\n';
				return 0;
			}
		}
		stk.insert({y, u, v});
	}
	for(int i = 1; i <= n; i++) {
		if(find(i * 2) == find(i * 2 + 1)) {
			cout << -1 << '\n';
			return 0;
		}
	}
	for(int i = 2; i <= n * 2 + 1; i++) {
		G[find(i)].PB(i);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			int x = find(i * 2), y = find(i * 2 + 1);
			ans += min(cnt[x], cnt[y]);
			for(int u:G[x]) vis[u / 2] = 1;
		}
	}
	cout << ans << '\n';
}