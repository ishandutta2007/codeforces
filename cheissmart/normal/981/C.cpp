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

vi G[100005];
bool vis[100005];

int dfs(int u) {
	vis[u] = 1;
	for(int v:G[u])
		if(vis[v] == 0)
			return dfs(v);
	return u;
}

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n-1;i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].PB(v);
		G[v].PB(u);
	}
	int rt = -1;
	for(int i=0;i<n;i++) {
		if(G[i].size() > 2) {
			if(rt == -1) {
				rt = i;
			} else {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	if(rt == -1) rt = 0;
	cout << "Yes" << endl;
	cout << G[rt].size() << endl;
	vis[rt] = 1;
	for(int u:G[rt]) {
		cout << rt+1 << " " << dfs(u)+1 << endl;
	}
	
}