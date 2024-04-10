#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

vi G[55];
bool vis[55];

void dfs(int u) {
	vis[u] = true;
	for(int v:G[u])
		if(vis[v] == 0)
			dfs(v);
}

int main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		G[x].PB(y);
		G[y].PB(x);
	}
	vector<pi> ct;
	for(int i=0;i<n;i++) 
		ct.PB({G[i].size(), i});
	int p = 0;
	for(int i=0;i<n;i++) {
		if(vis[i] == 0) {
			p++;
			dfs(i);
		}
	}
	
	cout << (1LL << n-p) << endl;
}