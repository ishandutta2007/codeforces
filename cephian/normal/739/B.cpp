#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

const int N = 2e5+5;
int a[N];
int sm[N] = {};
vector<int> c[N];

const int K = 19;
int vert[N][K];
ll dist[N][K];
int ans[N] = {};

int dfs(int v) {
	for(int u : c[v]) {
		ans[v] += dfs(u);
	}
	return ans[v] + sm[v];
}

int main() {	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 2; i <= n; ++i) {
		cin >> vert[i][0];
		cin >> dist[i][0];
		c[vert[i][0]].push_back(i);
	}
	vert[1][0] = 1;
	dist[1][0] = 0;

	for(int k = 1; k < K; ++k) {
		for(int i = 1; i <= n; ++i) {
			vert[i][k] = vert[vert[i][k-1]][k-1];
			dist[i][k] = dist[vert[i][k-1]][k-1] + dist[i][k-1];
		}
	}
	
	for(int v = 2; v <= n; ++v) {
		ll d = 0;
		int u = v;
		++sm[v];
		for(int k = K-1; k >= 0; --k) {
			if(d + dist[u][k] <= a[v]) {
				d += dist[u][k];
				u = vert[u][k];
			}
		}
		--sm[u];
	}

	dfs(1);
	for(int i = 1; i <= n; ++i)
		cout << ans[i] << " ";
	cout << "\n";

}