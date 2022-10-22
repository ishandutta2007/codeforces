#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 3e5 + 10;

int n, m, x[MAXN], y[MAXN], sec[MAXN], pos[MAXN];
ll pt[2][MAXN];
vector<int> adj[MAXN];

bool cmp(int u, int v){return y[u] - x[u] < y[v] - x[v];}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	while (m--){
		int a, b; cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	iota(sec, sec + n, 0);
	sort(sec, sec + n, cmp);
	for (int i = 0; i < n; i++) pt[0][i+1] = pt[0][i] + x[sec[i]];
	for (int i = 0; i < n; i++) pt[1][i+1] = pt[1][i] + y[sec[i]];
	for (int i = 0; i < n; i++) pos[sec[i]] = i;

	for (int v = 0; v < n; v++){
		int p = pos[v];
		ll sm = 0;
		int t = p;
		ll temp = pt[1][p];
		for (int u:adj[v])
			if (pos[u] < p)
				t--, temp -= y[u];
		sm += 1ll*t*x[v];
		sm += temp;

		t = n - p - 1;
		temp = pt[0][n] - pt[0][p+1];
		for (int u:adj[v])
			if (pos[u] > p)
				t--, temp -= x[u];
		sm += 1ll*t*y[v];
		sm += temp;

		cout << sm << " ";
	}
	cout << "\n";
	return 0;
}