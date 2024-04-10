#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;
int n;
int tx[4] = {1, -1, 0, 0};
int ty[4] = {0, 0, -1, 1};
int x,xx,y,yy;
char s[55][55];
int dis[55][55];
queue < pair <int, int > > q;
bool czy(int a, int b)
{
	return a >= 1 and a <= n and b >= 1 and b <= n;
}
vector < pair < int, int > > A , B;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(0);
	cin >> n;
	cin >> y >> x >> yy >> xx;
	for(int i = 1; n >= i; ++i)
	{
		for(int j = 1; n >= j; ++j)
			cin >> s[i][j];
	}
	for(int i = 1; n >= i; ++i)
		for(int j = 1; n >= j; ++j)
			dis[i][j] = 1e9;
	dis[y][x] = 0;
	q.push({y, x});
	while(!q.empty())
	{
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		for(int i = 0; 4 > i; ++i)
		{
			if(czy(nx + tx[i], ny + ty[i]) and s[nx + tx[i]][ny + ty[i]]=='0' and dis[nx + tx[i]][ny + ty[i]]==1e9)
			{
				dis[nx + tx[i]][ny + ty[i]] = dis[nx][ny] + 1;
				q.push({nx + tx[i], ny + ty[i]});
			}
		}
	}
	if(dis[yy][xx]!=1e9)
	{
		cout << 0;
		return 0;
	}
	for(int i = 1; n >= i; ++i)
		for(int j = 1; n >= j; ++j)
			if(dis[i][j] != 1e9)
				A.push_back({i,j});
	for(int i = 1; n >= i; ++i)
		for(int j = 1; n >= j; ++j)
			dis[i][j] = 1e9;
	
	dis[yy][xx] = 0;
	q.push({yy, xx});
	while(!q.empty())
	{
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		for(int i = 0; 4 > i; ++i)
		{
			if(czy(nx + tx[i], ny + ty[i]) and s[nx + tx[i]][ny + ty[i]]=='0' and dis[nx + tx[i]][ny + ty[i]]==1e9)
			{
				dis[nx + tx[i]][ny + ty[i]] = dis[nx][ny] + 1;
				q.push({nx + tx[i], ny + ty[i]});
			}
		}
	}
	for(int i = 1; n >= i; ++i)
		for(int j = 1; n >= j; ++j)
			if(dis[i][j] != 1e9)
				B.push_back({i,j});
	int res = 1e9;
	for(auto it: A)
		for(auto w: B)
			res = min(res, (it.first-w.first)*(it.first-w.first)+(it.second-w.second)*(it.second-w.second));
	cout << res;
	return 0;	
}