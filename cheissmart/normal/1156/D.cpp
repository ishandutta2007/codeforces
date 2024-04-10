#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

vi G[2][200005];
vi sz[2];
int vis[200005],vc=1,which[2][200005];

void dfs(int u, int c) {
	vis[u] = vc;
	sz[c].back()++;
	which[c][u] = sz[c].size() - 1;
	for(int v:G[c][u]) {
		if(vis[v] != vc)
			dfs(v, c);
	}
}

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n-1;i++) {
		int u, v, w;
		cin >> u >> v >> w;
		G[w][u].PB(v);
		G[w][v].PB(u);
	}
	memset(which,0xff,sizeof which);
	for (int c=0;c<=1;c++,vc++)
		for(int i=1;i<=n;i++) {
			if(vis[i] != vc) {
				sz[c].push_back(0);
				dfs(i,c);
			}
		}
	ll ans = 0;
	for(int i=0;i<2;i++) {
		for(int j:sz[i])
			ans += 1LL * j * (j - 1);
	}
	for(int i=1;i<=n;i++)
		if(which[0][i] != -1 && which[1][i] != -1)
			ans += 1LL * (sz[0][which[0][i]] - 1) * (sz[1][which[1][i]] - 1);
	cout << ans << endl;
}