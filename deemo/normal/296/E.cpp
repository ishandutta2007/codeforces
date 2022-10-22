#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const int MAX = 100 + 5;
const int SUPERMAX = 4e4 + 50;
const int MOD = 1e9 + 7;

int n, W, x, y;
ll c[MAX][MAX];
int d[MAX][MAX][2];
bool mark[MAX][MAX][2];
pair<int, int>	q[SUPERMAX];
ll ans[MAX][MAX][2];
vector<pair<int, int>>	par[MAX][MAX][2];

void init(){
	c[0][0] = 1;
	for (int i = 1; i < MAX; i++){
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
	}

}

void bfs(int a, int b){
	mark[a][b][0] = 1;
	d[a][b][0] = 0;
	int h = 0, t = 0;
	q[t++] = {a, b};

	while (h < t){
		pair<int, int>	f = q[h++];

		bool type;
		int tx = abs(f.first), ty = abs(f.second);
		if (f.first + f.second < 0){
			type = 1;
			a = x + f.first;
			b = y + f.second;
		}
		else{
			type = 0;
			a = f.first;
			b = f.second;
		}
		
		for (int i = 0; i <= a; i++)
			for (int j = 0; j <= b; j++){
				if (i == 0 && j == 0)	continue;

				int ta = x - a + i, tb = y - b + j;
				if (!type){
					ta = tx - i;
					tb = ty - j;
				}

	
				if (i * 50 + j * 100 <= W)
					if (!mark[ta][tb][!type] || d[ta][tb][!type] == d[tx][ty][type] + 1)	
						par[ta][tb][!type].push_back({tx, ty});
				
				if (mark[ta][tb][!type] || i * 50 + j * 100 > W)	continue;

				mark[ta][tb][!type] = 1;
				d[ta][tb][!type] = d[tx][ty][type] + 1;
			
				if (type)
					q[t++] = {ta, tb};
				else
					q[t++] = {-ta, -tb};
			}
	}
}

pair<pair<int, int>, bool>	sq[SUPERMAX];
void get(int a, int b, int type){
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			mark[i][j][0] = mark[i][j][1] = 0;
	
	mark[a][b][type] = 1;
	ans[a][b][type] = 1;
	int h = 0, t = 0;
	sq[t++] = {{a, b}, type};
	
	while (h < t){
		pair<pair<int, int>, bool>	fr = sq[h++];	
		int aa = fr.first.first, bb = fr.first.second, cc = fr.second;

		for (pair<int, int> u:par[aa][bb][cc]){
			ll xz = 0;
			if (cc == 0)
				xz = (c[aa][aa - u.first] * c[bb][bb - u.second]) % MOD;
			else
				xz = (c[x - aa][u.first - aa] * c[y - bb][u.second - bb]) % MOD;

			ans[u.first][u.second][!cc] += ans[aa][bb][cc] * xz;
			ans[u.first][u.second][!cc] %= MOD;
			if (!mark[u.first][u.second][!cc])	
				mark[u.first][u.second][!cc] = 1, sq[t++] = {{u.first, u.second}, !cc};
		}
	}
}

int main(){
	cin >> n >> W;
	for (int i = 0; i < n; i++){
		int temp;	cin >> temp;
		if (temp == 50)	x++;
		else	y++;
	}
	init();

	bfs(x, y);
	if (!mark[0][0][1]){
		cout << -1 << endl;
		cout << 0 << endl;
		return 0;
	}

	get(0, 0, 1);
	cout << d[0][0][1] << endl;
	cout << ans[x][y][0] << endl;
	return 0;
}