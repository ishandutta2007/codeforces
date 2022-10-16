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

const int INF = 1e9 + 7, N = 2e5 + 7;

int p[N], cnt1[N], cnt2[N];

int find(int u) {
	return p[u] == u ? u : p[u] = find(p[u]);
}
bool unite(int x, int y) {
	x = find(x), y = find(y);
	if(x != y) {
		if(cnt1[x] + cnt1[y] < cnt2[x] + cnt2[y] + 1) return false;
		p[x] = y;
		cnt1[y] += cnt1[x];
		cnt2[y] += cnt2[x] + 1;
	} else {
		if(cnt1[x] < cnt2[x] + 1) return false;
		cnt2[y]++;
	}
	return true;
}

signed main()
{
	IO_OP;

	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) p[i] = i, cnt1[i] = 1;
	V<array<int, 3>> ee;
	for(int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		ee.PB({w, a, b});
	}
	sort(ALL(ee));
	reverse(ALL(ee));
	ll ans = 0;
	for(auto e:ee) {
		if(unite(e[1], e[2])) ans += e[0];
	}
	cout << ans << '\n';
	
}