#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<numeric>

using namespace std;

#define F first
#define S second

const int MAXN = 1e3 + 10;
const int MAXR = 10 + 1;

int n, r, c, w, d[MAXN][MAXN];
char s[MAXN][MAXR][MAXR];
int css, sz, par[MAXN];
pair<int, int>	sec[MAXN * MAXN];
vector<int>	adj[MAXN];

bool cmp(pair<int, int> a, pair<int, int> b){return d[a.F][a.S] < d[b.F][b.S];}

int get_par(int v){return par[v]==v?v:par[v]=get_par(par[v]);}

void dfs(int v, int p = -1){
	if (p == -1 || d[p][v] == css)
		cout << v + 1 << " " << 0 << "\n";
	else
		cout << v + 1 << " " << p + 1 << "\n";
	
	for (int u:adj[v])
		if (u^p)
			dfs(u, v);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> r >> c >> n >> w;
	css = r * c;
	for (int i = 0; i < n; i++){
		for (int a = 0; a < r; a++)
			for (int b = 0; b < c; b++)	
				cin >> s[i][a][b];

		int cnt = 0;
		for (int j = 0; j < i; d[i][j] = d[j][i] = min(cnt * w, css), cnt = 0, j++)
			for (int a = 0; a < r; a++)
				for (int b = 0; b < c; b++)
					if (s[i][a][b] != s[j][a][b])	cnt++;
	}

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			sec[sz++] = {i, j};

	sort(sec, sec + sz, cmp);

	iota(par, par + n, 0);
	int sm = 0;
	for (int i = 0; i < sz; i++){
		auto e = sec[i];
		int p1 = get_par(e.F), p2 = get_par(e.S);
		if (p1 == p2)	continue;
		
		par[p1] = p2;
		adj[e.F].push_back(e.S);
		adj[e.S].push_back(e.F);
		sm += d[e.F][e.S];
	}
	
	cout << sm + css << "\n";
	dfs(0);
	return 0;
}