#include<stdio.h>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;
int m[1002][1002];
int dist[3][1002][1002];
bool flag[1002][1002];
typedef pair<int, int>pii;
typedef pair<int, pii>pi3;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<pii>dat[3];
int main()
{
	int mx, my;
	scanf("%d%d", &mx, &my);
	for (int i = 0; i < 1002; i++)for (int j = 0; j < 1002; j++)m[i][j] = -1;
	for (int i = 1; i <= mx; i++)
	{
		for (int j = 1; j <= my; j++)
		{
			char z;
			scanf(" %c", &z);
			if (z == '.')m[i][j] = 1;
			if ('1' <= z&&z <= '3')m[i][j] = 0;
			if (z == '1')dat[0].push_back(make_pair(i, j));
			if (z == '2')dat[1].push_back(make_pair(i, j));
			if (z == '3')dat[2].push_back(make_pair(i, j));
		}
	}
	for (int p = 0; p < 3; p++)
	{
		deque<pi3>deq;
		for (int i = 0; i < dat[p].size(); i++)deq.push_back(make_pair(0, dat[p][i]));
		for (int i = 0; i <= mx + 1; i++)
		{
			for (int j = 0; j <= my + 1; j++)
			{
				flag[i][j] = false;
				dist[p][i][j] = 600000000;
			}
		}
		for (;;)
		{
			if (deq.empty())break;
			pi3 z = deq.front();
			deq.pop_front();
			if (flag[z.second.first][z.second.second])continue;
			flag[z.second.first][z.second.second] = true;
			dist[p][z.second.first][z.second.second] = z.first;
			for (int i = 0; i < 4; i++)
			{
				if (m[z.second.first + dx[i]][z.second.second + dy[i]] == 0)
				{
					deq.push_front(make_pair(z.first, make_pair(z.second.first + dx[i], z.second.second + dy[i])));
				}
				if (m[z.second.first + dx[i]][z.second.second + dy[i]] == 1)
				{
					deq.push_back(make_pair(z.first + 1, make_pair(z.second.first + dx[i], z.second.second + dy[i])));
				}
			}
		}
	}
	int mini = 600000000;
	for (int i = 0; i <= mx + 1; i++)
	{
		for (int j = 0; j <= my + 1; j++)
		{
			if (m[i][j] == 1)mini = min(mini, dist[0][i][j] + dist[1][i][j] + dist[2][i][j] - 2);
		}
	}
	int mm[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int mi = 600000000;
			for (int k = 0; k < dat[j].size(); k++)
			{
				mi = min(mi, dist[i][dat[j][k].first][dat[j][k].second]);
			}
			mm[i][j] = mi;
		}
	}
	mini = min(mini, min(min(mm[0][1] + mm[0][2], mm[1][2] + mm[1][0]), mm[2][0] + mm[2][1]));
	if (mini == 600000000)printf("-1\n");
	else printf("%d\n", mini);
}