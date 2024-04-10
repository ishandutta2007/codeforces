#include<fstream>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int INF = 1e9 + 2;
const int MAXN = 1e3 + 5;
const int MAXK = 8 + 2;
const int MAX = MAXN * MAXN;

int n, m, k;
char c[MAXN][MAXN];
int d[MAXN][MAXN], g[MAXN][MAXN];
vector<pair<int, int>>	st;//cells with sleeping rats
vector<pair<int, int>>	fre, wk, sn, sc, tc;
pair<int, int>	q[MAX];

bool fit(int x, int y){return	x >= 0 && x < n && y >= 0 && y < m;}

void bfs(int x, int y, bool fl = 0){
	d[x][y] = 0;
	int h = 0, t = 0;
	q[t++] = {x, y};

	while (h < t){
		x = q[h].first;	y = q[h++].second;
		if (fl)	wk.push_back({x, y});
		else	sn.push_back({x, y});
		if (d[x][y] == k)	continue;

		for (int i = -1; i <= 1; i++)
			for (int j = -1; j <= 1; j++)
				if (abs(i + j) == 1 && fit(x + i, y + j) && d[x + i][y + j] == INF && c[x + i][y + j] != 'X'){
					d[x + i][y + j] = d[x][y] + 1;
					q[t++] = {x + i, y + j};
				}
	}
}

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++){
		string temp;	cin >> temp;
		for (int j = 0; j < m; j++){
			c[i][j] = temp[j];
			if (c[i][j] == 'R')
				st.push_back({i, j});
			d[i][j] = g[i][j] = INF;
			if (c[i][j] != 'X' && (int)fre.size() < 2)
				fre.push_back({i, j});
		}	
	}			
	bfs(st.back().first, st.back().second, 1);
	for (pair<int, int>	f:wk)	d[f.first][f.second] = INF;

	for (pair<int, int>	f:wk){
		sn.clear();
		bfs(f.first, f.second);

		bool enough = 1;
		pair<int, int>	tmp;
		for (pair<int, int>	v:st)
			if (d[v.first][v.second] > k){
				enough = 0;
				tmp = v;
				break;
			}

		if (enough){
			cout << f.first + 1 << " " << f.second + 1 << " ";
			if (f == fre[0])
				cout << fre.back().first + 1 << " " << fre.back().second  + 1 << endl;
			else
				cout << fre[0].first + 1 << " " << fre[0].second + 1 << endl;
			return 0;
		}
		
		{
			g[tmp.first][tmp.second] = 0;
			int h = 0, t = 0;
			q[t++] = tmp;
			sc.clear();
			while (h < t){
				int x = q[h].first, y = q[h++].second;
				sc.push_back({x, y});
				if (g[x][y] == k)	continue;
				for (int i = -1; i <= 1; i++)
					for (int j = -1; j <= 1; j++)
						if (abs(i + j) == 1 && fit(x + i, y + j) && g[x + i][y + j] == INF && c[x + i][y + j] != 'X'){
							g[x + i][y + j] = g[x][y] + 1;
							q[t++] = {x + i, y + j};
						}
			}
			for (pair<int, int>	w:sc)
				g[w.first][w.second] = INF;
			
			for (pair<int, int>	w:sc){
				g[w.first][w.second] = 0;
				int h = 0, t = 0;
				q[t++] = w;
				tc.clear();
				while (h < t){
					int x = q[h].first, y = q[h++].second;
					tc.push_back({x, y});
					if (g[x][y] == k)	continue;
					for (int i = -1; i <= 1; i++)
						for (int j = -1; j <= 1; j++)
							if (abs(i + j) == 1 && fit(x + i, y + j) && g[x + i][y + j] == INF && c[x + i][y + j] != 'X'){
								g[x + i][y + j] = g[x][y] + 1;
								q[t++] = {x + i, y + j};
							}
				}

				bool awesome = 1;
				for (pair<int, int>	rt:st)
					if (g[rt.first][rt.second] == INF && d[rt.first][rt.second] == INF){
						awesome = 0;
						break;
					}
				if (awesome){
					cout << w.first + 1 << " " << w.second + 1 << " " << f.first + 1 << " " << f.second + 1 << endl;
					return	0;
				}

				for (pair<int, int>	v:tc)
					g[v.first][v.second] = INF;
			}
		}

		for (pair<int, int>	w:sn)
			d[w.first][w.second] = INF;
	}	
	cout << -1 << endl;
	return 0;
}