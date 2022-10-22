//Breathe in the air if you care, you compare, don't say farewell.. 

#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

typedef long long ll;

const int max_k = 500 + 10;
const int max_n = 5e4 + 10;

ll ans;
int n, k;
int d[max_n][max_k];
vector<int>	adj[max_n];

void dfs(int v, int p){
	d[v][0] = 1;
	for (int u:adj[v]){
		if (u == p)	continue;
		dfs(u, v);
		for (int j = 0; j < k; j++)
			d[v][j + 1] += d[u][j];
	}
	ans += d[v][k];
		
	for (int i = 1; i + i <= k; i++){
		int a = 0, b = 0;
		for (int u:adj[v])
			if (u != p)
				a += d[u][i - 1], b += d[u][k - i - 1];
		ll t = 0;
		for (int u:adj[v])
			if (u != p){
				t += (ll)d[u][i - 1] * (b - d[u][k - i - 1]);
				if (i - 1 != k - i - 1)
					t += (ll)d[u][k - i - 1] * (a - d[u][i - 1]);
			}
		ans += t/2;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0, -1);
	cout << ans << endl;
	return 0;
}