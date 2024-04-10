#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 5 + 2;
const int MAXM = 5e4 + 20;

int n, m;
int t[MAXN][MAXM];
int d[MAXN][MAXM];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> n;
	for (int j = 0; j < m; j++)
		for (int i = 0; i < n; i++)
			cin >> t[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			d[i][j] = max(d[i - 1][j], d[i][j - 1]) + t[i - 1][j - 1];
	for (int i = 1; i <= m; i++)
		cout << d[n][i] << " ";
	cout << endl;
	return 0;
}