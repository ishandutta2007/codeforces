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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e18 + 7, N = 2e5 + 7;

int n, m, a, b, c;
int p[N], da[N], db[N], dc[N];
vi G[N];

void BFS(int s, int*d) {
	d[s] = 1;
	queue<int> q;
	q.push(s);
	while(q.size()) {
		int u = q.front();
		q.pop();
		for(int v:G[u]) {
			if(d[v] == 0) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> m >> a >> b >> c;
		for(int i = 1; i <= m; i++) cin >> p[i];
		sort(p+1, p+m+1);
		for(int i = 1; i <= m; i++) p[i] += p[i-1];
		for(int i = 0; i < m; i++)  {
			int u, v;
			cin >> u >> v;
			G[u].PB(v);
			G[v].PB(u);
		}
		BFS(a, da);
		BFS(b, db);
		BFS(c, dc);
		int mn = INF;
		for(int i = 1; i <= n; i++) {
			int two = db[i] - 1, one = da[i] - 1 + dc[i] - 1;
			if(one + two <= m) {
				int cost = p[one+two] + p[two];
				mn = min(mn, cost);
			}
		}
		cout << mn << endl;
		for(int i = 1; i <= n; i++) {
			 G[i].clear();
			 da[i] = db[i] = dc[i] = 0;
		}
	}	
	
}