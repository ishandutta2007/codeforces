#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 300000;
struct node
{
	int x, num;
}p[MAXN], v[MAXN];
int x, y, N, M, Ans, Link[MAXN];
int cmp(node a,node b)
{
	return a.x < b.x;
}
void Init()
{
	scanf("%d %d %d %d",&N,&M,&x,&y);
	for(int i = 1;i <= N;i++)
	{
		scanf("%d",&p[i].x);
		p[i].num = i;
	}
	//sort(p + 1,p + N + 1,cmp);
	for(int i = 1;i <= M;i++)
	{
		scanf("%d",&v[i].x);
		v[i].num = i;
	}
	//sort(v + 1,v + M + 1,cmp);
}

void Work()
{
	for(int i = 1, j = 1;i <= N;i++)
	{
		while(j <= M && v[j].x < p[i].x - x)
			j++;
		if (j <= M && v[j].x <= p[i].x + y)
		{
			Ans++;
			Link[i] = j;
			j++;
		}
	}
	printf("%d\n",Ans);
	for(int i = 1;i <= N;i++)
	if (Link[i])
		printf("%d %d\n",i, Link[i]);
}

int main()
{
	Init();
	Work();
	return 0;
}