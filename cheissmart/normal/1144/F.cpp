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

const int INF = 1e9 + 7;

int u[200005], v[200005], black[200005];
vi G[200005];

bool dfs(int u, int c) {
	black[u] = c;
	for(int v:G[u]) {
		if(black[v] == 0) {
			if(!dfs(v, -c))
				return false;
		}
		else if(black[v] == c)
			return false;
	}
	return true;
}

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;i++) {
		cin >> u[i] >> v[i];
		G[u[i]].PB(v[i]);
		G[v[i]].PB(u[i]);
	}
	if(!dfs(1, 1)) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for(int i=0;i<m;i++)
		if(black[u[i]]==1) cout << 0;
		else cout << 1;

}