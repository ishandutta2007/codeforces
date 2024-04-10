#include <bits/stdc++.h>
// file:///C:/Users/HP/Documents//source//Other/Play%20with%20Trees%20Solutions.pdf (problem C)
// https://oi-wiki.org/graph/mdst/
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

const int INF = 1e9 + 7, N = 202;

int a[N][N];
V<pi> G[N];

signed main()
{
	IO_OP;
	int n, m;
	cin >> n >> m;
	if(n == 1) {
		cout << 0 << '\n';
		return 0;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			a[i][j] = INF;
	for(int i = 1; i <= n; i++) a[i][i] = 0;
	V<array<int, 3>> edges;
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		a[u][v] = a[v][u] = w;
		edges.PB({u, v, w});
		G[u].EB(v, w);
		G[v].EB(u, w);
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
	array<int, 3> best = {INF, 0, 0}; // dist * 2, x * 2, edge id
	for(int i = 0; i < int(edges.size()); i++) { // find absolute 1-center
		auto e = edges[i];
		int u = e[0], v = e[1], w = e[2];
		// u --x----- v
		V<array<int, 2>> aux, stk;
		int mx_u = 0, mx_v = 0;
		for(int i = 1; i <= n; i++) {
			int A = a[u][i]; // x = 0
			int B = a[v][i]; // x = w
			mx_u = max(mx_u, A);
			mx_v = max(mx_v, B);
			// cerr << A << " " << B << endl;
			assert(abs(A - B) <= w);
			aux.PB({A, B});
		}
		if(mx_u < mx_v)	best = min(best, {mx_u * 2, 0 * 2, i});
		else best = min(best, {mx_v * 2, w * 2, i});
		sort(ALL(aux));
		for(auto p:aux) {
			while(stk.size() && p[1] >= stk.back()[1]) stk.pop_back();
			stk.PB(p);
		}
		for(int j = 0; j < int(stk.size()) - 1; j++) {
			// stk[j][0] + x = stk[j + 1][1] + w - x
			// => x = (stk[j + 1][1] + w - stk[j][0]) / 2
			int x2 = stk[j + 1][1] + w - stk[j][0];
			assert(0 <= x2 && x2 <= 2 * w);
			best = min(best, {stk[j][0] * 2 + x2, x2, i});
		}
	}
	cout << (double) best[0] / 2 << '\n';
}