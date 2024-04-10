#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 100005;

int occure[MAXN], order[MAXN], n;
struct eglist
{
	int other[MAXN * 5], succ[MAXN * 5], last[MAXN], sum;
	void clear()
	{
		memset(last, 0, sizeof(last));
		sum = 0;
	}
	void AddEdge(int a, int b)
	{
		other[++sum] = b, succ[sum] = last[a], last[a] = sum;
	}
}e;

int hash[MAXN];

void dfs(int pos, int num)
{
	//printf("%d %d\n", pos, num);
	if (pos == 4)
	{
		for(int i = 3; i < n - 1; i++)
		{
			int x = order[i], flag = 0;
			for(int j = e.last[x]; j; j = e.succ[j])
			{
				int y = e.other[j];
				flag = 1;
				for(int k = i - 2; k <= i + 1; k++)
					if (order[k] == y)
						flag = 0;
				if (flag)
				{
					order[i + 2] = y;
					break;
				}
			}
			if (!flag)
				return ;
		}
		memset(hash, 0, sizeof(hash));
		for(int i = 1; i <= n; i++)
			if (hash[order[i]])
				return;
			else
				hash[order[i]] = 1;
				
		order[n + 1] = order[1]; order[n + 2] = order[2];
		for(int i = 3; i <= n; i++)
		{
			for(int j = e.last[order[i]]; j; j = e.succ[j])
			{
				int y = e.other[j];
				int flag = 0;
				for(int k = i - 2; k <= i + 2; k++)
					if (order[k] == y)
						flag = 1;
				if (!flag)
					return;
			}
		}
		for(int i = 1; i <= n; i++)
			printf("%d%c", order[i], i == n ? '\n' : ' ');
		exit(0);
	//	return ;
	}
	
	for(int i = e.last[num]; i; i = e.succ[i])
	{
		//printf("ok\n");
		int y = e.other[i];
		order[pos + 1] = y;
		int flag = 1;
		for(int j = 1; j <= pos; j++)
			if (order[j] == y)
				flag = 0;
		if (flag)
			dfs(pos + 1, y);
	}
}

int main()
{

	scanf("%d", &n);
	memset(occure, 0, sizeof(occure));
	e.clear();
	for(int i = 1; i <= 2 * n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		e.AddEdge(a, b); occure[a]++;
		e.AddEdge(b, a); occure[b]++;
	}
	for(int i = 1; i <= n; i++)
	{
		if (occure[i] != 4)
		{
			printf("-1\n");
			return 0;
		}
	}
	memset(hash, 0, sizeof(hash));
	order[1] = 5;
	dfs(1, 5);
	printf("-1\n");
	return 0;
}