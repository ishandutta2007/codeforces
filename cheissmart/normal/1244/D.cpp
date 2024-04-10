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

const int INF = 1e17 + 7;

int c[100005][3], vis[100005], dp[100005][3][3], out[100005];
vi G[100005];

int32_t main()
{
	IO_OP;
	
	int n;
	cin >> n;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<3;j++) for(int k=0;k<3;k++)
			dp[i][j][k] = INF;
	for(int i=0;i<3;i++)
		for(int j=0;j<n;j++)
			cin >> c[j][i];
	for(int i=0;i<n-1;i++) {
		int u, v;
		cin >> u >>v;
		u--, v--;
		G[u].PB(v);
		G[v].PB(u);
	}
	int root;
	for(int i=0;i<n;i++) {
		if(G[i].size() > 2) {
			cout << -1 << endl;
			return 0;
		}
		if(G[i].size() == 1)
			root = i;
	}
	vi v({root});
	vis[root] = 1;
	for(int i=0;i<n-1;i++) {
		for(int j:G[v.back()]) {
			if(!vis[j]) {
				v.PB(j);
				vis[j] = 1;
			}
		}
	}
	int ans = INF;
	int ii, jj;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)if(i != j) {
			vi vv({i, j, 1^2^i^j});
			int cans = 0;
			for(int k=0;k<n;k++) {
				cans += c[v[k]][vv[k%3]];
			}
			if(cans < ans) {
				ans = cans;
				ii = i, jj = j;
			}
		}
	cout << ans << endl;
	vi vv({ii, jj, 1^2^ii^jj});
	int cans = 0;
	for(int k=0;k<n;k++) {
		out[v[k]] = vv[k%3];
	}
	for(int i=0;i<n;i++)
		cout << out[i]+1 << " ";
}