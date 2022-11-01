#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 3100000;
const int inf = 200000000;

int l, r, p;
int buc[MAXN], cnt, f[MAXN], g[MAXN];
int prim[MAXN], check[MAXN], top = 0;

int dfs(int now, int last)
{
	if (now <= r)
		buc[++cnt] = now;
	for(int i = last; i >= 1; i--)
	{
		if (prim[i] > r / now)
			continue;
		dfs(now * prim[i], i);
	}
}

int main()
{

	scanf("%d %d %d", &l, &r, &p);
	for(int i = 2; i <= 100; i++)
		if (!check[i])
		{
			prim[++top] = i;
			for(int j = i + i; j <= 100; j += i)
				check[j] = 1;
		}
	//printf("top = %d\n", top);
	for(int i = top; i >= 1; i--)
		dfs(prim[i], i);
	sort(buc + 1, buc + cnt + 1);
	
	for(int i = 1; i <= cnt; i++)
		g[i] = inf, f[i] = inf;
	/*printf("cnt = %d\n", cnt);
	
	for(int i = 1; i <= cnt; i++)
		printf("%d ", buc[i]);
	printf("\n");
	*/	
	for(int i = 2; i <= 100; i++)
	{
		int k = 1;
		for(int j = 1; j <= cnt; j++)
		{
			if (i >= buc[j])
				f[j] = min(f[j], 1);
			g[j] = min(g[j], f[j] + i);
			while(k <= cnt && (long long)buc[j] * i > buc[k])
				k++;
			if (k <= cnt && (long long)buc[j] * i == buc[k])
			{
				f[k] = min(f[k], f[j] + 1);
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= cnt; i++)
		if (buc[i] >= l)
	{
		if (g[i] <= p)
			ans++;
		//printf("%d:%d\n", g[i], f[i]);
	}
	printf("%d\n", ans);
	return 0;
}