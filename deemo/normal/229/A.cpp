#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 100 + 4;
const int MAXM = 1e4 + 10;
const int INF = 1e9;

int n, m;
char c[MAXN][MAXM];
int d[MAXN][MAXM], le[MAXN][MAXM], ri[MAXN][MAXM];

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> c[i][j];
	for (int i = 0; i < n; i++){
		int first = 0, last = m - 1;
		while (first < m && c[i][first] == '0')	first++;
		while (last >= 0 && c[i][last] == '0')	last--;
		if (first == m){
			cout << -1 << endl;
			return 0;
		}

		for (int j = 0; j < m; j++)
			if (c[i][j] == '1')
				le[i][j] = j;
			else{
				if (j == 0)
					le[i][j] = -INF;
				else	
					le[i][j] = le[i][j - 1];
			}

		for (int j = m - 1; j >= 0; j--){
			if (c[i][j] == '1')
				ri[i][j] = j;
			else{
				if (j == m - 1)
					ri[i][j] = INF;
				else
					ri[i][j] = ri[i][j + 1];
			}

			d[i][j] = min(j - le[i][j], ri[i][j] - j);
			d[i][j] = min(d[i][j], min(first + (m - j), (m - last) + j));
		}
	}

	int ans = 1e9;
	for (int j = 0; j < m; j++){
		int x = 0;
		for (int i = 0; i < n; i++)
			x += d[i][j];
		ans = min(ans, x);
	}
	cout << ans << endl;
	return	0;
}