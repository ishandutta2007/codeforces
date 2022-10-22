#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 80 + 3;
const int INF = 1e8;

int n, k;
int d[MAXN][MAXN][MAXN][MAXN], w[MAXN][MAXN];
vector<pii> adj[MAXN];

void smin(int &x, int y){x = min(x, y);}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	if (k > n){
		cout << "-1\n";
		return 0;
	}
	k--;
	int m;	cin >> m;
	memset(w, 63, sizeof(w));
	while (m--){
		int u, v, c; cin >> u >> v >> c;
		smin(w[u][v], c);
	}
	for (int u = 1; u <= n; u++)
		for (int v = 1; v <= n; v++)
			if (u^v && w[u][v] < 1e7)
				adj[u].push_back({v, w[u][v]});

	memset(d, 63, sizeof(d));
	for (int i = 1; i <= n; i++)
		d[0][0][n+1][i] = 0;
	
	for (int t = 0; t < k; t++)
		for (int l = 0; l < n; l++)
			for (int r = l+2; r <= n+1; r++)
				for (int v = l+1; v < r; v++)
					if (d[t][l][r][v] < INF)
						for (auto e:adj[v]){
							int u = e.F, c = e.S;
							if (l < u && u < r)
								smin(d[t+1][u<v?l:v][v<u?r:v][u], d[t][l][r][v] + c);
						}
	
	int ans = 1e9;
	for (int l = 0; l < n; l++)
		for (int r = l+2; r <= n+1; r++)
			for (int v = l+1; v < r; v++)
				ans = min(ans, d[k][l][r][v]);
	if (ans > INF)
		cout << "-1\n";
	else
		cout << ans << "\n";
	return 0;
}