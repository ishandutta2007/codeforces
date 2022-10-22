#include<cstdio>
#define N 3010
using namespace std;
struct edge{
	int to,next;
}e[N*20];
int first[N],len;
void add(int a,int b)
{
	len++;
	e[len].next=first[a];
	first[a]=len;
	e[len].to=b;
}
int head,tail,d[N],x,to[N][N];
int n,m,a,b,s,ans;
void bfs(int s)
{
	head=0,tail=1;
	d[head]=s;
	while(head<tail)
	{
		x=d[head++];
		for(int i=first[x];i;i=e[i].next)
		{
			if(e[i].to!=s&&!to[s][e[i].to])
				to[s][e[i].to]=to[s][x]+1,
				d[tail++]=e[i].to;
		}
	}
}
int s1,s2,t1,t2,l1,l2;
bool okok1(int a,int b)
{
	if(to[s1][a]+to[a][b]+to[b][t1]>l1||
		to[s2][a]+to[a][b]+to[b][t2]>l2)
			return 0;
	return 1;
}
bool okok2(int a,int b)
{
	if(to[s1][a]+to[a][b]+to[b][t1]>l1||
		to[t2][a]+to[a][b]+to[b][s2]>l2)
			return 0;
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	ans=m+1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	scanf("%d%d%d",&s1,&t1,&l1);
	scanf("%d%d%d",&s2,&t2,&l2);
	for(int i=1;i<=n;i++) bfs(i);
	if(to[s1][t1]<=l1&&to[s2][t2]<=l2)
		if(to[s1][t1]+to[s2][t2]<ans)
			ans=to[s1][t1]+to[s2][t2];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j&&!to[i][j]) continue;
			if(okok1(i,j))
			{
				s=to[s1][i]+to[i][j]+to[j][t1]
					+to[s2][i]+to[j][t2];
				if(s<ans) ans=s;
			}
			if(okok2(i,j))
			{
				s=to[s1][i]+to[i][j]+to[j][t1]
					+to[t2][i]+to[j][s2];
				if(s<ans) ans=s;
			}
		}
	}
	printf("%d",m-ans);
}