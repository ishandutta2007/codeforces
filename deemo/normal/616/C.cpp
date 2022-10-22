#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e3 + 10;

int n, m;
char c[MAXN][MAXN];
int col[MAXN][MAXN], sz[MAXN * MAXN], g;
string d[MAXN];
bool mark[MAXN][MAXN];

bool fit(int x, int y){return	x >= 0 && x < n && y >= 0 && y < m;}

void dfs(int x, int y){
	if (mark[x][y])	return;
	mark[x][y] = 1;
	col[x][y] = g;
	sz[g]++;

	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
			if (abs(i) + abs(j) == 1 && fit(x + i, y + j) && c[x + i][y + j] != '*')
				dfs(x + i, y + j);

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i =0 ; i < n; i++){
		string temp;	cin >> temp;
		for (int j = 0; j < m; j++)
			c[i][j] = temp[j];
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (c[i][j] != '*' && !mark[i][j]){
				dfs(i, j);
				g++;
			}

	for (int i = 0; i < n; i++){
		d[i].resize(m);
		for (int j = 0; j < m; j++){
			if (c[i][j] != '*')
				d[i][j] = '.';
			else{
				int ret = 0;
				vector<int>	vec;
				for (int a = -1; a < 2; a++)
					for (int b = -1; b < 2; b++)
						if (abs(a) + abs(b) == 1 && fit(i + a, j + b) && c[i + a][j + b] != '*')
							if (find(vec.begin(), vec.end(), col[i + a][j + b]) == vec.end()){
								ret += sz[col[i + a][j + b]];
								vec.push_back(col[i + a][j + b]);
							}
				ret++;
				ret %= 10;
				d[i][j] = ret + 48;
			}
		}
		cout << d[i] << "\n";
	}
	return	0;
}