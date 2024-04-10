#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int>pii;
typedef pair<pii, pii>pi4;
int map[100][100];
int main()
{
	int mx, my, query;
	scanf("%d%d%d", &mx, &my, &query);
	vector<pi4>vec;
	for (int i = 0; i < query; i++)
	{
		int za;
		scanf("%d", &za);
		if (za <= 2)
		{
			int zb;
			scanf("%d", &zb);
			zb--;
			vec.push_back(make_pair(make_pair(za, zb), make_pair(0, 0)));
		}
		else
		{
			int zb, zc, zd;
			scanf("%d%d%d", &zb, &zc, &zd);
			zb--;
			zc--;
			vec.push_back(make_pair(make_pair(za, zb), make_pair(zc, zd)));
		}
	}
	for (int i = query - 1; i >= 0; i--)
	{
		if (vec[i].first.first == 1)
		{
			int p = vec[i].first.second;
			int t = map[p][my - 1];
			for (int j = my - 1; j >= 1; j--)map[p][j] = map[p][j - 1];
			map[p][0] = t;
		}
		else if (vec[i].first.first == 2)
		{
			int p = vec[i].first.second;
			int t = map[mx - 1][p];
			for (int j = mx - 1; j >= 1; j--)map[j][p] = map[j - 1][p];
			map[0][p] = t;
		}
		else map[vec[i].first.second][vec[i].second.first] = vec[i].second.second;
	}
	for (int i = 0; i < mx; i++)
	{
		for (int j = 0; j < my; j++)
		{
			if (j != 0)printf(" ");
			printf("%d", map[i][j]);
		}
		printf("\n");
	}
}