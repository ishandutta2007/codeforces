#include <bits/stdc++.h>

using namespace std;

const int maxn=1e3+5;
const int inf = 1e7;
const int d1[] = {-1, 0, 1, 0}, d2[] = {0, 1, 0, -1};
int n, m, ans = inf, dist[3][maxn][maxn];
char c[maxn][maxn];

void bfs(int it) 
{
	deque<pair<int,int> > q;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) 
	{
		if(c[i][j] == '1'+it) q.emplace_back(i, j);
		else dist[it][i][j] = inf;
	}
	while(!q.empty()) 
	{
		auto v = q.front();
		q.pop_front();
		for(int i = 0; i < 4; i++) 
		{
			int x = v.first+d1[i], y = v.second+d2[i];
			if(x < 1 || x > n || y < 1 || y > m || c[x][y] == '#' || dist[it][x][y] < inf) continue;
			dist[it][x][y] = dist[it][v.first][v.second]+(c[x][y] == '.');
			if(c[x][y] == '.') q.emplace_back(x, y);
			else q.emplace_front(x, y);
		}
	}
}

int main() 
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=m;j++)
			cin>>c[i][j];
	for(int  i=0;i<3;i++) 
		bfs(i);
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= m; j++) 
			ans = min(dist[0][i][j]+dist[1][i][j]+dist[2][i][j]-2*(c[i][j] == '.'), ans);
	if(ans == inf) 
		cout<<-1;
	else 
		cout<<ans;
	return 0;
}