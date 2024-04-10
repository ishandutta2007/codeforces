#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

const int MAXN = 1e3 + 10;
const int MAXK = 10 + 1;

int n, m, k, d[2][MAXK][MAXN][MAXN];
string s, t;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	cin >> s >> t;
	memset(d, -10, sizeof(d));
	d[0][k][0][0] = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int kk = k; ~kk; kk--)
				for (int w = 1; ~w; w--){
					if (w == 1){
						if (kk)
							d[0][kk - 1][i][j] = max(d[0][kk - 1][i][j], d[w][kk][i][j]);
						if (i < n && j < m && s[i] == t[j])
							d[1][kk][i + 1][j + 1] = max(d[1][kk][i + 1][j + 1], d[w][kk][i][j] + 1);
					}
					else{
						if (i < n)
							d[0][kk][i + 1][j] = max(d[0][kk][i + 1][j], d[w][kk][i][j]);
						if (j < m)
							d[0][kk][i][j + 1] = max(d[0][kk][i][j + 1], d[w][kk][i][j]);
						if (i < n && j < m && s[i] == t[j])
							d[1][kk][i + 1][j + 1] = max(d[1][kk][i + 1][j + 1], d[w][kk][i][j] + 1);
					}
				}
	cout << d[0][0][n][m] << endl;
	return 0;
}