#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
 
using namespace std;
 
const int mod = 998244353;

int dp[200007][3];

vector<vector<pair<int, int> > > data;

void add_edge(int u, int v, int w) {
	data[u].push_back({w, v});
	data[v].push_back({w, u});
}

void dfs(int vertex, int last) {

	for (int i = 0; i < data[vertex].size(); ++i) {
		int to = data[vertex][i].second;
		if (to==last) continue;
		dfs(to, vertex);
	}

	sort(data[vertex].begin(), data[vertex].end());
	int destroyed[3][2];
	for (int i = 0; i < 3; ++i) {
		destroyed[i][0] = 1, destroyed[i][1] = 0;
	}


	for (int i = 0; i < data[vertex].size(); ++i) {
		int to = data[vertex][i].second;
		if (to != last) {
			for (int j = 0; j < 3; ++j) {
				int A = ((ll) destroyed[j][1] * dp[to][0]) % mod; //taken BEFORE
				int B = ((ll) destroyed[j][0] * dp[to][1]) % mod; //taken IN
				int C = ((ll) destroyed[j][0] * dp[to][2]) % mod; //taken AFTER on NEVER
				destroyed[j][1] = (A+B)%mod, destroyed[j][0] = C;
				//cout << destroyed[j][0] << " " << destroyed[j][1] << " " << dp[to][2] << endl;
			}
		}
		else{
			destroyed[1][1] = 0;
			destroyed[2][1] = (destroyed[2][0] + destroyed[2][1]) % mod;
			destroyed[2][0] = 0;
		}
	}

	for (int i = 0; i < 3; ++i) {
		dp[vertex][i] = (destroyed[i][0] + destroyed[i][1]) % mod;
	}




}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	data.assign(n+1, {});
	add_edge(0, 1, 0);

	for (int i = 0; i < n-1; ++i) {
		int u, v;
		cin >> u >> v;
		add_edge(u, v, i+1);
	}
 	
 	dfs(1, 0);

 	cout << dp[1][1];
 
}