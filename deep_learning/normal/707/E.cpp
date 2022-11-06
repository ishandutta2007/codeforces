#include <iostream>
#include <cstring>
#include <utility>
#include <cstdio>
#include <vector>
#include <string>
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll; 
class node
{
public:
	int x, y, w; 
}; 
class Q_tp
{
public:
	int x1, y1, x2, y2; 
} ask[2048]; 
class GARLAND
{
public:
	int len; 
	node arr[2048]; 
} garland[2048]; 
int n, m, k, tot;
ll ans[2048][2048], arr[2048][2048]; 
bool off[2048];
char query[1024000][64]; 
void add(int i, int j, int num)
{
	for (int x = i; x <= n; x += x & -x)
	{
		for (int y = j; y <= m; y += y & -y)
			arr[x][y] += num; 
	}
}
ll sum(int i, int j)
{
	ll res = 0; 
	for (int x = i; x; x -= x & -x)
	{
		for (int y = j; y; y -= y & -y)
			res += arr[x][y]; 
	}
	return res; 
}
ll sum(int x1, int y1, int x2, int y2)
{
	return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1); 
}
int main()
{
	// freopen("707E.in", "r", stdin); 
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; i++)
	{
		int len; 
		scanf("%d", &len); 
		for (int j = 0; j < len; j++)
		{
			int x, y, w; 
			scanf("%d%d%d", &garland[i].arr[garland[i].len].x, &garland[i].arr[garland[i].len].y
				, &garland[i].arr[garland[i].len].w); 
			garland[i].len++; 
		}
	}
	int q; 
	scanf("%d\n", &q); 
	for (int i = 0; i < q; i++)
	{
		gets(query[i]); 
		if (query[i][0] == 'A')
		{
			int x1, y1, x2, y2; 
			sscanf(query[i], "%*s%d%d%d%d", &ask[tot].x1, &ask[tot].y1, &ask[tot].x2, &ask[tot].y2); 
			tot++; 
		}
	}
	// printf("%d\n", ask.size());
	for (int i = 0; i < k; i++)
	{
		if (i)
		{
			for (int j = 0; j < garland[i - 1].len; j++)
				add(garland[i - 1].arr[j].x, garland[i - 1].arr[j].y, -garland[i - 1].arr[j].w); 
		}
		for (int j = 0; j < garland[i].len; j++)
			add(garland[i].arr[j].x, garland[i].arr[j].y, garland[i].arr[j].w); 
		for (int j = 0; j < tot; j++)
			ans[i][j] = sum(ask[j].x1, ask[j].y1, ask[j].x2, ask[j].y2); 
	}
	int cur = 0; 
	for (int i = 0; i < q; i++)
	{
		if (query[i][0] == 'S')
		{
			int x; 
			sscanf(query[i], "%*s%d", &x); 
			off[--x] ^= 1; 
		}
		else
		{
			ll res = 0; 
			for (int j = 0; j < k; j++)
			{
				if (!off[j])
					res += ans[j][cur]; 
			}
			printf("%lld\n", res);
			cur++; 
		}
	}
	return 0; 
}