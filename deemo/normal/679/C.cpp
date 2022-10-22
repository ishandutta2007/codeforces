#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<utility>

using namespace std;

const int MAXN = 500 + 7;

int n, k, p[MAXN][MAXN], cnt[MAXN * MAXN], g, cc[MAXN * MAXN], col[MAXN][MAXN];
bool vis[MAXN][MAXN];
string s[MAXN];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool fit(int a, int b){return 0 <= a && a < n && 0 <= b && b < n && s[a][b] != 'X';}

void dfs(int a, int b){
	if (vis[a][b])	return;
	vis[a][b] = 1;
	cnt[g]++;
	col[a][b] = g;
	
	for (int i = 0; i < 4; i++)
		if (fit(a + dx[i], b + dy[i]))
			dfs(a + dx[i], b + dy[i]);
}

bool in(int a, int b, int c){
	return b <= a && a < c;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> s[i];

	int ans = 0;
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			col[i][j] = MAXN * MAXN - 5;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!vis[i][j] && s[i][j] == '.')
				dfs(i, j), ans = max(ans, cnt[g++]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			p[i + 1][j + 1] = p[i + 1][j] + p[i][j + 1] - p[i][j] + (s[i][j] == 'X');


	for (int i = k - 1; i < n; i++){
		int ret = 0;
		memset(cc, 0, sizeof(cc));
		for (int ii = i + 1; ii >= i - k; ii--){
			if (ii < 0 || ii >= n)	continue;

			for (int jj = 0; jj <= k; jj++){
				if (jj < 0 || jj >= n)	continue;
				if (!in(ii, i - k + 1, i + 1) && !in(jj, 0, k))	continue;

				cc[col[ii][jj]]++;
				if (cc[col[ii][jj]] == 1)
					ret += cnt[col[ii][jj]];
			}
		}

		for (int j = k - 1; j < n; j++){
			ans = max(ans, ret + (p[i + 1][j + 1] - p[i + 1][j + 1 - k] - p[i + 1 - k][j + 1] + p[i + 1 - k][j + 1 - k]));
			if (j + 1 < n)
				for (int ii = i + 1; ii >= i - k; ii--){
					if (ii < 0 || ii >= n)	continue;

					if (ii == i + 1 || ii == i - k){
						cc[col[ii][j - k + 1]]--;
						if (cc[col[ii][j - k + 1]] == 0)
							ret -= cnt[col[ii][j - k + 1]];

						cc[col[ii][j + 1]]++;
						if (cc[col[ii][j + 1]] == 1)
							ret += cnt[col[ii][j + 1]];
					}
					else{
						if (j - k >= 0){
							cc[col[ii][j - k]]--;
							if (cc[col[ii][j - k]] == 0)
								ret -= cnt[col[ii][j - k]];
						}

						cc[col[ii][j + 2]]++;
						if (cc[col[ii][j + 2]] == 1)
							ret += cnt[col[ii][j + 2]];
					}

				}
		}
	}
	cout << ans << "\n";
	return 0;
}