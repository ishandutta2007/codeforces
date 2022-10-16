#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int d[305][305];

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> d[i][j];
	cin >> m;
	for(int i=0;i<m;i++) {
		int u, v, c;
		cin >> u >> v >> c;
		u--, v--;
		if(c < d[u][v]){
			d[u][v] = d[v][u] = c;
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					d[j][i] = d[i][j] = min(d[i][j], d[i][u] + d[v][j] + d[u][v]);
				}
			}
		}
		int ans = 0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<=i;j++) {
				ans += d[i][j];
			}
		}
		cout << ans << " ";
	}
}