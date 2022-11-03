#include <bits/stdc++.h>
		  
using namespace std;
		  
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double   
//ANKETA

int n, m;
vector<pair<int, int> > g[300007];
vector<int> g2[300007];
bool was[300007];
int color[300007];
int sum[300007];
int pred[300007];

void dfs(int v){
	was[v] = 1;
	for (auto to : g[v]) if (!was[to.x]){
		g2[v].pub(to.x);
		pred[to.x] = to.y;
		dfs(to.x);
	}		
}

vector<int> ans;

void calc(int v){
	for (int to : g2[v]){
		calc(to);
		sum[v] ^= sum[to];
	}
	if (sum[v]) ans.pub(pred[v]);
}

int main(){ 
	//freopen("input.txt", "r", stdin);       
	//freopen("output2.txt", "w", stdout);
	//freopen("heavy.in", "r", stdin);
	//freopen("heavy.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> color[i];
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].pub(mp(b, i));
		g[b].pub(mp(a, i));
	}
	dfs(0);
	vector<int> need;
	for (int i = 0; i < n; i++) if (color[i] == 1) need.pub(i);
	int gg = -1;
	for (int i = 0; i < n; i++) if (color[i] == -1) gg = i;

	if ((int)need.size() % 2 == 1 && gg == -1) cout << -1, exit(0);
	
	for (int i = 0; i < need.size(); i += 2){
		int a = need[i];
		int b;
		if (i + 1 < need.size()) b = need[i + 1];
		else b = gg;
		sum[a] ^= 1;
		sum[b] ^= 1;
	}

	calc(0);

	cout << ans.size() << "\n";
	for (int x : ans) cout << x + 1 << "\n";
}