#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, m, k, x[MAXN], y[MAXN], q[MAXN], lv[MAXN];
bool mark[MAXN];
vector<pii> adj[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++){
		cin >> x[i] >> y[i], x[i]--, y[i]--;
		adj[i].push_back({k+x[i], 1});
		adj[k+x[i]].push_back({i, 0});
		adj[i].push_back({k+n+y[i], 1});
		adj[k+n+y[i]].push_back({i, 0});
		if (x[i]){
			adj[k+x[i]-1].push_back({i, 0});
			adj[i].push_back({k+x[i]-1, 1});
		}
		if (x[i] < n-1){
			adj[k+x[i]+1].push_back({i, 0});
			adj[i].push_back({k+x[i]+1, 1});
		}
		if (y[i]){
			adj[k+n+y[i]-1].push_back({i, 0});
			adj[i].push_back({k+n+y[i]-1, 1});
		}
		if (y[i] < m-1){
			adj[k+n+y[i]+1].push_back({i, 0});
			adj[i].push_back({k+n+y[i]+1, 1});
		}
	}
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
			if (i^j && abs(x[i]-x[j]) + abs(y[i]-y[j]) == 1)
				adj[i].push_back({j, 0});

	int source = -1;
	for (int i = 0; i < k; i++)
		if (x[i]+y[i] == 0) source = i;

	memset(lv, 63, sizeof(lv));
	deque<int> q;
	q.push_back(source); lv[source] = 0;
	while (q.size()){
		int v = q.front(); q.pop_front();
		if (mark[v]) continue;
		mark[v] = 1;

		for (auto e:adj[v])
			if (lv[e.F] > lv[v]+e.S){
				lv[e.F] = lv[v]+e.S;
				if (e.S)
					q.push_back(e.F);
				else
					q.push_front(e.F);
			}
	}
	
	int ans = 1e9;
	for (int i = 0; i < k; i++)
		if (x[i] == n-1 && y[i] == m-1) ans = lv[i];
	ans = min(ans, lv[k+n-1]);
	ans = min(ans, lv[k+n+m-1]);

	if (ans > 1e8) ans = -1;
	cout << ans << "\n";
	return 0;
}