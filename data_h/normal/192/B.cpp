#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 1100;

int N;
struct node
{
	int a, num;
}d[MAXN];

int cmp(node a, node b)
{
	return a.a < b.a;
}

void Init()
{
	scanf("%d", &N);
	for(int i = 1;i <= N;i++)
		scanf("%d", &d[i].a), d[i].num = i;
	sort(d + 1, d + N + 1, cmp);
}

int Des[MAXN], now, f[MAXN];

void Work()
{
	for(int i = 1;i <= N;i++)
	{
		Des[d[i].num] = 1;
		now = d[i].a;
		if (Des[1])
			break;
		for(int j = 1;j <= N;j++)
			f[j] = 0;
		f[1] = 1;
		for(int j = 1;j <= N;j++)
		if (f[j])
		{
			if (j + 1 <= N && Des[j + 1] == 0)
				f[j + 1] = 1;
			if (j + 2 <= N && Des[j + 2] == 0)
				f[j + 2] = 1;
		}
		if (!f[N])
			break;
	}
	printf("%d\n", now);
}

int main()
{
	Init();
	Work();
	return 0;
}