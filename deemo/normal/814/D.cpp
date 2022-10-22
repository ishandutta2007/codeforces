#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e3 + 10;
const ld PP = acos(-1);

int n, x[MAXN], y[MAXN], r[MAXN];
bool mark[MAXN];
vector<int> adj[MAXN], _adj[MAXN];

ll dis(int i, int j){
	return 1ll*(x[i]-x[j])*(x[i]-x[j])+1ll*(y[i]-y[j])*(y[i]-y[j]);
}

bool check(int i, int j){return r[j] > r[i] && dis(i, j) <= 1ll*r[j]*r[j];}

int pu[MAXN];
void plant(int v, int c = 0){
	pu[v] = c;
	for (int u:adj[v])
		plant(u, c+1);
}

ld d[MAXN][2], ss[MAXN];
void dfs(int v){
	for (int u:adj[v]) dfs(u);

	{//0
		ld temp = ss[v];
		for (int u:adj[v])
			temp += d[u][1];
		d[v][0] = temp;

		int t = pu[v]&1;
		if (t)
			temp = -ss[v];
		else
			temp = ss[v];
		for (int u:adj[v])
			temp += d[u][0];
		d[v][0] = max(d[v][0], temp);
	}
	{//1
		ld temp = -ss[v];
		for (int u:adj[v])
			temp += d[u][0];
		d[v][1] = temp;

		int t = !(pu[v]&1);
		if (t)
			temp = -ss[v];
		else
			temp = ss[v];
		for (int u:adj[v])
			temp += d[u][1];
		d[v][1] = max(d[v][1], temp);
	}
}

pii mn[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i] >> r[i], mn[i].F = 1e9;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i^j && check(i, j)){
				mark[i] = 1;
				mn[i] = min(mn[i], {r[j], j});
				_adj[j].push_back(i);
			}
	for (int i = 0; i < n; i++)
		if (mark[i])
			adj[mn[i].S].push_back(i);
	
	for (int i = 0; i < n; i++)
		ss[i] = PP*(1ll*r[i]*r[i]);

	cout << fixed << setprecision(12);
	ld ans = 0;
	for (int v = 0; v < n; v++)
		if (!mark[v]){
			plant(v);
			dfs(v);
			ans += d[v][0];
		}
	cout << ans << "\n";
	return 0;
}