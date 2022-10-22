#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;
	
const int MAXN = 300 + 10;
const int INF = 1e9 + 2;

int n;
int cc[MAXN][MAXN];
int d[2 * MAXN][MAXN][MAXN];

bool fit(int a, int b){return	a >= 0 && a < n && b >= 0 && b < n;}

int get(int a, int b, int c){
	if (d[a][b][c] != INF)
		return	d[a][b][c];
	if (a == 2 * n - 2)
		return	d[a][b][c] = 0;

	int r1, r2, col1, col2;
	d[a][b][c] = -INF;
	if (a < n - 1){
		r1 = b, r2 = c;
		col1 = a - b, col2 = a - c;

		if (fit(r1 + 1, col1) && fit(r2 + 1, col2))
			d[a][b][c] = max(d[a][b][c], get(a + 1, b + 1, c + 1) + cc[r1 + 1][col1] + cc[r2 + 1][col2] - int(r2 == r1 && col1 == col2) * cc[r1 + 1][col1]);
		if (fit(r1 + 1, col1) && fit(r2, col2 + 1))
			d[a][b][c] = max(d[a][b][c], get(a + 1, b + 1, c) + cc[r1 + 1][col1] + cc[r2][col2 + 1] - int(r2 == r1 + 1 && col2 + 1 == col1) * cc[r2][col2 + 1]);
		if (fit(r1, col1 + 1) && fit(r2 + 1, col2))
			d[a][b][c] = max(d[a][b][c], get(a + 1, b, c + 1) + cc[r1][col1 + 1] + cc[r2 + 1][col2] - int(r2 + 1 == r1 && col1 + 1 == col2) * cc[r2 + 1][col2]);
		if (fit(r1, col1 + 1) && fit(r2, col2 + 1))
			d[a][b][c] = max(d[a][b][c], get(a + 1, b, c) + cc[r1][col1 + 1] + cc[r2][col2 + 1] - int(r1 == r2 && col1 == col2) * cc[r2][col2 + 1]);
	}
	else{
		int t = a - n;
		r1 = t + b + 1, r2 = t + 1 + c;
		col1 = a - r1, col2 = a - r2;
		if (fit(r1 + 1, col1) && fit(r2 + 1, col2))
			d[a][b][c] = max(d[a][b][c], get(a + 1, b, c) + cc[r1 + 1][col1] + cc[r2 + 1][col2] - int(r2 == r1 && col1 == col2) * cc[r1 + 1][col1]);
		if (fit(r1 + 1, col1) && fit(r2, col2 + 1))
			d[a][b][c] = max(d[a][b][c], get(a + 1, b, c - 1) + cc[r1 + 1][col1] + cc[r2][col2 + 1] - int(r2 == r1 + 1 && col2 + 1 == col1) * cc[r2][col2 + 1]);
		if (fit(r1, col1 + 1) && fit(r2 + 1, col2))
			d[a][b][c] = max(d[a][b][c], get(a + 1, b - 1, c) + cc[r1][col1 + 1] + cc[r2 + 1][col2] - int(r2 + 1 == r1 && col1 + 1 == col2) * cc[r2 + 1][col2]);
		if (fit(r1, col1 + 1) && fit(r2, col2 + 1))
			d[a][b][c] = max(d[a][b][c], get(a + 1, b - 1, c - 1) + cc[r1][col1 + 1] + cc[r2][col2 + 1] - int(r1 == r2 && col1 == col2) * cc[r2][col2 + 1]);
	}

	return	d[a][b][c];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> cc[i][j];
	for (int i = 0; i < 2 * MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			for (int w = 0; w < MAXN; w++)
				d[i][j][w] = INF;
	cout << get(0, 0, 0) + cc[0][0] << endl;
	return 0;
}