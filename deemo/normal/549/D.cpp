#include<iostream>

using namespace std;

const int MAXN = 100 + 5;

int n, m, d[MAXN][MAXN];
char c[MAXN][MAXN];

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> c[i][j];
	int cn = 0;
	for (int i = n - 1; i >= 0; i--)
		for (int j = m - 1; j >= 0; j--){
			d[i][j] = d[i + 1][j] + d[i][j + 1] - d[i + 1][j + 1];
			int x = c[i][j] == 'W'?1:-1;
			if (d[i][j] != x){
				cn++;
				d[i][j] = x;
			}
		}
	cout << cn << "\n";
	return	0;
}