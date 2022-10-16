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

const int INF = 1e9 + 7, N = 2e5 + 7;

vi G[N];

int cnt[2];

void dfs(int u, int p = -1, int depth = 0) {
	cnt[depth]++;
	for(int v:G[u]) if(p ^ v) dfs(v, u, depth^1);
}

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	dfs(1);
	cout << min(cnt[0], cnt[1]) - 1 << endl;
}