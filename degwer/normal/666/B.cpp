#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<int>pat[3000];
int dist[3000][3000];
bool flag[3000];
int oo[3000][3], ii[3000][3];
typedef pair<int, int>pii;
int main()
{
	int num, way;
	scanf("%d%d", &num, &way);
	for (int i = 0; i < way; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--;
		zb--;
		pat[za].push_back(zb);
	}
	for (int p = 0; p < num; p++)
	{
		queue<pii>que;
		for (int i = 0; i < num; i++)dist[p][i] = 1000000000;
		fill(flag, flag + 3000, false);
		que.push(make_pair(0, p));
		for (;;)
		{
			if (que.empty())break;
			pii z = que.front();
			que.pop();
			if (flag[z.second])continue;
			flag[z.second] = true;
			dist[p][z.second] = z.first;
			for (int i = 0; i < pat[z.second].size(); i++)
			{
				que.push(make_pair(z.first + 1, pat[z.second][i]));
			}
		}
	}
	for (int i = 0; i < num; i++)
	{
		int m[3], r[3];
		fill(m, m + 3, 0);
		fill(r, r + 3, -1);
		for (int j = 0; j < num; j++)
		{
			if (dist[i][j] < 1000000000 && i != j)
			{
				for (int k = 0; k < 3; k++)
				{
					if (m[k] < dist[i][j])
					{
						for (int l = 2; l >= k + 1; l--)
						{
							m[l] = m[l - 1];
							r[l] = r[l - 1];
						}
						m[k] = dist[i][j];
						r[k] = j;
						break;
					}
				}
			}
		}
		for (int j = 0; j < 3; j++)oo[i][j] = r[j];
	}
	for (int i = 0; i < num; i++)
	{
		int m[3], r[3];
		fill(m, m + 3, 0);
		fill(r, r + 3, -1);
		for (int j = 0; j < num; j++)
		{
			if (dist[j][i] < 1000000000 && i != j)
			{
				for (int k = 0; k < 3; k++)
				{
					if (m[k] < dist[j][i])
					{
						for (int l = 2; l >= k + 1; l--)
						{
							m[l] = m[l - 1];
							r[l] = r[l - 1];
						}
						m[k] = dist[j][i];
						r[k] = j;
						break;
					}
				}
			}
		}
		for (int j = 0; j < 3; j++)ii[i][j] = r[j];
	}
	int a[4];
	int maxi = 0;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (i == j)continue;
			if (dist[i][j] == 1000000000)continue;
			for (int k = 0; k < 3; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					int t[4];
					t[0] = ii[i][k];
					t[1] = i;
					t[2] = j;
					t[3] = oo[j][l];
					sort(t, t + 4);
					if (t[0] == t[1] || t[1] == t[2] || t[2] == t[3])continue;
					if (t[0] == -1)continue;
					if (maxi < dist[ii[i][k]][i] + dist[i][j] + dist[j][oo[j][l]])
					{
						maxi = dist[ii[i][k]][i] + dist[i][j] + dist[j][oo[j][l]];
						a[3] = ii[i][k];
						a[2] = i;
						a[1] = j;
						a[0] = oo[j][l];
					}
				}
			}
		}
	}
	printf("%d %d %d %d\n", a[3]+1, a[2]+1, a[1]+1, a[0]+1);
}