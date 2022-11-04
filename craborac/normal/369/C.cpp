#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

vector<pair<int, int> > mas[(int)1e5];
int ans;
int answer[(int)1e5];

int dfs(int v, int q)
{
	int col = 0;
	for(int i = 0; i < (int)mas[v].size(); i++)
	{
		if(mas[v][i].first != q)
		{
			col += mas[v][i].second - 1;
			int col1 = dfs(mas[v][i].first, v);
			if((col1 == 0) && (mas[v][i].second == 2))
			{	
				answer[ans] = mas[v][i].first + 1;
				ans++;
			}
			col += col1;
		}
	}
	return col;
}


int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y, t;
		scanf("%d%d%d", &x, &y, &t);
		x--;
		y--;
		mas[x].push_back(make_pair(y, t));
		mas[y].push_back(make_pair(x, t));
	}
	ans = 0;
	dfs(0, -1);
	printf("%d\n", ans);
	for(int i = 0; i < ans; i++)
		printf("%d ", answer[i]);
	return 0;
}