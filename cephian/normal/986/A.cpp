#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 1e5+5;
vector<int> G[N];
vector<int> goods[105];
int costs[N][105];

int main() {
	fio;	
	int n, m, k, s;
	cin >> n >> m >> k >> s;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		goods[--a].push_back(i);
	}

	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	
	for(int i = 0; i < k; ++i) {
		queue<int> Q;
		for(int j = 0; j < n; ++j)
			costs[j][i] = -1;
		for(int x : goods[i]) {
			costs[x][i] = 0;
			Q.push(x);
		}
		while(!Q.empty()) {
			int v = Q.front();
			Q.pop();
			for(int u : G[v]) {
				if(costs[u][i] == -1) {
					costs[u][i] = costs[v][i] + 1;
					Q.push(u);
				}
			}
		}
	}
	for(int i = 0; i < n; ++i) {
		int ans = 0;
		sort(costs[i], costs[i] + k);
		for(int j = 0; j < s; ++j) {
			ans += costs[i][j];
		}
		cout << ans << " ";
	}
	cout << "\n";
}