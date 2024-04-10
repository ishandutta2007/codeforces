#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 400 + 5;

int n, m;
char c[MAXN][MAXN];
int dn[MAXN][MAXN], ri[MAXN][MAXN], dl[MAXN][MAXN], dr[MAXN][MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> c[i][j];
	
	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j < m; j++)
			dn[i + 1][j + 1] = dn[i + 2][j + 1] + (c[i][j] == '1');
	for (int j = m - 1; j >= 0; j--)
		for (int i = 0; i < n; i++)
			ri[i + 1][j + 1] = ri[i + 1][j + 2] + (c[i][j] == '1');
	
	for (int j = 0; j < m; j++)
		for (int i = 0; i < n; i++)
			dl[i + 1][j + 1] = int(c[i][j] == '1') + dl[i + 2][j];
	for (int j = m - 1; j >= 0; j--)
		for (int i = 0; i < n; i++)
			dr[i + 1][j + 1] = dr[i + 2][j + 2] + (c[i][j] == '1');

	int ret = 0;
	for (int i = 1; i <= n; i++){
		int a, b;
		for (a = 1; a <= m; a++)
			for (b = a + 2; b <= m; b += 2)
				if (ri[i][a] - ri[i][b + 1] == 0){
					int sz = (b - a)/2;
					if (sz <= n - i && dr[i][a] - dr[i + sz + 1][a + sz + 1] == 0 && dl[i][b] - dl[i + sz + 1][b - sz - 1] == 0)	ret++;
					if (sz < i && dl[i - sz][a + sz] - dl[i + 1][a - 1] == 0 && dr[i - sz][b - sz] - dr[i + 1][b + 1] == 0)	ret++;
				}
	}
	for (int j = 1; j <= m; j++){
		int a, b;
		for (a = 1; a <= n; a++)
			for (b = a + 2; b <= n; b += 2)
				if (dn[a][j] - dn[b + 1][j] == 0){
					int sz = (b - a)/ 2;
					if (sz <= m - j && dr[a][j] - dr[a + sz + 1][j + sz + 1] == 0 && dl[a + sz][j + sz] - dl[b + 1][j - 1] == 0)	ret++;
					if (sz < j && dl[a][j] - dl[a + sz + 1][j - sz - 1] == 0 && dr[a + sz][j - sz] - dr[b + 1][j + 1] == 0)	ret++;
				}
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int sz = 1; sz <= min(n - i, m - j); sz++)
				if (dr[i][j] - dr[i + sz + 1][j + sz + 1] == 0){
					if (ri[i][j] - ri[i][j + sz + 1] == 0 && dn[i][j + sz] - dn[i + sz + 1][j + sz] == 0)	ret++;
					if (ri[i + sz][j] - ri[i + sz][j + sz + 1] == 0 && dn[i][j] - dn[i + sz + 1][j] == 0)	ret++;
				}			

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int sz = 1; sz <= min(n - i, j - 1); sz++)
				if (dl[i][j] - dl[i + sz + 1][j - sz - 1] == 0){
					if (ri[i][j - sz] - ri[i][j + 1] == 0 && dn[i][j - sz] - dn[i + sz + 1][j - sz] == 0)	ret++;
					if (ri[i + sz][j - sz] - ri[i + sz][j + 1] == 0 && dn[i][j] - dn[i + sz + 1][j] == 0)	ret++;
				}
	cout << ret << endl;
	return	0;
}