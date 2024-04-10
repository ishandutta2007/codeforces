#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int N;
struct node
{
	int x, y;
}d[2000];
int L[2100], R[2100], Ans;

int cmp(node a,node b)
{
	if (a.x != b.x)
		return a.x > b.x;
	return a.y < b.y;
}

void Init()
{
	scanf("%d",&N);
	for(int i = 1;i <= N;i++)
	{
		scanf("%d %d",&d[i].x,&d[i].y);
		d[i].x += 1001;;
		d[i].y += 1001;
	}
	sort(d + 1,d + N + 1,cmp);
}

void Work()
{
	for(int i = 1;i <= N;i++)
		R[d[i].y]++;
	for(int i = 1, j;i <= N;i++)
	{
		for(j = i;d[j].x == d[i].x && j <= N;j++);
		for(int k = i;k < j;k++)
			R[d[k].y]--;
		for(int k = i + 1;k < j - 1;k++)
			if (L[d[k].y] && R[d[k].y])
				Ans++;
		for(int k = i;k < j;k++)
			L[d[k].y]++;
		i = j - 1;
	}
	printf("%d\n",Ans);
} 

int main()
{
	Init();
	Work();
	return 0;
}