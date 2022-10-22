#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 40 + 3;

int n, m, q;
char c[MAXN][MAXN];
int nxt[MAXN][MAXN][MAXN], p[MAXN][MAXN];
int save[MAXN][MAXN][MAXN][MAXN];
int ans[MAXN][MAXN][MAXN][MAXN];

int main(){
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			cin >> c[i][j];
			p[i + 1][j + 1] = p[i + 1][j] + p[i][j + 1] - p[i][j] + bool(c[i][j] == '1');
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 1; k <= i + 1; k++){
				int w;
				for (w = 0; w <= j; w++)
					if (p[i + 1][j + 1] - p[i + 1 - k][j + 1] - p[i + 1][j - w] + p[i + 1 - k][j - w] != 0)	break;
				nxt[i][j][k] = w;
			}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int x = 0; x <= i; x++)
				for (int y = 0; y <= j; y++){
					int cnt = 0;
					for (int k = 1; k <= i-x+1; k++)
						cnt += min(nxt[i][j][k], j - y + 1);
					save[i][j][x][y] = cnt;
				}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int x = 0; x <= i; x++)
				for (int y = 0; y <= j; y++){
					int cnt = 0;
					for (int k = 1; k <= i-x+1; k++)
						cnt += save[i - k + 1][j][x][y];
					if (y < j)
						cnt += ans[x][y][i][j - 1];
					ans[x][y][i][j] = cnt;
				}

	while (q--){
		int r1, r2, c1, c2;	cin >> r1 >> c1 >> r2 >> c2;	r1--, c1--, r2--, c2--;
		cout << ans[r1][c1][r2][c2] << "\n";
	}
	return 0;
}