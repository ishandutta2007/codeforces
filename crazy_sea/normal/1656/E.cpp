#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int N=1e5+10;
struct edge{
	int next,to;
}e[N<<1];
int first[N],len,a[N],fa[N],T,n,x,y;
void add(int a,int b)
{
	e[++len]=edge{first[a],b};
	first[a]=len;
}
void dfs(int x,int d)
{
	a[x]*=d;
	for(int i=first[x],y;i;i=e[i].next)
		if((y=e[i].to)!=fa[x]) fa[y]=x,dfs(y,-d);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<n;i++)
			scanf("%d%d",&x,&y),add(x,y),add(y,x),a[x]++,a[y]++;
		dfs(1,1);
		for(int i=1;i<=n;i++) printf("%d ",a[i]);
		putchar('\n');
		for(int i=1;i<=n;i++) first[i]=a[i]=0;
	}
}