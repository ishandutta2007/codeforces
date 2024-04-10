#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 5e5 + 7, M = 1 << 21;

int a[N], b[N], e[M * 3], n, cnt;

vi G[M];
deque<int> stk;

void link(int val, int x, int k) {
	val &= (1 << k) - 1;
	e[cnt] = x ^ (val + 2 * n);
	G[x].PB(cnt);
	G[val + 2 * n].PB(cnt);
	cnt++;
}

void dfs(int u) {
	while(G[u].size()) {
		int edge = G[u].back(); G[u].pop_back();
		if(e[edge] == -1) continue;
		int v = e[edge] ^ u;
		e[edge] = -1;
		dfs(v);
	}
	if(u < 2 * n)
		stk.PB(u);
}

bool ok(int k) {
	int tot = 2 * n + (1 << k);
	for(int i = 0; i < tot; i++) G[i].clear();
	cnt = 0;
	for(int i = 0; i < n; i++) {
		int x = 2 * i, y = x + 1;
		link(a[i], x, k);
		link(b[i], y, k);
		e[cnt] = x ^ y;
		G[x].PB(cnt);
		G[y].PB(cnt);
		cnt++;
	}
	for(int i = 0; i < tot; i++) {
		if(G[i].size() & 1) return false;
	}
	stk.clear();
	dfs(0);
	if(stk.size() != 2 * n + 1) return false;
	stk.pop_back();
	if(stk[0]/2 != stk[1]/2) stk.PB(stk.front()), stk.pop_front();
	cout << k << endl;
	for(int i:stk) cout << i + 1 << " ";
	cout << endl;
	return true;
}

signed main()
{
	IO_OP;
	
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	for(int i = 20; i >= 0; i--)
		if(ok(i)) return 0;
}