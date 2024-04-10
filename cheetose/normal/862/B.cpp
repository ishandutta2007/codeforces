#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
vector<int> v[100001];
int color[100001];
void bfs()
{
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++)
		{
			int next = v[x][i];
			if (color[next] == -1)
			{
				color[next] = 3 - color[x];
				q.push(next);
			}
		}
	}
}
int main()
{
	memset(color, -1, sizeof(color));
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	color[1] = 1;
	bfs();
	ll c1 = 0, c2 = 0;
	for (int i = 1; i <= n; i++)
	{
		if (color[i] == 1)c1++;
		if (color[i] == 2)c2++;
	}
	printf("%I64d", c1*c2 - (n - 1));
}