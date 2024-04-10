#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 300000;
struct node
{
	long long x, y;
}A[MAXN], B[MAXN];
int N, M;

long long Cross(node a,node b,node c)
{
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

void Init()
{
	scanf("%d",&N);
	for(int i = 1;i <= N;i++)
		scanf("%I64d %I64d",&A[i].x, &A[i].y);
}

void Work()
{
	int p = 0;
	node now;
	scanf("%d",&M);
	for(int i = 1;i <= M;i++)
	{
		if (i == 4)
			i = 4;
		scanf("%I64d %I64d",&now.x,&now.y);
		if (Cross(A[1], A[2], now) >= 0)
			continue;
		if (Cross(A[1], A[N], now) <= 0)
			continue; 
		int l = 2, r = N, mid;
		while(l < r)
		{
			mid = (l + r) >> 1;
			if (Cross(A[1], A[mid], now) < 0)
				l = mid + 1;
			else
				r = mid;
		}
		if (l > 1 && Cross(A[l - 1], A[l], now) < 0)
			p++;
	}
	if (p == M)
		printf("YES\n");
	else
		printf("NO\n");
}

int main()
{
	Init();
	Work();
	return 0;
}