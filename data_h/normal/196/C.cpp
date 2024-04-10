#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 20000;

struct node
{
	long long x, y;
	int num;
	double a2;
	friend int operator <(node a, node b)
	{
		return a.x < b.x || a.x == b.x && a.y < b.y;
	}
}p[MAXN], cent;
struct eglist
{
	int other[MAXN * 2], last[MAXN * 2], succ[MAXN * 2], sum;
	void AddEdge(int x, int y)
	{
		other[++sum] = y, succ[sum] = last[x], last[x] = sum;
		other[++sum] = x, succ[sum] = last[y], last[y] = sum;
	}
}e;

int N, Ans[MAXN], visit[MAXN], size[MAXN];

void Dfs(int x)
{
	visit[x] = 1;
	size[x] = 1;
	for(int i = e.last[x];i;i = e.succ[i])
	{
		int y = e.other[i];
		if (!visit[y])
			Dfs(y), size[x] += size[y];
	}
}

void Init()
{
	scanf("%d", &N);
	for(int i = 1;i < N;i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		e.AddEdge(a, b);
	}
	for(int i = 1;i <= N;i++)
	{
		scanf("%I64d %I64d", &p[i].x, &p[i].y);
		p[i].num = i;
	}
}

long long Cross(node a, node b, node c)
{
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

int cmp(node a, node b)
{
	return Cross(cent, a, b) > 0;
}

void Work(int x, int l, int r)
{
	visit[x] = 1;
	for(int i = l + 1;i <= r;i++)
		if (p[i] < p[l])
			swap(p[i], p[l]);
	Ans[p[l].num] = x;
	if (size[x] == 1)
		return;
	cent = p[l];
	sort(p + l + 1, p + r + 1, cmp);
	int cnt = l + 1;
	for(int i = e.last[x];i;i = e.succ[i])
	{
		int y = e.other[i];
		if (!visit[y])
		{
			Work(y, cnt, cnt + size[y] - 1);
			cnt += size[y];
		}
	}
}

int main()
{
	Init();
	Dfs(1);
	memset(visit, 0, sizeof(visit));
	Work(1, 1, N);
	for(int i = 1;i <= N;i++)
		printf("%d ", Ans[i]);
	return 0;
}