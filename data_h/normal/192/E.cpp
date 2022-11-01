#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 210000;

int N;
struct eglist
{
	int other[MAXN * 2], last[MAXN * 2], succ[MAXN * 2], sum;
	eglist()
	{
		sum = 1;
	}
	void AddEdge(int a, int b)
	{
		other[++sum] = b, succ[sum] = last[a], last[a] = sum;
		other[++sum] = a, succ[sum] = last[b], last[b] = sum;
	}
}e;

int Father[19][MAXN], st[MAXN], se[MAXN], top, q[MAXN], u[MAXN], dep[MAXN];
int In[MAXN], Out[MAXN], len, g[MAXN];

void Init()
{
	scanf("%d", &N);
	for(int i = 1, x, y;i < N;i++)
	{
		scanf("%d %d", &x, &y);
		e.AddEdge(x, y);
	}
	int t = 0, w = 1;
	q[w] = 1;
	u[1] = 0;
	Father[0][1] = 0;
	while(t < w)
	{
		int x = q[++t];
		for(int i = e.last[x];i;i = e.succ[i])
		{
			int y = e.other[i];
			if (y == Father[0][x])
				continue;
			Father[0][y] = x;
			dep[y] = dep[x] + 1;
			u[y] = i / 2;
			q[++w] = y;
		}
	}
	st[top = 1] = 1, se[1] = e.last[1];
	In[1] = ++len;
	while(top)
	{
		int x = st[top];
		if (se[top] == 0)
		{
			Out[x] = ++len;
			top--;
		}
		else
		{
			int y = e.other[se[top]];
			se[top] = e.succ[se[top]];
			if (y == Father[0][x])
				continue;
			In[y] = ++len;
			st[++top] = y;
			se[top] = e.last[y];
		}
	}
}

int M, p[MAXN];

int Find(int a, int b)
{
	if (dep[a] < dep[b])
		swap(a, b);
	for(int i = 18;i >= 0;i--)
	{
		if (dep[a] - (1 << i) >= dep[b])
			a = Father[i][a];
	}
	if (a == b)
		return a;
	for(int i = 18;i >= 0;i--)
		if (Father[i][a] != Father[i][b])
			a = Father[i][a], b = Father[i][b];
	return Father[0][a];
}

int Find2(int a, int b)
{
	for(int i = 18;i >= 0;i--)
		if (dep[a] - (1 << i) >= dep[b] + 1)
			a = Father[i][a];
	return a;
}

void Work()
{
	for(int i = 0;i <= 18;i++)
		for(int j = 1;j <= N;j++)
			Father[i + 1][j] = Father[i][Father[i][j]];
	scanf("%d", &M);
	for(int i = 1, a, b, c, d;i <= M;i++)
	{
		scanf("%d %d", &a, &b);
		c = Find(a, b);
		if (a != c)
		{
			d = Find2(a, c);
			g[In[d]]++;
			g[In[a] + 1]--;
		}
		if (b != c)
		{
			d = Find2(b, c);
			g[In[d]]++;
			g[In[b] + 1]--;
		}
	}
	for(int i = 1;i <= len;i++)
		g[i] += g[i - 1];
	for(int i = 1;i <= N;i++)
		p[u[i]] = g[In[i]] - g[Out[i]];
	for(int i = 1;i < N;i++)
		printf("%d ", p[i]);
}

int main()
{
	Init();
	Work();
	return 0;
}