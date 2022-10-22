#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<utility>

using namespace std;

const int max_n = 1e3 + 30;
const int INF = 1e9;

int n, m;
char c[max_n][max_n];
int d[max_n][max_n];
pair<int, int>	s, e;
pair<int, int>	q[max_n * max_n];
bool mark[max_n][max_n];

void bfs(){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			d[i][j] = INF;
	int h = 0, t = 0;
	mark[e.first][e.second] = 1;
	d[e.first][e.second] = 0;
	q[t++] = e;
	while (h < t){
		pair<int, int>	fr = q[h++];
		int row = fr.first, col = fr.second;
		if (row + 1 < n && mark[row + 1][col] == 0)
			if (c[row + 1][col] != 'T')
				q[t++] = {row + 1, col}, d[row + 1][col] = d[row][col] + 1, mark[row + 1][col] = 1;
		if (row - 1 >= 0 && mark[row - 1][col] == 0)
			if (c[row - 1][col] != 'T')
				q[t++] = {row - 1, col}, d[row - 1][col] = d[row][col] + 1, mark[row - 1][col] = 1;
		if (col + 1 < m && mark[row][col + 1] == 0)
			if (c[row][col + 1] != 'T')
				q[t++] = {row, col + 1}, d[row][col + 1] = d[row][col] + 1, mark[row][col + 1] = 1;
		if (col - 1 >= 0 && mark[row][col - 1] == 0)
			if (c[row][col - 1] != 'T')
				q[t++] = {row, col - 1}, d[row][col - 1] = d[row][col] + 1, mark[row][col - 1] = 1;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		string temp;	cin >> temp;
		for (int j = 0; j < m; j++){
			c[i][j] = temp[j];
			if (c[i][j] == 'E')		e = {i, j};
			if (c[i][j] == 'S')		s = {i, j};
		}
	}
	bfs();
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (d[i][j] <= d[s.first][s.second] && c[i][j] <= '9')	ans += c[i][j] - 48;
	cout << ans << endl;
	return 0;
}