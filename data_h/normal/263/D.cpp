#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 200000, MAXM = MAXN;

int n, m, k;
int pri[MAXN], path[MAXN], top;

struct eglist
{
	int other[MAXM * 2], succ[MAXM * 2], last[MAXM * 2], sum;
	void clear()
	{
		memset(last, 0, sizeof(last));
		sum = 0;
	}
	void AddEdge(int a, int b)
	{
		other[++sum] = b, succ[sum] = last[a], last[a] = sum;
		other[++sum] = a, succ[sum] = last[b], last[b] = sum;
	}
}e;

int main()
{

	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		e.AddEdge(a, b);
	}
	memset(pri, 0, sizeof(pri));
	int x = 1; top = 1;
	pri[x] = 1; path[top] = x;
	while(1)
	{
		int flag = 1;
		for(int i = e.last[x]; i; i = e.succ[i])
		{
			int y = e.other[i];
			if (pri[y])
				continue;
			flag = 0;
			pri[y] = ++top;
			path[top] = y;
			x = y;
			break;
		}
		if (!flag)
		 	continue;
		int MinTmp = MAXN, cho = -1;
		for(int i = e.last[x]; i; i = e.succ[i])
		{
			int y = e.other[i];
			if (pri[y] < MinTmp)
				MinTmp = pri[y], cho = y;
		}
		printf("%d\n", top - MinTmp + 1);
		for(int i = MinTmp; i <= top; i++)
			printf("%d%c", path[i], i == top ? '\n' : ' ');
		break;
	}
	return 0;
}