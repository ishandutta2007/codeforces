#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<utility>

using namespace std;

const int MAXN = 5e2 + 10;
const int INF = 1e9;

int n, m;
int dis[MAXN][MAXN], cnt[MAXN][MAXN], save[MAXN][MAXN];
bool mark[MAXN][MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j)
				dis[i][j] = INF;
	while (m--){
		int a, b, c;	cin >> a >> b >> c;	a--, b--;
		dis[a][b] = dis[b][a] = c;
		mark[a][b] = mark[b][a] = 1;
		save[a][b] = save[b][a] = c;
	}	
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			if (j == i)	continue;
			for (int k = 0; k < n; k++)
				if (k != i && mark[i][k] && save[i][k] + dis[k][j] == dis[i][j])	
					cnt[i][j]++;
		}

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++){
			int ret = 0;
			for (int k = 0; k < n; k++)
				if (dis[i][j] == dis[i][k] + dis[j][k])
					ret += cnt[k][j];
			cout << ret << " ";
		}
	cout << "\n";
	return 0;
}