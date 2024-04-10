#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

typedef long long ll;

const int MAXN = 60 + 3;

int n, k, q, len[MAXN][MAXN][MAXN];
int c[MAXN][MAXN][MAXN], d[MAXN][MAXN][MAXN], e[MAXN][MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> q;
	for (int w = 0; w < k; w++){
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> len[w][i][j], d[w][i][j] = len[w][i][j];
	
		for (int kk = 0; kk < n; kk++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					d[w][i][j] = min(d[w][i][j], d[w][i][kk] + d[w][kk][j]);
	}
	
	memset(e, 63, sizeof(e));
	memset(c, 63, sizeof(c));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			for (int kk = 0; kk < k; kk++)
				e[i][j] = min(e[i][j], d[kk][i][j]);
			c[1][i][j] = e[i][j];
		}

	for (int w = 2; w < MAXN; w++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int p = 0; p < n; p++)
					c[w][i][j] = min(c[w][i][j], e[i][p] + c[w - 1][p][j]);
	
	while (q--){
		int u, v, t;	cin >> u >> v >> t, u--, v--, t++;
		t = min(t, n);
		cout << c[t][u][v] << "\n";
	}
	return 0;
}