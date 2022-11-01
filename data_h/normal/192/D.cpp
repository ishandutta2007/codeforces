#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 210000;
int N, left;
struct node
{
	int v, num;
}d[MAXN];
int sa[MAXN], Ans, v[MAXN];
long long sum[MAXN], Tot;

int cmp(node a, node b)
{
	return a.v > b.v;
}

void Init()
{
	scanf("%d %d", &N, &left);
	Ans = N;
	scanf("%I64d", &Tot);
	for(int i = 1;i <= N;i++)
		scanf("%d", &d[i].v), d[i].num = i;
	sort(d + 1, d + N, cmp);
}

void Work()
{
	for(int i = 1;i <= N;i++)
		sum[i] = sum[i - 1] + d[i].v, sa[d[i].num] = i, v[d[i].num] = d[i].v;
	
	for(int i = 1;i < N;i++)
	{
		if (sa[i] <= left)
		{
			if (sum[left] > Tot)
				Ans = min(Ans, i);
		}
		else
		{
			if (sum[left - 1] + v[i] > Tot)
				Ans = min(Ans, i);
		}
	}
	printf("%d\n", Ans);
}

int main()
{
	Init();
	Work();
	return 0;
}