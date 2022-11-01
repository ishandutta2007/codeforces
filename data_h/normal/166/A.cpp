#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
struct node
{
	int p, t;
	friend int operator <(node a,node b)
	{
		return a.p > b.p || a.p == b.p && a.t < b.t;
	}
}d[60];
void Init()
{
	int N,K;
	scanf("%d %d",&N,&K);
	for(int i = 1;i <= N;i++)
	{
		scanf("%d %d",&d[i].p,&d[i].t);
	}
	sort(d + 1,d + N + 1);
	int Ans = 1;
	for(int i = K - 1;i >= 1;i--)
		if (!(d[K] < d[i]) && !(d[i] < d[K]))
			Ans++;
	for(int i = K + 1;i <= N;i++)
		if (!(d[K] < d[i]) && !(d[i] < d[K]))
			Ans++;
	printf("%d\n",Ans);
}
int main()
{
	Init();
	return 0;
}