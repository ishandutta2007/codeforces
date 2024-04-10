#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 210000;

struct eglist
{
	int other[MAXN * 2], succ[MAXN * 2], last[MAXN * 2], r[MAXN * 2], sum, num[MAXN * 2], G[MAXN * 2];
	void clear()
	{
		memset(last, 0, sizeof(last));
		sum = 1;
	}
	void AddEdge(int a, int b, int c, int d)
	{
		//if (b != 1)
			other[++sum] = b, succ[sum] = last[a], last[a] = sum, r[sum] = 0, num[sum] = d, G[sum] = c;
		//if (a != 1)
			other[++sum] = a, succ[sum] = last[b], last[b] = sum, r[sum] = 1, num[sum] = d, G[sum] = c;
	}
}e;
int n, m, totw[MAXN], flow[MAXN];
struct node
{
	int x;
	double val;
	node(){}
	node(int _x, double _val) : x(_x), val(_val) {}
	friend int operator <(node a, node b)
	{
		return a.val < b.val;
	}
};
struct Res
{
	int id, dir;
	friend int operator <(Res a, Res b)
	{
		return a.id < b.id;
	}
}res[MAXN];
int cnt = 0, visit[MAXN];
priority_queue<node> q;
int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &m);
	e.clear();
	for(int i = 1; i <= m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		e.AddEdge(a, b, c, i);
		totw[a] += c;
		totw[b] += c;
	}
	q.push(node(1, 0));
	while(!q.empty())
	{
		node now = q.top();
		q.pop();
		int x = now.x;
		if (visit[x] || x == n)
			continue;
		visit[x] = 1;
		for(int i = e.last[x]; i; i = e.succ[i])
		if (e.r[i] != -1)
		{
			res[++cnt].id = e.num[i];
			res[cnt].dir = e.r[i];
			e.r[i] = e.r[i ^ 1] = -1;
			int y = e.other[i];
			flow[y] += e.G[i];
			q.push(node(y, (double)flow[y] / totw[y]));
		}
	}
	sort(res + 1, res + cnt + 1);
	for(int i = 1; i <= cnt; i++)
		printf("%d\n", res[i].dir);
	return 0;
}