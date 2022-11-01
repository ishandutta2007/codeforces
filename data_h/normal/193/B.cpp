#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 32;

int a[MAXN][MAXN], b[MAXN], N, u, r, k[MAXN], p[MAXN];
long long Ans = -200000000000000ll;

void Dfs(int dep, int last)
{
	if ((u - dep) % 2 == 0)
	{
		long long res = 0;
		for(int i = 1;i <= N;i++)
			res += (long long)k[i] * a[dep][i];
		Ans = max(res, Ans);
	}
	if (dep == u)
		return;
	if (!last)
	{
		for(int i = 1;i <= N;i++)
			a[dep + 1][i] = a[dep][i] ^ b[i];
		Dfs(dep + 1, 1);
	}
	for(int i = 1;i <= N;i++)
		a[dep + 1][i] = a[dep][p[i]] + r;
	Dfs(dep + 1, 0);
}

int main()
{
	scanf("%d %d %d", &N, &u, &r);
	for(int i = 1;i <= N;i++)
		scanf("%d", &a[0][i]);
	for(int i = 1;i <= N;i++)
		scanf("%d", &b[i]);
	for(int i = 1;i <= N;i++)
		scanf("%d", &k[i]);
	for(int i = 1;i <= N;i++)
		scanf("%d", &p[i]);
	Dfs(0, 0);
	printf("%I64d\n", Ans);
	return 0;
}