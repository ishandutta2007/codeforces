#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 30 + 3;

int n;
vector<int> adj[MAXN];
ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, 1, 0, -1};
pair<ll, ll> ans[MAXN];

int f(int x){
	while (x >= 4)	x -= 4;
	return x;
}

void dfs(int v, ll x, ll y, int p = -1, int prev = -1, ll zz = 1e15){
	ans[v] = {x, y};
	int cur = 0;
	for (int u:adj[v])
		if (u^p){
			while (cur == prev)	cur++;
			dfs(u, x+dx[cur]*zz, y+dy[cur]*zz, v, f(cur+2), zz>>1);
			cur++;
		}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
		if (adj[i].size() > 4){
			cout << "NO\n";
			return 0;
		}
	dfs(0, 0, 0);

	cout << "YES\n";
	for (int i = 0; i < n; i++)
		cout << ans[i].F << " " << ans[i].S << "\n";
	return 0;
}