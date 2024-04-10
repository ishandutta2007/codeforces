#include<bits/stdc++.h>
using namespace std;

const int N = 14;
const int INF = int(1e9);

int dp[1 << N], par[1 << N], last[1 << N];
pair<int, int> last_pair[1 << N];
int dp2[N][N][1 << N];
int lastv[N][N][1 << N];
vector<int> bits[1 << N];

int n, m;
vector<int> g[N];

int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y; --x; --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i = 0; i < (1 << n); i++) dp[i] = INF;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) for(int z = 0; z < (1 << n); z++) dp2[i][j][z] = INF;
	for(int i = 0; i < n; i++)
		for(auto x : g[i]) {
			dp2[i][x][0] = 1;
			lastv[i][x][0] = i;
		}
	for(int mask = 0; mask < (1 << n); mask++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++){
				if((mask & (1 << i)) || (mask & (1 << j)) || (i == j) || (dp2[i][j][mask] == INF)) continue;
				for(auto z : g[j]){
					if(mask & (1 << z)) continue;
					if(z == lastv[i][j][mask]) continue;
					int nmask = mask ^ (1 << j);
					if(dp2[i][z][nmask] == INF){
						dp2[i][z][nmask] = 1;
						lastv[i][z][nmask] = j;
					}
				}
			}
	for(int mask = 0; mask < (1 << n); mask++) for(int j = 0; j < n; j++)if(mask & (1 << j)) bits[mask].push_back(j);
	dp[1] = 0;
	for(int mask = 0; mask < (1 << n); mask++)
		for(int addmask = mask; addmask; addmask = (addmask - 1) & mask) {
			int lastmask = mask ^ addmask;
			int cnt = __builtin_popcount(addmask) + 1;
			if(dp[lastmask] + cnt >= dp[mask]) continue;
			bool f = false;
			for(auto x : bits[lastmask]){
				for(auto y : bits[lastmask]){
					if(dp2[x][y][addmask] == 1){
						dp[mask] = dp[lastmask] + cnt;
						last_pair[mask] = make_pair(x, y);
						last[mask] = addmask;
					}
					if(f) break;
				}
				if(f) break;
			}
		}
	if(dp[(1 << n) - 1] == INF) cout << -1 << endl;
	else{
		cout << dp[(1 << n) - 1] << endl;
		int cur = (1 << n) - 1;
		while(cur != 1){
			int lst = last[cur];
			int x = last_pair[cur].first;
			int y = last_pair[cur].second;
			cur ^= lst;
			while(lst){
				int ny = lastv[x][y][lst];
				cout << y + 1 << " " << ny + 1 << endl;
				lst ^= (1 << ny);
				y = ny;
			}
			cout << x + 1 << " " << y + 1 << endl;
		}
	}
}