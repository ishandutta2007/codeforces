#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int m[400][400];
bool flag[400];
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
		m[za][zb] = 1;
		m[zb][za] = 1;
	}
	if (m[0][num - 1])
	{
		for (int i = 0; i < num; i++)for (int j = 0; j < num; j++)if (i != j)m[i][j] ^= 1;
	}
	queue<pii>que;
	que.push(make_pair(0, 0));
	fill(flag, flag + num, false);
	for (;;)
	{
		if (que.empty())
		{
			printf("-1\n");
			return 0;
		}
		pii z = que.front();
		que.pop();
		if (flag[z.second])continue;
		flag[z.second] = true;
		if (z.second == num - 1)
		{
			printf("%d\n", z.first);
			return 0;
		}
		for (int i = 0; i < num; i++)
		{
			if (m[z.second][i])que.push(make_pair(z.first + 1, i));
		}
	}
}